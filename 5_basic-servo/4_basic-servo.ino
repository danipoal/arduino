#include <Servo.h>

int const potPin = A0;

int potVal;
int angle;
Servo myServo;

void setup()
{
  myServo.attach(9);    //Indica al servo que el pwm de voltage le entra x el 9
  Serial.begin(9600);
}

void loop()
{
  potVal = analogRead(potPin);
  /* map() Cambia escala de valores de 0 hasta 1023 a 0 hasta 179
   *       que seran valores útiles para el servo
   *          10 bits voltage -> 180 º angulo  
   */
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print("potVal: ");
  Serial.print(potVal);
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);   //El servo se mueve a la posicion indicada
  delay(15);
}