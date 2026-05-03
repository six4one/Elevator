/*
 * Elevator_Params.h
 *
 * Created: 2026-04-18 6:02:08 AM
 *  Author: admin
 */ 


#ifndef ELEVATOR_PARAMS_H_
#define ELEVATOR_PARAMS_H_
#include "ClearCore.h"

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
const float deratingFactor = 1;				//1 = 100%		Factor to throttle the elevator's performance during debugging
const uint32_t  RUN_SPEED_IPM = 420;			//100%			designed top operating speed
const uint32_t  JOG_SPEED_SLOW_IPM = (float)RUN_SPEED_IPM*0.1;		//20%
const uint32_t  JOG_SPEED_FAST_IPM = (float)RUN_SPEED_IPM*0.5;		//50%

//acceleration parameter in inches/second^2
const float acceleration_IPSS = 6;	//design acceleration in inches/second^2 where any greater value might affect passenger comfort.

//Main hoist motor:	ClearPath P/N: CPM-SDHPN1433P-ELN
const uint32_t cabCountsPerRev = 1000;			//encoder counts per revolution for M0
const uint32_t cabGearRatio = 60;					//gear-down ratio of main hoist gearbox
const float cabChainPitch = 0.75;					//main hoist chain pitch in inches
const uint32_t cabDriveTeeth = 22;				//number of teeth on the hoist output drive sprockets
const float cabCountsPerInch = (float)cabCountsPerRev * cabGearRatio / cabChainPitch / cabDriveTeeth;	//29090.9090

//Derived cab velocities in pulses/second
const uint32_t cabVelocityLimit_PPS = (float)RUN_SPEED_IPM * cabCountsPerInch * 1.02 / 60 * deratingFactor;	//conversion to counts/second plus 2%
const uint32_t cabJogSlow_PPS = (float)JOG_SPEED_SLOW_IPM * cabCountsPerInch / 60 * deratingFactor;
const uint32_t cabJogFast_PPS = (float)JOG_SPEED_FAST_IPM * cabCountsPerInch / 60 * deratingFactor;
const uint32_t cabRunSpeed_PPS = (float)RUN_SPEED_IPM * cabCountsPerInch / 60 * deratingFactor;

//Derived door accelerations in pulses/second^2
const uint32_t cabAccelerationLimit_PPSS = (float)acceleration_IPSS * cabCountsPerInch * 1.02;
const uint32_t cabAcceleration_PPSS = (float)acceleration_IPSS * cabCountsPerInch;

//Door drive motors:	ClearPath P/N: CPM-SDSK-3421S-RLN
const uint32_t doorCountsPerRev = 1000;			//encoder counts per revolution for M1, M2
const uint32_t doorGearRatio = 10;				//gear-down ratio of door motor gearboxes
const float doorChainPitch = 0.5;					//door drive chain pitch in inches
const uint32_t doorDriveTeeth = 17;				//number of teeth on the door output drive sprockets
const float doorCountsPerInch = (float)doorCountsPerRev * doorGearRatio / doorChainPitch/ doorDriveTeeth ;	//941.1765

//Derived cab velocities in pulses/second
const uint32_t doorVelocityLimit_PPS = (float)RUN_SPEED_IPM * doorCountsPerInch * 1.02 / 60 * deratingFactor;
const uint32_t doorJogSpeed_PPS = (float)JOG_SPEED_FAST_IPM * doorCountsPerInch / 60 *deratingFactor;
const uint32_t doorRunSpeed_PPS = (float)RUN_SPEED_IPM * doorCountsPerInch / 60 * deratingFactor;

//Derived door accelerations in pulses/second^2
const uint32_t doorAccelerationLimit_PPSS = (float)acceleration_IPSS * doorCountsPerInch * 1.02;
const uint32_t doorAcceleration_PPSS = (float)acceleration_IPSS * doorCountsPerInch;

const uint32_t cabAt2_C = (float)apartmentLevel_I * cabCountsPerInch;	//# of counts for M0 from cab home to apartment level
const uint32_t cabAt1_C = (float)mainLevel_I * cabCountsPerInch;		//# of counts for M0 from cab home to main level
const uint32_t cabAtG_C = (float)garageLevel_I * cabCountsPerInch;		//# of counts for M0 from cab home to garage level
const uint32_t cabAtB_C = (float)basementLevel_I * cabCountsPerInch;	//# of counts for M0 from cab home to basement level

//General program variables:
uint32_t flashTime = 0;



#endif /* ELEVATOR_PARAMS_H_ */