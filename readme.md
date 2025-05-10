Overview

This guide explains how to set up and operate the SmartHome ESP8266 Two-Relay Controller using the Blynk mobile app to switch two light bulbs remotely.

Components

ESP8266 board (NodeMCU or Wemos D1 Mini)

2-Channel Relay Module (5V)

Two AC light bulbs with appropriate sockets

Jumper wires and breadboard (optional)

USB cable for programming ESP8266

Smartphone with Blynk IoT app installed

Wiring Diagram

ESP8266         Relay Module         Light Bulb
========        ============         ===========
D1 (GPIO5) ---> IN1                (Switches Bulb1 mains)
GND  ---------> GND                
5V   ---------> VCC                

D2 (GPIO4) ---> IN2                (Switches Bulb2 mains)
GND  ---------> GND                
5V   ---------> VCC                

WARNING: When working with mains voltage, take all safety precautions and ensure power is disconnected during wiring.

Blynk App Setup

Download and install the Blynk app (iOS or Android).

Create a new account or log in.

Create a new Device:

Hardware: ESP8266

Connection Type: WiFi

You will receive an Auth Token via email. Copy it into the auth[] field in the code above.

In the Blynk project, add two Button widgets:

Button 1:

Output: Virtual Pin V1

Mode: Switch

Label: "Light 1"

Button 2:

Output: Virtual Pin V2

Mode: Switch

Label: "Light 2"

Save the project.

Uploading the Code

Open the Arduino IDE.

Install required libraries via Sketch > Include Library > Manage Libraries...:

Blynk by Volodymyr Shymanskyy

Select board NodeMCU 1.0 (ESP-12E Module) or Wemos D1 R2 & mini.

Set the correct Port.

Paste in the code above, update auth[], ssid[], and pass[].

Click Upload.

Operation

Power on the ESP8266 via USB or external 5V supply.

Launch the Blynk app and open your project.

Toggle the Light 1 and Light 2 buttons to switch the corresponding bulbs ON/OFF.

Troubleshooting

Relay not switching: Check wiring, ensure INx pins match code constants.

ESP8266 not connecting to WiFi: Verify SSID and password; check signal strength.

Blynk connection issues: Confirm Auth Token; verify Blynk server connectivity.

