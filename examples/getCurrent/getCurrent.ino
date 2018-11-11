#include <Tli4970.h>

// Tli4970 Object
Tli4970 Tli4970CurrentSensor = Tli4970();

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  while(!Serial);
  
  // Use default SPI for communication with the Tli4970 (no OCD pin is defined)
  Tli4970CurrentSensor.begin();
  // Use custom SPI
  // Tli4970CurrentSensor.begin(SPI2, (uint8_t)96u, (uint8_t)97u);
  // Set a OCD pin in addition to the begin() functions to enable it
  // Tli4970CurrentSensor.setPinOCD((uint8_t)8);
}

// the loop function runs over and over again forever
void loop() {
  if(Tli4970CurrentSensor.readOut())
  {
    Serial.print("FAIL: ");
    Serial.println(Tli4970CurrentSensor.getStatus());
  }
  else
  {
    Serial.print("Success: ");
    Serial.println(Tli4970CurrentSensor.getCurrent());
  }
  delay(500);
}