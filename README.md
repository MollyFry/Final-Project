# Final Project Museum Security System 

## System Behavior Description 
Molly Fry and Catie Amirault                                                                                                                                       

This is a security system designed for smaller budget museums to protect their precious items. Larger museums have intense, costly security systems, but smaller museums might not have the budget for that. So, our system is marketed towards museums that might not have the funding for intense security systems but still need something to protect their items. When all of the items are safe and no one is trying to steal them, a green light will be on and the display will show “no intruder”. There is also a light next to the items so that people can get a better look at the items if they need to. The light turns on and off through turning a dial. If someone tries to take the items the green light will turn off and a red light will turn on and the display will say “INTRUDER ALERT!”. When the system detects someone trying to steal the items a box will fall onto the display blocking it off. This way the intruder gets hit and can no longer access the items, keeping them safe.


## Project Behavior Table 

|Specification                                                                            |        Test Result          |         Comment
|------------------|-----------------------------|----------------------
| When no one is trying to touch the items the green LED is on and the display reads “no intruder”|         pass    |         
| distance sensor senses when someone's hand is near the items |         pass  |       
| When someone is trying to steal the item the red LED turns on, the alarm goes off, and the display reads “INTRUDER ALERT!”    | pass|                                                                      
| when intrusion is detected the motor runs and the box falls down | pass | 
| when the potentiometer is turned the LED next to the items turn on              | pass | 
| the alarm goes off when someone is trying to steal the item | fail | the alarm is always going off and we could not get it to only make a sound when the system detects something 

![image](https://github.com/user-attachments/assets/fa53f9bf-c518-4796-b5dc-363100e484fe)

