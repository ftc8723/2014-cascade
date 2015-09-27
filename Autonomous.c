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
#pragma debuggerWindows("joystickSimple");
#include "Utilities.c"

void autonomousFloor()
{
	writeDebugStreamLine("start autonomousFloor");
	displayTextLine(0, "running autonomous floor");

	//takes a start time for the ir mission
	long irTime = nSysTime;
	int IRV = SensorValue(IRSeeker);
	writeDebugStreamLine("starting IR = %d", IRV);

	if(SensorValue(IRSeeker) == 5){ // approach middle structure, jog right, knock over pole
		//ir facing
		driveForward(1000);
		turnRightFor(1000);
		driveForward(1400);
		turnLeftFor(1000);
		driveForward(2000);
	}
	else if(SensorValue(IRSeeker) == 6){ // approach structure, angle right, knock over pole
		//facing ramp
		turnRightToIR(2);
		driveForward(2000);
	}
	else if(SensorValue(IRSeeker) == 7){ //ram pole
		//pole facing
		driveFull(1000);
	}

	//find the time taken for the ir in sec
	long irEndTime = nSysTime;
	long irTaken = (irEndTime - irTime) / 1000;
	writeDebugStreamLine("the IR time taken is %d", irTaken);
}

void autonomousRamp()
{
	int lightvalue = SensorValue(light);
	int lastvalue = 0;
	int lightchanges = 0;

	//takes the time when ramp started
	long rampStartTime = nSysTime;
	writeDebugStreamLine("the time is %d", rampStartTime);

	//go to the bottom of ramp
	while(lightchanges < 4) //runs loop until the light sensor output changes 4 times
	{
		motor[rightMotor] = 50;
		motor[leftMotor] = 50;
		if (lightvalue != lastvalue){//does the following if the light reading has changed
			writeDebugStreamLine("light is %f", lightvalue);
			lastvalue = lightvalue;
			lightchanges++;
		}
		lightvalue = SensorValue(light);//changes lightvalue to the current reading
	}

	//computes the time taken to get off the ramp(in sec)
	long rampEndTime = nSysTime;
	long rampTaken = (rampEndTime - rampStartTime) / 1000;
	writeDebugStreamLine("the ramp time taken is %d", rampTaken);

	driveWithin(20);
	//drives to 20 cm away from the closest object

	//lower hooks
	lowerHooks();
}

task main {
	//autonomousFloor();
	autonomousRamp();
}
