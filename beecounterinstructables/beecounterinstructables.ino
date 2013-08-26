
/*
This is for the first gateways: 

from http://www.instructables.com/id/Honey-Bee-Counter/
 */

// this constant won't change:
const int ain = 3; //pin 44 is the first digital input for Gate A
const int aout = 2;// pin 45 is the second digital input for Gate A

// Variables will change:
int ins = 0;  // counts ins and outs
int outs = 0;

int ai = 0;  // Gate A 1st pin status
int lai = 0; // Gate A last status of 1st pin
int ao = 0;  // Gate A 2nd pin status
int lao = 0;  // Gate A last status of 2nd pin



int count = 0;  // this just tests if there has been a change in our bee count
int lcount = 0;


//Display through servo

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 


void setup() {
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);

  // initialize the button pin as a input:
  pinMode(ain, INPUT);
  pinMode(aout, INPUT);

  // initialize serial communication:
  Serial.begin(9600); //a bit different than the Arduino here.... 38400
  
    myservo.attach(9);  // attaches the servo on pin 9 to the servo object 

  
}

void loop() {
  // read the pushbutton input pin:
  ai = !digitalRead(ain);
  ao = !digitalRead(aout);



  if (lai != ai){  // has the status if the 1st pin changed?
    if (ai > ao) {  // if yes, is the bee going in or out?
      ins++;        // if its going in add one bee to ins
    }
  }
  if (lao != ao){ 
    if (ao > ai) {
      outs++;
    }
  }



  lai = ai; // updates the last status
  lao = ao;


  count = ins + outs;

  if (lcount != count){   // if the count has changed we print the new count



    lcount = count;
  }


      Serial.print("number In:  ");

    Serial.print(ins);
    Serial.print("  number Out:  ");
    Serial.print(outs);
    
    
      Serial.print("   count ");

    Serial.print(count);
    Serial.print(" | Exitval "); // prints a space between the numbers
  Serial.print(ai); // prints the value read
  Serial.print("  |  "); // prints a space between the numbers
  Serial.print(" Nestval "); // prints a space between the numbers

  Serial.print(ao);

  Serial.println(" ... "); // prints a space between the numbers
  
  pos = 90+ins - outs;
  pos=90+count*10;
      myservo.write(pos);              // tell servo to go to position in variable 'pos' 


}

