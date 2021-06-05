# HS2/Hid-Wheel

![alt text](https://github.com/Zy0d0x0/HS2-Wheel/blob/main/front.png)

In the changelog of the new release of the HS2 Firmware version V1.3.7, it was noted that USB support has been added to the radio using the port on the rear. 
This is what gave M7SYN the idea of using an Arduino to simulate a USB keyboard, acting as a tuner and navigational wheel. This project demonstrates how M7SYN created this little wheel that should have either been added to the HS2 or created as sub product and sold along with the radio as an added extra, given the price of the original setup.

Keys found to have been intended for use with a keyboard control:

* Enter
* Left 
* Right
* Up
* Down
* F1 (PA)
* F10 (Menu)

Thanks to both SQ9CWN & Marek for helping find out the keys used by the keyboard, as M7SYN does not own a wired USB keyboard.

# Hardware Setup

Required Hardware:

* Arduino Uno - atmega16u2-Uno-Rev3
* Rotary Encoder
* Wires
* 3D Printer

The wiring for this wheel is simple as it's just a rotary encoder connected to the Arduino.

M7SYN just connects the wires directly to the encoder for this project.

![alt text](https://lastminuteengineers.com/wp-content/uploads/arduino/wiring-rotary-encoder-with-arduino-uno.png)


The table below shows the Pin Connections between the Encoder and the Arduino:


Rotary Encoder | Arduino Pins
-------------- | -------------
GRD | GRD
5V | 5V
SW | DPin 4
DT | DPin 3
CLK | DPin 2

Resource From: https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/

Using a 3D printer it is possible to print the following frame for the rotary encoder, so it can then be screwed into the frame. A tuner knob, taken from this git repository or from other resources, can then be applied. 
 
When fitting the rotary encoder to the frame you may find that the fitment is tight as the washer was not used in this project. 
You may also find that bending the little tab on the encoder will allow the locking nut to fit over the top and be tightened up.

![alt text](https://github.com/Zy0d0x0/HS2-Wheel/blob/main/Frame_Cura.JPG)

The Knob can be found here https://www.thingiverse.com/thing:2797118


# Software Setup

Download and Install Flip https://www.microchip.com/Developmenttools/ProductDetails/FLIP
This will later be used to flash the Arduino with a new firmware so when the Arduino is 
plugged into any device it will be recognised as a USB Keyboard.

When you connect the Arduino and open up Device Manager, you will note that the Ardunio is currently
displaying as a COM port. While the Arduino is connected and showing as a COM port
the `Main-Wheel.ino` needs to be put onto the Ardunio using what ever IDE you normaly use.

When the Ardunio has the `Main-Wheel.ino` sketch copied to its onboard memory, it then needs 
to be put into DFU mode. This can by done by using a jumper pin or a small piece of wire
and shorting the 2 pins as shown in the image below: 

![alt text](https://github.com/Zy0d0x0/HS2-Wheel/blob/main/dfu.JPG)

Resource from: https://www.arduino.cc/en/Hacking/DFUProgramming8U2


As displayed in the above screenshot, when the pins have been shorted take another look at device manager. It should
no longer show the Arduino to be using a COM port, due to a missing driver. 

If this is the case right click and then click "Update Driver", select install driver from a local folder on the computer, then navigate to `C:\Program Files (x86)\Atmel\Flip 3.4.7\usb`, then click update driver. 
This should now install the required driver for Arduino's DFU mode so that FLIP can connect to it.

Open the FLIP tool, click on the button that looks like a micro chip and select ATmega16U2 in the dropdown menu. Then click the ok button to save the changes.

![alt text](https://github.com/Zy0d0x0/HS2-Wheel/blob/main/flipboardsettings.JPG)

Once the settings have been set for the Arduino click the `Connect` Button. This is next to the micro chip button you previously pressed. Once the `Connect` button has been press you should see a `USB` button that also needs to be clicked. You will then notice at the bottom of the FLIP software
the connection showing as established. 

![alt text](https://github.com/Zy0d0x0/HS2-Wheel/blob/main/flipboardconnect.JPG)

Next you click the `File` button and `Load HEX File`, selecting the `Arduino-keyboard-0.3.hex` file, and click the `Run` button on the lower part of the applications. Once this has completed click the `Start Application` button and you should hear the Arduino disconnect. Un-plug the Arduino and plug it back in again to power cycle it.
Now you should be able to see that the device no longer displays as a COM port in the Device Manager.

Open up notepad, add some text, then try using the wheel to navigate. If all goes well on Windows, try pluggin in the wheel into the HS2 usb port on the rear of the radio.

The primay resource for the flashing of the Arduino to make it a keybord was found by watching this video: https://www.youtube.com/watch?v=tvqA-JcTQNg

# Restoring The Ardunio

Returning the Arduino to its normal state is possible by putting the Arduino into DFU mode once again with the jumper pin, then, instead of selecting the `Arduino-keyboard-0.3.hex` file, you will need to use the `Arduino-usbserial-atmega16u2-Uno-Rev3.hex`.


# Todo

- [ ] Create rear cover to enclose the Arduino while still exposing the USB port.
