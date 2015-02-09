# IoT Marshmallow Cannon

The .ino code required to control the 2lemetry IoT Marshmallow cannon. One Arduino is required for each of the three cannon elements:

- Heading (rotation of the barrel)
- Pitch (angle of the barrel relative to the ground)
- Trigger (to fire the cannon and launch the marshmallow)

For each Heading and Pitch control Arduino, a Motor Header is required to drive the 1.8 deg/step, 0.33A_max stepper motors.
