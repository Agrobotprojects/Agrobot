int i1=5,i2=6;
int e1=3;

void setup() 
{
pinMode(i1,OUTPUT);
pinMode(i2,OUTPUT);
pinMode(e1,OUTPUT);
}

void loop() 
{
analogWrite(e1,100);//speed control
digitalWrite(i1,HIGH); //rotation
digitalWrite(i2,LOW); //rotation
delay(2000);
//other direction
digitalWrite(i1,LOW);//rotation
digitalWrite(i2,HIGH);
delay(2000);
//stop
digitalWrite(i1,LOW);//rotation
digitalWrite(i2,LOW);
}
