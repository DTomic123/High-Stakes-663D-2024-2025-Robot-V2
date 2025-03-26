/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\663D                                             */
/*    Created:      Wed Sep 04 2024                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Conveyor             motor         13              
// Intake               motor         14              
// TopLeft              motor         15              
// TopRight             motor         16              
// UpperRight           motor         17              
// UpperLeft            motor         18              
// LowerLeft            motor         19              
// LowerRight           motor         20              
// ClumpA               digital_out   A               
// ClumpB               digital_out   B               
// Controller1          controller                    
// Inertial             inertial      3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;
competition Competition;

void toggleClampA() {
  if (ClampA.value() == false) {
    ClampA.set(true);
  }
  else {
    ClampA.set(false);
  }
}

 double angle = Rotation.angle(degrees);

double KP = 0;
double Target = 0;

void LadyBPosition1() {
  KP = 10;
  Target = 0;

  LadyB.setVelocity((Target - Rotation.angle()) * KP, percent);

} 

void LadyBPosition2() {
KP = 1;
Target = 19.5;
LadyB.spin(forward);
 LadyB.setVelocity((Target - Rotation.angle()) * KP, percent);

}

void LadyBPosition3() {
KP = 100;
Target = 100;
LadyB.spin(forward);
  LadyB.setVelocity((Target - Rotation.angle()) * KP, percent);

}
 



color Red = color(10,0,0);
color Blue = color(0,0,240);

void Skills() {
Drivetrain.setDriveVelocity(50, percent);
Conveyor.setVelocity(50, percent);
Intake.setVelocity(50, percent);
Engage.setVelocity(50, percent);
RightDrive.setVelocity(50, percent);
LeftDrive.setVelocity(50, percent);
Drivetrain.setDriveVelocity(30,percent);
Drivetrain.setTurnVelocity(20, percent);
Conveyor.setReversed(true);
Intake.setReversed(true);
Drivetrain.setDriveVelocity(25, percent);
LadyBPosition3();
wait(1,seconds);
//Drivetrain.driveFor(forward,10,inches); //adjust for plastic fields
//Engage.stop();
Engage.spin(forward);
LadyBPosition1();
Conveyor.setVelocity(100, percent);
Intake.setVelocity(100, percent);
Engage.setVelocity(100, percent);
Drivetrain.turnFor(left,8,degrees);
ClampA.set(true);
Drivetrain.driveFor(reverse,27,inches);
ClampA.set(false);
Drivetrain.turnFor(right,120,degrees);
Drivetrain.setDriveVelocity(30,percent);
Drivetrain.driveFor(forward,30,inches);//First Ring
Drivetrain.turnFor(right,35,degrees);
Drivetrain.driveFor(forward,65,inches);//second ring
Drivetrain.driveFor(reverse,20,inches);
Drivetrain.turnFor(right,112,degrees);
Drivetrain.driveFor(forward,76,inches); //gets row
//wait(1,seconds); //just in case
Drivetrain.driveFor(reverse,12,inches);
Drivetrain.turnFor(left,75,degrees);
Drivetrain.driveFor(forward,20,inches);
Drivetrain.driveFor(reverse,20,inches);
Drivetrain.turnFor(left,125,degrees);
Conveyor.spin(reverse);
ClampA.set(true);
Drivetrain.driveFor(reverse,15,inches);
Engage.stop();
Drivetrain.driveFor(forward,20,inches);
Drivetrain.turnFor(right,38,degrees);
Drivetrain.setDriveVelocity(50, percent);
Drivetrain.driveFor(forward,75,inches);
Drivetrain.turnFor(right,145,degrees);
Drivetrain.setDriveVelocity(30, percent);
Drivetrain.driveFor(reverse,90,inches);
ClampA.set(false);
Drivetrain.driveFor(forward,10,inches);
Drivetrain.turnFor(left,90,degrees);
Engage.spin(forward);
Drivetrain.driveFor(forward,35,inches);
Drivetrain.driveFor(reverse,10,inches);
Drivetrain.turnFor(left,180,degrees);
Drivetrain.setDriveVelocity(50, percent);
Drivetrain.driveFor(reverse,20,inches);
ClampA.set(true); 
Drivetrain.driveFor(reverse,20,inches);
Drivetrain.driveFor(forward,30,inches);

}  

int current_auton_selection = 0;
bool auto_started = false;
void pre_auton() {
  vexcodeInit();
 

  while(!auto_started){
    if(ColorS.rgb(Blue)){
      Intake.setReversed(true);
    }

    if(ColorS.rgb(Red)){
      Intake.setReversed(false);
    }

    
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 40, "Battery Percentage:");
    Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
    Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");

    
    switch(current_auton_selection){
      case 0:
        Brain.Screen.printAt(5, 140, "Auton 1");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 1){
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}
void autonomous(void) {
  auto_started = true;
  switch(current_auton_selection){ 
    case 0:
      Skills();
      break;
  }
}

int main() {
  Competition.autonomous(autonomous);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
