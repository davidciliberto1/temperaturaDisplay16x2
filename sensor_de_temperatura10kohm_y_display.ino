#include <LiquidCrystal.h>

#include <math.h>
LiquidCrystal lcd(7,6,5,4,3,2); 
int rele = 8;
 
void setup()
{           
  pinMode(8, OUTPUT);
  digitalWrite(rele, LOW);
  lcd.begin(16, 2); 
  Serial.begin(9600);  
} 

void loop() 
{             
  
    lcd.setCursor(0,0);

  int val;
  double temp;
  val = analogRead(0);
  temp = log(((10240000/val) - 10000));
  temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp ))* temp );
  temp = temp - 273.15;
  Serial.print(temp);
  Serial.println("°C");
       lcd.print(temp);
           lcd.setCursor(6, 0);
       lcd.print("C");


  delay(1000);
if(temp < 27) {
  digitalWrite(rele, LOW);
  delay(1000);
}
else {
  digitalWrite(rele, HIGH);
  delay(1000);
}

}
