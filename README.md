# HS2/Hid-Wheel

![alt text](https://github.com/Zy0d0x0/HS2-Wheel/blob/main/front.png)

Since the new release of the HS2 Firmware version V1.3.7. It was noted in the changelog that USB support 
has been added to the radio using the port on the rear. This gave M7SYN a idea to use a Ardunio to
simulate a USB keyboard to work as a tuner and navigational wheel. The below project shows how M7SYN created
this little wheel that should of been added to the HS2 or created as sub product sold along with the radio inculded
with the price.

Keys found to be in use:

* Enter
* Left 
* Right
* Up
* Down
* F1 (PA)
* F10 (Menu)

Thanks to both SQ9CWN & CALL for helping find out the keys used by the keyboard as M7SYN does not own a wired USB keyboard.

# Hardware Setup

Required Hardware:

* Ardunio Uno - atmega16u2-Uno-Rev3
* Rotary Encoder
* Wires
* 3D Printer

The wiring for this wheel is simple as it's just a rotary encoder connected to the Ardunio.

M7SYN just connects the wires directly to the encoder for this project.

![alt text](https://lastminuteengineers.com/wp-content/uploads/arduino/wiring-rotary-encoder-with-arduino-uno.png)


The below table shows the Pin Connections between the Encoder and the Ardunio:


Rotary Encoder | Ardunio Pins
-------------- | -------------
GRD | GRD
5V | 5V
SW | DPin 4
DT | DPin 3
CLK | DPin 2

Resource From: https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/

Using a 3D printer it is possible to print the following frame for the rotary encoder to then next be screwed into
and when a tuner knob has either been used from this git or has been sourced on other resourses this can be applied. 
 
When fitting the rotary encoder to the frame it maybe found that the fitment is tight as in this project the washer was not used. 
It was also found by bending the little tab on the encoder it allowed the locking nut to fit over the top and be tighted up.

![alt text](https://github.com/Zy0d0x0/HS2-Wheel/blob/main/Frame_Cura.JPG)

The Knob can be found here https://www.thingiverse.com/thing:2797118


# Software Setup

Download and Install Flip https://www.microchip.com/Developmenttools/ProductDetails/FLIP
This will later be used to flash the ardunio with a new firmware so when the Ardunio is 
plugged into any device it should then load as USB Keyboard.

Connect the Ardunio and open up Device Manager, take note the Ardunio is currently
displaying as a COM port. While the Ardunio is currently connected and showing as a COM port
the `Main-Wheel.ino` needs to be put onto the Ardunio using what ever IDE you normaly use.

When the Ardunio has the `Main-Wheel.ino` sketch copied to its onboard memory. The Ardunio then needs 
to put into DFU mode this can by done by using a jumper pin or a small peice of wire
and shorting the 2 pins shown in the below image. 

![alt text](https://github.com/Zy0d0x0/HS2-Wheel/blob/main/dfu.JPG)

Resource from: https://www.arduino.cc/en/Hacking/DFUProgramming8U2


As displayed in the above screenshot when the pins have been shorted take another look at device manager it should
noted the Ardunio is not longer showing as a COM port and it may be missing its driver, If this is the case right click and then click update driver, 
select install driver from a local folder on the computer then navigate to `C:\Program Files (x86)\Atmel\Flip 3.4.7\usb`
then click update driver this should now install the required driver for Ardunio DFU mode so that FLIP can connect to it.

Open the FLIP tool and click on the button that looks like a micro chip and select ATmega16U2 in the dropdown menu then click the ok button to save the changes.

![alt text](https://github.com/Zy0d0x0/HS2-Wheel/blob/main/flipboardsettings.JPG)

Once the settings have been set for the Ardunio click the `Connect` Button. This is next to the micro chip button prevoisuly pressed. Once the `Connect` button has been press you should see a `USB` button that also needs to be clicked. It should be noticed at the bottom of the FLIP software
the connection will then become established. 

![alt text](https://github.com/Zy0d0x0/HS2-Wheel/blob/main/flipboardconnect.JPG)

By clicking the `File` button and `Load HEX File`, Select the `Arduino-keyboard-0.3.hex` file and click then `Run` button on the lower part of the applications. Once this has comleted click the `Start Application` button you should then hear the Ardunio disconnect. Un-plug the Ardunio and plug it back in again to power cycle it.
Now it should be possible to see in device manager the device does not display as a COM port.
Open up notepad add some text then try using the wheel to navigate if all goes well on windows try pluggin in the wheel into the HS2 usb port on the rear of the radio.

The primay resource for the flashing of the Arduino to make it aa keybord was found by watching this video: https://www.youtube.com/watch?v=tvqA-JcTQNg

# Restoring The Ardunio

Returning the Ardunio to its normal state is possible by putting the ardunio into DFU mode once again with the jumper pin
then instead of selecting the `Arduino-keyboard-0.3.hex` file this time around you need to use the `Arduino-usbserial-atmega16u2-Uno-Rev3.hex`.


# Todo

- [ ] Craated rear cover to enclose the Ardunio while still exposing the USB port.
