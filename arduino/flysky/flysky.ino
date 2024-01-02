#include <IBusBM.h>

IBusBM IBusServo;
IBusBM IBusSensor;

void setup() {
  Serial.begin(115200);

  IBusServo.begin(Serial);

  IBusSensor.begin(Serial2, 0, 15, 4);

  IBusSensor.addSensor(IBUSS_EXTV);
}

void loop() {
  for (int i=0; i<6 ; i++) {
    Serial.print(IBusServo.readChannel(i));
    Serial.print(" ");
  }
  Serial.println("");
  IBusSensor.setSensorMeasurement(1, 840);
  delay(500);
}