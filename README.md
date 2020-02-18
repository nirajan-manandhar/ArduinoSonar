# ArudioSonar
Making a Sonar system, controlled with an Arduino

Components: 
1. Arduino Uno
2. Ultrasonic Sensor (Ultrasonic Sensor HC-SR04)
3. Stepper Motor (28BYJ-48)

There are two files.
One Processing file, and one Arudino file. They communicate through serial communication.

I have used code from other developer's projects:

1. For the processing code, which controls the graphics: 
https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing/all
2. For the Arduino code, which controls the stepper motor: https://github.com/tyhenry/CheapStepper/blob/master/examples/cheapStepper_simple/cheapStepper_simple.ino

[Will post schematic later]

I have modified the code from both these sources to work with my components.
The biggest changes are using a stepper motor instead of a servo motor, because that is what I happened to have on-hand, and using custom stepper motor code rather than the built-in stepper library.

Although there is an Arduino library for stepper motors, I had troubles with getting clockWise rotation using the library's built-in functions. Link #2 was a solution that I found to work great with my stepper motor, and it was one of the most  easy-to-understand solutions that I found.

