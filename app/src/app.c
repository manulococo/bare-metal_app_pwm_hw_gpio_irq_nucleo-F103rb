/*
 * Copyright (c) 2023 Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *
 * @file   : app.c
 * @date   : Set 26, 2023
 * @author : Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>
 * @version	v1.0.0
 */

/********************** inclusions *******************************************/
/* Project includes. */
#include "main.h"

/* Demo includes. */
#include "logger.h"
#include "dwt.h"

/* Tasks includes. */
#include "board.h"

/********************** macros and definitions *******************************/
#define G_APP_CNT_INI	0u

#define DUTY_CYCLE_MIN	0u
#define DUTY_CYCLE_MAX	200u
<<<<<<< HEAD
#define DUTY_CYCLE_INC	(DUTY_CYCLE_MAX/10)
=======
#define DUTY_CYCLE_INC	(DUTY_CYCLE_MAX/20)
>>>>>>> 5972a3b308b4f9cec8a918b99b3c71970705e51a

/********************** internal data declaration ****************************/

/********************** internal functions declaration ***********************/

/********************** internal data definition *****************************/
const char *p_sys	= " Bare Metal - Event-Triggered Systems (ETS)\r\n";
<<<<<<< HEAD
const char *p_app	= " App - PWM HW\r\n";
=======
const char *p_app	= " App - PWM HW & GPIO IRQ\r\n";
>>>>>>> 5972a3b308b4f9cec8a918b99b3c71970705e51a

/********************** external data declaration *****************************/
uint32_t g_app_cnt;
volatile uint32_t g_tick_cnt;
<<<<<<< HEAD
=======
volatile uint32_t duty_cycle;
>>>>>>> 5972a3b308b4f9cec8a918b99b3c71970705e51a

/********************** external functions definition ************************/
void app_init(void)
{
	/* Print out: Application Initialized */
	LOGGER_LOG("\r\n");
	LOGGER_LOG("%s is running - Tick [mS] = %d\r\n", GET_NAME(app_init), (int)HAL_GetTick());

	LOGGER_LOG(p_sys);
	LOGGER_LOG(p_app);

	g_app_cnt = G_APP_CNT_INI;

	/* Print out: Application execution counter */
	LOGGER_LOG(" %s = %d\r\n", GET_NAME(g_app_cnt), (int)g_app_cnt);

	/* Start timer */
<<<<<<< HEAD
=======
	duty_cycle = DUTY_CYCLE_MIN;
>>>>>>> 5972a3b308b4f9cec8a918b99b3c71970705e51a
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
}

/* STM32 PWM Frequency
 *
 *   Fpwm = Fclk / ((ARR + 1) * (PSC + 1))
 *
 *   Fpwm = 50Hz, Fclk = 64MHz, ARR = 200, PSC = 6400
 *
 * STM32 PWM Duty Cycle
 *
 *   DutyCyclepwm [%] = (CCRX / ARR) [%]
 *
 *   CCRX = 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200
 */
void app_update(void)
{
<<<<<<< HEAD
	uint32_t duty_cycle = DUTY_CYCLE_MAX;

=======
>>>>>>> 5972a3b308b4f9cec8a918b99b3c71970705e51a
	/* Update App Counter */
	g_app_cnt++;

	/* Print out: Application Update */
	LOGGER_LOG("\r\n");
	LOGGER_LOG("%s is running - Tick [mS] = %d\r\n", GET_NAME(app_update), (int)HAL_GetTick());

	/* Print out: Application execution counter */
	LOGGER_LOG(" %s = %d\r\n", GET_NAME(g_app_cnt), (int)g_app_cnt);

<<<<<<< HEAD
	for (;;)
	{
        while (DUTY_CYCLE_MAX > duty_cycle)
        {
            TIM2->CCR1 = duty_cycle;
            duty_cycle += DUTY_CYCLE_INC;
            HAL_Delay(100);
        }
        while (DUTY_CYCLE_MIN < duty_cycle)
        {
            TIM2->CCR1 = duty_cycle;
            duty_cycle -= DUTY_CYCLE_INC;
            HAL_Delay(100);
        }
	}
=======
	for (;;);
>>>>>>> 5972a3b308b4f9cec8a918b99b3c71970705e51a
}

void HAL_SYSTICK_Callback(void)
{
	g_tick_cnt++;
}

/* Callback in non blocking modes (Interrupt and DMA) */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  // Check which version of the timer triggered this callback
  if (htim == &htim2 )
  {
  }
}

<<<<<<< HEAD
=======
/* Callback in non blocking modes (Interrupt and DMA) */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	// Check which version of the gpio triggered this callback
	if (GPIO_Pin == BTN_A_PIN)
	{
        if (DUTY_CYCLE_MAX > duty_cycle)
        {
            TIM2->CCR1 = duty_cycle;
            duty_cycle += DUTY_CYCLE_INC;
        }
        else
        {
            duty_cycle = DUTY_CYCLE_MIN;
        }
	}
}

>>>>>>> 5972a3b308b4f9cec8a918b99b3c71970705e51a
/********************** end of file ******************************************/
