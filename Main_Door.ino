/*
 *  Created by Akash Murthy         - akashmurthy11@gmail.com
 *             Abhishek Kumar Singh - abhishek.betterthanbest@gmail.com
 *  Written by Akash Murthy
 */

// This program shown how to control btuino from PC Via Bluetooth
// Arduino  >>>   HC-05 Bluetooth
// D11      >>>   Rx
// D10      >>>   Tx

//Relay pins(2,3,4,5) - 4 ch 

#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

String message = ""; //Message buffer

char character;

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  for(int a=2;a<=5;a++)
  {
    pinMode(a, OUTPUT);
    digitalWrite(a, HIGH);
  }
}

void loop() {
  roll_pitch();
  // delay(1000); // <-- This delay signifies me doing things other than reading the serial info it's also screwing things up.
}

void door(int i)
{
    digitalWrite(i, LOW);
    delay(1200);
    digitalWrite(i, HIGH);
}

void roll_pitch() { //
  while (mySerial.available()) {
    character = mySerial.read();
    message.concat(character);

    if (character == '#') { // if end of message received
      Serial.print(message); //display message and
      if (message.substring(0,6) == "109400") {
        if(message[7]=='1'){door(2);}
        if(message[7]=='2'){door(3);}
        if(message[7]=='3'){door(4);}
        if(message[7]=='4'){door(5);}
        mySerial.print("Success! ");
        mySerial.print("Door ");
        mySerial.print(message[7]);
        mySerial.println(" opened");
      }
      message = ""; //clear buffer
      Serial.println();
    }
  }
}

//#include <SoftwareSerial.h>// import the serial library
//SoftwareSerial bt(10, 11); // RX, TX
//
//int relay = 13;
//String Data = ""; // the data given from Computer
//
//void setup() {
//
//  bt.begin(9600);
//  Serial.begin(9600);
//
//  bt.println("Main_Door");
//  Serial.println("Main_Door");
//  pinMode(relay, OUTPUT);
//}
//
//void loop() {
//  while (bt.available() == 0) {}
//  char in ;
//  
//  if (bt.available() > 0) {
//    in = bt.read();
//    Serial.write( in );
//    Data = Data + in ;
//  }
//  if (Data == "109400#1") { // if number 1 pressed ....
//    digitalWrite(relay, 1);
//    bt.println("Success!");
//    delay(500);
//    digitalWrite(relay, 0);
//
//  }
//  if ( in == 13) {
//    bt.print("Received: ");
//    bt.println(Data);
//    Data = "";
//  }
//  delay(100); // prepare for next data ...
//}
