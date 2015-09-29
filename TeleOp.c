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

#include "JoystickDriver.c"
#include "Utilities.c"
#include "Driver.c"
#include "Manipulators.c"

task main()
{
//	waitForStart();
	allstop();

	// loop while we drive and run manipulatorss
	int previousIR = -1;
	int previousLight = -1;
	int previousSonar = -1;

	while(true)
	{
		//Get the Latest joystick values
		getJoystickSettings(joystick);
		//use the joystick settings to drive the wheels
		drive();
		//use the joystick settings to run the manipulators
		manipulators();

		int currentIR = SensorValue(IRSeeker);
		if (currentIR != previousIR){
			displayTextLine(2, "IR is %d", currentIR);
			previousIR = currentIR;
		}
		int currentLight = SensorValue(light);
		if (currentLight != previousLight){
			displayTextLine(3, "Light is %d", currentLight);
			previousLight = currentLight;
		}
		int currentSonar = SensorValue(sonar);
		if (currentSonar != previousSonar){
			displayTextLine(4, "Sonar is %d", currentSonar);
			previousSonar = currentSonar;
		}

	}
}
