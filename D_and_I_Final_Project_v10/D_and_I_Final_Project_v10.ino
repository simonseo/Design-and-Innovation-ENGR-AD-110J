/*
  EMOTION OF THE OCEAN
*/

int redPin = 10;
int greenPin = 9;
int bluePin = 6;

// decide later whether the pin will be analogue or digital
int salinityPin  = A3;
int tempPin = A2;
int ampPin = A1;
int particlePin = A0;

int sensorValue;        // value read from the sensor
int salinityValue;        // value output to the PWM (analog out)
int tempValue;
int particleValue;

float emotionIndex;

int lastprinted = 0;
/////////////////////////////////////////SENSORS///////////////////////////////////////

//int ampPin = A2;

const int numReadings1 = 150;
int readings1[numReadings1];      // the readings from the analog input
int readIndex1 = 0;              // the index of the current reading
int total1 = 0;                  // the running total
int average1 = 0;                // the average

const int numReadings2 = 10;
int readings2[numReadings2];      // the readings from the analog input
int readIndex2 = 0;              // the index of the current reading
long total2 = 0;                  // the running total
float ampValue = 0;                // the average


///////////////////////////////////////////////////////////////////////////////////////
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
  pinMode(particlePin, INPUT_PULLUP); //LDR, Purple A0
  pinMode(salinityPin, INPUT); //Salinity, Gray A3
  pinMode(ampPin, INPUT); //Amplitude, Green A1
  pinMode(tempPin, INPUT); //Temp, Blue A2++

  for (int thisReading = 0; thisReading < numReadings1; thisReading++) {
    readings1[thisReading] = 0;
  }
  for (int thisReading = 0; thisReading < numReadings2; thisReading++) {
    readings2[thisReading] = 0;

    //  for (int i = A0; i < A5; i++) {
    //    pinMode(i, INPUT_PULLUP);
    //  }
  }
}
void loop()
{ // Salinity Sensor 1

  // read the analog in value:
  sensorValue = analogRead(salinityPin);
  //  Serial.print("Sensor1:\t");
  //  Serial.println(sensorValue);
  // map it to the range of the analog out:
  salinityValue = constrain(sensorValue, 820, 890); //820~890
  salinityValue = map(salinityValue, 820, 890, 0, 200); //0~200
  salinityValue = abs(salinityValue - 100); //0~100

  // Need to find the upper and lower bound of the sensors and then use the constrain function.
  //  Serial.print("Mapped salinityValue:\t");
  //  Serial.println(salinityValue);
  // Need to calibrate or check the sensor and get the average value. The average value should be set to 50. If high, then >50. If low, then <50.

  // Temperature Sensor 2
  // read the analog in value:
  sensorValue = analogRead(tempPin);
  //  Serial.print("Sensor2:\t");
  //  Serial.println(sensorValue);
  // map it to the range of the analog out:
  //tempValue = map(sensorValue, 0, 1023, 0, 100);
  //  Serial.print("Mapped tempValue:\t");
  //  Serial.println(tempValue);
  // Need to calibrate or check the sensor and get the average value. The average value should be set to 50. If high, then >50. If low, then <50.
  float voltage = sensorValue * 5.0;
  voltage /= 1024.0;
  float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset

  tempValue = constrain(temperatureC, 15, 35);
  tempValue = map(tempValue, 15, 35, 0, 200);
  tempValue = abs(tempValue - 100);

  // Particle Sensor 4
  // read the analog in value:
  sensorValue = analogRead(particlePin);
  // map it to the range of the analog out:
  //  Serial.print("Sensor3:\t");
  //  Serial.println(sensorValue);
  particleValue = constrain(sensorValue, 23, 65);
  particleValue = map(particleValue, 23, 65, 0, 100);
  //  Serial.print("Mapped OutputValue3:\t");
  //  Serial.println(outputValue3);

  // Need to calibrate or check the sensor and get the average value. The average value should be set to 50. If high, then >50. If low, then <50.
  //Serial.println(String(analogRead(A0)) + "\t" + String(analogRead(A1)) + "\t" + String(analogRead(A2)) + "\t" + String(analogRead(A3)) +"\t" + String(emotionIndex));
  Serial.println(String(salinityValue) + "\t" + String(analogRead(ampPin)) + "\t" + String(ampValue) + "\t" + String(tempValue) + "\t" + String(total2 / numReadings2) + "\t" + String(total2) + "\t" + String(emotionIndex));

  // subtract the last reading:
  total1 = total1 - readings1[readIndex1];
  // read from the sensor:
  readings1[readIndex1] = analogRead(ampPin);
  // add the reading to the total:
  total1 = total1 + readings1[readIndex1];
  // advance to the next position in the array:
  readIndex1 = readIndex1 + 1;

  // if we're at the end of the array...
  if (readIndex1 >= numReadings1) {
    // ...wrap around to the beginning:
    readIndex1 = 0;
  }

  // calculate the average:
  average1 = total1 / numReadings1;

  ///////////Total2////////

  // subtract the last reading:
  total2 = total2 - readings2[readIndex2];
  // read from the sensor:
  readings2[readIndex2] = sq(analogRead(ampPin) - 516);
  // add the reading to the total:
  total2 = total2 + readings2[readIndex2];
  // advance to the next position in the array:
  readIndex2 = readIndex2 + 1;

  // if we're at the end of the array...
  if (readIndex2 >= numReadings2) {
    // ...wrap around to the beginning:
    readIndex2 = 0;
  }

  // calculate the average:
  if (total2 < 0) {
    total2 = 32767;
  }
  ampValue = sqrt(total2 / numReadings2);



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

  emotionIndex = ((100 - salinityValue) * 0.10 + (100 - tempValue) * 0.10 + (100 - particleValue) * 0.10 + (100 - ampValue) * 0.70) / 100;

  static long start_time = 0;
  if (!start_time) {
    start_time = millis(); //start_time = time when last changed color
  }
  // Below printing is important.
  //  Serial.println("Current EMOTION INDEX");
  //  Serial.println(emotionIndex);

  // Angry
  if (emotionIndex >= 0 && emotionIndex < 0.2) {
    if (millis() - start_time > 10000) {
      if (lastprinted != 2) {
        setColor(255, 0, 0);  // red
        Serial.println(2);
        lastprinted = 2;
        start_time = 0;
      }
    }
  }
  // Sad
  else if (emotionIndex >= 0.2 && emotionIndex < 0.3) {
    if (millis() - start_time > 10000) {
      if (lastprinted != 3) {
        setColor(122, 114, 114);  // gray
        Serial.println(3);
        lastprinted = 3;
        start_time = 0;
      }
    }
  }

  // Calm
  else if (emotionIndex >= 0.3 && emotionIndex < 0.45) {
    if (millis() - start_time > 10000) {
      if (lastprinted != 1) {
        Serial.println(1);
        setColor(0, 0, 255); // blue
        lastprinted = 1;
        start_time = 0;
      }
    }
  }
  // Happy
  else if (emotionIndex >= 0.45 && emotionIndex < 0.7) {

    if (millis() - start_time > 10000) {
      if (lastprinted != 0) {
        setColor(225, 155, 0); // Yellow
        Serial.println(0);
        lastprinted = 0;
        start_time = 0;
      }
    }
  }
  // in Love
  else if (emotionIndex >= 0.7 && emotionIndex < 1) {
    if (millis() - start_time > 10000) {
      if (lastprinted != 4) {
        setColor(249, 30, 150); // Pink
        Serial.println(4);
        lastprinted = 4;
        start_time = 0;
      }
    }
  }
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
