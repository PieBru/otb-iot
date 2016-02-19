/*
 * OTB-IOT - Out of The Box Internet Of Things
 *
 * Copyright (C) 2016 Piers Finlayson
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version. 
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for 
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define OTB_GPIO_PIN_IO_STATUS_UNKNOWN  0
#define OTB_GPIO_PIN_IO_STATUS_INPUT    1
#define OTB_GPIO_PIN_IO_STATUS_OUTPUT   2

void otb_gpio_init(void);
bool otb_gpio_is_valid(uint8_t pin);
bool otb_gpio_is_reserved(uint8_t pin);
sint8 otb_gpio_get(int pin);
bool otb_gpio_set(int pin, int value);
void otb_gpio_mqtt(char *cmd1, char *cmd2, char *cmd3);


