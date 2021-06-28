#include <Wire.h>

 
const int trigpin=11;
const int echopin=12;

long duration;
int distance;
int jarak=0;
 
int pinSensor = A0;
 
//Variabel data
float tegangan; //data untuk tegangan
float ntu; //data untuk nilai pembacaan satuan sensor kekeruhan
 
void setup(){
 pinMode(trigpin, OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);
}
 
void loop()
{
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  duration=pulseIn(echopin,HIGH);
  jarak=duration*(0.034/2);
 // for(int i=0;i<100;i++)
  {
  //jarak=jarak+distance;
  }
  //jarak=jarak/100;
  if(jarak<=15)
  {
    jarak=jarak+1;
  }
  else if(jarak<=39)
  {
    jarak=jarak+2;
  }
  else
  {
    jarak=jarak+3;
  }
  Serial.println(jarak);
    tegangan = 00;
    for(int i=00; i<800; i++)
    {
        tegangan += ((float)analogRead(pinSensor)/1023)*5;
    }
    tegangan = tegangan/800;
    tegangan = round_to_dp(tegangan,1);
 if(tegangan>=3.30)
 {
  Serial.println(tegangan);
  Serial.println("Bersih");
  delay(1000);
 }
 else if(tegangan>3.00)
  {
    Serial.println(tegangan);
  Serial.println("Kotor");
  delay(1000);
  }
 else if(tegangan<3.00)
 {
  Serial.println(tegangan);
  Serial.println("Sangat Kotor");
  delay(1000);
 }
}
 
float round_to_dp( float nilaibaca, int desimal)
{
  float multiplier = powf( 10.0f, desimal );
  nilaibaca = roundf( nilaibaca * multiplier ) / multiplier;
  return nilaibaca;
}
 
