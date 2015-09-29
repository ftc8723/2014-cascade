#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     HTSMUX,         sensorI2CCustom)
#pragma config(Sensor, S3,     touch,          sensorTouch)
#pragma config(Sensor, S4,     sonar,          sensorNone)
#pragma config(Motor,  motorA,          ziptiesMotor,  tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     rightMotor,    tmotorTetrix, openLoop, driveRight)
#pragma config(Motor,  mtr_S1_C1_2,     leftMotor,     tmotorTetrix, openLoop, reversed, driveLeft)
#pragma config(Motor,  mtr_S1_C3_1,     raiseMotor,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    rightHook,            tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    leftHook,             tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)

#pragma debuggerWindows("debugStream");
#pragma debuggerWindows("joystickGame");
#pragma debuggerWindows("nxtLCDScreen");

#include "JoystickDriver.c"
#include "Utilities.c"

//void autonomousFloor()
//{
//	writeDebugStreamLine("start autonomousFloor");
//	displayTextLine(0, "running autonomous floor");

//	int IRV = SensorValue(IRSeeker);
//	writeDebugStreamLine("starting IR = %d", IRV);
//	displayBigTextLine(3, "LN32:%d", SensorValue(IRSeeker));
//	raiseHooksFar();

//	if(IRV == 5){ // approach middle structure, jog right, knock over pole //5
//		//ir facing
//		writeDebugStreamLine("Position 1");
//		driveForward(1000);
//		turnRightFor(750);
//		driveForward(600);
//		turnLeftFor(750);
//		driveFull(2000);
//	}
//	else if(IRV == 6){ // approach structure, angle right, knock over pole //5
//		//facing ramp
//		writeDebugStreamLine("Position 2");

//		driveForward(1100);
//		turnRightToIR(7);
//		driveFull(1000);
//	}
//	else{ //ram pole from side
//		//pole facing
//		writeDebugStreamLine("Position 3");
//		driveWithin(13);
//		turnRightFor(532);
//		driveFull(500);
//		wait1Msec(500);
//	}
//}

task main {
	//waitForStart();
	initialPosition();
	//autonomousFloor();
}
