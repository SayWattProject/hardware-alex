// EmonLibrary examples openenergymonitor.org, Licence GNU GPL V3

#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance


void setup() {  
  Serial.begin(9600);
  emon1.current(5, 20);             // Current: input pin, calibration.
}

void loop() {
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only
  Serial.print(Irms*120.0/sqrt(2));	       // Apparent power
  Serial.print(" ");
  Serial.println(Irms);		       // Irms
  delay(100);
}
