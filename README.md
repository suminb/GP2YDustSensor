# Sharp GP2Y* Dust Sensor library

Arduino compatible (ESP8266, ESP32, etc) library for the Sharp GP2Y dust sensors:
- GP2Y1010AU0F
- GP2Y1014AU0F

**Features:**
- multi-reading average
- running average
- runtime calibration
- sensitivity setting
- offset adjustment (zero dust value)

**Example:**

```c++
#include <GP2YDustSensor.h>

const uint8_t SHARP_LED_PIN = 14;   // Sharp Dust/particle sensor Led Pin
const uint8_t SHARP_VO_PIN = A0;    // Sharp Dust/particle analog out pin used for reading 

GP2YDustSensor dustSensor(GP2YDustSensorType::GP2Y1014AU0F, SHARP_LED_PIN, SHARP_VO_PIN);

void setup() {
  Serial.begin(9600);
  //dustSensor.setBaseline(0.4); // set no dust voltage according to your own experiments
  //dustSensor.setCalibrationFactor(1.1); // calibrate against precision instrument
  dustSensor.begin();
}

void loop() {
  Serial.print("Dust density: ");
  Serial.print(dustSensor.getDustDensity());
  Serial.print(" ug/m3; Running average: ");
  Serial.print(dustSensor.getRunningAverage());
  Serial.println(" ug/m3");
  delay(1000);
}
```
