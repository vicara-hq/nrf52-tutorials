/**
 * Copyright (c) 2009 - 2020, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/** @file
* @brief Example template project.
* @defgroup nrf_templates_example Example Template
*
*/

#include <stdbool.h>
#include <stdint.h>

#include "nrf.h"
#include "nordic_common.h"
#include "boards.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"

#define LED_1       17
#define LED_2       18
#define LED_3       19
#define LED_4       20
#define BUTTON_1    13
#define BUTTON_2    14
#define BUTTON_3    15
#define BUTTON_4    16
#define DEBOUNCE_MS 150

static void gpio_init()
{
    nrf_gpio_cfg_input(BUTTON_1, NRF_GPIO_PIN_PULLUP);
    nrf_gpio_cfg_input(BUTTON_2, NRF_GPIO_PIN_PULLUP);
    nrf_gpio_cfg_input(BUTTON_3, NRF_GPIO_PIN_PULLUP);
    nrf_gpio_cfg_input(BUTTON_4, NRF_GPIO_PIN_PULLUP);

    nrf_gpio_cfg_output(LED_1);
    nrf_gpio_cfg_output(LED_2);
    nrf_gpio_cfg_output(LED_3);
    nrf_gpio_cfg_output(LED_4);
}

/**
 * @brief Function for application main entry.
 */
int main(void)
{
    gpio_init();
    while (true)
    {
       if(!nrf_gpio_pin_read(BUTTON_1))
       {
            nrf_delay_ms(DEBOUNCE_MS);
            if(!nrf_gpio_pin_read(BUTTON_1))
            {
                nrf_gpio_pin_toggle(LED_1);
            }
       }
       else if(!nrf_gpio_pin_read(BUTTON_2))
       {
            nrf_delay_ms(DEBOUNCE_MS);
            if(!nrf_gpio_pin_read(BUTTON_2))
            {
                nrf_gpio_pin_toggle(LED_2);
            }
       }
       else if(!nrf_gpio_pin_read(BUTTON_3))
       {
            nrf_delay_ms(DEBOUNCE_MS);
            if(!nrf_gpio_pin_read(BUTTON_3))
            {
                nrf_gpio_pin_toggle(LED_3);
            }
       }
       else if(!nrf_gpio_pin_read(BUTTON_4))
       {
            nrf_delay_ms(DEBOUNCE_MS);
            if(!nrf_gpio_pin_read(BUTTON_4))
            {
                nrf_gpio_pin_toggle(LED_4);
            }
       }
    }
}
/** @} */
