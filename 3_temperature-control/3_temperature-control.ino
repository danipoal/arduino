const int sensorPin = A0;
const float baselineTemp = 22.0;

/*
 * Indicamos los pines a usar
 * Serial begin -> Indica transmision placa - pc
 *  de transmision analogica 9600 bits/segundo
 */
void setup() {
  int pinNumber;
  
  Serial.begin(9600);
  pinNumber = 2;
  while(pinNumber < 5)
  {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
    pinNumber++;
  }
}

void loop() {
  int sensorVal;
  float voltage;
  float temperature;

  sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  /*
   * Convertimos el valor sensorVal de analogico a digital
   * SensorVal analogico devuelve un valor de 0 a 1023
   *  se convierte de 0 a 1 dividiendolo y luego se saca el 
   *  voltaje * 5.0 
   */
  voltage = (sensorVal / 1024.0) * 5.0;
  Serial.print(", volts: ");
  Serial.print(voltage);

  //Convertimos el voltage a temperatura
  temperature = (voltage - 0.5) * 100;
  Serial.print(", Grados ºC: ");
  Serial.println(temperature);

  //Funcionalidad leds segun temp
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);

  if (temperature < baselineTemp)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  if (temperature > baselineTemp)
    digitalWrite(2, HIGH);
  if (temperature > baselineTemp + 2)
    digitalWrite(3, HIGH);
  if (temperature > baselineTemp + 4)
    digitalWrite(4, HIGH);
  delay(1);
}
