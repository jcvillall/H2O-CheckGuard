#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo valvula;

// Pines
#define POT A0
#define LED_VERDE 2
#define LED_AMARILLO 3
#define LED_ROJO 4
#define BUZZER 5
#define SERVO_PIN 6

int valor = 0;

void setup() {

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  valvula.attach(SERVO_PIN);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("H2O CheckGuard");

  delay(2000);
}

void loop() {

  valor = analogRead(POT);

  lcd.clear();

  // NORMAL
  if(valor < 400){

    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO, LOW);

    noTone(BUZZER);

    valvula.write(0);

    lcd.setCursor(0,0);
    lcd.print("Estado NORMAL");

    lcd.setCursor(0,1);
    lcd.print("Flujo Bajo");
  }

  // CONSUMO ALTO
  else if(valor >= 400 && valor < 700){

    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARILLO, HIGH);
    digitalWrite(LED_ROJO, LOW);

    noTone(BUZZER);

    valvula.write(0);

    lcd.setCursor(0,0);
    lcd.print("Consumo Alto");

    lcd.setCursor(0,1);
    lcd.print("Monitoreando");
  }

  // FUGA
  else{

    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO, HIGH);

    tone(BUZZER, 1000);

    valvula.write(90);

    lcd.setCursor(0,0);
    lcd.print("!!! FUGA !!!");

    lcd.setCursor(0,1);
    lcd.print("Valvula OFF");
  }

  delay(500);
}
