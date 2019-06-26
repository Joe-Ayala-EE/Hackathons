#include <dht.h>
#include <LiquidCrystal.h>

dht DHT;

LiquidCrystal lcd(12,11,5,4,3,2) ;

#define DHT11_PIN 7
int Fan = 6; // Tie the led to pin 6
int SensorValue = 7;
int safeTemp = 30;
int redLed = 8 ;

void setup(){
  lcd.begin (16,2);
  lcd.print ("Smart Tank v1.0");
  Serial.begin(9600);
  pinMode(SensorValue, INPUT); //set the button pin as INPUT
  pinMode(Fan, OUTPUT); //set the Fan pin as OUTPUT
  pinMode(redLed, OUTPUT);
  
}

void loop()
{
  
  int chk = DHT.read11(DHT11_PIN);
  
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(1000);
  
  Serial.print("Temperature in Degrees Celsius = ");
  Serial.println(DHT.temperature);
  Serial.print("Percent Humidity = ");
  Serial.println(DHT.humidity);


  
    //Read the state of sensor
  if (safeTemp <= DHT.temperature )
  {
    digitalWrite(Fan, HIGH); //Turn on the fan to cool the water 
    digitalWrite(redLed, HIGH);
    
  }
  else
  {
    digitalWrite(Fan, LOW);
    digitalWrite(redLed, LOW);
    }
delay(1000);
  
}
