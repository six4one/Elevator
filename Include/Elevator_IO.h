/*
* Elevator_IO.h
*
* Created: 2026-04-14 6:50:36 AM
*  Author: admin
*/


#ifndef ELEVATOR_IO_H_
#define ELEVATOR_IO_H_
#include "ClearCore.h"

static DigitalIn &powerFailureDetected = ConnectorDI6;
static DigitalIn &smokeDetected = ConnectorDI7;
static DigitalIn &perimeterSeal = ConnectorDI8;
static DigitalIn &cabOvertravel = ConnectorA9;
static DigitalIn &cabHome = ConnectorA10;
static DigitalIn &doorXHome = ConnectorA11;
static DigitalIn &doorYHome = ConnectorA12;

static DigitalInOut &faultState = ConnectorIO1;
static DigitalInOut &liftEnable = ConnectorIO2;

//	CCIO-8 EXPANSION BOARD ALIASES (1 of 8) ---
static CcioPin *callB_PB = nullptr;		//Input one of the call buttons for Basement level is pressed
static CcioPin *callG_PB = nullptr;		//Input one of the call buttons for Garage level is pressed
static CcioPin *call1_PB = nullptr;		//Input one of the call buttons for Main level is pressed
static CcioPin *call2_PB = nullptr;		//Input one of the call buttons for Main level is pressed
static CcioPin *cabStop_PB = nullptr;	//Input the stop button on the cab console is pressed (provisional)
static CcioPin *jogMode = nullptr;		//Input: key switch in the cab control cabinet is in "Jog" position
//static CcioPin *??? = nullptr;		//Spare I/O
//static CcioPin *??? = nullptr;		//Spare I/O

//	CCIO-8 EXPANSION BOARD ALIASES (2 of 8) ---
static CcioPin *jogCabUp = nullptr;		//Input: one of the Cab UP jog buttons is pressed
static CcioPin *jogCabDown = nullptr;	//Input: one of the Cab Down jog buttons is pressed
static CcioPin *jogDoorXUp = nullptr;	//Input: one of the DoorX Up jog buttons is pressed
static CcioPin *jogDoorXDown = nullptr;	//Input: one of the DoorX Down jog buttons is pressed
static CcioPin *jogDoorYUp = nullptr;	//Input: one of the DoorY Up jog buttons is pressed
static CcioPin *jogDoorYDown = nullptr;	//Input: one of the DoorY Down jog buttons is pressed
static CcioPin *jog2Hand = nullptr;		//Input: one of the 2nd-hand buttons is pressed
//static CcioPin *??? = nullptr;		//Spare I/O

//	CCIO-8 EXPANSION BOARD ALIASES (3 of 8) ---
static CcioPin *cabBrake = nullptr;		//Input: Cab's mechanical safety brake system has been deployed
static CcioPin *runMode = nullptr;		//Input: key switch in main control cabinet is in "Run" position
static CcioPin *reset = nullptr;		//Input: key switch in main control cabinet is in "Reset" position
static CcioPin *cabOverLoad = nullptr;	//Input: chain tension monitor system reports an overload condition
static CcioPin *cabEmpty = nullptr;		//Input: chain tension monitor system reports that the cab is empty
static CcioPin *doorXClosed = nullptr;	//Input: door X is closed
static CcioPin *doorYClosed = nullptr;	//Input: door Y is closed
static CcioPin *cabOverspeed = nullptr;	//Input: cab speed governor is triggered by an over-speed condition

//	CCIO-8 EXPANSION BOARD ALIASES (4 of 8) ---
static CcioPin *doorXUpperBreach = nullptr;	//Input: Laser beam across Door X's upper edge has been breached
static CcioPin *doorXLowerBreach = nullptr;	//Input: Laser beam across Door X's lower edge has been breached
static CcioPin *doorYUpperBreach = nullptr;	//Input: Laser beam across Door Y's upper edge has been breached
static CcioPin *doorYLowerBreach = nullptr;	//Input: Laser beam across Door Y's lower edge has been breached
static CcioPin *cabXUpperBreach = nullptr;	//Input: Laser beam across the cab's upper threshold @ opening X has been breached
static CcioPin *cabXLowerBreach = nullptr;	//Input: Laser beam across the cab's lower threshold @ opening X has been breached
static CcioPin *cabYUpperBreach = nullptr;	//Input: Laser beam across the cab's upper threshold @ opening Y has been breached
static CcioPin *cabYLowerBreach = nullptr;	//Input: Laser beam across the cab's lower threshold @ opening Y has been breached

//	CCIO-8 EXPANSION BOARD ALIASES (5 of 8) ---
static CcioPin *cabAtB = nullptr;			//Input: The cab is at Basement level (B)
static CcioPin *cabAtG = nullptr;			//Input: The cab is at Garage level (G)
static CcioPin *cabAt1 = nullptr;			//Input: The cab is at Main level (1)
static CcioPin *cabAt2 = nullptr;			//Input: The cab is at Apartment level (2)
static CcioPin *extDoorsClosed = nullptr;	//Input: All 4 exterior access doors are closed
//static CcioPin *??? = nullptr;			//Spare I/O
//static CcioPin *??? = nullptr;			//Spare I/O
//static CcioPin *??? = nullptr;			//Spare I/O

//	CCIO-8 EXPANSION BOARD ALIASES (6 of 8) ---
static CcioPin *unlockDoorB = nullptr;		//Output: Unlock door B to permit entry to cab from outside.
static CcioPin *unlockDoorG = nullptr;		//Output: Unlock door G to permit entry to cab from outside.
static CcioPin *unlockDoor1 = nullptr;		//Output: Unlock door 1 to permit entry to cab from outside.
static CcioPin *unlockDoor2 = nullptr;		//Output: Unlock door 2 to permit entry to cab from outside.
static CcioPin *openDoorB = nullptr;		//Output: automatically open exterior door at basement level (provisional)
static CcioPin *openDoorG = nullptr;		//Output: automatically open exterior door at garage level (provisional)
static CcioPin *openDoor1 = nullptr;		//Output: automatically open exterior door at main level (provisional)
static CcioPin *openDoor2 = nullptr;		//Output: automatically open exterior door at apartment level



//	CCIO-8 EXPANSION BOARD ALIASES (7 of 8) ---
static CcioPin *callB_PL = nullptr;			//Output: illuminate 2 basement (B) level call buttons (in cab and @ ext door)
static CcioPin *callG_PL = nullptr;			//Output: illuminate 2 garage (G) level call buttons (in cab and @ ext door)
static CcioPin *call1_PL = nullptr;			//Output: illuminate 2 main (1) level call buttons (in cab and @ ext door)
static CcioPin *call2_PL = nullptr;			//Output: illuminate 2 apartment (2) level call buttons (in cab and @ ext door)
static CcioPin *stop_PL = nullptr;			//Output: illuminate the stop button on the cab console
static CcioPin *enableLaserX = nullptr;		//Output: enable the 2 laser emitters on door X
static CcioPin *enableLaserY = nullptr;		//Output: enable the 2 laser emitters on door Y
static CcioPin *XYEnable = nullptr;			//Output: enable the motor drives for both doors X and Y

//	CCIO-8 EXPANSION BOARD ALIASES (8 of 8) ---
static CcioPin *aviBit0 = nullptr;			//Output: bit 0 for the 4-bit parallel buss for cab audio and visual feedback modules
static CcioPin *aviBit1 = nullptr;			//Output: bit 1 for the 4-bit parallel buss for cab audio and visual feedback modules
static CcioPin *aviBit2 = nullptr;			//Output: bit 2 for the 4-bit parallel buss for cab audio and visual feedback modules
static CcioPin *aviBit3 = nullptr;			//Output: bit 3 for the 4-bit parallel buss for cab audio and visual feedback modules
static CcioPin *lubePump = nullptr;			//Output: enable the lubrication pump
static CcioPin *beeper = nullptr;			//Output: enable the audible beeper
static CcioPin *cabEnvironment = nullptr;	//Output: enable the cab lighting and ventilation
static CcioPin *cabSecure = nullptr;		//Output: report to the MQTT module that the cab is in a closed and secure state to monitor chain tension stability during motion

inline void InitializeElevatorIO() {
	
	//Inputs connected to ClearCore
	powerFailureDetected.Mode(Connector::INPUT_DIGITAL);
	smokeDetected.Mode(Connector::INPUT_DIGITAL);
	perimeterSeal.Mode(Connector::INPUT_DIGITAL);
	cabOvertravel.Mode(Connector::INPUT_DIGITAL);
	cabHome.Mode(Connector::INPUT_DIGITAL);
	doorXHome.Mode(Connector::INPUT_DIGITAL);
	doorYHome.Mode(Connector::INPUT_DIGITAL);
	
	//Outputs connected to ClearCore
	faultState.Mode(Connector::OUTPUT_DIGITAL);
	liftEnable.Mode(Connector::OUTPUT_DIGITAL);
	
	// 2. Assign the expansion pins AFTER discovery has occurred
	callB_PB = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOA0);
	callG_PB = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOA1);
	call1_PB = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOA2);
	call2_PB = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOA3);
	cabStop_PB = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOA4);
	jogMode = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOA5);
//	??? = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOA6);
//	??? = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOA7);
	
	jogCabUp = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOB0);
	jogCabDown = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOB1);
	jogDoorXUp = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOB2);
	jogDoorXDown = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOB3);
	jogDoorYUp = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOB4);
	jogDoorYDown = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOB5);
	jog2Hand = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOB6);
//	??? = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOB7);

	cabBrake = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOC0);
	runMode = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOC1);
	reset = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOC2);
	cabOverLoad = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOC3);
	cabEmpty = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOC4);
	doorXClosed = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOC5);
	doorYClosed = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOC6);
	cabOverspeed = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOC7);
	
	doorXUpperBreach = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOD0);
	doorXLowerBreach = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOD1);
	doorYUpperBreach = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOD2);
	doorYUpperBreach = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOD3);
	cabXUpperBreach = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOD4);
	cabXLowerBreach = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOD5);
	cabYUpperBreach = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOD6);
	cabYLowerBreach = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOD7);
	
	cabAtB = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOE0);
	cabAtG = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOE1);
	cabAt1 = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOE2);
	cabAt2 = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOE3);
	extDoorsClosed = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOE4);
//	??? = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOE5);
//	??? = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOE6);
//	??? = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOE7);	

	unlockDoorB = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOF0);
	unlockDoorG = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOF1);
	unlockDoor1 = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOF2);
	unlockDoor2 = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOF3);
	openDoorB = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOF4);
	openDoorG = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOF5);
	openDoor1 = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOF6);
	openDoor2 = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOF7);
	

	callB_PL = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOG0);
	callG_PL = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOG1);
	call1_PL = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOG2);
	call2_PL = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOG3);
	stop_PL = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOG4);
	enableLaserX = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOG5);
	enableLaserY = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOG6);
	XYEnable= CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOG7);	

	aviBit0 = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOH0);
	aviBit1 = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOH1);
	aviBit2 = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOH2);
	aviBit3 = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOH3);
	lubePump = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOH4);
	beeper = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOH5);
	cabEnvironment = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOH6);
	cabSecure = CcioMgr.PinByIndex(CLEARCORE_PIN_CCIOH7);
		
	//Inputs connected to CCIO-8
	if (callB_PB) callB_PB->Mode(Connector::INPUT_DIGITAL);
	if (callG_PB) callG_PB->Mode(Connector::INPUT_DIGITAL);
	if (call1_PB) call1_PB->Mode(Connector::INPUT_DIGITAL);
	if (call2_PB) call2_PB->Mode(Connector::INPUT_DIGITAL);
	if (cabStop_PB) cabStop_PB->Mode(Connector::INPUT_DIGITAL);
	if (jogMode) jogMode->Mode(Connector::INPUT_DIGITAL);
//	if (???) ???->Mode(Connector::INPUT_DIGITAL);
//	if (???) ???->Mode(Connector::INPUT_DIGITAL);
	
	if (jogCabUp) jogCabUp->Mode(Connector::INPUT_DIGITAL);
	if (jogCabDown) jogCabDown->Mode(Connector::INPUT_DIGITAL);
	if (jogDoorXUp) jogDoorXUp->Mode(Connector::INPUT_DIGITAL);
	if (jogDoorXDown) jogDoorXDown->Mode(Connector::INPUT_DIGITAL);
	if (jogDoorYUp) jogDoorYUp->Mode(Connector::INPUT_DIGITAL);
	if (jogDoorYDown) jogDoorYDown->Mode(Connector::INPUT_DIGITAL);
	if (jog2Hand) jog2Hand->Mode(Connector::INPUT_DIGITAL);
//	if (???) ???->Mode(Connector::INPUT_DIGITAL);
	
	if (cabBrake) cabBrake->Mode(Connector::INPUT_DIGITAL);
	if (runMode) runMode->Mode(Connector::INPUT_DIGITAL);
	if (reset) reset->Mode(Connector::INPUT_DIGITAL);
	if (cabOverLoad) cabOverLoad->Mode(Connector::INPUT_DIGITAL);
	if (cabEmpty) cabEmpty->Mode(Connector::INPUT_DIGITAL);
	if (doorXClosed) doorXClosed->Mode(Connector::INPUT_DIGITAL);
	if (doorYClosed) doorYClosed->Mode(Connector::INPUT_DIGITAL);
	if (cabOverspeed) cabOverspeed->Mode(Connector::INPUT_DIGITAL);
	
	if (doorXUpperBreach) doorXUpperBreach->Mode(Connector::INPUT_DIGITAL);
	if (doorXLowerBreach) doorXLowerBreach->Mode(Connector::INPUT_DIGITAL);
	if (doorYUpperBreach) doorYUpperBreach->Mode(Connector::INPUT_DIGITAL);
	if (doorYLowerBreach) doorYLowerBreach->Mode(Connector::INPUT_DIGITAL);
	if (cabXUpperBreach) cabXUpperBreach->Mode(Connector::INPUT_DIGITAL);
	if (cabXLowerBreach) cabXLowerBreach->Mode(Connector::INPUT_DIGITAL);
	if (cabYUpperBreach) cabYUpperBreach->Mode(Connector::INPUT_DIGITAL);
	if (cabYLowerBreach) cabYLowerBreach->Mode(Connector::INPUT_DIGITAL);
	
	if (extDoorsClosed) extDoorsClosed->Mode(Connector::INPUT_DIGITAL);
	if (cabAtB) cabAtB->Mode(Connector::INPUT_DIGITAL);
	if (cabAtG) cabAtG->Mode(Connector::INPUT_DIGITAL);
	if (cabAt1) cabAt1->Mode(Connector::INPUT_DIGITAL);
	if (cabAt2) cabAt2->Mode(Connector::INPUT_DIGITAL);
//	if (???) ???->Mode(Connector::INPUT_DIGITAL);
//	if (???) ???->Mode(Connector::INPUT_DIGITAL);
//	if (???) ???->Mode(Connector::INPUT_DIGITAL);

	//Outputs connected to CCIO-8
	if (unlockDoorB) unlockDoorB->Mode(Connector::OUTPUT_DIGITAL);
	if (unlockDoorG) unlockDoorG->Mode(Connector::OUTPUT_DIGITAL);
	if (unlockDoor1) unlockDoor1->Mode(Connector::OUTPUT_DIGITAL);
	if (unlockDoor2) unlockDoor2->Mode(Connector::OUTPUT_DIGITAL);
	if (openDoorB) openDoorB->Mode(Connector::OUTPUT_DIGITAL);
	if (openDoorG) openDoorG->Mode(Connector::OUTPUT_DIGITAL);
	if (openDoor1) openDoor1->Mode(Connector::OUTPUT_DIGITAL);
	if (openDoor2) openDoor2->Mode(Connector::OUTPUT_DIGITAL);
	
	if (callB_PL) callB_PL->Mode(Connector::OUTPUT_DIGITAL);
	if (callG_PL) callG_PL->Mode(Connector::OUTPUT_DIGITAL);
	if (call1_PL) call1_PL->Mode(Connector::OUTPUT_DIGITAL);
	if (call2_PL) call2_PL->Mode(Connector::OUTPUT_DIGITAL);
	if (stop_PL) stop_PL->Mode(Connector::OUTPUT_DIGITAL);
	if (enableLaserX) enableLaserX->Mode(Connector::OUTPUT_DIGITAL);
	if (enableLaserY) enableLaserY->Mode(Connector::OUTPUT_DIGITAL);
	if (XYEnable) XYEnable->Mode(Connector::OUTPUT_DIGITAL);
	
	if (aviBit0) aviBit0->Mode(Connector::OUTPUT_DIGITAL);
	if (aviBit1) aviBit1->Mode(Connector::OUTPUT_DIGITAL);
	if (aviBit2) aviBit2->Mode(Connector::OUTPUT_DIGITAL);
	if (aviBit3) aviBit3->Mode(Connector::OUTPUT_DIGITAL);
	if (lubePump) lubePump->Mode(Connector::OUTPUT_DIGITAL);
	if (beeper) beeper->Mode(Connector::OUTPUT_DIGITAL);
	if (cabEnvironment) cabEnvironment->Mode(Connector::OUTPUT_DIGITAL);
	if (cabSecure) cabSecure->Mode(Connector::OUTPUT_DIGITAL);
}

#endif /* ELEVATOR_IO_H_ */