int ledPinRED = 2;
int ledPinYEL = 1;
int ledPinGRE = 0;

int sensorLuzPin = A0;
int val;
int valAtual = 0;

int buzzer = 8;

#include <LiquidCrystal.h>
LiquidCrystal lcd1(12, 11, 10, 6, 5, 4, 3);

void setup()
{
  pinMode(ledPinRED, OUTPUT);
  pinMode(ledPinYEL, OUTPUT);
  pinMode(ledPinGRE, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  lcd1.begin(16, 2);
  lcd1.clear();
  lcd1.setCursor(0, 0);
}

void loop()
{
  
   	
  	val = analogRead(sensorLuzPin); 
  	int luz = map(val, 54 , 974, 0, 100);
  	Serial.println(luz);    
    
  	if (valAtual != val) {
      	noTone(buzzer);
      	lcd1.clear();
    	lcd1.display();
      	if (luz > 0 && luz <= 32) { // requisito 1
          	lcd1.clear();
          	digitalWrite(ledPinRED, LOW);	
            digitalWrite(ledPinYEL, LOW);
      		digitalWrite(ledPinGRE, HIGH);	
        } else if (luz > 32 && luz <= 35) { // requisito 2
            lcd1.print("Ambiente a meia");
            lcd1.setCursor(0, 1);
            lcd1.print("luz");
          	digitalWrite(ledPinRED, LOW);	
            digitalWrite(ledPinYEL, HIGH);
            digitalWrite(ledPinGRE, LOW);
            lcd1.setCursor(0, 0);
        } else { // requisito 3
            lcd1.print("Ambiente CLARO"); 
          	digitalWrite(ledPinRED, HIGH);	
            digitalWrite(ledPinYEL, LOW);	
            digitalWrite(ledPinGRE, LOW);	
          	tone(buzzer, 500); // requisito 4
        }
      }
	
  	valAtual = val;
  	delay(1000);
}