#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     IRSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorNone)
#pragma config(Motor,  motorA,          ziptiesMotor,  tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     rightMotor,    tmotorTetrix, openLoop, driveRight, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftMotor,     tmotorTetrix, openLoop, reversed, driveLeft, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     raiseMotor,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    rightHook,            tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    leftHook,             tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)

#pragma debuggerWindows("debugStream");

#include "JoystickDriver.c"
#include "Utilities.c"
#include "Driver.c"
#include "Autonomous.c"
#include "Manipulators.c"

task main()
{
	allstop();

	// autonomous runs up to 30 seconds from start
  unsigned long programStart = nSysTime;
	unsigned long autonomousEnd = programStart + 30000;

	// run the right autonomous program
	//autonomousFloor();
	//autonomousRamp();
  allstop();

	// stop until the autonomous period is over
	waitUntil(autonomousEnd);

	// loop while we drive and run manipulatorss
	while(true)
	{
		//Get the Latest joystick values
		getJoystickSettings(joystick);
		//use the joystick settings to drive the wheels
		drive();
		//use the joystick settings to run the manipulators
		manipulators();
	}
}
