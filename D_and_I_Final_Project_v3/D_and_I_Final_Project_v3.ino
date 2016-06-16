/*
  RGB LED
*/

int redPin = 10;
int greenPin = 9;
int bluePin = 6;

// decide later whether the pin will be analogue or digital
int sensorPin1 = A0;
int sensorPin2 = A1;
int sensorPin3 = A2;
int sensorPin4 = A3;
int sensorPin5 = A5;

int sensorValue;        // value read from the sensor
int outputValue1;        // value output to the PWM (analog out)
int outputValue2;
int outputValue3;
int outputValue4;
int outputValue5;
float emotionIndex;
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(sensorPin1, OUTPUT);
  pinMode(sensorPin2, OUTPUT);
  pinMode(sensorPin3, OUTPUT);
  pinMode(sensorPin4, OUTPUT);
  pinMode(sensorPin5, OUTPUT);
  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP); //LDR, Blue
  pinMode(A1, INPUT); //Salinity, White
  pinMode(A2, INPUT); //Amplitude, Purple
  pinMode(A3, INPUT); //Temp, Green
}

void loop()
{
  Serial.println(String(analogRead(A0))+"\t"+String(analogRead(A1))+"\t"+String(analogRead(A2))+"\t"+String(analogRead(A3)));
  // Sensor 1
  // read the analog in value:
  sensorValue = analogRead(sensorPin1);
  //Serial.print("Sensor1:\t");
  //Serial.println(sensorValue);
  // map it to the range of the analog out:
  outputValue1 = map(sensorValue, 50, 300, 0, 100);
  //Serial.print("Mapped OutputValue1:\t");
  //Serial.println(outputValue1);
  // Need to calibrate or check the sensor and get the average value. The average value should be set to 50. If high, then >50. If low, then <50.


  // Sensor 2
  // read the analog in value:
  sensorValue = analogRead(sensorPin2);
  //Serial.print("Sensor2:\t");
  //Serial.println(sensorValue);
  // map it to the range of the analog out:
  outputValue2 = map(sensorValue, 0, 1023, 0, 100);
  //Serial.print("Mapped OutputValue2:\t");
  //Serial.println(outputValue2);
  // Need to calibrate or check the sensor and get the average value. The average value should be set to 50. If high, then >50. If low, then <50.


  // Sensor 3
  // read the analog in value:
  sensorValue = analogRead(sensorPin3);
  // map it to the range of the analog out:
  //Serial.print("Sensor3:\t");
  //Serial.println(sensorValue);
  outputValue3 = map(sensorValue, 0, 1023, 0, 100);
  //Serial.print("Mapped OutputValue3:\t");
  //Serial.println(outputValue3);

  // Need to calibrate or check the sensor and get the average value. The average value should be set to 50. If high, then >50. If low, then <50.


  // Sensor 4
  // read the analog in value:
  sensorValue = analogRead(sensorPin4);
  //Serial.print("Sensor4:\t");
  //Serial.println(sensorValue);
  // map it to the range of the analog out:
  outputValue4 = map(sensorValue, 0, 1023, 0, 100);
  //Serial.print("Mapped OutputValue4:\t");
  //Serial.println(outputValue4);

  // Need to calibrate or check the sensor and get the average value. The average value should be set to 50. If high, then >50. If low, then <50.

  // Sensor 1
  // read the analog in value:
  sensorValue = analogRead(sensorPin5);
  // map it to the range of the analog out:
  //Serial.print("Sensor5:\t");
  //Serial.println(sensorValue);
  outputValue5 = map(sensorValue, 0, 1023, 0, 100);
  //Serial.print("Mapped OutputValue5:\t");
  //Serial.println(outputValue5);

  // Need to calibrate or check the sensor and get the average value. The average value should be set to 50. If high, then >50. If low, then <50.

  // EMOTION INDEX CALCULATION

  // Percentage Weitages.They are in order. Amplitude(30%), Salinity(5%), Pollution(20%), Temperature(20%),DO(25%). Only DO is postive rest are negative.

  emotionIndex = (100 - outputValue1) * 0.01;// + (100 - outputValue2) * 0.05 + (100 - outputValue3) * 0.20 + (outputValue1) * 0.25 + (100 - outputValue1) * 0.20)/100;
  //Serial.println("Current EMOTION INDEX");
  //Serial.println(emotionIndex);
  // Angry
  if (emotionIndex >= 0 && emotionIndex < 0.2) {
    setColor(255, 0, 0);  // red
  }

  // Sad
  else if (emotionIndex >= 0.2 && emotionIndex < 0.3) {
    setColor(122, 114, 114);  // gray
  }

  // Calm
  else if (emotionIndex >= 0.3 && emotionIndex < 0.45) {
    setColor(0, 0, 255); // blue
  }


  // Happy
  else if (emotionIndex >= 0.45 && emotionIndex < 0.7) {
    setColor(255, 255, 0); // Yellow
  }

  // in Love
  else if (emotionIndex >= 0.7 && emotionIndex < 1) {
    setColor(249, 30, 234); // Pink
  }

}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
