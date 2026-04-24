/*
 * Elevator_Params.h
 *
 * Created: 2026-04-18 6:02:08 AM
 *  Author: admin
 */ 


#ifndef ELEVATOR_PARAMS_H_
#define ELEVATOR_PARAMS_H_

//Building structure parameters:
float cabOnBottom =	0;					//baseline reference when cab is resting on bottom, measured from floor surface
float cabHomeInches = 0.2;				//offset from bottom to cab home height in inches
float basementLevelInches =	4;			//offset from home to basement level in inches
float garageLevelInches = 81.4375;		//offset from home to garage level in inches
float mainLevelInches = 120.3125;		//offset from home to main level in inches
float apartmentLevelInches = 230.375;	//offset from home to apartment level in inches


//Mechanical system parameters:

//Main hoist system:
//motor:	ClearPath P/N: CPM-SDHPN1433P-ELN
uint16_t M0CountsPerRev = 6400;		//encoder counts per revolution for M0
uint16_t M0GearRatio = 60;			//gear-down ratio of main hoist gearbox
float M0ChainPitch = 0.75;		//main hoist chain pitch in inches
uint16_t M0DriveTeeth = 22;			//number of teeth on the hoist output drive sprockets
float M0CountsPerInch = (float)M0CountsPerRev * M0GearRatio / M0DriveTeeth / M0ChainPitch;

//Door drive system
//motor:	ClearPath P/N: CPM-SDSK-3421S-RLN
uint16_t M1CountsPerRev = 800;		//encoder counts per revolution for M1, M2
uint16_t M1GearRatio = 10;			//gear-down ratio of door motor gearboxes
float M1ChainPitch = 0.5;		//door drive chain pitch in inches
uint16_t M1DriveTeeth = 17;			//number of teeth on the door output drive sprockets
float M1CountsPerInch = (float)M1CountsPerRev * M1GearRatio / M1DriveTeeth / M1ChainPitch;

//General program variables:
uint32_t flashTime = 0;



#endif /* ELEVATOR_PARAMS_H_ */