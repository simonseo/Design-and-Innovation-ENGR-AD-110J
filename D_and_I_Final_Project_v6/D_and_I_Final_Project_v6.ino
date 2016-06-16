/*
  EMOTION OF THE OCEAN
*/

int redPin = 10;
int greenPin = 9;
int bluePin = 6;

// decide later whether the pin will be analogue or digital
int sensorPin1 = A0;
int sensorPin2 = A1;
int sensorPin3 = A2;
int sensorPin4 = A3;
int sensorPin5 = A4;

int sensorValue;        // value read from the sensor
int outputValue1;        // value output to the PWM (analog out)
int outputValue2;
int outputValue3;
int outputValue4;
int outputValue5;
float emotionIndex;

int lastprinted = 0;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  //  pinMode(sensorPin1, OUTPUT);
  //  pinMode(sensorPin2, OUTPUT);
  //  pinMode(sensorPin3, OUTPUT);
  //  pinMode(sensorPin4, OUTPUT);
  //  pinMode(sensorPin5, OUTPUT);
  Serial.begin(9600);

  //  for (int i = A0; i < A5; i++) {
  //    pinMode(i, INPUT_PULLUP);
  //  }
}

void loop()
{ // Sensor 1
  // read the analog in value:
  sensorValue = analogRead(sensorPin1);
//  Serial.print("Sensor1:\t");
//  Serial.println(sensorValue);
  // map it to the range of the analog out:
  outputValue1 = map(sensorValue, 0, 1023, 0, 100);

  // Need to find the upper and lower bound of the sensors and then use the constrain function.
//  Serial.print("Mapped OutputValue1:\t");
//  Serial.println(outputValue1);
  // Need to calibrate or check the sensor and get the average value. The average value should be set to 50. If high, then >50. If low, then <50.

  // Sensor 2
  // read the analog in value:
  sensorValue = analogRead(sensorPin2);
//  Serial.print("Sensor2:\t");
//  Serial.println(sensorValue);
  // map it to the range of the analog out:
  outputValue2 = map(sensorValue, 0, 1023, 0, 100);
//  Serial.print("Mapped OutputValue2:\t");
//  Serial.println(outputValue2);
  // Need to calibrate or check the sensor and get the average value. The average value should be set to 50. If high, then >50. If low, then <50.


  // Sensor 3
  // read the analog in value:
  sensorValue = analogRead(sensorPin3);
  // map it to the range of the analog out:
//  Serial.print("Sensor3:\t");
//  Serial.println(sensorValue);
  outputValue3 = map(sensorValue, 0, 1023, 0, 100);
//  Serial.print("Mapped OutputValue3:\t");
//  Serial.println(outputValue3);

  // Need to calibrate or check the sensor and get the average value. The average value should be set to 50. If high, then >50. If low, then <50.


  // Sensor 4
  // read the analog in value:
  sensorValue = analogRead(sensorPin4);
  //  Serial.print("Sensor4:\t");
  //  Serial.println(sensorValue);
  // map it to the range of the analog out:
  outputValue4 = map(sensorValue, 0, 1023, 0, 100);

  // Need to calibrate or check the sensor and get the average value. The average value should be set to 50. If high, then >50. If low, then <50.

  // Sensor 5
  // read the analog in value:
  sensorValue = analogRead(sensorPin5);
  // map it to the range of the analog out:
  //  Serial.print("  Sensor5:\t");
  //  Serial.print(sensorValue);

  float voltage = sensorValue * 5.0;
  voltage /= 1024.0;
  float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset

  outputValue5 = map(temperatureC, 26, 32, 0, 100);
// Below printing is important.
//  Serial.print("Mapped s1: ");
//  Serial.print(outputValue1);
//  Serial.print("  Mapped s2: ");
//  Serial.print(outputValue2);
//  Serial.print("  Mapped s3: ");
//  Serial.print(outputValue3);
//  Serial.print("  Mapped s4: ");
//  Serial.print(outputValue4);
//  Serial.print("  Mapped s5: ");
//  Serial.print(outputValue5);
//  Serial.println();

  // Need to calibrate or check the sensor and get the average value. The average value should be set to 50. If high, then >50. If low, then <50.

  //---------- EMOTION INDEX CALCULATION -------------------------------

  // Percentage Weitages.They are in order. Amplitude(30%), Salinity(5%), Pollution(20%), Temperature(20%),DO(25%). Only DO is postive rest are negative.

  emotionIndex = ((100 - outputValue1) * 0.30 + (100 - outputValue2) * 0.05 + (100 - outputValue3) * 0.20 + (outputValue1) * 0.25 + (100 - outputValue1) * 0.20) / 100;
// Below printing is important.
//  Serial.println("Current EMOTION INDEX");
//  Serial.println(emotionIndex);

  // Angry
  if (emotionIndex >= 0 && emotionIndex < 0.2) {
    setColor(255, 0, 0);  // red
    if(lastprinted != 0) Serial.println(0);
    lastprinted = 0;
  }
  // Sad
  else if (emotionIndex >= 0.2 && emotionIndex < 0.3) {
    setColor(122, 114, 114);  // gray
    if(lastprinted != 1) Serial.println(1);
    lastprinted = 1;
  }
  // Calm
  else if (emotionIndex >= 0.3 && emotionIndex < 0.45) {
    setColor(0, 0, 255); // blue
    if(lastprinted != 2) Serial.println(2);
    lastprinted = 2;
  }
  // Happy
  else if (emotionIndex >= 0.45 && emotionIndex < 0.7) {
    setColor(255, 255, 0); // Yellow
    if(lastprinted != 3) Serial.println(3);
    lastprinted = 3;
  }
  // in Love
  else if (emotionIndex >= 0.7 && emotionIndex < 1) {
    setColor(249, 30, 234); // Pink
    if(lastprinted != 4) Serial.println(4);
    lastprinted = 4;
  }

}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
