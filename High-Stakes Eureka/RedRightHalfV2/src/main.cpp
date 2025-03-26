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
  KP = .1;
  Target = 0;

  LadyB.setVelocity((Target - Rotation.angle()) * KP, percent);

} 

void LadyBPosition2() {
KP = .5;
Target = 65;
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



void RedRightV2() { 
Engage.setVelocity(100, percent);
Intake.setVelocity(100, percent);
Conveyor.setVelocity(100, percent);
Drivetrain.setDriveVelocity(55, percent);
Drivetrain.setTurnVelocity(10, percent);
Drivetrain.driveFor(reverse,5,inches);
Drivetrain.turnFor(right,-35,degrees);
Drivetrain.setDriveVelocity(30, percent);
ClampA.set(true);
Drivetrain.driveFor(reverse,62,inches);
ClampA.set(false);
Drivetrain.turnFor(right,-85,degrees);
Engage.spin(forward);
Drivetrain.setDriveVelocity(55, percent);
Drivetrain.driveFor(forward,25,inches);
Drivetrain.turnFor(left,-170,degrees);
LadyBPosition2();
wait(1,seconds);
Drivetrain.driveFor(forward,40,inches);
Engage.stop();
wait(2.5,seconds);
LadyB.stop();








/*Drivetrain.turnFor(right,110,degrees);
Drivetrain.setDriveVelocity(45, percent);
Drivetrain.driveFor(forward,24,inches);
Drivetrain.turnFor(right,16,degrees);
Drivetrain.driveFor(forward,6,inches);
Doink.set(true);
wait(.75,seconds);
Drivetrain.driveFor(reverse,55, inches);
Doink.set(true);
Engage.spin(forward);
Drivetrain.driveFor(forward,20,inches);
Drivetrain.turnFor(right,50,degrees);
*/

}  











int current_auton_selection = 0;
bool auto_started = false;
void pre_auton() {
  vexcodeInit();
 

  while(!auto_started){
    if(ColorS.rgb() == Blue){
    Intake.setReversed(true);
    }

    if(ColorS.rgb() == Red) {
    Intake.spin(forward);
    }
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 40, "Battery Percentage:");
    Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
    Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
    Brain.Screen.printAt(5, 120, "Selected Auton:");
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
      RedRightV2();
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
