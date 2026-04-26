//I just added this to test GIT
//added @ 1:49 2026-04/24 to test GIT

#include "ClearCore.h"
#include "Include\Elevator_Params.h"
#include "Include\Elevator_IO.h"


#define CcioPort ConnectorCOM0

#define baudRate 9600
#define SerialPort ConnectorUsb

#define cabMotor ConnectorM0
#define doorXMotor ConnectorM1
#define doorYMotor ConnectorM2

Floor floors[] = {
	{"Basement",  4.0,       DOOR_X, UP,   true},
	{"Garage",    81.4375,   DOOR_Y, UP,   true},
	{"Main",      120.3125,  DOOR_X, DOWN, false},
	{"Apartment", 230.375,   DOOR_Y, DOWN, false}
};

/*
 * Reference https://teknic-inc.github.io/ClearCore-library/_microchip_install.html
 * for more information about how this ProjectTemplate should be used.
 */



//	Functions are declared here
bool serialSetup();
bool CCIO_Setup();
bool MotorSetup();
bool StopAllMotors();
void HandleJogMode();
void HandleMotion(Floor* target);

int main(void) {
	
	//	Here is where the ClearCore hardware is initialized
	
	if(serialSetup()){		//initialize the serial communication over USB for debugging
		SerialPort.SendLine("Serial communication over USB enabled");
	}
	else{
		SerialPort.SendLine("Serial communication over USB setup failed");
	}
	
	if(CCIO_Setup()){			//initialize the CCIO-8 communication bus
		SerialPort.SendLine("CCIO-8 expansion modules communication bus is on-line");
	}
	else{
		SerialPort.SendLine("CCIO-8 expansion modules communication bus failed to start properly");
	}
	
	if(MotorSetup()){
		SerialPort.SendLine("Motors have been defined and setup");
	}
	else{
		SerialPort.SendLine("There was a problem setting up the motors");
	}
	
    bool ledState = true;
	flashTime = Milliseconds();
	

//	Main loop	
    while (1)
    {
		//HandleJogMode();
		
//		input_pin->State();				How to read hardware inputs
//		output_pin->State(<logic>);		How to write to hardware outputs
//		ConnectorLed.State(<logic>);	How to write to the onboard LED

/*		How to write variables to serial port
char buffer[128];
snprintf(buffer, sizeof(buffer),"M0: %.3f   M1: %.3f", M0CountsPerInch, M1CountsPerInch );
SerialPort.SendLine(buffer);
*/
		
		if(Milliseconds() > flashTime + 1000){
			
			
			flashTime = Milliseconds();
			faultState.State(ledState);
			liftEnable.State(!ledState);
			ConnectorLed.State(ledState);
			ledState = !ledState;
			
			char buffer[128];
			snprintf(buffer, sizeof(buffer),"As float: %lu   As Int: %lu", cabCountsPerInch, cabCountsPerInch );
			SerialPort.SendLine(buffer);
		}
    }
}

// Setup functions

bool serialSetup(){
	// Set up serial communication and wait up to 5 seconds for a port to open
	// Serial communication is not required for this example to run.
	ConnectorLed.State(true);
	SerialPort.Mode(Connector::USB_CDC);
	SerialPort.Speed(baudRate);
	uint32_t timeout = 5000;
	uint32_t startTime = Milliseconds();
	SerialPort.PortOpen();
	while (!SerialPort && Milliseconds() - startTime < timeout) {
		continue;
	}
	ConnectorLed.State(false);
	return(SerialPort);
}

bool CCIO_Setup(){
	ConnectorLed.State(true);
	CcioPort.Mode(Connector::CCIO);
	CcioPort.PortOpen();
	
	// IMPORTANT: Wait for discovery to complete
	uint8_t boardsFound = 0;
	for (int i = 0; i < 50 && boardsFound == 0; i++) {
		boardsFound = CcioMgr.CcioCount();
		Delay_ms(10);
	}

	if (boardsFound == 8) {		//change to 8
		InitializeElevatorIO();
		return(true);
		ConnectorLed.State(false);
	}
	return(false);
}

bool MotorSetup(){
    // Sets the input clocking rate. This normal rate is ideal for ClearPath
    // step and direction applications.
    MotorMgr.MotorInputClocking(MotorManager::CLOCK_RATE_NORMAL);
    
    // Sets all motor connectors into step and direction mode.
    MotorMgr.MotorModeSet(MotorManager::MOTOR_ALL,
    Connector::CPM_MODE_STEP_AND_DIR);
    
    // Put the motor connectors into the HLFB mode to read bipolar PWM (the
    // correct mode for ASG w/ Measured Torque)
    cabMotor.HlfbMode(MotorDriver::HLFB_MODE_HAS_BIPOLAR_PWM);
    doorXMotor.HlfbMode(MotorDriver::HLFB_MODE_HAS_BIPOLAR_PWM);
	doorYMotor.HlfbMode(MotorDriver::HLFB_MODE_HAS_BIPOLAR_PWM);
    
    // Set the HFLB carrier frequencies to 482 Hz
    cabMotor.HlfbCarrier(MotorDriver::HLFB_CARRIER_482_HZ);
    doorXMotor.HlfbCarrier(MotorDriver::HLFB_CARRIER_482_HZ);
	doorYMotor.HlfbCarrier(MotorDriver::HLFB_CARRIER_482_HZ);
    
    // Sets the maximum velocity for each move.
    cabMotor.VelMax(cabVelocityLimit_PPS);
    doorXMotor.VelMax(doorVelocityLimit_PPS);
	doorYMotor.VelMax(doorVelocityLimit_PPS);
    
    // Sets the maximum acceleration for each move.
    cabMotor.AccelMax(cabAcceleration_PPSS);
    doorXMotor.AccelMax(doorAcceleration_PPSS);
	doorYMotor.AccelMax(doorAcceleration_PPSS);
	
	return(true);
}


// Define the logic here
bool StopAllMotors(){
	cabMotor.MoveVelocity(0);
	doorXMotor.MoveVelocity(0);
	doorYMotor.MoveVelocity(0);
	
	cabMotor.EnableRequest(false);
	doorXMotor.EnableRequest(false);
	doorYMotor.EnableRequest(false);
	return(true);
}

void HandleMotion(Floor* target) {
	// Your HSM switch-case logic...
}

void HandleJogMode() {
	// 1. Dead-man Gate (Must be held for any motion)
	if(!jog2Hand->State()){
		StopAllMotors();
		return;
	}

	// 2. Read Combined Home/Limit Sensors
	//bool cabAtHomeLimit = ReadPin(CAB_HOME_SENSE);   // The -0.25" bottom stop
	bool cabAtHomeLimit = cabHome.State();
	bool dxAtHomeLimit  = doorXHome.State(); // Basement level stop
	bool dyAtHomeLimit  = doorYHome.State(); // Garage level stop
	
	// Proximity Slow-down zones
	bool cabInBasementZone = cabAtB->State();
	bool cabInApartmentZone = cabAt2->State();

	// 3. Cab Jog Logic
	double cabVel = 0;
	if (jogCabUp->State() && !cabOvertravel.State()) {
		cabVel = cabInApartmentZone ? cabJogSlow_PPS : cabJogFast_PPS;
	}
	else if (jogCabDown->State() && !cabAtHomeLimit) {
		cabVel = cabInBasementZone ? -cabJogSlow_PPS : -cabJogFast_PPS;
	}
	cabMotor.MoveVelocity(cabVel);

	// 4. Door X Jog (Cannot go below home)
	double dxVel = 0;
	if (jogDoorXUp->State() && !jogDoorXDown->State()) dxVel = doorJogSpeed_PPS;
	else if (jogDoorXDown->State() && jogDoorXUp->State() && !dxAtHomeLimit) dxVel = -doorJogSpeed_PPS;
	doorXMotor.MoveVelocity(dxVel);

	// 5. Door Y Jog (Cannot go below home)
	double dyVel = 0;
	if (jogDoorYUp->State() && jogDoorYDown->State()) dyVel = doorJogSpeed_PPS;
	else if ((jogDoorYDown->State() && !jogDoorYUp->State()) && !dyAtHomeLimit) dyVel = -doorJogSpeed_PPS;
	doorYMotor.MoveVelocity(dyVel);
	return;
}
