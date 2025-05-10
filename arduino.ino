/*
  SmartHome Two-Relay Control via Blynk
  Hardware: ESP8266 (NodeMCU/Wemos D1 Mini), 2-Channel Relay Module, Two Light Bulbs
  Dependencies: Blynk (install via Library Manager)
*/

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// ======== User Configuration ========
char auth[] = "BLYNK_AUTH_TOKEN";   // Replace with your Blynk auth token
char ssid[] = "WIFI_SSID";          // Replace with your WiFi SSID
char pass[] = "WIFI_PASSWORD";      // Replace with your WiFi password

// ======== Pin Definitions ========
const uint8_t RELAY1_PIN = D1;  // GPIO5
const uint8_t RELAY2_PIN = D2;  // GPIO4

// Virtual Pins for Blynk App
const uint8_t VIRTUAL_RELAY1 = V1;
const uint8_t VIRTUAL_RELAY2 = V2;

BlynkTimer timer;

// Synchronize relay state to Blynk app on connection
BLYNK_CONNECTED() {
  Blynk.syncVirtual(VIRTUAL_RELAY1);
  Blynk.syncVirtual(VIRTUAL_RELAY2);
}

// Handle Relay 1 commands from Blynk
BLYNK_WRITE(VIRTUAL_RELAY1) {
  int value = param.asInt();      // 0 or 1 from Blynk button
  digitalWrite(RELAY1_PIN, value);
}

// Handle Relay 2 commands from Blynk
BLYNK_WRITE(VIRTUAL_RELAY2) {
  int value = param.asInt();
  digitalWrite(RELAY2_PIN, value);
}

void setup() {
  // Initialize serial for debug
  Serial.begin(115200);
  delay(100);

  // Initialize relay pins
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  digitalWrite(RELAY1_PIN, LOW);  // Ensure relays are OFF initially
  digitalWrite(RELAY2_PIN, LOW);

  // Connect to Blynk
  Blynk.begin(auth, ssid, pass);

  // Optionally, set a heartbeat to keep connection alive
  timer.setInterval(10000L, []() {
    Blynk.virtualWrite(V0, millis() / 1000);
  });
}

void loop() {
  Blynk.run();
  timer.run();
}