# include <LiquidCrystal.h>
LiquidCrystal lcd(6,7,9,10,11,12);

int sensePin = A0;
float celsius;

void setup()
{
  pinMode(sensePin, INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop()
{
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  Serial.println(celsius);
  delay(500);
  lcd.print("Temperature is : ");
  lcd.setCursor(0,1);
  lcd.print(celsius);
  lcd.print(" C");
  delay(1000);
  lcd.clear();
}
