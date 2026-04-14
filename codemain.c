#include <Arduino.h>

#define BLYNK_TEMPLATE_ID   "tự điền có trên web hiện tôi chưa làm" 
#define BLYNK_TEMPLATE_NAME "tên dự án thôi"
#define BLYNK_AUTH_TOKEN    "tương tự cái ở trên" 

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "tên wifi";
char pass[] = "mật khẩu wifi";

// các chân cần nối (nối với Ln298)
#define IN1 12
#define IN2 13
#define IN3 14
#define IN4 27

void stopRobot() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}

void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  
  stopRobot();
  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V1) { // Tiến
  if (param.asInt() == 1) {
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  } else stopRobot();
}

BLYNK_WRITE(V2) { // Lùi
  if (param.asInt() == 1) {
    digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  } else stopRobot();
}

BLYNK_WRITE(V3) { // Trái
  if (param.asInt() == 1) {
    digitalWrite(IN1, LOW);  digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  } else stopRobot();
}

BLYNK_WRITE(V4) { // Phải
  if (param.asInt() == 1) {
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);  digitalWrite(IN4, LOW);
  } else stopRobot();
}

void loop() {
  Blynk.run();
}
