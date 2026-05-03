/*
 * Elevator_Params.h
 *
 * Created: 2026-04-18 6:02:08 AM
 *  Author: admin
 */ 


#ifndef ELEVATOR_PARAMS_H_
#define ELEVATOR_PARAMS_H_

enum DoorDirection { UP, DOWN };
enum DoorID { DOOR_X, DOOR_Y };
	
struct Floor {
	const char* name;
	float height;
	DoorID activeDoor;
	DoorDirection direction;
	bool requiresApproach; // True ONLY for Basement and Garage
};

// Extern tells the compiler the array is defined elsewhere (in the .cpp)
extern Floor floors[4];

//Building structure parameters used in struct Floor
const float apartmentLevel_I = 230.375;	//offset from home to apartment level in inches
const float mainLevel_I = 120.3125;		//offset from home to main level in inches
const float garageLevel_I = 81.4375;		//offset from home to garage level in inches
const float basementLevel_I =	4;			//offset from home to basement level in inches
const float cabHome_I = 0;				//offset from bottom to cab home height in inches

//Design parameters in inches:
const float cabXHeight_I = 84;		//cab interior floor-to-ceiling distance on X-side
const float cabYHeight_I = 84;		//cab interior floor-to-ceiling distance on Y-side
const float doorXHeight_I = 90.125;	//height of the X-side door
const float doorYHeight_I = 90.125;	//height of the Y-side door
const float doorCloseOffset_I = -4.25;	//distance bottom edge of door (X or Y) must be offset from the cab floor to close the interlock circuitry
const float doorApproachOffset_I = 0.25;	//distance from the door (X @ basement, or Y @ garage) home position where the cab and doors synchronize as the relevant door goes in or out of the parked position

//Mechanical system parameters:

//velocity Parameters in inches/minute
const float deratingFactor = 0.1;				//1 = 100%		Factor to throttle the elevator's performance during debugging
const uint16_t  RUN_SPEED_IPM = 420;			//100%			designed top operating speed
const uint16_t  JOG_SPEED_SLOW_IPM = (float)RUN_SPEED_IPM*0.2;		//20%
const uint16_t  JOG_SPEED_FAST_IPM = (float)RUN_SPEED_IPM*0.5;		//50%

//acceleration parameter in inches/second^2
const float acceleration_IPSS = 58;	//design acceleration in inches/second^2 where any greater value might affect passenger comfort.

//Main hoist motor:	ClearPath P/N: CPM-SDHPN1433P-ELN
const uint16_t cabCountsPerRev = 32000;			//encoder counts per revolution for M0
const uint16_t cabGearRatio = 60;					//gear-down ratio of main hoist gearbox
const float cabChainPitch = 0.75;					//main hoist chain pitch in inches
const uint16_t cabDriveTeeth = 22;				//number of teeth on the hoist output drive sprockets
const float32_t cabCountsPerInch = (float)cabCountsPerRev * cabGearRatio / cabChainPitch / cabDriveTeeth;	//116,363.3636

const uint32_t cabAt2_C = apartmentLevel_I * cabCountsPerInch;	//# of counts for M0 from cab home to apartment level
const uint32_t cabAt1_C = mainLevel_I * cabCountsPerInch;		//# of counts for M0 from cab home to main level
const uint32_t cabAtG_C = garageLevel_I * cabCountsPerInch;		//# of counts for M0 from cab home to garage level
const uint32_t cabAtB_C = basementLevel_I * cabCountsPerInch;	//# of counts for M0 from cab home to basement level

const uint32_t cabVelocityLimit_PPS = (float)RUN_SPEED_IPM * cabCountsPerInch * 1.02 / 60;	//conversion to counts/second plus 2%
//const uint32_t cabAcceleration_PPSS = 6400000;	//Equivalent to 58 inches/sec^2 or 1.5 m/sec^2 for the door drive system
const uint32_t cabAcceleration_PPSS = (float)acceleration_IPSS * cabCountsPerInch;


//Door drive motors:	ClearPath P/N: CPM-SDSK-3421S-RLN
const uint16_t doorCountsPerRev = 800;			//encoder counts per revolution for M1, M2
const uint16_t doorGearRatio = 10;				//gear-down ratio of door motor gearboxes
const float doorChainPitch = 0.5;					//door drive chain pitch in inches
const uint16_t doorDriveTeeth = 17;				//number of teeth on the door output drive sprockets
const float32_t doorCountsPerInch = (float)doorCountsPerRev * doorGearRatio / doorChainPitch/ doorDriveTeeth ;	//941.1765

// #todo Need to understand how the HSM is going to handle door open/close logic befor treating these properly
const uint32_t doorAt2_C = apartmentLevel_I * doorCountsPerInch;
const uint32_t doorAt1_C = apartmentLevel_I * doorCountsPerInch;
const uint32_t doorAtG_C = apartmentLevel_I * doorCountsPerInch;
const uint32_t doorAtB_C = apartmentLevel_I * doorCountsPerInch;

const uint32_t doorVelocityLimit_PPS = 500;		//Slightly more than 400 IPM for the door motor, gearbox, and sprocket
const uint32_t doorAcceleration_PPSS = 1100;		//Equivalent to 58 inches/sec^2 or 1.5 m/sec^2 for the door drive system





//Derived velocities in pulses/second
const uint32_t cabJogSlow_PPS = (float)JOG_SPEED_SLOW_IPM * cabCountsPerInch / 60;
//const uint32_t cabJogSlow_PPS = 5000;		//24000;
// uint16_t cabJogFast_PPS = (float)JOG_SPEED_FAST_IPM * cabCountsPerInch / 60;
const uint32_t cabJogFast_PPS = 25000;		//120000;
// uint16_t cabRunSpeed_PPS = (float)RUN_SPEED_IPM * cabCountsPerInch / 60;
const uint32_t cabRunSpeed_PPS = 50000;		//240000;

// uint16_t doorJogSpeed_PPS = (float)JOG_SPEED_FAST_IPM * doorCountsPerInch / 60;
const uint16_t doorJogSpeed_PPS = 100;
// uint16_t doorRunSpeed_PPS = (float)RUN_SPEED_IPM * doorCountsPerInch / 60;
const uint16_t doorRunSpeed_PPS = 500;

//General program variables:
uint32_t flashTime = 0;



#endif /* ELEVATOR_PARAMS_H_ */