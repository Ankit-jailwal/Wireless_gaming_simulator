uint8_t buf[8] = { 
  0 };   /* Keyboard report buffer */

#define PIN_W 7
#define PIN_S 8


int state1 = 1,state2=1;
int led=13;

void setup() 
{
  Serial.begin(9600);
  pinMode(PIN_W, INPUT);
  pinMode(PIN_S, INPUT);
  digitalWrite(PIN_W, 1); 
  digitalWrite(PIN_S, 1);
  pinMode(led,OUTPUT); 
  delay(100);
}

void loop() 
{
  state1 = digitalRead(PIN_W);
  if (state1 == 0) {
    digitalWrite(led,HIGH);
    buf[2] = 26;   // W key
    Serial.write(buf, 8); // Send keypre
    releaseKey();
  } 

  state2 = digitalRead(PIN_S);
  if (state2 == 0) {
    digitalWrite(led,HIGH);
    buf[2] = 22;   // S KEY
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  }
 else
   {digitalWrite(led,LOW);
   } 
  

}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key  
}
