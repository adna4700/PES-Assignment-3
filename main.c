
#include <stdio.h>
#include "board.h"
#include "Blinkenlights_test.h"
#include "TouchSensor.h"

int main(void)
{

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    KL25Z_RGB_Flasher();
    Int_RGB();
    Touch_Init();
    int a = Touch_Scan_LH();
    PRINTF("%d",a);
    return 0 ;
}
