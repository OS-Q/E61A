

#ifndef PROJDEFS_H
#define PROJDEFS_H

/*
 * Defines the prototype to which task functions must conform.  Defined in this
 * file to ensure the type is known before portable.h is included.
 */
typedef void (* TaskFunction_t)( void * );

/* Converts a time in milliseconds to a time in ticks.  This macro can be
 * overridden by a macro of the same name defined in FreeRTOSConfig.h in case the
 * definition here is not suitable for your application. */
#ifndef pdMS_TO_TICKS
    #if configUSE_16_BIT_TICKS == 1
        #define pdMS_TO_TICKS( xTimeInMs )   ( ( TickType_t ) ( ( ( uint32_t ) ( xTimeInMs ) * ( TickType_t ) configTICK_RATE_HZ ) / ( TickType_t ) 1000U ) )
    #else
        #define pdMS_TO_TICKS( xTimeInMs )   ( ( TickType_t ) ( ( ( TickType_t ) ( xTimeInMs ) * ( TickType_t ) configTICK_RATE_HZ ) / ( TickType_t ) 1000U ) )
    #endif
#endif

#define pdFALSE                                  ( ( BaseType_t ) 0 )
#define pdTRUE                                   ( ( BaseType_t ) 1 )

#define pdPASS                                   ( pdTRUE )
#define pdFAIL                                   ( pdFALSE )
#define errQUEUE_EMPTY                           ( ( BaseType_t ) 0 )
#define errQUEUE_FULL                            ( ( BaseType_t ) 0 )

/* FreeRTOS error definitions. */
#define errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY    ( -1 )
#define errQUEUE_BLOCKED                         ( -4 )
#define errQUEUE_YIELD                           ( -5 )

/* Macros used for basic data corruption checks. */
#ifndef configUSE_LIST_DATA_INTEGRITY_CHECK_BYTES
    #define configUSE_LIST_DATA_INTEGRITY_CHECK_BYTES    0
#endif

#if ( configUSE_16_BIT_TICKS == 1 )
    #define pdINTEGRITY_CHECK_VALUE    0x5a5a
#else
    #define pdINTEGRITY_CHECK_VALUE    0x5a5a5a5aUL
#endif

#endif /* PROJDEFS_H */
