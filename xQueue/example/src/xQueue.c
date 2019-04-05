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
#include "stdio.h"
#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "stdlib.h"
#include "time.h"
#define  static volatile bool   Send_Led;
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
//static void delay(int x)
//{
	//int i,j;
	//for(i=0;i<1000;i++)
	//{
	//	for(j=0;j<x;j++){}
	//}
//}

static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();
}
static void vSenderTask( void *pvParameters )
{
	//uint8_t*  lValueToSend = ((rand()%3)+1);
	xQueueHandle  xQueue;
    uint32_t xStatus;
   // lValueToSend = (uint8_t* ) pvParameters;
    while(1){
    if(Send_Led == 1)
    {
    	srand(time(0));
    	uint8_t* lValueToSend =((rand()%3)+1);
    	uint8_t r =((portFLOAT)rand()/(portFLOAT)RAND_MAX);
    	vTaskDelay((portTickType)(r*configTICK_RATE_HZ));
    xStatus = xQueueSendToBack(xQueue,&lValueToSend,1000);
	if( xStatus != pdPASS )
	{

	// "Could not send to the queue.\r\n" /
		}
		}
}}
static void vReceiverTask( void *pvParameters )
{
	uint8_t led;
	xQueueHandle  xQueue;
	portBASE_TYPE xStatus;
	const portTickType  xTicksToWait = 2000;
	while(1)
	{
		if( uxQueueMessagesWaiting(xQueue ) != 0 )
		{
		//vPrintString( "Queue should have been empty!\r\n" );
		}
		xStatus = xQueueReceive( xQueue, &led, xTicksToWait );
		if( xStatus == pdPASS )
		{

			//Board_LED_Set(led, false);
		}
		else
		{

		//vPrintString( "Could not receive from the queue.\r\n" );
		}

	}
}
static void vTimerTask(void *pvParameters)
{
	while(1){
	Send_Led=1;
	vTaskDelay(4000);
	Send_Led=0;
	vTaskDelay(30000);
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
	xQueueHandle  xQueue;
	xQueue = xQueueCreate( 1500, sizeof(uint8_t) );
	/* LED1 toggle thread */
	if( xQueue != NULL )
	{
		xTaskCreate(vTimerTask, (signed char *) "vtimer1",
						configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY +2UL),
						(xTaskHandle *) NULL);
			xTaskCreate(vSenderTask, (signed char *) "sender",
							configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
							(xTaskHandle *) NULL);

			xTaskCreate(vReceiverTask, (signed char *) "reciever",
							configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
							(xTaskHandle *) NULL);
	vTaskStartScheduler();

	/* Should never arrive here */
	return 1;
}
}
/**
 * @}
 */
