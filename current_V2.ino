// EmonLibrary examples openenergymonitor.org, Licence GNU GPL V3
// Current-V2
// 9-Mei-2023
// Laat  Gr / OR branden als stroom stijgt.

#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance

// Define Output indicators
#define Led_Green 2
#define Led_Orange 3
#define Led_Red 4


void setup()
{  
  Serial.begin(9600);
  
  emon1.current(1, 60);             // Current: input pin, calibration.

  pinMode (Led_Green, OUTPUT);
  pinMode (Led_Orange, OUTPUT);
  pinMode (Led_Red, OUTPUT);

  digitalWrite(Led_Green, 0);
  digitalWrite(Led_Orange, 0);
  digitalWrite(Led_Red, 0);
}

void loop()                                                                                                                                                             
{
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only
  
  //Serial.print(Irms*230.0);	       // Apparent power
  //Serial.print(" ");
  Serial.println(Irms);		       // Irms

  if (Irms <= 30) {
     digitalWrite(Led_Green, 1);
     digitalWrite(Led_Orange, 0);
     digitalWrite(Led_Red, 0);
  }
  else if ((Irms > 30) &&  (Irms <= 55)) {
        digitalWrite(Led_Green, 1);
        digitalWrite(Led_Orange, 1);
        digitalWrite(Led_Red, 0);
     }
  else if ((Irms > 55) &&  (Irms <= 100)) {
       digitalWrite(Led_Green, 1);
       digitalWrite(Led_Orange, 1);
       digitalWrite(Led_Red, 1);
      }
  
}
