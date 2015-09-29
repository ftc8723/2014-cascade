#include "hitechnic-sensormux.h"
#include "hitechnic-irseeker-v2.h"

const tMUXSensor IRL = msensor_S2_3;
const tMUXSensor IRR = msensor_S2_4;

void allstop() {
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
}

void waitForStartOrTouch()
{
	while (true)
	{
		if (SensorValue(touch) == 1) {
			break;
		}

		getJoystickSettings(joystick);
		if (!joystick.StopPgm) {
			break;
		}
	}
	return;
}

void waitUntil(unsigned long time) {
	while(nSysTime < time) {
		wait1Msec(100);
	}
}

void driveForward(int timeRunning){
	long startTime = nSysTime;
	long currentTime = startTime;
	while(currentTime < startTime+timeRunning){
		motor[leftMotor] = 50;
		motor[rightMotor] = 50;
		currentTime = nSysTime;
	}
}

void driveWithin(int distanceInCm){
	int sonarVal = SensorValue(sonar);
	while(sonarVal > distanceInCm){
		motor[leftMotor] = 50;
		motor[rightMotor] = 50;
		sonarVal = SensorValue(sonar);
		//writeDebugStreamLine("the sonar value is %d", sonarVal);
	}
}

void driveFull(int timeRunning){
	long startTime = nSysTime;
	long currentTime = startTime;
	while(currentTime < startTime+timeRunning){
		motor[leftMotor] = 100;
		motor[rightMotor] = 100;
		currentTime = nSysTime;
	}
}

//void irTurnBy(int turnBy){
//	int irVal = (HTIRS2readDCDir(IRL));
//	int initialIrVal = irVal;
//	while(irVal != initialIrVal+turnBy){
//		motor[rightMotor] = 50;
//		motor[leftMotor] = -50;
//		irVal = HTIRS2readDCDir(IRL);
//	}
//}

void turnLeftToIR(int toIR) {
	int irVal = (HTIRS2readDCDir(IRL));
	while(irVal != toIR){
		motor[leftMotor] = -50;
		motor[rightMotor] = 50;
		irVal = HTIRS2readDCDir(IRL);
	}
}

void turnRightToIR(int toIR) {
	int irVal = (HTIRS2readDCDir(IRL));
	while(irVal != toIR){
		motor[leftMotor] = 50;
		motor[rightMotor] = -50;
		irVal = HTIRS2readDCDir(IRL);
	}
}

void turnLeftFor(int timeInMs) {
	long startTime = nSysTime;
	long currentTime = startTime;
	while(currentTime < startTime+timeInMs){
		motor[leftMotor] = -50;
		motor[rightMotor] = 50;
		currentTime = nSysTime;
	}
}

void turnRightFor(int timeInMs) {
	long startTime = nSysTime;
	long currentTime = startTime;
	while(currentTime < startTime+timeInMs){
		motor[leftMotor] = 50;
		motor[rightMotor] = -50;
		currentTime = nSysTime;
	}
}

void raiseHooks(){
	// raise
	servo[rightHook] = 90;
	servo[leftHook] = 109;
	writeDebugStreamLine("raising hooks");
	wait1Msec(500);
}

void lowerHooks(){
	//lower
	servo[rightHook] = 30;
	servo[leftHook] = 176;
	writeDebugStreamLine("lowering hooks");
	wait1Msec(500);
}

void driveBack(int timeRunning){
	long startTime = nSysTime;
	long currentTime = startTime;
	while(currentTime < startTime+timeRunning){
		motor[leftMotor] = -50;
		motor[rightMotor] = -50;
		currentTime = nSysTime;
	}
}

void raiseHooksFar(){
	// raise
	servo[rightHook] = 207;
	servo[leftHook] = 2;
	writeDebugStreamLine("raising hooks");
	wait1Msec(500);
}

int initialPosition(){
	int maximumIRL = -1;
	int maximumIRR = -1;
	int initialPos = -1;
	for(int i=1; i<=50; i++){
		int currentIRL = HTIRS2readACDir(IRL);
		int currentIRR = HTIRS2readACDir(IRR);
	maximumIRL = (currentIRL > maximumIRL) ? currentIRL : maximumIRL;
	maximumIRR = (currentIRR > maximumIRR) ? currentIRR : maximumIRR;
	}
	if(maximumIRL == 5 && maximumIRR == 5){
		initialPos = 3;
	}
	else if(maximumIRL == 5 && maximumIRR == 6){
		initialPos = 2;
	}
	else if(maximumIRL == 6 && maximumIRR == 7){
		initialPos = 1;
	}
	writeDebugStreamLine("initial position is %d", initialPos);
	displayTextLine(0, "initial position is %d", initialPos);
	return initialPos;
}

// loop while we drive and run manipulatorss
int previousIRL, previousIRR, previousTouch, previousSonar = -1;
void showSensorValues() {
	eraseDisplay();

	int currentIRL = HTIRS2readACDir(IRL);
	int currentIRR = HTIRS2readACDir(IRR);
	if (currentIRL != previousIRL || currentIRR != previousIRR){
		displayTextLine(2, "IR is %d,%d", currentIRL, currentIRR);
		previousIRL = currentIRL;
		previousIRR = currentIRR;
	}

	int currentTouch = SensorValue(touch);
	if (currentTouch != previousTouch){
		displayTextLine(3, "Touch is %d", currentTouch);
		previousTouch = currentTouch;
	}

	int currentSonar = SensorValue(sonar);
	if (currentSonar != previousSonar){
		displayTextLine(4, "Sonar is %d", currentSonar);
		previousSonar = currentSonar;
	}
}
