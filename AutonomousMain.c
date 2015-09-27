void autonomousFloor()
{
	writeDebugStreamLine("start autonomousFloor");
	nxtDisplayTextLine(0, "running autonomous floor");

	//takes a start time for the ir mission
	long irTime = nSysTime;
	int IRV = SensorValue(IRSeeker);
	writeDebugStreamLine("starting IR = %d", IRV);

	if(SensorValue(IRSeeker) == 5){
		//red facing
		//now ir facing
		driveForward(1000);
		turnRightFor(1000);
		driveForward(1400);
		turnLeftFor(1000);
		driveForward(2000);
	}
	else if(SensorValue(IRSeeker) == 6){
		//in the middle
		//now facing ramp
		turnRightToIR(2);
		driveForward(2000);
	}
	else if(SensorValue(IRSeeker) == 7){
		//blue facing
	//now pole facing
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
	servo[leftHook] = 37;
	servo[rightHook] = 90;
}

task main {
	autonomousFloor();
	autonomousRamp();
}
