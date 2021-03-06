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

#ifndef OTB_CONF_H
#define OTB_CONF_H

// Choosing 0x200000 as second boot image is at 0x202000
#define OTB_CONF_LOCATION OTB_BOOT_CONF_LOCATION
#define OTB_CONF_MAX_CONF_SIZE OTB_BOOT_CONF_LEN

// Randomly generated 32-bit int
#define OTB_CONF_MAGIC 0x3B1EC363  

// Lengths are #defined within structs so padding can be easily verified.
// otb_conf_struct will be held in RAM so need to keep as small as possible.

typedef struct otb_conf_location
{
  // 32 bytes * 3 = 96 bytes

#define OTB_CONF_LOCATION_MAX_LEN  32
  // Location 1 - e.g. property
  char loc1[OTB_CONF_LOCATION_MAX_LEN];
  
  // Location 2 - e.g. room
  char loc2[OTB_CONF_LOCATION_MAX_LEN];
  
  // Location 3 e.g. bit of room
  char loc3[OTB_CONF_LOCATION_MAX_LEN];
} otb_conf_location;

typedef struct otb_conf_ds18b20
{
  // 48 bytes

  // The chip ID of a DS18B20 sensor, as a null terminated string in the following format:
  // 28-02157166b0ff.  This is 15 chars, but 16 with 1 byte for terminating.
#define OTB_CONF_DS18B20_MAX_ID_LEN  16
  char id[OTB_CONF_DS18B20_MAX_ID_LEN];
  
  // Location of this sensor.  Maximum 31 chars, so 32 with padding.
#define OTB_CONF_DS18B20_LOCATION_MAX_LEN  32  
  char loc[OTB_CONF_DS18B20_LOCATION_MAX_LEN];
} otb_conf_ds18b20;

// ADS1115 family sensors
typedef struct otb_conf_ads
{
  // 44 bytes

  // Location of this ADS.  Maximum 31 chars, so 32 with padding.
  #define OTB_CONF_ADS_LOCATION_MAX_LEN 32
  char loc[OTB_CONF_ADS_LOCATION_MAX_LEN];

  // The I2C address of this ADS.  Will be 0x48, 0x49, 0x4a or 0x4b, as indicated by
  // connection of addr pin.
  // 0 means unset
  char addr;

  // Index into array of ADSs in config (OTB_CONF_ADS_MAX_ADSS)
  char index;

  // Mux setting for this ADS - valid values 0-7
  // 000 : AINP = AIN0 and AINN = AIN1 (default)
  // 001 : AINP = AIN0 and AINN = AIN3
  // 010 : AINP = AIN1 and AINN = AIN3
  // 011 : AINP = AIN2 and AINN = AIN3
  // 100 : AINP = AIN0 and AINN = GND
  // 101 : AINP = AIN1 and AINN = GND
  // 110 : AINP = AIN2 and AINN = GND
  // 111 : AINP = AIN3 and AINN = GND
  char mux;

  // Gain amplifier setting - valid values 0-7
  // 000 : FS = ±6.144V(1)
  // 001 : FS = ±4.096V(1)
  // 010 : FS = ±2.048V (default)
  // 011 : FS = ±1.024V
  // 100 : FS = ±0.512V
  // 101 : FS = ±0.256V
  // 110 : FS = ±0.256V
  // 111 : FS = ±0.256V
  char gain;

  // Sample rate
  // 000 : 8SPS
  // 001 : 16SPS
  // 010 : 32SPS
  // 011 : 64SPS
  // 100 : 128SPS (default)
  // 101 : 250SPS
  // 110 : 475SPS
  // 111 : 860SPS
  char rate;

  // Whether to do continuous or one shot sampling:
  // 0 = continuous
  // 1 = one shot
  // One shot can be used to turn the ADS off
  char cont;

  // Whether to use RMS of straight average for sampling.
  // 0 = straight average
  // 1 = RMS
  char rms;

  // Unused, must be set to zero
  char pad1[1];

  // Period to sample over, set to seconds.  Will run number of samples as indicated
  // below every period seconds - assuming set to continuous mode.
  // 0xffff is invalid
  // 0x0 means this function is off for this ADS
  uint16_t period;

  // Number of samples to take every second seconds.
  // 0xffff is invalid
  // 0x0 means this function is off for this ADS.
  // > 1024 is unsupported
  uint16_t samples;

} otb_conf_ads;

typedef struct otb_conf_mqtt
{
  // 100 bytes

  // Currently only IP address format supported, 32 byte field
  char svr[OTB_MQTT_MAX_SVR_LEN];

  // MQTT port - default is 1883
  int port;

  // 32 byte field
  char user[OTB_MQTT_MAX_USER_LEN];

  // 32 byte field
  char pass[OTB_MQTT_MAX_PASS_LEN];
} otb_conf_mqtt;

typedef struct otb_conf_relay
{
  // 56 bytes
  
#define OTB_CONF_RELAY_LOC_LEN  32
  unsigned char loc[OTB_CONF_RELAY_LOC_LEN];

  // Index into array of relay boards
  char index;
  
  // Type of relay module - takes integer value
#define OTB_CONF_RELAY_TYPE_MIN      0
#define OTB_CONF_RELAY_TYPE_NONE     0
#define OTB_CONF_RELAY_TYPE_OTB_0_4  1
#define OTB_CONF_RELAY_TYPE_PCA      2
#define OTB_CONF_RELAY_TYPE_PCF      3
#define OTB_CONF_RELAY_TYPE_MCP      4
#define OTB_CONF_RELAY_TYPE_NUM      5
#define OTB_CONF_RELAY_TYPE_NONE_STR     "none"
#define OTB_CONF_RELAY_TYPE_OTB_0_4_STR  "otb"
#define OTB_CONF_RELAY_TYPE_PCA_STR      "pca"
#define OTB_CONF_RELAY_TYPE_PCF_STR      "pcf"
#define OTB_CONF_RELAY_TYPE_MCP_STR      "mcp"
  unsigned char type;
  
  // Address - for pca, pcf and mcp is the I2c address of the driver.  For otb is
  // the value of the jumper pins (0-7 - the code then maps this to I2C address)
  unsigned char addr;
  
  // Number of relays connected to this module.  Defaults to 8 for OTB and PCA.  0 and
  // > 16 are invalid.
  unsigned char num_relays;
  
  // Status LED - invalid for OTB (has status LED), -1 = no status led, otherwise pin
  // number of status LED.
  signed char status_led;
  
  unsigned char pad1[3];
  
  // Desired power on state of each relay for this module - lsb is lowest numbered relay
  
#define OTB_CONF_RELAY_MAX_PER_MODULE  16
  unsigned char relay_pwr_on[OTB_CONF_RELAY_MAX_PER_MODULE/8];
  
} otb_conf_relay;

typedef struct otb_conf_struct
{
  // Following fields are in version 1
  
  // Magic number to check this is a valid configuration
  uint32_t magic;
  
  // Version - starts at 1
#define OTB_CONF_VERSION_CURRENT  1
  uint16_t version;
  
  // 16-bit checksum.  #defines are bytes in struct of checksum
#define OTB_CONF_CHECKSUM_BYTE1 7
#define OTB_CONF_CHECKSUM_BYTE2 8
  uint16_t checksum;
  
  // Wifi SSID. Max is 32, but we want to null terminate.
#define OTB_CONF_WIFI_SSID_MAX_LEN  33
  char ssid[OTB_CONF_WIFI_SSID_MAX_LEN]; 

  // Whether to keep AP active when station is connected.  By default this is
  // 0 (false).  Can be changed via wifi or mqtt, the latter either
  // temporarily or permanently.  AP will always activate when station
  // disconnects
  char keep_ap_active;

  // Number of configured DS18B20s
  uint8_t ds18b20s;
  
  // Must be set to zero 
  char pad1[1]; 
  
  // Wifi password.  Max is 63, but we're going to store as a string
#define OTB_CONF_WIFI_PASSWORD_MAX_LEN  64
  char password[OTB_CONF_WIFI_PASSWORD_MAX_LEN];
  
  // Don't need to worry about padding this array - as otb_conf_ds18b20 must be padded
  // Size is 48 bytes * 8 = 384 bytes
  otb_conf_ds18b20 ds18b20[OTB_DS18B20_MAX_DS18B20S];
  
  // Location information about this OTB-IOT device
  // Size is 96 bytes
  otb_conf_location loc;

  // MQTT information
  otb_conf_mqtt mqtt;

  // Number of configured ADSs
  uint8_t adss;
  
  // Must be set to zero
  char pad2[3];
  
  // Must be set to zero
  
#define OTB_CONF_ADS_MAX_ADSS 4  
  otb_conf_ads ads[OTB_CONF_ADS_MAX_ADSS];
  
  // ESP has 17 GPIO pins.
  char gpio_boot_state[17];
  
  // Must be set to zero
  char pad3[3];
  
#define OTB_CONF_RELAY_MAX_MODULES 8
  otb_conf_relay relay[OTB_CONF_RELAY_MAX_MODULES];
  
  // Adding any configuration past this point needs to be supported by a different
  // version

} otb_conf_struct;

#define OTB_CONF_RC_ERROR          0
#define OTB_CONF_RC_NOT_CHANGED    1
#define OTB_CONF_RC_CHANGED        2

extern otb_conf_struct *otb_conf;

void otb_conf_init(void);
void otb_conf_ads_init_one(otb_conf_ads *ads, char ii);
void otb_conf_ads_init(otb_conf_struct *conf);
bool otb_conf_verify(otb_conf_struct *conf);
void otb_conf_init_config(otb_conf_struct *conf);
bool otb_conf_load(void);
void otb_conf_log(otb_conf_struct *conf);
bool otb_conf_save(otb_conf_struct *conf);
uint16_t otb_conf_calc_checksum(otb_conf_struct *conf);
bool otb_conf_verify_checksum(otb_conf_struct *conf);
uint8  otb_conf_store_sta_conf(char *ssid, char *password, bool commit);
bool otb_conf_store_ap_enabled(bool enable);
bool otb_conf_update(otb_conf_struct *conf);
bool otb_conf_update_loc(int loc, char *val);
bool otb_conf_set_keep_ap_active(unsigned char *next_cmd, void *arg, unsigned char *prev_cmd);
bool otb_conf_set_loc(unsigned char *next_cmd, void *arg, unsigned char *prev_cmd);
bool otb_conf_delete_loc(unsigned char *next_cmd, void *arg, unsigned char *prev_cmd);
void otb_conf_mqtt_conf(char *cmd1, char *cmd2, char *cmd3, char *cmd4, char *cmd5);

#ifdef OTB_CONF_C

otb_conf_struct *otb_conf;
otb_conf_struct otb_conf_private;

#endif // OTB_CONF_C

#endif // OTB_CONF_H
