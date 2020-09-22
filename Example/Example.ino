/*
  on Sep 22, 2020
  by MohammedDamirchi
  https://electropeak.com/learn/
*/

#include <Adafruit_Sensor.h>
#include "Adafruit_Si7021.h"
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bme; // I2C
Adafruit_Si7021 sensor = Adafruit_Si7021();



void setup() {
  Serial.begin(9600);
  bme.begin();
  sensor.begin();

}

void loop() {
  Serial.print("Temperature(bme): ");
  Serial.print(bme.readTemperature());
  Serial.print(" *C\t");

  Serial.print("Pressure: ");
  Serial.print(bme.readPressure()*0.00750062);
  Serial.print(" mmHg\t");

  Serial.print("Approx altitude: ");
  Serial.print(bme.readAltitude(1013.25)); // this should be adjusted to your local forcase
  Serial.print(" m\t");


  Serial.print("Humidity: ");
  Serial.print(sensor.readHumidity(), 2);
  Serial.print("\tTemperature(Si7021): ");
  Serial.println(sensor.readTemperature(), 2);
  delay(50);
}
