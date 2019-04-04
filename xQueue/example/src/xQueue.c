/*
 * @brief FreeRTOS Blinky example
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2014
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/* Sets up system hardware */
static void delay(int x)
{
	int i,j;
	for(i=0;i<1000;i++)
	{
		for(j=0;j<x;j++){}
	}
}

static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();
}
static void vSenderTask( void *pvParameters )
{
	uint8_t  lValueToSend;
    uint32_t xStatus;
    lValueToSend = (uint8_t ) pvParameters;
while(1){

	xStatus = xQueueSendToBack( xQueue, &lValueToSend, 1000 );
	if( xStatus != pdPASS )
	{

		vPrintString( "Could not send to the queue.\r\n" );
		}
		}
}
static void vReceiverTask( void *pvParameters )
{
	uint8_t led;
	BaseType_t xStatus;
	const TickType_t xTicksToWait = pdMS_TO_TICKS( 100 );
	while(1)
	{
		if( uxQueueMessagesWaiting( xQueue ) != 0 )
		{
		vPrintString( "Queue should have been empty!\r\n" );
		}
		xStatus = xQueueReceive( xQueue, &x, xTicksToWait );
		if( xStatus == pdPASS )
		{
		/* Data was successfully received from the queue, print out the received
		value. */
			Board_LED_Set(led, false);
		}
		else
		{

		vPrintString( "Could not receive from the queue.\r\n" );
		}

	}
}
/*****************************************************************************
 * Public functions
 ****************************************************************************/

/**
 * @brief	main routine for FreeRTOS blinky example
 * @return	Nothing, function should not exit
 */
int main(void)
{

	prvSetupHardware();
	xQueueCreate( 15, sizeof(uint8_t) );
	/* LED1 toggle thread */
	if( xQueue != NULL )
	{
	int *r;
		r = ((rand % 3) + 1);
		xTaskCreate( vSenderTask, "Sender1", 128, ( int * ) r, 1, NULL );
		xTaskCreate( vReceiverTask, "Receiver", 128, NULL, 2, NULL );
		/* Start the scheduler */
	vTaskStartScheduler();

	/* Should never arrive here */
	return 1;
}
}
/**
 * @}
 */
