# HS2-Wheel By M7SYN

![alt text](https://github.com/Zy0d0x0/HS2-Wheel/blob/main/wheel-built.jpg)


Download and Install Flip https://www.microchip.com/Developmenttools/ProductDetails/FLIP
Flip will later be used to flash the ardunio with a new firmware so when the ardunio is 
plugged into any device it should then load as USB Keyboard.

Connect the ardunio and open up device manager, you should notice the ardunio is currently
displaying as a COM port. While the ardunio is currently connected and showing as a COM port
you should flash the Main-Wheel.ino sketch onto the ardunio ready.

Once the ardunio has the keyboard sketched flashed onto its onboard memory. We need
to put the ardunio in DFU mode this can by done by using jumper pin or a small wire
and shorting the 2 pins. 

![alt text](https://github.com/Zy0d0x0/HS2-Wheel/blob/main/dfu.JPG)

Resource from: https://www.arduino.cc/en/Hacking/DFUProgramming8U2


When the pins have been shorted take another look at device manager you should
notice the ardunio is not longer showing as a COM port and it may be missing 
its driver if this is the case right click and click update driver then select
from a directory locally on the computer then navigate to C:\Program Files (x86)\Atmel\Flip 3.4.7\usb
and click update driver this should now install the required driver for FLIP to connect to.

Open the FLIP tool and click on the button that looks like a chip and select ATmega16U2 then click ok to save. Once the settings have been set for the ardunion click the connect button. at the bottom of the window you should see that it has connect. Then click the file button and load hex file. Select the Arduino-keyboard-0.3.hex file and click run. Once this has comleted click the start application button you should then hear the ardunio disconnect. Un plug the ardunio and plug it back in again to power cycle it.
Now you should see in device manager the device does not show as a COM port.
Open up notepad add some text then try using the wheel to navigate if all goes well on windows try pluggin in the wheel into the HS2 usb port on the rear of the radio.



Returning To Normal

if you would like to return the ardunio back to its normal state use the Flip tool once again but this time select 
the Arduino-usbserial-atmega16u2-Uno-Rev3.hex.
