#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor TopRight = motor(PORT20, ratio6_1, true);
motor BottomRight = motor(PORT16, ratio6_1, true);
motor FrontRight = motor(PORT17, ratio6_1, true);
motor TopLeft = motor(PORT13, ratio6_1, true);
motor BottomLeft = motor(PORT14, ratio6_1, true);
motor FrontLeft = motor(PORT11, ratio6_1, true);
motor Conveyor = motor(PORT21, ratio6_1, true);
motor LadyB = motor(PORT19, ratio6_1,false);
motor Intake = motor (PORT15, ratio18_1,true);
digital_out ClampA = digital_out(Brain.ThreeWirePort.H);
motor_group LeftDrive = motor_group(TopLeft,BottomLeft,FrontLeft);
motor_group RightDrive = motor_group(TopRight,BottomRight,FrontRight);
controller Controller1 = controller(primary);
drivetrain Drivetrain = drivetrain(LeftDrive,RightDrive,320,320,130,mm,1.3);
motor_group Engage = motor_group(Intake,Conveyor);
rotation Rotation = rotation(PORT1,false);
digital_out Doink = digital_out(Brain.ThreeWirePort.G);
motor_group intake = (Conveyor,Intake);



// VEXcode generated functions
bool RemoteControlCodeEnabled = true;
//Controller Variables/Inputs
bool Controller1RightShoulderControlMotorsStopped = true;
bool Controller1LeftShoulderControlMotorsStopped = true;
bool Controller1ArrowsMotorsStopped = true;
bool Controller1ButtonsMotorsStopped = true;
// defines a task that will handle monitoring inputs from Controller1

int rc_auto_loop_function_Controller1() {
  wait(20,msec);
  while(true) {
    if(RemoteControlCodeEnabled) {
      // Button Configuration on Controller1
      if (Controller1.ButtonR1.pressing()) {
        intake.spin(forward);
        Conveyor.spin(forward);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonR2.pressing()) {
        Intake.spin(reverse);
        Conveyor.spin(reverse);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (!Controller1RightShoulderControlMotorsStopped) {
        Intake.stop();
        Conveyor.stop();
        Controller1RightShoulderControlMotorsStopped = true;
      }

      
    }
   
    }
    
    wait(20, msec);
  }


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}