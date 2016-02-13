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

typedef struct otb_util_timeout
{
  uint32_t start_time;
  uint32_t end_time;
} otb_util_timeout;

extern void otb_util_log_fn(char *text);
extern void otb_util_assert(bool value, char *value_s);
void otb_reset(void);
void otb_util_clear_reset(void);
extern bool otb_util_timer_finished(otb_util_timeout *timeout);
extern void otb_util_delay_ms(uint32_t value);
extern void otb_util_check_defs(void);
void otb_util_log_snprintf(char *log_string,
                           uint16_t max_log_string_len,
                           char *format,
                           va_list args);
extern void otb_util_log(bool error,
                         char *log_string,
                         uint16_t max_log_string_len,
                         char *format,
                         ...);
void otb_util_log_error_via_mqtt(char *);
size_t otb_util_strnlen(const char *s, size_t maxlen);
void otb_init_wifi(void *arg);
void otb_init_mqtt(void *arg);
void otb_init_ds18b20(void *arg);

