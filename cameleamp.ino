const int RED = 11;
const int GREEN = 10;
const int BLUE = 9;
// the setup function runs once when you press reset or power the board
void setup()
{
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(RED, OUTPUT);
    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
    analogWrite(RED, 0);
    analogWrite(GREEN, 0);
    analogWrite(BLUE, 0);
}

// the loop function runs over and over again forever
void loop()
{
  for (size_t i = 0; i < 255; i++)
  {
    analogWrite(RED, i);
    delay(10);
  }
  for (size_t i = 0; i < 255; i++)
  {
    analogWrite(RED, 255 - i);
    delay(10);
  }
  for (size_t i = 0; i < 255; i++)
  {
    analogWrite(GREEN, i);
    delay(10);
  }
  for (size_t i = 0; i < 255; i++)
  {
    analogWrite(GREEN, 255 - i);
    delay(10);
  }
  for (size_t i = 0; i < 255; i++)
  {
    analogWrite(BLUE, i);
    delay(10);
  }
  for (size_t i = 0; i < 255; i++)
  {
    analogWrite(BLUE, 255 - i);
    delay(10);
  }
       
}
