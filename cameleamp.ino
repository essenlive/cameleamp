const int RED = 11;
const int GREEN = 10;
const int BLUE = 9;
const int S0 = 2;
const int S1 = 3;
const int S2 = 7;
const int S3 = 8;
const int sensorOut = 6;
//////////////////////////////////

// Stores frequency read by the photodiodes
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

void setup()
{
  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);

  // Setting frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  //LED Setup
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);

  // Begins serial communication
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop()
{
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  delay(100);
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);
  delay(100);
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);
  delay(100);

  // Printing the RED (R) value
  Serial.print("R = ");
  Serial.print(redFrequency);
  // Printing the GREEN (G) value
  Serial.print(" G = ");
  Serial.print(greenFrequency);
  // Printing the BLUE (B) value
  Serial.print(" B = ");
  Serial.println(blueFrequency);

  redColor = map(redFrequency, 60, 281, 255, 0);
  greenColor = map(greenFrequency, 70, 412, 255, 0);
  blueColor = map(blueFrequency, 70, 164, 255, 0);

  analogWrite(RED, redColor);
  analogWrite(GREEN, greenColor);
  analogWrite(BLUE, blueColor);
  delay(1000);
  // for (size_t i = 0; i < 255; i++)
  // {
  //   analogWrite(RED, i);
  //   delay(10);
  // }
  // for (size_t i = 0; i < 255; i++)
  // {
  //   analogWrite(RED, 255 - i);
  //   delay(10);
  // }
  // for (size_t i = 0; i < 255; i++)
  // {
  //   analogWrite(GREEN, i);
  //   delay(10);
  // }
  // for (size_t i = 0; i < 255; i++)
  // {
  //   analogWrite(GREEN, 255 - i);
  //   delay(10);
  // }
  // for (size_t i = 0; i < 255; i++)
  // {
  //   analogWrite(BLUE, i);
  //   delay(10);
  // }
  // for (size_t i = 0; i < 255; i++)
  // {
  //   analogWrite(BLUE, 255 - i);
  //   delay(10);
  // }
}
