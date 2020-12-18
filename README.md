# HITLAB | Broomstick Controller  
Developed by Daniel Page  


<img src="setup.jpg" height="400">  


## Object Classes  


### LED  
**Constructor:** 
```
led name(pin, OUTPUT);  
```

#### Methods  
- `void on();`  
- `void off();`  

#### Variable  
- `int pinAdr;`  



### Button  
**Constructor:**  
```
button name(pin, INPUT_PULLUP);  
```

#### Methods  
- `void invert();`    
- `void poll();`  
- `bool getState();`    

#### Variable  
- `int pinAdr;`  



### Potentiometer  
**Constructor:**  
```
pot name(pin, INPUT, ADC bits, device voltage);  
```

#### Method  
- `float getVoltage();`  

#### Variable  
- `int pinAdr;`  



### Messenger  
```
msg name;
```

#### Method  
- `void init();`
- `void stageBut(int num, ...);`
- `void stagePot(int num, ...);`
- `void transmit();`

### Variable  
- `String messageString;`



## Variadic Functions  

### Active High <-> Active Low  
```
invertTrigger(number of addresses, &button1, &button2,...);  
```



### Update Button States  
Polling occurs before checking because the sending mechanism needs all of the information on states stored as variables to send it all at once.  
```
pollInputs(number of addresses, &button1, &button2,...);  
```
