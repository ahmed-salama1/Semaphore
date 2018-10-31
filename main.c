

/* Includes */
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include <string.h>

#define STK 40

char *msg1 = "LED4";
char *msg2 = "LED5";
char *ms = "LL";
char msg3[5];
char *msg4;
char a1;
int j;

SemaphoreHandle_t xSemaphore;

void task1(void *pvParameters)
{
	/*creating a semaphore*/
	xSemaphore = xSemaphoreCreateMutex();

	/*take the semaphore to control it thru other function*/
	xSemaphoreTake(xSemaphore,0);

	//STM_EVAL_LEDOff(LED4);

	while(1){
		/*checking if it's not successfully created*/
		if(!xSemaphore){

		}
		else{

			//vTaskDelay(500);
			/*block the sema to wait the signal from other func*/
			xSemaphoreTake(xSemaphore,portMAX_DELAY);

			/*plink the led if the sema was released*/
			STM_EVAL_LEDToggle(LED4);
			//vTaskDelay(700);
		}

		}
	}


void task2(void *pvParameters){

	while(1){


		/*wait for a button signal to release semaphore*/
		if((GPIOA->IDR & GPIO_IDR_IDR_8) == GPIO_IDR_IDR_8){

			/*release semaphore*/
			xSemaphoreGive(xSemaphore);

			vTaskDelay(200);
		}
	}
}
int main(void)
{
	TaskHandle_t task1handle;
	TaskHandle_t task2handle;
//
//
//	  /* Initialize LEDs */
	  STM_EVAL_LEDInit(LED6);
	  STM_EVAL_LEDInit(LED4);
	  STM_EVAL_LEDInit(LED5);
	  init_gpio();

	xTaskCreate(task1,"a7a",STK,NULL,2,&task1handle);
	xTaskCreate(task2,"a7a2",STK,NULL,1,&task2handle);
	vTaskStartScheduler();


  /* Infinite loop */
  while (1)
  {

  }
}
