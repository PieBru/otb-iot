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

extern void otb_mqtt_publish(MQTT_Client *mqtt_client,
                             char *subtopic,
                             char *extra_subtopic,
                             char *message,
                             char *extra_message,
                             uint8_t qos,
                             bool retain);
void otb_mqtt_handle_loc(char **loc1,
                         char **loc1_,
                         char **loc2,
                         char **loc2_,
                         char **loc3,
                         char **loc3_);
extern void otb_mqtt_subscribe(MQTT_Client *mqtt_client,
                               char *subtopic,
                               char *extra_subtopic,
                               uint8_t qos);
extern void otb_mqtt_on_connected(uint32_t *client);
extern void otb_mqtt_on_disconnected(uint32_t *client);
extern void otb_mqtt_on_published(uint32_t *client);
extern void otb_mqtt_on_receive_publish(uint32_t *client,
                                        const char* topic,
                                        uint32_t topic_len,
                                        const char *msg,
                                        uint32_t msg_len);
extern void otb_mqtt_initialize(char *host,
                                int port,
                                int security,
                                char *device_id,
                                char *mqtt_username,
                                char *mqtt_password,
                                uint16_t keepalive);
void otb_mqtt_report_error(char *cmd, char *error);
void otb_mqtt_report_status(char *cmd, char *status);
