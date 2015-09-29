void allstop() {
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
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
//	int irVal = (SensorValue(IRSeeker));
//	int initialIrVal = irVal;
//	while(irVal != initialIrVal+turnBy){
//		motor[rightMotor] = 50;
//		motor[leftMotor] = -50;
//		irVal = SensorValue(IRSeeker);
//	}
//}

void turnLeftToIR(int toIR) {
	int irVal = (SensorValue(IRSeeker));
	while(irVal != toIR){
		motor[leftMotor] = -50;
		motor[rightMotor] = 50;
		irVal = SensorValue(IRSeeker);
	}
}

void turnRightToIR(int toIR) {
	int irVal = (SensorValue(IRSeeker));
	while(irVal != toIR){
		motor[leftMotor] = 50;
		motor[rightMotor] = -50;
		irVal = SensorValue(IRSeeker);
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
