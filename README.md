# Damper Dynamometer #

### History ###
The damper dynamometer project was originally started by three Mechanical Engineers seniors as a capstone project.
The project was not brought to its' full completion as a capstone and was handed to me through the UW Formula Motorsports
team I was part of. Due to limited access to information about this project and limited experience in engineering projects,
I rewrote/revised the original code I was given multiple times into the version seen now.
This project as a whole was my introduction to mechanical engineering, electrical engineering, and programming.

### Description ###
The damper dynamometer (damper dyno for short) is an existing physical system that is used to measure the damping coefficients
of automotive dampers. The damper dyno used two sensors, a load cell and linear potientometer,
to build a force versus velocity curve used to interpolate the damping coefficients.
An arduino collected the data from the sensors and sent the information through the Serial line for post-processing.
Post-processing techniques includes using Python's live graph feature which data was read through the Serial line.
The Arduino was outfitted a 24bit ADC shield that had its' own library to come with.
The load cell was a Futek load cell able to measures loads up to 2kN.
