# Damper Dynamometer #

### Background ###
The damper dynamometer project was originally started by three Mechanical Engineer seniors as a capstone project.
I solely took on completing the capstone as part of the UW Formula Motorsports during my freshman year at the University
of Washington. Most of the capstone when I took on the project where there was an alumnium case, a plunger-type actuator,
a pneumatic solenoid to control the actuation, most of the sensor hardware to capture data, 
and working code to actuate the damper dynamometer.

### Description ###
The damper dynamometer (or damper dyno) is an existing physical system that is used to measure the damping coefficients
of automotive dampers. The damper dyno used an rod powered by pneumatics to actuate the damper and two sensors: a load cell
and linear potentiometer. Using the data from the load cell and linear potentiometer in a feedback loop, a force versus
velocity plot can be formed and interpolate the damping coefficient using the following equation:
```C = F/V```, where C is damping coefficient, F is the force exerted by the damper measured by the load cell,
and V is the velocity of the damper derived by position over time measured by the linear potientometer.


Using software, an Arduino microcontroller can be programmed to actuate the system, read in sensor data, and create a feedback
loop to control the actuation of the system more precisely to reach a constant velocity of 10 inches per second.
To actuate the system, the Arduino sends signals to open and close the supply and exhaust valves of a pnuematic solenoid
to retract and extend the plunger-type actuator.


The two sensors used was a 2000 lb LCM325 Futek load cell and a CLP-75 linear potentiometer with a 10-inch
actuation length. The load cell's readings were amplified using a Texense XN4 strain gauge amplifier. The microcontroller
used to read sensor input and control the damper system was a Arduino Uno with an onboard 10-bit analog-to-digital
converter.

### Project Goals ###
The goal of my contribution to completing the capstone is to improve the accuracy of the derived damping coefficient.
The state of the capstone when I took on the project had a +/- 10 lb accuracy for the automotive damper on an approximately
330 lb car which was unsatisfactory. The project goal was to achieve a +/- 1 lb accuracy or better.

### My Contributions ###
To improve the accuracy of the derived damping coefficient,
there needed to be a more accurate and precise method of data collection. 
To try to achieve this, I outfitted the Arduino Uno with a ARD-LTC2499 shield
which had a 24-bit analog-to-digital converter. 


To quickly derive the damping coefficient without building the entire force versus velocity curve, I needed to actuate the damper at a constant 10 inches/second.
Since the 80 psi of supplying air pressure to the pneumatic solenoid is greater than what was needed to actuate the damper and there needed to be a way to control the actuation speed,
I implemented multiple feedback algorithms to try regulate the actuation speed
while keeping in mind of the supply air pressure.


The first feedback algorithm I tried was pulse-width-modulation switching
to slightly open one of the valves to constrict the air pressure coming into the actuator.
The second feedback algorithm I tried was proportional-inverse-derivative control
which takes the speed of actuation as feedback to regulate the actuation speed.
The third and final feedback algorithm I tried was timed interrupts which was calibrated to achieve 10 inches/second.


Concurrently with finding the correct actuation algorithm, 
I designed and made a stabilizer bar for the damper dynamometer as during actuation,
there was a slight rotation of the damper.
This rotation skewed the measured data from the linear potentiometer as the measured displacement length slightly changes.

### Challenges I Faced ###
Due to the limited amount of any engineering experience I had during my freshman year,
I found understanding the documentation and reviewing design decisions difficult.
Understanding the entire system as a whole and debugging issues was my greatest challenge.
Having to deduce whether the issue is a mechanical problem, electrical problem, or software problem
and figuring out how to fix that problem became the main bulk of the project.
The collection of considering how the electronics measures the mechanics
and how the software translates the electrical signals into a digital form was proved to be just rewarding as it was difficult.


One core issue I found near the end of the project was that the load cell was rated to measure 2000 lb when the maximum force expected to be seen was 330 lb.
Since I was trying to accurately read less than 16.5% of the load cell's resolution, I was not getting the resolution desired for the project even with the strain gauge amplifier.


Another core issue I found was that the 24-bit analog-to-digital converter that I outfitted on the
Arduino microcontroller was the main performance bottleneck as it took several hundred clock cycles to translate one analog signal to a digital value.
