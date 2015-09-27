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

	//Zipties Motor Control
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

	// Raise or lower the hooks for grabbing the rolling goals
	if(joy1Btn(1) == 1) {
		// raise
		servo[rightHook] = 37;
		servo[leftHook] = 90;
	} // lowers
	else if(joy1Btn(0) == 1) {
		servo[rightHook] = 90;
		servo[leftHook] = 37;
	}
}
