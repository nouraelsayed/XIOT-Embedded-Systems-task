The aim of the project is to control the output pin using an input pin 
and send the status using serial communication (i used UART).
when the button is pressed the external interrupt will be enabled and pressed withon state will be sent using UART
on the other hand it can send the temperature sennsor reading via UART  each 3 sec using Timer0 .
-the first used function is "IO_Pins_Control" :
when the button is pressed the input pin will be connected
with VCC'5v' and led state will be on then our controller will send pressed and the state of the led
via UART ....
-the second used function is "serial_monitor" :
it takes a string and send it via UART with a rate "9600 bps "
-the third used function is "temp_sensor":
it takes reading from temperature sensor LM35 
HOW LM35 reads temp ?
acctually it reads volt each 10 mv = 1 0c 
we firstly read the value and convert it to a digital as we can deal with it
and by using this equation we can deduce the temp :
"temp=value on pin  of adc 5*100/1204"
- the last one is "Interrupt":
first of all it checks if there is an external interrupt if it existis ,it will be executed 
-then it will be check the interrupt caused by timer0 every 3 sec it will be executed.

Finally , i'm passionate about embedded systems embedded systems and i have a good knowleged in embedded systems 
C , Microcontrollers specially: PIC16F877A and ATMEGA 16 so i chose to implement the system using it
i'm trying to shift my career into embedded systems so i do all my best to improve my skills.
Thank you .....
