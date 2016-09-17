/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 * This example runs directly on ESP8266 chip.
 * You need to install this for ESP8266 development:
 *   https://github.com/esp8266/Arduino
 * Please be sure to select the right ESP8266 module
 * in the Tools -> Board menu!
 *
 * Change WiFi ssid, pass, and Blynk auth token to run :)
 * This is Blynk's basic ESP8266 sketch, modified by Costas
 * to include a few other essential items 9th Sept 2016.
 * 
 * We recommend you download DroidX to your PC and run Android
 * via this simulator, direct D/L link http://dl.haima.me/download/DXDown/win/Z001/Droid4XInstaller.exe
 *
 **************************************************************/
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ArduinoOTA.h>       // for local OTA updates
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>      // Essential for almost all sketches
SimpleTimer timer;

//********************* SECTION FOR YOU TO COMPLETE WITH YOUR DETAILS *************
// You should get Auth Token in the Blynk App.
char auth[] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"; // Go to the Project Settings (nut icon).
char cloudserver[16] = "blynk-cloud.com";
char localserver[16] = "192.168.10.229";          // Enter your IP details for the local server
char ssid[] = "MTN WIFI 19996";                   // Your WiFi credentials.
char pass[] = "xxxxxxxxxxxx";                     // Set password to "" for open networks.
char OTAhost[] = "ESP8266Skeleton";              // Optional, but very useful
//************************************************************************************************

void setup()
{
  // Put your setup code here, to run once
  Serial.begin(115200);
  Serial.println("\n Starting");
  //Blynk.begin(auth, ssid, pass);                         // Blynk.config() if already connected to WiFi e.g. WiFiManager
  //Blynk.begin(auth, ssid, pass, cloudserver);            // for Blynk's cloud server
  Blynk.begin(auth, ssid, pass, localserver);              // for a local server
  int mytimeout = millis() / 1000;
  while (Blynk.connect(1000) == false) {        // wait here until connected to the server
    if((millis() / 1000) > mytimeout + 8){      // try to connect to the server for less than 9 seconds
      break;                                    // continue with the sketch regardless of connection to the server
    }
  }  

  ArduinoOTA.setHostname(OTAhost);   
  ArduinoOTA.begin();                           // for local OTA updates

  timer.setInterval(15000, reconnectBlynk);     // check every 15 seconds if we are connected to the server
}

void reconnectBlynk() {                         // reconnect to server if disconnected, timer checks every 60 seconds
  if (!Blynk.connected()) {
    if(Blynk.connect()) {
      BLYNK_LOG("Reconnected");
    } else {
      BLYNK_LOG("Not reconnected");
    }
  }
}

void loop()
{
  if (Blynk.connected()) {   // to ensure that Blynk.run() function is only called if we are still connected to the server
    Blynk.run();
  }
  timer.run();
  ArduinoOTA.handle();       // for local OTA updates
}
