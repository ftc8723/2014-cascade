void manipulators() {
		//Arm Motor Control
		if(joy1Btn(2) == 1)       // If button 5 (LB) is pressed...
		{
			motor[raiseMotor] = 35;     // ...raise the elevator.
		}
		else if(joy1Btn(3) == 1)  // Else, if button 7 (LT) is pressed...
		{
			motor[raiseMotor] = -35;    // ...lower the elevator.
		}
		else                      // Else (neither button is pressed)...
		{
			motor[raiseMotor] = 0;      // ...stop the elevator.
		}

		//Zipties Motor Control
		if(joy1Btn(5) == 1)       // If button 6 (RB)is pressed...
		{
			motor[motorA] = 50;     // ...vaccum in the plastic spheres.
		}
		else if(joy1Btn(7) == 1)  // Else, if button 8 (RT) is pressed...
		{
			motor[motorA] = -50;    // ...let out the balls.
		}
		else                      // Else (neither button is pressed)...
		{
			motor[motorA] = 0;      // ...stop the zipties.
		}

	 //Raise or lower the hooks for grabbing the rolling goals
	if(joy1Btn(5) == 1) {
		raiseHooks();
	}
	else if(joy1Btn(7) == 1) {
		lowerHooks();
	}
}
