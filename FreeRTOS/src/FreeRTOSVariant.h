#ifndef freeRTOSVariant_h
#define freeRTOSVariant_h

#ifdef __cplusplus
extern "C" {
#endif

#include <avr/io.h>
#include <avr/wdt.h>

// System Tick - Scheduler timer
// Use the Watchdog timer, and choose the rate at which scheduler interrupts will occur.

#ifndef portUSE_WDTO
    #define portUSE_WDTO        WDTO_15MS    // portUSE_WDTO to use the Watchdog Timer for xTaskIncrementTick
#endif

/* Watchdog period options:     WDTO_15MS
                                WDTO_30MS
                                WDTO_60MS
                                WDTO_120MS
                                WDTO_250MS
                                WDTO_500MS
                                WDTO_1S
                                WDTO_2S
*/
//    xxx Watchdog Timer is 128kHz nominal, but 120 kHz at 5V DC and 25 degrees is actually more accurate, from data sheet.
#define configTICK_RATE_HZ      ( (TickType_t)( (uint32_t)128000 >> (portUSE_WDTO + 11) ) )  // 2^11 = 2048 WDT scaler for 128kHz Timer

/*-----------------------------------------------------------*/

#ifndef INC_TASK_H
#include "Arduino_FreeRTOS.h"
#include "task.h"
#endif

void initVariant(void);

void vApplicationIdleHook( void );

void vApplicationMallocFailedHook( void );
void vApplicationStackOverflowHook( TaskHandle_t xTask, char * pcTaskName );

void vApplicationGetIdleTaskMemory( StaticTask_t ** ppxIdleTaskTCBBuffer,
                                    StackType_t ** ppxIdleTaskStackBuffer,
                                    configSTACK_DEPTH_TYPE * pulIdleTaskStackSize );
void vApplicationGetTimerTaskMemory( StaticTask_t ** ppxTimerTaskTCBBuffer,
                                     StackType_t ** ppxTimerTaskStackBuffer,
                                     configSTACK_DEPTH_TYPE * pulTimerTaskStackSize );

#ifdef __cplusplus
}
#endif

#endif // freeRTOSVariant_h
