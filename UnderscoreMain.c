#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,	none)
#pragma config(Sensor, S2,     IRSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     light,	       sensorLightActive)
#pragma config(Sensor, S4,     sonar,	       sensorNone)
#pragma config(Motor,  motorA,		gripperMotor,  tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,	rightMotor,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,	leftMotor,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,	unused,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,	unUsed,        tmotorTetrix, openLoop, encoder)

#pragma debuggerWindows("joystickSimple");
#include "Driver.c"
#include "Autonomous.c"
#include "Manipulators.c"

task main()
{
	autonomous();

	//Loop Forever
	while(1 == 1)
	{
		//Get the Latest joystick values
		getJoystickSettings(joystick);

		if (!hatSwitchControl()){
			joystickControl();
		}


	}
}
