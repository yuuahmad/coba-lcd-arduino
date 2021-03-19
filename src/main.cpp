#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();
}
void updateDisplay()
{
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
}

void loop()
{
  int nilai = analogRead(A0);
  nilai = map(nilai, 0, 1024, 0, 100);
  if (nilai >= 0 && nilai < 33)
  {
    lcd.setCursor(0, 0);
    lcd.print("ini satu                ");
    for (int i = 0; i < 20; i++)
    {
      lcd.setCursor(0, 1);
      lcd.print(i);
      delay(1000);
      lcd.setCursor(0, 1);
      lcd.print("                      ");
      int nilai = analogRead(A0);
      nilai = map(nilai, 0, 1024, 0, 100);
      if (nilai >= 33)
      {
        break;
      }
    }
  }
  else if (nilai >= 33 && nilai < 66)
  {
    lcd.setCursor(0, 0);
    lcd.print("halaman dua              ");
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("lainnya                  ");
  }
}