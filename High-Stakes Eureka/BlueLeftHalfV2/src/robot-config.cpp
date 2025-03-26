#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors

motor TopRight = motor(PORT20, ratio6_1, false);
motor BottomRight = motor(PORT16, ratio6_1, false);
motor FrontRight = motor(PORT17, ratio6_1, false);

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
drivetrain Drivetrain = drivetrain(LeftDrive,RightDrive,320,320,320,mm,1);
motor_group Engage = motor_group(Intake,Conveyor);
rotation Rotation = rotation(PORT1,false);
rotation ForwardS = rotation(PORT2);
color ColorS = color(PORT10);
digital_out Doink = digital_out(Brain.ThreeWirePort.G);



// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}