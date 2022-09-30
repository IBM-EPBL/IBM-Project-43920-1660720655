float aReading;
float tDigital;
float tCelcius;
int piezo = 8;
int led = 13;
int dcMotor = 12;
int tempSensor = A0;
void setup()
{
  Serial.begin(9600);
  pinMode(dcMotor, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(tempSensor,INPUT);
}

void loop()
{ 
  aReading = analogRead(A0);
  tDigital = aReading*5.0/1023.0;
  tCelcius = (tDigital-0.5)*100;
  Serial.println("Temp value:"+String(tCelcius)+"C");
  if(tCelcius>24)
  {
    noTone(piezo);
    digitalWrite(led,HIGH);
    digitalWrite(dcMotor,HIGH);
  }
  else if(tCelcius<16)
  {
    tone(piezo,158);
  	digitalWrite(led,LOW);
    digitalWrite(dcMotor,LOW);
  }
  else
  {
    noTone(piezo);
  	digitalWrite(led,LOW);
    digitalWrite(dcMotor,LOW);
  } 
  delay(1000); 
}