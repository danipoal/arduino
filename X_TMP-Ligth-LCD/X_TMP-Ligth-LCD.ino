#include <LiquidCrystal.h>

#define TEMP_OFFSET 0.5

const int temp_AI = A0;
const int light_AI = A1;
const int lcd_register_select = 12;
const int lcd_enable = 11;
const int lcd_d4 = 5;
const int lcd_d5 = 4;
const int lcd_d6 = 3;
const int lcd_d7 = 2;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   // Definimos pines que estan conectados al LCD


void setup() {
  Serial.begin(9600); // Abrimos puerto para el monitor en serie del IDE
  lcd.begin(16, 2);   // Definimos filas y columnas del LCD

  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  int temp_sensor = analogRead(temp_AI);
  int ligth_sensor = analogRead(light_AI);


  Serial.print("Temperatura: ");
  Serial.println(temp_sensor);

  Serial.print("Light: ");
  Serial.println(ligth_sensor);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp_sensor);

  lcd.setCursor(0, 1);     // Lo siguiente que imprima sera en col 0, fila 1
  lcd.print("Ligth: ");
  lcd.print(ligth_sensor);

  delay(500);
}