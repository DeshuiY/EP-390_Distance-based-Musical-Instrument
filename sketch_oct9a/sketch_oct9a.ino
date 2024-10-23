const int trigPin = 9;

// defin the Trigger pin， trigPin is connected to 9 on the Arduino(same to the Tennsy 4.0)

const int echoPin = 10;

// defin the Echo pin, echoPin is connected to 10 on the Arduino(same to the Tennsy 4.0)

const int buttonPin = 2;

float duration, distance;

int buttonState;

// float  both have decimal points
// duration: store in time (in microseconds) between the sound wave being sent and recevied 
// distance: store the calculated distance based on the measured time(cm)

void setup() {

  pinMode(trigPin, OUTPUT);

  // sets trigPin as an output pin

  pinMode(echoPin, INPUT);

  //sets echoPin as an input pin

  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);

  // sets the serial communication at a baud rate of 9600
  // in teensy may not need. 
  // start send signal 9600 per seconds

  // put your setup code here, to run once

}

void loop() {

  digitalWrite(trigPin, LOW);  

  // sets the trigPin to low to ensure it starts in a low state before seeding pulse

	delayMicroseconds(2);  

  // delay time (measured in Microsenconds)

	digitalWrite(trigPin, HIGH);  

  // sends high signal on the trigPin for triggering the sensor to send out a sound pulse

	delayMicroseconds(10); 

  // keep the signal high for 10 microseconds

	digitalWrite(trigPin, LOW);  

  // sets trigPin back to low signal (end the pulse)

  duration = pulseIn(echoPin, HIGH);

  // The timer starts when echoPin is HIGH, and stops when echoPin turns LOW.



  distance = (duration*.0343)/2;

  // 0.0343 means 343 meters per second (speed of sound in air) converted to centimeters per microsecond.

  
  // division by 2 because we need to consider the send and receive.



  // Header-based System
  Serial.print("d ");

  // print the text "Distance" to the console, print on the same line

  Serial.println(distance);

  // printIn for printing and then moving to the next line, so the  next output will start on a new line 

  buttonState = digitalRead(buttonPin);

  

  Serial.print("b ");
  Serial.println(buttonState);

  delay(100);

  // pause the program for 100 milliseconds before taking the next measurement.

  // put your main code here, to run repeatedly:

}