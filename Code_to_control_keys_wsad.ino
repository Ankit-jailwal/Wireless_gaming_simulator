uint8_t buf[8] = { 
  0 };   /* Keyboard report buffer */

#define PIN_W 5
#define PIN_S 6
#define PIN_A 7
#define PIN_D 4
int state = 1;

void setup() 
{
  Serial.begin(9600);
  pinMode(PIN_W, INPUT);
  pinMode(PIN_S, INPUT);
  pinMode(PIN_A, INPUT); 
  pinMode(PIN_D, INPUT);
  // enable internal pull-up
  digitalWrite(PIN_W, 1); 
  digitalWrite(PIN_S, 1); 
  digitalWrite(PIN_A, 1); 
  digitalWrite(PIN_D, 1); 

  delay(200);
}

void loop() 
{
  state = digitalRead(PIN_W);
  if (state != 1) {
    buf[2] = 26;   // W key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_S);
  if (state != 1) {
    buf[2] = 22;   // S KEY
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_A);
  if (state != 1) {
    buf[2] = 4;   // A KEY
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 
  state = digitalRead(PIN_D);
  if (state != 1) {
    buf[2] = 7;   // D KEY
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key  
}
