// C++ code
//
#define moistureSensor A0
#define luminositySensor A2
#define waterPump A4
#define lamp 12

void setup()
{
  pinMode(lamp, OUTPUT);
  pinMode(waterPump, OUTPUT);
  
  pinMode(moistureSensor, INPUT);
  pinMode(luminositySensor, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Debut des mesures");
  int moisture_value = analogRead(moistureSensor);
  int luminosity_value = analogRead(luminositySensor);
  Serial.println((String)"  - Humidite du sol : " + moisture_value);
  Serial.println((String)"  - Luminosite : " + luminosity_value);
  Serial.println("\n\n");
  
  if (luminosity_value > 500){
    Serial.println("User activate the lamp");
    digitalWrite(lamp, HIGH);
  }else{
    digitalWrite(lamp, LOW);
  }
  
  if (moisture_value > 0 && moisture_value < 500){
    digitalWrite(waterPump,HIGH);
    delay(2000);
    digitalWrite(waterPump,LOW);
  }
  else
  {
    digitalWrite(waterPump,LOW);
  }
  
  delay(1000); // Wait for 1000 millisecond(s)

  
}