This folder contains scripts I used to get the Artisan roaster scope coffee brewing software working with an Arduino in Windows  https://github.com/artisan-roaster-scope/artisan

1.  Install the Artisan software in windows
		*https://github.com/artisan-roaster-scope/artisan/releases/tag/v1.2.0
2.  Connect your LM35 Thermal sensor to the Arduino
		*Easy 3 wire connection for 5v, gnd, and analog
		*http://learningaboutelectronics.com/Articles/LM35-temperature-sensor-circuit.php
3.	Write your Arduino sketech to read temperature from the LM35
		*Had to browse around a bit to find one that had a reliable *F output
		*https://github.com/mttyd/Coffee/blob/master/Coffee_Temp_only/Coffee_Temp_only.ino
		*that sketch has been modified so that it only outputs the temperature
		*Make sure to test your sketch and note the COM port your Arduino is connected to.  You'll need it for your Python script.
		*Don't forget to load the script to your Arduino
4.  Next the Artisan software will not be able to read your data without a translator.  You can buy a board that is built for this function but I was impatient and just wanted to get a prototype working with parts I had on hand (Arduino and LM35)
		*In the Artisan software go to Config->Device  You'll pick the radio button at the bottom for "Prog"
		*The external program (first blank) will be the path to your python Script
5.  I haven't done much with Python in the past so this tutorial at adafruit was a HUGE help: https://learn.adafruit.com/arduino-lesson-17-email-sending-movement-detector/installing-python-and-pyserial
		*Read the tutorial first my general notes are below
		*First download and install Python and add the path to the python executable to Windows
		*You can get by without one but I also installed the PyScripter IDE for testing: https://sourceforge.net/projects/pyscripter/
		*In order to use serial communications (your Arduino)in Python you'll also need the pyserial library.
		*If you are doing this on windows you may need to run the command line install as Administrator to get it to work.
		*I used the following script in Artisan.  You can run it from the Python IDE to test it first or just roll the dice: https://github.com/mttyd/Coffee/blob/master/arduino_temp_read.py
6.  At this point you may have to change the axis values in Artisan so that you can see your temp (default cutoff is 100*)
		*Config->Axes  Change the min temperature axis to min 50 
7.  Hit Start and  you should see data coming from your Arduino.  I huffed some warm air on the sensor to make it change/test.
		
		
