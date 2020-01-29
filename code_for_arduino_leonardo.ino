int led=13;
int sensorpin1=7;
int sensorpin2=8;

void setup(){
 
   pinMode(led,OUTPUT);
   pinMode(sensorpin1,INPUT_PULLUP);
   pinMode(sensorpin2,INPUT_PULLUP);
   Keyboard.begin();
   

}

void loop()
{

int value1=digitalRead(sensorpin1);
int value2=digitalRead(sensorpin2);
  if(value1==1)
   {digitalWrite(led,HIGH);
    Keyboard.write(65);
    } 
  else if(value2==1)
  {digitalWrite(led,HIGH);
    Keyboard.write(66);
  } 
  else
   {digitalWrite(led,LOW);
    }
  
delay(50);
}
