# HS2/Hid-Wheel

Since the new HS2 Firmware version V1.3.7 has been released it was noted in the changelog, that USB support 
has been added to the radio using the USB port on the rear. This gave M7SYN a idea to use a Ardunio to
simulate a USB keyboard.

Keys Found to be in use:

* Enter
* Left 
* Right
* Up
* Down
* F1 (PA)
* F10 (Menu)

Thanks to both SQ9CWN & CALL for helping find out the keys used by the keyboard as i do not own 
a wired USB keyboard.

![alt text](https://github.com/Zy0d0x0/HS2-Wheel/blob/main/front.png)

# Hardware Setup

Required Hardware:

* Ardunio Uno - atmega16u2-Uno-Rev3
* Rotary Encoder
* Wires
* 3D Printer

The wiring for this wheel is simple as it's just a rotary encoder connected to the Ardunio.

![alt text](https://lastminuteengineers.com/wp-content/uploads/arduino/wiring-rotary-encoder-with-arduino-uno.png)


Pin Connection:

* GRD - GRD
* 5V - 5V
* SW - DPin 4
* DT - DPin 3
* CLK - DPin 2

Resource From: https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/

Using a 3D printer a frame is then printed out for the rotary encoder to next be screwed into
and the button being pushed over the top of the enocder. When fitting the rotary encode is can be
a bit of a tight fit and the washer is not used. It was also found by bending the little tab on the
encoder it allowed the locking nut to fit over the top and be tighted up.

![alt text](https://github.com/Zy0d0x0/HS2-Wheel/blob/main/Frame_Cura.JPG)


The Knob can be found here https://www.thingiverse.com/thing:2797118


# Software Setup

Download and Install Flip https://www.microchip.com/Developmenttools/ProductDetails/FLIP
This will later be used to flash the ardunio with a new firmware so when the ardunio is 
plugged into any device it should then load as USB Keyboard.

Connect the Ardunio and open up Device Manager, take note the Ardunio is currently
displaying as a COM port. While the Ardunio is currently connected and showing as a COM port
the `Main-Wheel.ino` needs to be put onto the Ardunio using what ever IDE you normaly use.

When the Ardunio has the `Main-Wheel.ino` onto its onboard memory. We need 
to put the ardunio in DFU mode this can by done by using a jumper pin or a small peice of wire
and shorting the 2 pins. 

![alt text](https://github.com/Zy0d0x0/HS2-Wheel/blob/main/dfu.JPG)

Resource from: https://www.arduino.cc/en/Hacking/DFUProgramming8U2


As displayed in the above screenshot when the pins have been shorted take another look at device manager it should
noted the Ardunio is not longer showing as a COM port and it may be missing its driver, If this is the case right click and then click update driver, 
select install driver from a local folder on the computer then navigate to `C:\Program Files (x86)\Atmel\Flip 3.4.7\usb`
then click update driver this should now install the required driver for Ardunio DFU mode so that FLIP can connect to it.

Open the FLIP tool and click on the button that looks like a chip and select ATmega16U2 in the dropdown menu then click the ok button to save the changes.

![alt text](https://github.com/Zy0d0x0/HS2-Wheel/blob/main/flipboardsettings.JPG)

Once the settings have been set for the Ardunio click the Connect Button next to the chip button prevoisuly pressed. It should be noticed at the bottom of the FLIP software
the connection will become established. 

![alt text](https://github.com/Zy0d0x0/HS2-Wheel/blob/main/flipboardconnect.JPG)

Then click the file button and load hex file. Select the `Arduino-keyboard-0.3.hex` file and click run. Once this has comleted click the start application button you should then hear the ardunio disconnect. Un plug the ardunio and plug it back in again to power cycle it.
Now you should see in device manager the device does not show as a COM port.
Open up notepad add some text then try using the wheel to navigate if all goes well on windows try pluggin in the wheel into the HS2 usb port on the rear of the radio.

Resource for most of the flashing meterials: https://www.youtube.com/watch?v=tvqA-JcTQNg

# Restore Ardunio

Returning the Ardunio to its normal state is possible by putting the ardunio into DFU mode once again with the jumper pin
then instead of selecting the `Arduino-keyboard-0.3.hex` file this time around you need to use the `Arduino-usbserial-atmega16u2-Uno-Rev3.hex`.

