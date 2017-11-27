// EmonLibrary examples openenergymonitor.org, Licence GNU GPL V3

#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance

#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {  
  Serial.begin(9600);
  emon1.current(4, 20);             // Current: input pin, calibration.

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");

}

void loop() {
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only
  Serial.print(Irms*120.0/sqrt(2));	       // Apparent power
  Serial.print(" ");
  Serial.println(Irms);		       // Irms
  mySerial.print(Irms*120.0/sqrt(2));
  mySerial.print(" W, ");
  mySerial.print(Irms);
  mySerial.println(" A");
  delay(100);
}
