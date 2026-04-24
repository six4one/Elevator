
#include "ClearCore.h"
#include "Include\Elevator_IO.h"
#include "Include\Elevator_Params.h"


#define CcioPort ConnectorCOM0

#define baudRate 9600
#define SerialPort ConnectorUsb

/*
 * Reference https://teknic-inc.github.io/ClearCore-library/_microchip_install.html
 * for more information about how this ProjectTemplate should be used.
 */

int main(void) {
	CcioPort.Mode(Connector::CCIO);
	CcioPort.PortOpen();
	
	// IMPORTANT: Wait for discovery to complete
	uint8_t boardsFound = 0;
	for (int i = 0; i < 50 && boardsFound == 0; i++) {
		boardsFound = CcioMgr.CcioCount();
		Delay_ms(10);
	}

//	bool boardsReady = (CcioMgr.CcioCount() > 0);
	if (boardsFound >= 1) {
		InitializeElevatorIO();
	}
	
    bool ledState = true;
	flashTime = Milliseconds();
	
	// Set up serial communication and wait up to 5 seconds for a port to open
	// Serial communication is not required for this example to run.
	SerialPort.Mode(Connector::USB_CDC);
	SerialPort.Speed(baudRate);
	uint32_t timeout = 5000;
	uint32_t startTime = Milliseconds();
	SerialPort.PortOpen();
	while (!SerialPort && Milliseconds() - startTime < timeout) {
		continue;
	}
	
	
    while (1)
    {
		
		//ConnectorLed.State(ledState);
		/*
		if(callB_PB->State()){ConnectorLed.State(true);}
		else{ConnectorLed.State(false);}
		*/
		cabStop_PB->State(callB_PB->State());
		
		
		if(Milliseconds() > flashTime + 1000){
			char buffer[128];
			snprintf(buffer, sizeof(buffer),"M0: %.3f   M1: %.3f", M0CountsPerInch, M1CountsPerInch );
			SerialPort.SendLine(buffer);
			
			flashTime = Milliseconds();
			faultState.State(ledState);
			liftEnable.State(!ledState);
			ConnectorLed.State(ledState);
/*			
			if (unlockDoorB != nullptr) {
				unlockDoorB->State(ledState);
			}
*/
			ledState = !ledState;
		}
        
        //Delay_ms(1000);
    }
}
