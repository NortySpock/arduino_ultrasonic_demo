# arduino_ultrasonic_demo

This is an ultrasonic rangefinder demo for the Arduino UNO, used to demo the sensor for use in FIRST Robotics FRC competitions.

So, after years of saying "Oh come on, how well do ultrasonic sensors work at a rock concert?", I realized I should probably test my assumptions rather than blather on about something I know nothing about.   

My research said the ultrasonic rangefinder worked at 40kHz, far beyond the range of human hearing (20kHz), and had a range of 3 or 4 meters   
Two things:    
    1) no normal speaker or music system is going to deliberately put out 40kHz if no one can hear it    
    2) so unless our opponents bring dog-whistles to competition we should be operating in a low-noise environment!   

So I bought an Arudino and an ultrasonic rangefinder and decided to test it out for myself.  

My tests showed that    
(A) it is possible to rig up an Arduino UNO to a 5 pin ultrasonic sensor (HC-SR05, $6 at Microcenter)  and calculate a distance measurement (I used centimeters), using just 50 lines of code   
(B) playing ACDC at maximum loudness on my computer had no obvious effect on the distance reported by the ultrasonic sensor, which showed the same amount of variation in distance as it had reported before.  

Conclusion: I was totally wrong, and we should try ultrasonic sensors on our robot to assist with close-in manuvering.   
Note: the speed of sound changes with temperature and air pressure   

Relevant links:   
https://www.robot-electronics.co.uk/htm/srf05tech.htm   
https://www.robot-electronics.co.uk/htm/sonar_faq.htm    
https://www.youtube.com/watch?v=6F1B_N6LuKw (48 minute long presentation on setting up and testing the ultrasonic sensor)   
https://hypertextbook.com/facts/2000/CheukWong.shtml  speed of sound (m/s) = 331.5 + 0.60 T(°C) (or 343 m/s at 20°C, room temp), so we can adjust for arena temperature   
https://www.vellemanusa.com/products/view/?id=528365 ultrasonic sensor product page, though I didn't find it very useful   
