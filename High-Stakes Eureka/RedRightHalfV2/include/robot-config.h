using namespace vex;

extern brain Brain;

// VEXcode devices

extern motor TopRight;
extern motor BottomRight;
extern motor FrontRight;
extern motor TopLeft;
extern motor BottomLeft;
extern motor FrontLeft;
extern motor Intake;
extern motor LadyB;
extern digital_out ClampA;
extern motor_group LeftDrive;
extern motor_group RightDrive;
extern controller Controller1;
extern drivetrain Drivetrain;
extern color ColorS;
extern inertial Inertial;
extern rotation Rotation; 
extern motor_group Engage;
extern digital_out Doink;
extern rotation ForwardS;
extern motor Conveyor;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );