#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  none)
#pragma config(Sensor, S2,     IRSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
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
#pragma debuggerWindows("joystickSimple");
#include "Utilities.c"
#include "JoystickDriver.c"

void autonomousFloor()
{
	writeDebugStreamLine("start autonomousFloor");
	displayTextLine(0, "running autonomous floor");

	//takes a start time for the ir mission
	long irTime = nSysTime;
	int IRV = SensorValue(IRSeeker);
	writeDebugStreamLine("starting IR = %d", IRV);
	displayBigTextLine(3, "LN32:%d", SensorValue(IRSeeker));
	raiseHooksFar();

	// Jared: consider driving forward a little first to see if this differentiates IR values

	if(IRV == 5){ // approach middle structure, jog right, knock over pole //5
		//ir facing
		writeDebugStreamLine("Position 1");
		driveForward(1000);
		turnRightFor(750);
		driveForward(900);
		turnLeftFor(750);
		driveFull(2000);
	}
	else if(IRV == 6){ // approach structure, angle right, knock over pole //5
		//facing ramp
		writeDebugStreamLine("Position 2");

		driveForward(1100);
		turnRightToIR(7);
		driveFull(1000);
	}
	else if(IRV == 7){ //ram pole from side
		//pole facing
		writeDebugStreamLine("Position 3");
		driveWithin(13);
		turnRightFor(532);
		writeDebugStreamLine("turning");
		wait1Msec(500);
	}

	//find the time taken for the ir in sec
	//Jared: what does this do - is this needed?
	long irEndTime = nSysTime;
	long irTaken = (irEndTime - irTime) / 1000;
	writeDebugStreamLine("the IR time taken is %d", irTaken);
}

void autonomousRamp()
{
	raiseHooks();
	lowerHooks();
	raiseHooks();

	//int lightvalue = SensorValue(light);
	int lastvalue = 0;
	int lightchanges = 0;

	//takes the time when ramp started
	long rampStartTime = nSysTime;
	writeDebugStreamLine("the time is %d", rampStartTime);

	//go to the bottom of ramp
	//while(lightchanges < 1) //runs loop until the light sensor output changes 4 times
	//{
	//	motor[rightMotor] = 50;
	//	motor[leftMotor] = 50;
	//	if (lightvalue != lastvalue){//does the following if the light reading has changed
	//		writeDebugStreamLine("light is %f", lightvalue);
	//		lastvalue = lightvalue;
	//		lightchanges++;
	//	}
	//	lightvalue = SensorValue(light);//changes lightvalue to the current reading
	//}

	//computes the time taken to get off the ramp(in sec)
	long rampEndTime = nSysTime;
	long rampTaken = (rampEndTime - rampStartTime) / 1000;
	writeDebugStreamLine("the ramp time taken is %d", rampTaken);

	wait1Msec(1000);
	driveForward(2575);
	allstop();
	wait1Msec(500);
	int rampIR = SensorValue(IRSeeker);
	driveWithin(21);

	//lowers hooks
	lowerHooks();
	if(rampIR == 1){
		writeDebugStreamLine("rampIR = 1");
		turnLeftToIR(7);
		turnLeftFor(100);
	}
	else if(rampIR == 2){
		writeDebugStreamLine("rampIR = 2");
		turnLeftToIR(7);
	}
	else {
		writeDebugStreamLine("rampIR = 3");
		turnLeftToIR(7);
		turnLeftFor(100);
	}
	driveForward(4500);
	raiseHooks();
	driveBack(2575);
}

task main {
	waitForStart();
	//autonomousFloor();
	autonomousRamp();
}
