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

double KP = 0;
double Target = 0;
void LadyBPosition1() {
  KP = .5;
  Target = 2;

  LadyB.setVelocity((Target - Rotation.angle()) * KP, percent);

} 

void LadyBPosition2() {
KP = 1;
Target = 18.5;
LadyB.spin(forward);
 LadyB.setVelocity((Target - Rotation.angle()) * KP, percent);

}

void LadyBPosition3() {
KP = 100;
Target = 100;
LadyB.spin(forward);
  LadyB.setVelocity((Target - Rotation.angle()) * KP, percent);

}


 double angle = Rotation.angle(degrees);
 





void BlueRightHalf() {
LadyBPosition3();
Engage.setVelocity(100, percent);
wait(.8, seconds);
LadyBPosition1();
ClampA.set(true);
Drivetrain.setDriveVelocity(30, percent);  //was 30
Drivetrain.driveFor(reverse,30,inches);
Drivetrain.setTurnVelocity(30, percent); 
Drivetrain.turnFor(left,-123,degrees);
Intake.spin(forward); //DO NOT DELETE  This here might have to be changed to reverse if alliance has a better ring rush //was 30
Drivetrain.driveFor(forward,65, inches);
Engage.spinFor(forward,.75,seconds);
Intake.spin(forward);
Drivetrain.turnFor(left,-37,degrees);  //was 43
Drivetrain.setDriveVelocity(30, percent); //was 30
Drivetrain.driveFor(forward, 13, inches);  //was 15
Drivetrain.driveFor(reverse, 60, inches);
Drivetrain.turnFor(left,3,degrees);
ClampA.set(false);
Drivetrain.driveFor(forward,8,inches);
Drivetrain.turnFor(left,-27,degrees);
Engage.spin(forward);
Drivetrain.driveFor(forward, 32, inches);
Drivetrain.driveFor(reverse, 15, inches);

//turning towards ladder
Drivetrain.turnFor(left,-175,degrees);
Engage.stop();
LadyBPosition2();
wait(1,seconds);
Drivetrain.driveFor(forward,39,inches);
}  





int current_auton_selection = 0;
bool auto_started = false;
void pre_auton() {
  vexcodeInit();
 

  while(!auto_started){
   
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 40, "Battery Percentage:");
    Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
    Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
    Brain.Screen.printAt(5, 120, "Selected Auton:");
    switch(current_auton_selection){
      case 0:
        Brain.Screen.printAt(5, 140, "On Skib, Mad Sus");
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
      BlueRightHalf();
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
