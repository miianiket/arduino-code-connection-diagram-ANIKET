\\VCC IS CONNECT TO UNO 5V
\\GND IS CONNECT TO GND 
\\DATA PIN CONNECT TO D8
\\DATA PIN AND VCC IN BETWEEN CONNECT 1K OHM RESISTAN 
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 8 //conection  of data pin to D8
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float Celsius = 0;
float Fahrenheit = 0;
void setup() {
  sensors.begin();
  Serial.begin(9600);
}
void loop() {
  sensors.requestTemperatures();
  Celsius = sensors.getTempCByIndex(0);
  Fahrenheit = sensors.toFahrenheit(Celsius);
  Serial.print(Celsius);
  Serial.print(" C  ");
  Serial.print(Fahrenheit);
  Serial.println(" F");
  delay(1000);
}
