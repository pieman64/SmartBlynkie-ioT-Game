# SmartBlynkie-ioT-Game
Learn to **[Blynk](http://www.blynk.cc/ "arguably the best IOT system currently available")** with the SmartBlynkie™© ioT Game app for Android and iPhone.

**What is the SmartBlynkie Game?**

Well let's start by saying what it's not. It's not really a Smart game for existing Blynkers to play but they are free to play the game if they wish. It's a game for none Blynkers, aged from 5 to 145, to learn the different features of **Blynk**. The hope is that you will then apply what you have learned from playing the game and studying the sketch extracts, to real world applications like **home and business automation** etc.

**Will we be providing the full sketch (software code) from day one for users to flash to their ESP's?**

No, if we did that then many users wouldn't learn very much as it is easier to learn with chunks of code rather than a few thousands lines of code. We will however provide the compiled binary (bin) file for you to start playing the game **immediately**.

Don't worry if you think these instructions look a bit daunting, you should find it all quite **straightforward** once you start.

![Smart Blynkie ioT game side by side iamges](https://cloud.githubusercontent.com/assets/8315296/18383156/d6b99e36-768c-11e6-9f39-f4e8ac4103fc.png "Smart Blynkie ioT game screenshots")

Watch the brief video by clicking the image below.

[![Video of the Smart Blynkie™© ioT Game](https://cloud.githubusercontent.com/assets/8315296/18383157/d9aafe46-768c-11e6-8569-474ee446d578.png "Video of the Smart Blynkie™© ioT Game")](https://youtu.be/RBnHyGzlykE?t=23s "SmartBlynkie™© ioT Game")

To start playing the SmartBlynkie™© ioT Game follow these steps and be sure to digest the full contents of this README.md:

1. Download Blynk App: [http://j.mp/blynk_Android](http://j.mp/blynk_Android) or [http://j.mp/blynk_iOS](http://j.mp/blynk_iOS)

2. Touch the QR icon and point the camera to the code below or open the following ***Smartphone*** link [http://tinyurl.com/zwn2bz3
![Smart Blynkie QR code for cloud cloned project](https://cloud.githubusercontent.com/assets/8315296/18383161/ddcc1f5a-768c-11e6-8c15-c200705422b3.png "Smart Blynkie QR code for cloud cloned project")
](http://tinyurl.com/zwn2bz3)

3. Load the game on to your ESP (covered in the next section). Enjoy the app and hope to see you over at the [Blynk Community](http://community.blynk.cc "hang out with other Blynkers") with all the other happy Blynkers.

Regards

**Costas**

----------

 
**Loading the Game on your ESP**

There are numerous ways to flash your ESP with the required bin (binary) file to be able to play the game but we will kick off by providing one of the best, cross platform tools.

**esptool.py** runs via Python and can be installed on almost any machine. If you don't already have Python just ask Google for something like "install Python on Windows" or "install Python on Ubuntu" etc.

The GitHub for esptool.py is available for download [here](https://github.com/themadinventor/esptool "esptool for Python"). Do be aware there are several versions of esptool and one is used by the Arduino IDE. As some game players will not want to install the full Arduino IDE before they decide if Blynk is for them we recommend the Python version.

esptool.py users a command line interface (CLI) rather than a graphical user interface (GUI) and the command instructions can be quite long, but you should be able to simply cut and paste them from this page.

Once you have downloaded esptool.py you need to download the latest bin file for the game. The files are located here on GitHub and you want the one with the highest version number (currently [SmartBlynkieV1.0.2.bin](https://github.com/pieman64/test/blob/master/SmartBlynkieV1.0.2.bin "Click the Download button to receive your copy of Smart Blynkie for ESP devices.")).

**Move** the bin file to the directory where your copy of **esptool.py** is located (so for me on Windows 8.1 I have it at C:\ESPTool4python\esptool-master\). On most systems you will need Administrator / root access to be able to flash the bin file to your ESP. So for example with Windows 8.1 right click Command Prompt and click Run as Administrator. Then move to your esptool directory. For me it is cd C:\ESPTool4python\esptool-master\

Make sure you don't have the serial port open in any other applications like the Arduino IDE Serial Monitor, HyperTerminal, Termite or RealTerm etc. Then issue a command like the one below, changing **COM7** to your Serial port. **WARNING:** Ensure you set the correct parameters for your ESP as outlined [here](https://github.com/themadinventor/esptool "esptool for Python"). **Failure to do this correctly could destroy your ESP.**

**python esptool.py -p COM7 write_flash -fm dio -fs 32m 0x0000 SmartBlynkieV1.0.2.bin**

You can copy, paste and then edit the command above rather than type it all in to the command line interface. If all goes well you should see the blue onboard LED flash on the ESP has it flashes the new firmware and something like the following appear in the Command Prompt window:

    esptool.py v1.2-dev
    Connecting...
    Running Cesanta flasher stub...
    Flash params set to 0x0240
    Writing 385024 @ 0x0... 385024 (100 %)
    Wrote 385024 bytes at 0x0 in 33.4 seconds (92.2 kbit/s)...
    Leaving...

Please note after the flash the onboard LED will be **OFF**, if it is ON then you have done something wrong and need to check the details and try again. For the first time after flashing the firmware is is **preferable**, but not essential, to open your favourite Terminal program (Arduino IDE Serial Monitor, HyperTerminal, Termite or RealTerm etc) and connect to the ESP.

You will then be able to see various prompts and the interaction with WiFi Manager etc.

We have used **Ken Taylor's branch of WiFi Manager** to feed WiFI and Blynk credentials into the ESP. Please take a look at the [screenshots](https://github.com/kentaylor/WiFiManager "WiFI Manager - Ken Taylor Branch screenshots") etc for his branch so you know what to expect when you set up your ESP.

At this stage you don't need to have a working knowledge of WiFi Manager has we have done most of this for you. However in due course you will probably want to include it in the awesome apps that you are going to create.

If you are using an **Android Smartphone** we highly recommend setting the initial WiFi credentials with a brand new Android app called **ESP Connect**. It is available on Google's Play store [here](https://play.google.com/store/apps/details?id=au.com.umranium.espconnect "Add WiFi credentials to your ESP with this new app, ESP Connect").

If you have **previously** used your ESP with WiFi you will already have working credentials in your ESP and the benefit of Ken Taylor's branch of WiFi Manager is that you can just skip the SSID and Password fields.

We are using a **Wio Link ESP** and it has a button labelled **CONFIG**, tied to **GPIO 0** on the ESP. To use the WiFi Manager Access Point just briefly short GPIO 0 **(WeMos D3**) to GND once the ESP has booted up. If you look in your WiFi networks a new **SSID** will appear within 60 seconds called ESPXXXXXXXXXX (XXXX being different for each ESP based on the unique MAC address). The Access Point will now be available from a web browser on **192.168.4.1**. You can change your settings later by repeating the grounding of the GPIO 0 pin.

The ESP's onboard LED (normally blue) will be ON when the Access Point is available and and OFF when you exit the portal.

So the **important fields** for Smart Blynkie are shown in the image below:

![Ken Taylor branch of WiFi Manager](https://cloud.githubusercontent.com/assets/8315296/18383170/eabd0602-768c-11e6-8fd4-1d891f62b190.png "[Ken Taylor branch of WiFi Manager")

To run the game on Blynk's server you just need to enter the token from the Smart Blynkie project on your Smartphone. Leave Blynk Server 1 IP as "blynk-cloud.com". The game is **slightly** more responsive on a local server, so if you have set one up, enter the Blynk token from your local server for Smart Blynkie in the Blynk Token 2 field. Add the IP of your local server in Blynk Server 2 IP. Leave all the other fields as they are but click the tickbox against the DHT-22 Sensor field as we might make us of this variable in the ESP firmware at a later date. Click Save at the bottom of the web page and wait up to 60 seconds before clicking the **main page** link to be sure your ESP has been allocated an IP address.

Click Exited Portal and your ESP will try to connect to Blynk's Cloud server and if it fails, it will connect to your local server. 

That's it, you all ready now to **play Smart Blynkie**.

----------
**Game Features:**

 1. Parental control with Blynk's cool app sharing feature.
 
 2. Play against friends and family **from around the world**.
 
 3. Vary game duration with  blue slider 1 30s, 2 60s, 3 90s 4 120s. Default is 60 second game duration and needs to be set after each ESP reboot.
 
 4. Vary difficulty with red slider 1 quite easy to 4 quite difficult. Default is level 2 and the slider widget is set to 2 on each reboot of the ESP.
 
 5. Retains high score and scorer using Blynk's sync feature but be sure not to sync too many pins within a short period of time or it may lead to [flooding](http://docs.blynk.cc/#troubleshooting-flood-error "prevent flooding the server with data").
 
 6. The Red CLR button in the SETUP tab should have the ON and OFF labels changed by the user to both read "RST" as it simply resets (rebbots) the ESP, previously it also cleared player names and top scorer details.
 
 7. **Terminal keywords** added ("stop", "reboot" and others). If you type "reboot" in Terminal    it will restart the ESP but it does not clear player names and high scorer data like the CLR button does. Typing "stop" will stop the current game as the centre button on the Player widget is simply used to start and restart the game. This might have changed by the time you read this as Blynk are currently updating this widget. Details of other keywords to be provided in due course.
    
 8. Includes **local OTA update** facility so updates can be done without connecting your ESP to your computer. 
 
 9. Before you play your first game update the details in the RTC and Email widgets on the CONTROL tab to your timezone and email address.

----------


Latest PLAY tab screenshot (subject to ongoing changes)

![Smart Blynkie ioT PLAY tab screenshot](https://cloud.githubusercontent.com/assets/8315296/18383184/02500364-768d-11e6-8227-2a2142f3b5ed.png "Smart Blynkie ioT PLAY tab screenshot")
  

**TODO List:**

1. ~~Set the Player widget Play and Stop buttons to start and restart, not start and stop. Game can be stopped with keyword "stop" typed into the Terminal widget.~~ [Completed]
 
2. Additional **Parental Control** features to be added.

3. Add remote (internet) OTA update facility.

Latest SETUP tab screenshot (subject to ongoing changes)

![SmartBlynkie SETUP tab screenshot](https://cloud.githubusercontent.com/assets/8315296/18383193/0a1dd166-768d-11e6-980b-70d940348b76.png "SmartBlynkie SETUP tab screenshot")

Please raise an issue here on GitHub if you have any questions about the game or preferences for the sketch extracts you wish to see first.

----------

**P.S.** Courtesy of Blynk's **Project sharing** feature, if you are still waiting for your ESP to arrive from the Far East, or elsewhere, you can **try** using one of **our** ESP's with the following QR code or Smartphone link [http://tinyurl.com/z5bgqwv
![Cloud based shared project QR code](https://cloud.githubusercontent.com/assets/8315296/18383199/129963f0-768d-11e6-8b91-7a5c6b78e9bd.png "Cloud based shared project QR code")](http://tinyurl.com/z5bgqwv) 

If someone is already playing a game on the ESP, watch them play the current game (maximum 2 minutes), enter your name in the Terminal (SETUP tab) and return to the PLAY tab to start your game.

We would like to say **a big thanks** to the following people that have provided tools and assistance, without which there would be no game to play.

Dmitriy Dumanskiy - @doom369, @vshymanskyy, Pavel and the rest of the team at **Blynk**.

Ivan Grokhotkov @igrr "**Mr ESP**".

@tzapu and @kentaylor for **WiFi Manager**.

Frederik Ahlberg themadinvetor aka @projectgus for **esptool.py**.

@Lichtsignaal and @psoro at the **Blynk Community** that first got us going with those nasty ESP01's.

**Espressif** and **WeMos**.

**Anyone else we have forgotten**.

