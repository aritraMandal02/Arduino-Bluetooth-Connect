//void setup() {
//  Serial.begin(9600);
//  Serial.println("Arduino Bluetooth App");
//  delay(2500);
//}
//
//void loop() {
//
//  Serial.println("0");
//  Serial.println("1");
//  Serial.println("0");
//  Serial.println("0");
//  Serial.println("1");
//  Serial.println("0");
//  Serial.println("1");
//  Serial.println("1");
//  Serial.println("Created by: Aritra");
//  delay(500);
//
//}

/*=======================================================*/

//
//void setup() {
//  // put your setup code here, to run once:
//  Serial.begin(9600);
//  pinMode(8, OUTPUT);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  if(Serial.available()>0)
//    {
//      char data = Serial.read(); // Reading the data received from bluetooth module
//      switch(data)
//      {
//        case '1': digitalWrite(8, HIGH);
//        Serial.println("Light on");
//        break;
//        case '0': digitalWrite(8, LOW);
//        Serial.println("Light off");
//        break;
//        default: break;
//      }
//      Serial.println(data);
//    }
//    delay(50);
//}

/*===================================================================*/

const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(10);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}