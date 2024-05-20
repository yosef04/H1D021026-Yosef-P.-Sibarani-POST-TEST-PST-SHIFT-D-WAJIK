#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Servo myServo;

LiquidCrystal_I2C lcd(0x27, 16, 2);
int SDA_pin = D6;
int SCL_pin = D7;

void setup()
{
    myServo.attach(D0);

    Wire.begin(SDA_pin, SCL_pin);

    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
}

void loop()
{
    myServo.write(180);
    lcd.clear();
    lcd.print("TERBUKA");
    delay(5000);

    myServo.write(0);
    lcd.clear();
    lcd.print("TERTUTUP");
    delay(5000);
}