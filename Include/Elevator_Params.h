/*
 * Elevator_Params.h
 *
 * Created: 2026-04-18 6:02:08 AM
 *  Author: admin
 */ 


#ifndef ELEVATOR_PARAMS_H_
#define ELEVATOR_PARAMS_H_

//Building structure parameters:
//float cabOnBottom =	0;					//baseline reference when cab is resting on bottom, measured from floor surface
/*
float cabHomeInches = 0;				//offset from bottom to cab home height in inches
float basementLevelInches =	4;			//offset from home to basement level in inches
float garageLevelInches = 81.4375;		//offset from home to garage level in inches
float mainLevelInches = 120.3125;		//offset from home to main level in inches
float apartmentLevelInches = 230.375;	//offset from home to apartment level in inches
*/
enum DoorDirection { UP, DOWN };
enum DoorID { DOOR_X, DOOR_Y };
	
struct Floor {
	const char* name;
	double height;
	DoorID activeDoor;
	DoorDirection direction;
	bool requiresApproach; // True ONLY for Basement and Garage
};

// Extern tells the compiler the array is defined elsewhere (in the .cpp)
extern Floor floors[4];


//Design parameters in inches:
float cabXHeight = 84;
float cabYHeight = 84;
float doorXHeight = 90.125;
float doorYHeight = 90.125;
float doorCloseOffset = 4.25;

//Mechanical system parameters:

//Main hoist motor:	ClearPath P/N: CPM-SDHPN1433P-ELN
uint16_t cabCountsPerRev = 32000;			//encoder counts per revolution for M0
uint16_t cabGearRatio = 60;					//gear-down ratio of main hoist gearbox
float cabChainPitch = 0.75;					//main hoist chain pitch in inches
uint16_t cabDriveTeeth = 22;				//number of teeth on the hoist output drive sprockets
uint32_t cabCountsPerInch = (float)cabCountsPerRev * cabGearRatio / cabDriveTeeth / cabChainPitch;	//2909.0909
uint32_t cabVelocityLimit_PPS = 50000;		//Slightly more than 400 IPM for the cab motor, gearbox, and sprocket
uint32_t cabAcceleration_PPSS = 40000;	//Equivalent to 58 inches/sec^2 or 1.5 m/sec^2 for the door drive system

//Door drive motors:	ClearPath P/N: CPM-SDSK-3421S-RLN
uint16_t doorCountsPerRev = 800;			//encoder counts per revolution for M1, M2
uint16_t doorGearRatio = 10;				//gear-down ratio of door motor gearboxes
float doorChainPitch = 0.5;					//door drive chain pitch in inches
uint16_t doorDriveTeeth = 17;				//number of teeth on the door output drive sprockets
// uint32_t doorCountsPerInch = (float)doorCountsPerRev * doorGearRatio / doorDriveTeeth / doorChainPitch;	//941.176
uint32_t doorCountsPerInch = 116364;
uint32_t doorVelocityLimit_PPS = 500;		//Slightly more than 400 IPM for the door motor, gearbox, and sprocket
uint32_t doorAcceleration_PPSS = 1100;		//Equivalent to 58 inches/sec^2 or 1.5 m/sec^2 for the door drive system

//velocity Parameters in inches/minute
uint16_t  JOG_SPEED_SLOW_IPM = 25;
uint16_t  JOG_SPEED_FAST_IPM = 200;
uint16_t  RUN_SPEED_IPM = 400;

//Derived velocities in pulses/second
// uint16_t cabJogSlow_PPS = (float)JOG_SPEED_SLOW_IPM * cabCountsPerInch / 60;
const uint32_t cabJogSlow_PPS = 1000;
// uint16_t cabJogFast_PPS = (float)JOG_SPEED_FAST_IPM * cabCountsPerInch / 60;
const uint32_t cabJogFast_PPS = 5000;
// uint16_t cabRunSpeed_PPS = (float)RUN_SPEED_IPM * cabCountsPerInch / 60;
const uint32_t cabRunSpeed_PPS = 500;

// uint16_t doorJogSpeed_PPS = (float)JOG_SPEED_FAST_IPM * doorCountsPerInch / 60;
const uint16_t doorJogSpeed_PPS = 100;
// uint16_t doorRunSpeed_PPS = (float)RUN_SPEED_IPM * doorCountsPerInch / 60;
const uint16_t doorRunSpeed_PPS = 500;

//General program variables:
uint32_t flashTime = 0;



#endif /* ELEVATOR_PARAMS_H_ */