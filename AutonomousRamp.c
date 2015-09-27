#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S2,     IRSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  motorA,          gripperMotor,  tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     rightMotor,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftMotor,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     armMotor,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop, encoder)

#pragma debuggerWindows("debugStream");

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

void irTurnBy(int turnBy){
	int irVal = (SensorValue(IRSeeker));
	int initialIrVal = irVal;
	while(irVal != initialIrVal+turnBy){
		motor[rightMotor] = 50;
		motor[leftMotor] = -50;
		irVal = SensorValue(IRSeeker);
	}
}

void irTurnTo(char turnDir, int turnTo){
	int irVal = (SensorValue(IRSeeker));
	if(turnDir == 'l'){
		while(irVal != turnTo){
			motor[rightMotor] = 50;
			motor[leftMotor] = -50;
			irVal = SensorValue(IRSeeker);
		}
	}
	else if(turnDir == 'r'){
		while(irVal != turnTo){
			motor[rightMotor] = -50;
			motor[leftMotor] = 50;
			irVal = SensorValue(IRSeeker);
		}
	}
}

void turnFor(char direction, int timeInMs){
	long startTime = nSysTime;
	long currentTime = startTime;
	if(direction == 'r'){
		while(currentTime < startTime+timeInMs){
			motor[leftMotor] = 50;
			motor[rightMotor] = -50;
			currentTime = nSysTime;
		}
	}
	else if(direction == 'l'){
		while(currentTime < startTime+timeInMs){
			motor[leftMotor] = -50;
			motor[rightMotor] = 50;
			currentTime = nSysTime;
		}
	}
}

void autonomous()
{
	int lightvalue = SensorValue(light);
	int lastvalue = 0;
	int lightchanges = 0;
	int ramp = SensorValue(IRSeeker);

	//takes the time when ramp started
	long rampStartTime = nSysTime;
	writeDebugStreamLine("the time is %d", rampStartTime);

	if((ramp == 0) || (ramp == 3)){
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
	}
	//computes the time taken to get off the ramp(in sec)
	long rampEndTime = nSysTime;
	long rampTaken = (rampEndTime - rampStartTime) / 1000;
	writeDebugStreamLine("the ramp time taken is %d", rampTaken);

	//takes a start time for the ir mission
	long irTime = nSysTime;
	writeDebugStreamLine("the start time for IR is %d", irTime);

	int IRV = SensorValue(IRSeeker);
	writeDebugStreamLine("the ir is %d", IRV);

	if(SensorValue(IRSeeker) == 5){
		irTurnTo('r', 4);
		driveForward(7000);
		turnFor('l', 2000);
	}
	else{
		turnFor('l', 1000);
		irTurnTo('l', 5);
		driveForward(2000);
		irTurnTo('l', 6);
		driveForward(3000);
	}

	//find the time taken for the ir in sec
	long irEndTime = nSysTime;
	long irTaken = (irEndTime - irTime) / 1000;
	writeDebugStreamLine("the IR time taken is %d", irTaken);
}
