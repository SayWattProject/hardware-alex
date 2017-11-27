// EmonLibrary examples openenergymonitor.org, Licence GNU GPL V3

#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance
EnergyMonitor emon2;                   // Create an instance
EnergyMonitor emon3;                   // Create an instance

void setup() {  
  Serial.begin(9600);
  emon1.current(5, 20);             // Current: input pin, calibration.
  emon2.current(4, 20);             // Current: input pin, calibration.
  emon3.current(3, 20);             // Current: input pin, calibration.
}

void loop() {
  double Irms1 = emon1.calcIrms(1480);  // Calculate Irms only
  Serial.print("1 ");
  Serial.println(Irms1*120.0/sqrt(2));	       // Apparent power
  double Irms2 = emon2.calcIrms(1480);  // Calculate Irms only
  Serial.print("2 ");
  Serial.println(Irms2*120.0/sqrt(2));         // Apparent power
  double Irms3 = emon3.calcIrms(1480);  // Calculate Irms only
  Serial.print("3 ");
  Serial.println(Irms3*120.0/sqrt(2));         // Apparent power
//  Serial.print(" ");
//  Serial.println(Irms);		       // Irms
  delay(1000);
}
