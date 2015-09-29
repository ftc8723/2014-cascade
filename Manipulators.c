void manipulators() {
	bool buttonPressed = false;
	//Elevator Control
	if(joy1Btn(2) == 1)       // If button 1 (A) is pressed...
	{
		buttonPressed = true;
		motor[raiseMotor] = -100;     // ...lower the elevator.
		writeDebugStreamLine("Lowering elevator");
		displayTextLine(0, "lowering elevator");
	}
	else if(joy1Btn(4) == 1)  // Else, if button 3 (Y) is pressed...
	{
		motor[raiseMotor] = 100;    // ...raise the elevator.
		buttonPressed = true;
		writeDebugStreamLine("Raising elevator");
		displayTextLine(0, "raising elevator");

	}
	else                      // Else (neither button is pressed)...
	{
		motor[raiseMotor] = 0;      // ...stop the elevator.
	}

	//Zipties Motor Control
	if(joy1Btn(5) == 1)       // If button 5 (LB)is pressed...
	{
		motor[motorA] = 100;     // ...vaccum in the plastic spheres.
		buttonPressed = true;
		displayTextLine(0, "Get balls");
		writeDebugStreamLine("getting balls");
	}
	else if(joy1Btn(7) == 1)  // Else, if button 7 (LT) is pressed...
	{
		motor[motorA] = -100;    // ...let out the balls.
		buttonPressed = true;
		displayTextLine(0, "put balls");
		writeDebugStreamLine("putting balls");
	}
	else                      // Else (neither button is pressed)...
	{
		motor[motorA] = 0;      // ...stop the zipties.
	}

	//Raise or lower the hooks for grabbing the rolling goals
	if(joy1Btn(6) == 1) { //button: rb
		raiseHooks();
		buttonPressed = true;
		displayTextLine(0, "raising hooks");
		writeDebugStreamLine("raising hooks");
	}
	else if(joy1Btn(8) == 1) { //button: rt
		lowerHooks();
		buttonPressed = true;
		displayTextLine(0, "lowering hooks");
		writeDebugStreamLine("lowering hooks");
	}
	if (buttonPressed == false){
		displayTextLine(0, "NO button pressed");
	}
}
