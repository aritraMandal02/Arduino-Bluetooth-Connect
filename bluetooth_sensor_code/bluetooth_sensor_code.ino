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
//        case '2': digitalWrite(8, LOW);
//        break;
//        default: break;
//      }
//      Serial.println(data);
//    }
//    delay(50);
//}
//


void setup() {
  Serial.begin(9600);
  Serial.println("Arduino Bluetooth App");
  delay(2500);
  

}

void loop() {

  Serial.println("0");
  Serial.println("1");
  Serial.println("0");
  Serial.println("0");
  Serial.println("1");
  Serial.println("0");
  Serial.println("1");
  Serial.println("1");
  Serial.println("Created by: Aritra");
  
}
