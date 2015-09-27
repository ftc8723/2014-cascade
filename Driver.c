bool hatSwitchControl();
void joystickControl();

void drive() {
	if(!hatSwitchControl()) {
		joystickControl();
	}
}

bool hatSwitchControl() {
	int hatValue = joystick.joy1_TopHat;
	//writeDebugStreamLine("running hat program, value is %d", hatValue);
	if(hatValue == -1){
		return false;
	}
	else if(hatValue == 0) {
		//forward
		motor[rightMotor] = 100;
		motor[leftMotor] = 100;
	}
	else if(hatValue == 1) {
		//forward-right
		motor[rightMotor] = 10;
		motor[leftMotor] = 40;
	}
	else if(hatValue == 2) {
		//turn right
		motor[rightMotor] = -50;
		motor[leftMotor] = 50;
	}
	else if(hatValue == 3) {
		//back-right
		motor[rightMotor] = -10;
		motor[leftMotor] = -40;
	}
	else if(hatValue == 4) {
		//back
		motor[rightMotor] = -100;
		motor[leftMotor] = -100;
	}
	else if(hatValue == 5) {
		//back-left
		motor[rightMotor] = -40;
		motor[leftMotor] = -10;
	}
	else if(hatValue == 6) {
		//turn left
		motor[rightMotor] = 50;
		motor[leftMotor] = -50;
	}
	else if(hatValue == 7) {
		//forward-left
		motor[rightMotor] = 40;
		motor[leftMotor] = 10;
	}
	return true;
}
void joystickControl() {
	//Integer variable that allows you to specify a "deadzone" where values (both positive or negative)
	//less than the threshold will be ignored.
	int threshold = 10;
	//Driving Control
	if(abs(joystick.joy1_y2) > threshold)     // If the right analog stick's Y-axis readings are either above or below the threshold...
	{
		motor[rightMotor] = joystick.joy1_y2;				// ...move the right side of the robot.
	}
	else                                      // Else the readings are within the threshold, so...
	{
		motor[rightMotor] = 0;											// ...stop the right side of the robot.
	}
	if(abs(joystick.joy1_y1) > threshold)     // If the left analog stick's Y-axis readings are either above or below the threshold...
	{
		motor[leftMotor] = joystick.joy1_y1;				// ...move the left side of the robot.
	}
	else                                      // Else the readings are within the threshold, so...
	{
		motor[leftMotor] = 0;											// ...stop the left side of the robot.
	}
}
