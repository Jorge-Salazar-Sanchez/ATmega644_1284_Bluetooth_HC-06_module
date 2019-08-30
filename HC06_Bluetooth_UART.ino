//The goal is to use the HC-06 module for controlling Arduino via Bluetooth communication
//sending text commands from the the HC-06 module, and also sending text from the Arduino back to the the HC-06 module.
//In this example, the code uses the two UART's available in the Atmega644p and 1284p.


void setup() {
  // Initialize Serial Ports (UART's)
  
  Serial.begin(9600);    // Serial Port 0 
  Serial1.begin(9600);   // Serial Port 1
}

byte rx_byte = 0;        // Variable used to store received byte


void loop() {

  // Check for data byte on Serial Port 0
  if (Serial.available()) {
  
    // Get byte from Serial Port 0
     rx_byte = Serial.read();
    
    // Send byte to Serial Port 1
    Serial1.write(rx_byte);
  }
  
   // Check for data byte on Serial Port 1  
  if (Serial1.available()) {
   
    // Get a byte from Serial Port 1 
    rx_byte = Serial1.read();
    
    // Send the byte to the Serial Port 0
    Serial.write(rx_byte);
  }
}
 

