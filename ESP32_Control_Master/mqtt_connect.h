#include <WiFi.h>
#include <PubSubClient.h>
#include "wifi_connect.h"
#include "display.h"

// mqtt broker info
#define mqtt_server "10.42.0.1"
#define topic_mpu_data "mpu/data"
#define topic_led_control "led/control"
#define topic_detect_gesture "detector"
#define topic_register "register"

//#define mqtt_user "esp32"
//#define mqtt_pwd "123456789"

const uint16_t mqtt_port = 1883;
const byte ledPin = 2;
extern bool recording;

extern String topic_info;
extern String topic_gettime;
extern String topic_settime;
extern String topic_time;

void reconnect();
void callback(char* topic, byte* payload, unsigned int length);
PubSubClient get_pubsub_client();
void led_control(String msg);
void gesture_recognize(String msg);
void send_time_to_server();
void set_time_to_clock();
void display_username_password(String msg);
