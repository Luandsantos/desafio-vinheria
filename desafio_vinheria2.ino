const int analogIn = A0;
int umidade = 0;
int umidadeAtual = 0;
int volt = 0;
int voltAtual = 0;
double Voltage = 0;
double temp = 0;
double tempAtual = 0;

int ledPinRED2 = 2;
int ledPinYEL2 = 1;
int ledPinGRE2 = 0;

int buzzer = A2;


#include <LiquidCrystal.h>
LiquidCrystal lcd2(12, 11, 10, 6, 5, 4, 3); // temperatura
LiquidCrystal lcd3(13, 9, 8, 7, A3, A4, A5); // umidade

void setup(){  
  	pinMode(A1, INPUT);
    pinMode(ledPinRED2, OUTPUT);
    pinMode(ledPinYEL2, OUTPUT);
  	pinMode(ledPinGRE2, OUTPUT);
  	pinMode(buzzer, OUTPUT);
  
  
  	lcd2.begin(16, 2);
	lcd2.clear();
  	lcd2.setCursor(0, 0);
  
  	lcd3.begin(16, 2);
  	lcd3.clear();
  	lcd3.setCursor(0, 0);
  	lcd3.print("Oi");
}

void loop(){
  
  
  	temp = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);

   	//volt = analogRead(analogIn);
  	//Voltage = (volt / 1023.0) * 5000; 
  	//temp = (Voltage-500) * 0.1;
  
  	umidade = analogRead(A1);
  
  	int umidadeLida = map(umidade, 0, 1023, 10, 90);
    	
   	if (tempAtual != temp) { // temperatura
      	noTone(buzzer);
      	lcd2.clear();
    	lcd2.display();
      	if (temp >= 10 && temp <= 15) { // requisito 5
        	lcd2.print("Temp. OK");
          	lcd2.setCursor(0, 1);
          	lcd2.print("Temp. = ");
          	lcd2.print(temp);
          	lcd2.print("C");
          	lcd2.setCursor(0, 0);
          	digitalWrite(ledPinYEL2, LOW);
        } else if (temp > 15) { // requisito 9
			lcd2.print("Temp. ALTA");
          	lcd2.setCursor(0, 1);
          	lcd2.print("Temp. = ");
          	lcd2.print(temp);
          	lcd2.print("C");
          	lcd2.setCursor(0, 0);
            digitalWrite(ledPinYEL2, HIGH); // requisito 8	
            tone(buzzer, 300); 
        } else {
        	lcd2.print("Temp. BAIXA"); // requisito 10
          	lcd2.setCursor(0, 1);
          	lcd2.print("Temp. = ");
          	lcd2.print(temp);
          	lcd2.print("C");
          	lcd2.setCursor(0, 0);
            digitalWrite(ledPinYEL2, HIGH);	// requisito 8
            tone(buzzer, 400);
        }
	}
  
  	if (umidadeAtual != umidadeLida) {
		lcd3.clear();
      	lcd3.display();
		if (umidadeLida >= 50 && umidadeLida <= 70) { // requisito 6
        	lcd3.print("Umidade OK");
          	lcd3.setCursor(0, 1);
          	lcd3.print("Umidade = ");
          	lcd3.print(umidadeLida);
          	lcd3.print("%");
          	lcd3.setCursor(0, 0);
          	digitalWrite(ledPinRED2, LOW);
        } else if (umidadeLida >= 70) { // requisito 12
        	lcd3.print("Umidade ALTA");
          	lcd3.setCursor(0, 1);
          	lcd3.print("Umidade = ");
          	lcd3.print(umidadeLida);
          	lcd3.print("%");
          	lcd3.setCursor(0, 0);
            digitalWrite(ledPinRED2, HIGH); // requisito 11
        } else { // requisito 13
            lcd3.print("Umidade BAIXA");
          	lcd3.setCursor(0, 1);
          	lcd3.print("Umidade = ");
          	lcd3.print(umidadeLida);
          	lcd3.print("%");
          	lcd3.setCursor(0, 0);
           	digitalWrite(ledPinRED2, HIGH); // requisito 11
        }
    }
    
	tempAtual = temp;
	//voltAtual =  volt;
  	umidadeAtual = umidadeLida;
  	delay(1000);  //iterate every 5 seconds

}