int exitval;
int nestval;

int exitpin = 3;
int  nestpin = 2;

// We will always start with the assumption no bees are in the nest or outside the nest
int censusOut = 0;
int censusIn = 0;

void setup()

{

  pinMode(13, OUTPUT);
  pinMode(exitpin, INPUT);
  pinMode(nestpin, INPUT);


  Serial.begin(9600); // sets the serial port to 9600

    digitalWrite(13, HIGH);
}

void loop()
{

  exitval = !digitalRead(exitpin); // read digital input pin 3 // Invert them!
  nestval = !digitalRead(nestpin); // read digital input pin 2 // invert them for ease of thinking!
  //val = analogRead(0); // read analog input pin 0

  // !!!    1 means triggered, 0 means open   !!!
  Serial.print(" Exitval "); // prints a space between the numbers
  Serial.print(exitval); // prints the value read
  Serial.print("  |  "); // prints a space between the numbers
  Serial.print(" Nestval "); // prints a space between the numbers

  Serial.print(nestval);

  Serial.print(" ... "); // prints a space between the numbers




  if(exitval || nestval){   //If either switch is triggered, we have a bee! now we need to see if it comes all the way
    if(exitval) {

      long timeout = millis()+1000; //one second delay
      while(timeout>millis()){
        nestval = !digitalRead(nestpin); // read the value again
        if(nestval) { // this means a bee has moved from the exit to the nest a RETUNRNER
        censusIn++;
          Serial.print("  ||  "); // prints a space between the numbers
          Serial.print(" A Return! "); // prints a space between the numbers

          Serial.print(censusIn);
          break;
        }

      }
    } 

    else {   // nestval was the one triggered
      long timeout = millis()+1000; //one second delay
      while(timeout>millis()){
        exitval = !digitalRead(exitpin); // read the value again
        if(exitval) { // this means a bee has moved from the nest to the exit  A LEAVER!
          censusOut++;
          Serial.print("  ||  "); // prints a space between the numbers
          Serial.print(" A Leaver! "); // prints a space between the numbers

          Serial.print(censusOut);
          break;
        }

      }
    }

  }

   Serial.print(" Inside "); // prints a space between the numbers
          Serial.print(censusIn);
                    Serial.print("  ||  "); // prints a space between the numbers

   Serial.print(" Outside "); // prints a space between the numbers
          Serial.print(censusOut);
          
          
  Serial.println(" "); // prints a space between the numbers


  delay(10); // wait 10ms for next reading

}


