#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     IRSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorNone)
#pragma config(Motor,  motorA,          ziptiesMotor,  tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     leftMotor,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     rightMotor,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     raiseMotor,    tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    rightHook,            tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    leftHook,             tServoStandard)

#include "JoystickDriver.c"

void manipulators() {
	//Arm Motor Control
	if(joy1Btn(5) == 1)       // If button 5 (LB) is pressed...
	{
		motor[raiseMotor] = 35;     // ...raise the grabber.
	}
	else if(joy1Btn(7) == 1)  // Else, if button 7 (LT) is pressed...
	{
		motor[raiseMotor] = -35;    // ...lower the grabber.
	}
	else                      // Else (neither button is pressed)...
	{
		motor[raiseMotor] = 0;      // ...stop the elevator.
	}

	//Gripper Motor Control
	if(joy1Btn(6) == 1)       // If button 6 (RB)is pressed...
	{
		motor[ziptiesMotor] = 50;     // ...suck in the balls.
	}
	else if(joy1Btn(8) == 1)  // Else, if button 8 (RT) is pressed...
	{
		motor[ziptiesMotor] = -50;    // ...let out the balls.
	}
	else                      // Else (neither button is pressed)...
	{
		motor[ziptiesMotor] = 0;      // ...stop the zipties.
	}
}

void moveHooks(){
	if(joy1Btn(1) = 1) {
		servo[rightHook] = 0;
		servo[leftHook] = 0;
	}
	else if(joy1Btn(0) == 1) {
		servo[rightHook] = 127;
		servo[leftHook] = 127;
	}
}
