#pragma config(Sensor, S2,     HTIRS2,         sensorI2CCustom)
#include "hitechnic-irseeker-v2.h"

int irEnhVal(int sp0, int sp1, int sp2, int sp3, int sp4){
	int initialVal = 0;
	int realVal = 0;
	float ratio = -1;
	if(sp0>=sp1 && sp0>=sp2 && sp0>=sp3 && sp0>=sp4){
		initialVal = 0;
		ratio = sp1;
		ratio = 25*(ratio/(sp0+sp1));
		realVal = initialVal + ratio;
	}
	else if(sp1>=sp0 && sp1>=sp2 && sp1>=sp3 && sp1>=sp4){
		initialVal = 25;
		if(sp2>sp0){
			ratio = sp2;
			ratio = 25*(ratio/(sp1+sp2));
			realVal = initialVal + ratio;
		}
		else{
			ratio = sp0;
			ratio = 25*(ratio/(sp1+sp0));
			realVal = initialVal - ratio;
		}
	}
	else if(sp2>=sp0 && sp2>=sp1 && sp2>=sp3 && sp2>=sp4){
		initialVal = 50;
		if(sp3>sp1){
			ratio = sp3;
			ratio = 25*(ratio/(sp2+sp3));
			realVal = initialVal + ratio;
		}
		else{
			ratio = sp1;
			ratio = 25*(ratio/(sp2+sp1));
			realVal = initialVal - ratio;
		}
	}
	else if(sp3>=sp0 && sp3>=sp1 && sp3>=sp2 && sp3>=sp4){
		initialVal = 75;
		if(sp4>sp2){
			ratio = sp4;
			ratio = 25*(ratio/(sp3+sp4));
			realVal = initialVal + ratio;
		}
		else{
			ratio = sp2;
			ratio = 25*(ratio/(sp3+sp2));
			realVal = initialVal - ratio;
		}
	}
	else if(sp4>=sp0 && sp4>=sp1 && sp4>=sp2 && sp4>=sp3){
		initialVal = 100;
		ratio = sp3;
		ratio = 25*(ratio/(sp4+sp3));
		realVal = initialVal - ratio;
	}
	writeDebugStreamLine("%d", ratio);
	return realVal;
}
task main (){
	writeDebugStreamLine("irEnhVal(0,0,25,0,0) = %d", irEnhVal(0,0,25,0,0));
	writeDebugStreamLine("irEnhVal(0,15,25,0,0) = %d", irEnhVal(0,15,25,0,0));
	writeDebugStreamLine("irEnhVal(0,0,25,25,0) = %d", irEnhVal(0,0,25,25,0));
	writeDebugStreamLine("irEnhVal(50,34,0,0,0) = %d", irEnhVal(50,34,0,0,0));
	writeDebugStreamLine("irEnhVal(2,76,23,0,0) = %d", irEnhVal(2,76,23,0,0));
	writeDebugStreamLine("irEnhVal(0,3,50,42,0) = %d", irEnhVal(0,3,50,42,0));
	writeDebugStreamLine("irEnhVal(0,0,10,50,20) = %d", irEnhVal(0,0,10,50,20));

	// Create struct to hold sensor data
	tHTIRS2 irSeeker;

	// Initialise and configure struct and port
	initSensor(&irSeeker, S2);
	irSeeker.mode = DSP_1200;

	while(true){
		// Read the sensor data.
		readSensor(&irSeeker);
		displayTextLine(1, "D:%4d %4d 3%d", irSeeker.dcDirection, irSeeker.acDirection, irSeeker.enhDirection);
		displayTextLine(2, "0:%4d %4d", irSeeker.dcValues[0], irSeeker.acValues[0]);
		displayTextLine(3, "1:%4d %4d", irSeeker.dcValues[1], irSeeker.acValues[1]);
		displayTextLine(4, "2:%4d %4d %3d", irSeeker.dcValues[2], irSeeker.acValues[2], irSeeker.enhStrength);
		displayTextLine(5, "3:%4d %4d", irSeeker.dcValues[3], irSeeker.acValues[3]);
		displayTextLine(6, "4:%4d %4d", irSeeker.dcValues[4], irSeeker.acValues[4]);
		displayTextLine(7, "J:%4d", irEnhVal(irSeeker.acValues[0], irSeeker.acValues[1], irSeeker.acValues[2], irSeeker.acValues[3], irSeeker.acValues[4]));
	}
}
