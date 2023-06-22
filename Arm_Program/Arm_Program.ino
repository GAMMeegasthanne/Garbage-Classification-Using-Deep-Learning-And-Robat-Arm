#include <Servo.h>

bool Motorsetup = false;
Servo servo1;
Servo servo2; //h
Servo servo3; 
Servo servo4;
Servo servo5;
int pos = 0;  
 


int servoPin1 = 9;   
int servoPin2 = 8;  
int servoPin3 = 7; 
int servoPin4 = 6; 
int servoPin5 = 5;

void setup() {

  servo1.attach(servoPin1); 
  servo2.attach(servoPin2);  
  servo3.attach(servoPin3);
  servo4.attach(servoPin4); 
  servo5.attach(servoPin5); 
  

  Serial.begin(9600);       
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();  

    if (command == 'A') 
    {
      
      METAL_Bin();

      
    } 
    
    else if (command == 'B') 
    {
      PLASTIC_Bin();
   
    }
  
     else if (command == 'C') 
     {
      MIX_Bin();

    }
     else if (command == 'D') 
     {
      ORGANIC_Bin();

     
    }

    //..........................

      else if (command == 'f') //test
     {
      servo2.write(50);
      delay(15);
      servo2.write(70);
      delay(15);

     
    }

      else if (command == 'g') 
     {
      servo2.write(70);

     
    }
    //..................................

    
  }

   Serial.println(Motorsetup);
}

void MIX_Bin()

{
      
      Motorsetup = true;
      Serial.print(Motorsetup); 
      Serial.println();
      servo4.write(120);
      delay(1000);
      servo2.write(90);
      delay(1000);
      servo1.write(80);
      delay(1000);
      
      servo3.write(10);
      delay(1000);

      servo2.write(90);
      delay(1000);
      servo2.write(100);
      delay(1000);
      servo2.write(115);
      delay(1000);
      
      servo3.write(140);
      delay(1000);

      delay(1000);
      servo2.write(90);
      delay(1000);
      servo1.write(0);//base      
      delay(100);
     
      
      servo2.write(85);
      delay(1000);
      
      
      servo4.write(60);
      delay(1000);

      servo3.write(10);
      delay(1000);
      servo3.write(130);//grip
      delay(1000);

      
      servo2.write(90);
      delay(1000);
      

      servo4.write(120);
      delay(1000);
      
      servo1.write(80);
      delay(2000);
      Motorsetup = false;
      Serial.print(Motorsetup); 
      Serial.println();

}

void METAL_Bin()

{

      Motorsetup = true;
      Serial.print(Motorsetup); 
      Serial.println();
      servo4.write(120);
      delay(1000);
      servo2.write(90);
      delay(1000);
      servo1.write(80);
      delay(1000);
      
      servo3.write(10);
      delay(1000);

      servo2.write(90);
      delay(1000);
      servo2.write(100);
      delay(1000);
      servo2.write(115);
      delay(1000);
      
      servo3.write(120);
      delay(1000);

      delay(1000);
      servo2.write(90);
      delay(1000);
      servo1.write(150);//base
      delay(1000);
     
      
      servo2.write(85);
      delay(1000);
      
      
      servo4.write(60);
      delay(1000);

      servo3.write(10);
      delay(1000);
      servo3.write(120);//grip
      delay(1000);

      
      servo2.write(90);
      delay(1000);
      

      servo4.write(120);
      delay(1000);
      
      servo1.write(80);
      delay(2000);
      Motorsetup = false;
      Serial.print(Motorsetup); 
      Serial.println();

}

void PLASTIC_Bin()

{
      Motorsetup = true;
      Serial.print(Motorsetup); 
      Serial.println();
      servo4.write(120);
      delay(1000);
      servo2.write(90);
      delay(1000);
      servo1.write(80);
      delay(1000);
      
      servo3.write(10);
      delay(1000);

      servo2.write(90);
      delay(1000);
      servo2.write(100);
      delay(1000);
      servo2.write(115);
      delay(1000);
      
      servo3.write(120);
      delay(1000);

      delay(1000);
      servo2.write(90);
      delay(1000);
      servo1.write(170);//base
      delay(1000);
     
      
      servo2.write(85);
      delay(1000);
      
      
      servo4.write(60);
      delay(1000);

      servo3.write(10);
      delay(1000);
      servo3.write(120);//grip
      delay(1000);

      
      servo2.write(90);
      delay(1000);
      

      servo4.write(120);
      delay(1000);
      
      servo1.write(80);
      delay(2000);
      Motorsetup = false;
      Serial.print(Motorsetup); 
      Serial.println();

}

void ORGANIC_Bin()

{
      Motorsetup = true;
      Serial.print(Motorsetup); 
      Serial.println();
      servo4.write(120);
      delay(1000);
      servo2.write(90);
      delay(1000);
      servo1.write(80);
      delay(1000);
      
      servo3.write(10);
      delay(1000);

      servo2.write(90);
      delay(1000);
      servo2.write(100);
      delay(1000);
      servo2.write(115);
      delay(1000);
      
      servo3.write(120);
      delay(1000);

      delay(1000);
      servo2.write(90);
      delay(1000);
      servo1.write(25);//base
      delay(1000);
     
      
      servo2.write(85);
      delay(1000);
      
      
      servo4.write(60);
      delay(1000);

      servo3.write(10);
      delay(1000);
      servo3.write(120);//grip
      delay(1000);

      
      servo2.write(90);
      delay(1000);
      

      servo4.write(120);
      delay(1000);
      
      servo1.write(80);
      delay(2000);
      Motorsetup = false;
      
}
