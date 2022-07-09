/*
      To run or simulate this project efficiently, please follow all the instructions
      provided through comments.

      There is a bit deifferent when running the project using real devices or when using a simulator(Proteus).
      When using simulator you are needed to lower the delay because siulations in proteus does not run in real time,
      so in oreder to get the reuslts without waitng for long time, you are adviced to lower the delay time as much as you can.
      
      When you intend to use real(actual) devices, you need to chane the delay time because the instructions will be
      executed fast(approximately in real time).
      So, set the parameters as instructed bellow:
      -------------------------------------------
      Proteus Simulation   |   Actual Device
      -------------------------------------------
      delay(100)           |   delay(1000)
      delay(200)           |   delay(2000)
      delay(300)           |   delay(3000)
      delay(150)           |   delay(1500)
      delay(500)           |   delay(5000)
      delay(5)             |   delay(50)
      delay(15)            |   delay(150)
      delay(400)            |   delay(4000)
      delay(700)            |   delay(7000)
      delay(10)            |   delay(100)
      lcd(0x20, 16, 2)     |   lcd(0x27, 16, 2);
      -------------------------------------------
      
                       NOTE: READ EVERY COMMENT FOR BETTER UNDESTANDING AND BETTER RESULTS

                              THANK YOU
*/


#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);   //LiquidCrystal_I2C lcd(0x27, 16, 2); for actual device

// Black Line Follower
int IR1 = 12;      //Left sensor
int IR2 = 11;      //Right Sensor

// motor A
int enA = 5;    //Left motor
int MotorAip1 = 3;
int MotorAip2 = 4;

// motor B
int enB = 6;    //Right motor
int MotorBip1 = 7;
int MotorBip2 = 8;

//Sensor values
int rf_switch = A0;        //RF_Detector
int mt_switch = A1;       //Metal_Detector
int  mode_switch = 2;     //Switch mode
int led = 13;       //Output
int buzzer = 9;

//Sensors and mode states
boolean rf_switch_state = 0;
boolean mt_switch_state = 0;
boolean mode = false;

void setup()
{
  // put your setup code here, to run once:
  
  Serial.begin(9600);

  //Inputs and Outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(MotorAip1, OUTPUT);
  pinMode(MotorAip2, OUTPUT);
  pinMode(MotorBip1, OUTPUT);
  pinMode(MotorBip2, OUTPUT);
  pinMode(mode_switch, INPUT_PULLUP);       //Mode switch
  pinMode(led, OUTPUT);             //LED
  digitalWrite(led, LOW);
  pinMode(buzzer, OUTPUT);          // Buzzer

  // Initialize the LCD and turn on light
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  delay(300); 
  
  lcd.print(" PHONE DETECTOR ");
  lcd.setCursor(0, 1);
  delay(100);  
  lcd.print("     ROBOT ");
  delay(300);  
  
  lcd.clear();
  delay(100);
  lcd.print("  DESIGNED BY");
  lcd.setCursor(0, 1);
  delay(100); 
  lcd.print("    KASHINDI ");
  delay(200);  
  lcd.clear();
  delay(100);
  lcd.print(" SYSTEM STARTUP ");
  delay(100);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" ..PLEASE WAIT..");
  
 for (int i = 5; i >= 1 ;  i--){
    lcd.setCursor(0, 1);
    delay(5);
    lcd.print("       ");
    lcd.print(i);
    delay(15 );  
 }

  lcd.clear();
  delay(200);
  lcd.print("USE SWITCH TO SE");
  lcd.setCursor(0, 1);
  delay(100);
  lcd.print("   T EITHER");
  delay(200);

  lcd.clear();
  lcd.print("  MOVEMENT OR ");
  lcd.setCursor(0, 1);
  delay(100);
  lcd.print("STATIONARY MODE");
  
  delay(500);
}

void loop(){

 rf_switch_state = digitalRead(rf_switch);
 mt_switch_state = digitalRead(mt_switch);
 mode = digitalRead(mode_switch);

//Cheking if switch is pressed
 if(mode == false){

  stationary_mode();
 }
 else{
  movement_mode();
 }
}


//PART A: STATIONERY MODE
void stationary_mode(){

      stop_motors();
  
    if(rf_switch_state == 0 && mt_switch_state == 0){
      digitalWrite(led, LOW);
      digitalWrite(buzzer, LOW);
      lcd.setCursor(0, 0);
      lcd.print(" STATIONARY MODE   ");
      lcd.setCursor(0, 1);
      lcd.print("  NO DETECTION    ");
    }

    else if(rf_switch_state == HIGH && mt_switch_state == LOW){
      digitalWrite(led, HIGH);
      digitalWrite(buzzer, HIGH);
      //lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" RADIO FREQUENCY ");
      lcd.setCursor(0, 1);
      lcd.print("    DETECTED     ");
      delay(400);
     // sendSMS();
    }

    else if(rf_switch_state == LOW && mt_switch_state == HIGH){
      digitalWrite(led, HIGH);
      digitalWrite(buzzer, HIGH);
      //lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("      METAL      ");
      lcd.setCursor(0, 1);
      lcd.print("    DETECTED     ");
      delay(400);
     // sendSMS();
    }

    else if(rf_switch_state == HIGH && mt_switch_state == HIGH){
      digitalWrite(led, HIGH);
      digitalWrite(buzzer, HIGH);
     // lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("   RF AND METAL    ");
      lcd.setCursor(0, 1);
      lcd.print("     DETECTED     ");
      delay(400);
      //sendSMS();
    }

    else{
      digitalWrite(led, LOW);
      digitalWrite(buzzer, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" STATIONARY MODE   ");
      lcd.setCursor(0, 1);
      lcd.print("  NO DETECTION    ");
      delay(200);
    }
  }


//PART B: MOVEMENT MODE
void movement_mode(){
    
  //PART ONE: BOTH IR ON BLACK LIGHT
  if (digitalRead(IR1) == HIGH && digitalRead(IR2) == HIGH && rf_switch_state == 0 && mt_switch_state == 0) //IR will not glow on black line
  {
    stop_motors();
    lcd.clear();
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.print("  MOVEMENT MODE    ");
    lcd.setCursor(0, 1);
    lcd.print("  NO DETECTION    ");
  }

  else if (digitalRead(IR1) == HIGH && digitalRead(IR2) == HIGH && rf_switch_state == 1 && mt_switch_state == 1) //IR will not glow on black line
  {
    stop_motors();
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0, 0);
    lcd.print("   RF AND METAL    ");
    lcd.setCursor(0, 1);
    lcd.setCursor(0, 1);
    lcd.print("    DETECTED     ");
    sendSMS();
    delay(700);
  }

  else if (digitalRead(IR1) == HIGH && digitalRead(IR2) == HIGH && rf_switch_state == 1 && mt_switch_state == 0) //IR will not glow on black line
  {
    stop_motors();
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0, 0);
    lcd.print(" RADIO FREQUENCY ");
    lcd.setCursor(0, 1);
    lcd.print("    DETECTED     ");
    sendSMS();
    delay(700);
  }

  else if (digitalRead(IR1) == HIGH && digitalRead(IR2) == HIGH && rf_switch_state == 0 && mt_switch_state == 1) //IR will not glow on black line
  {
    stop_motors();
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0, 0);
    lcd.print("      METAL      ");
    lcd.setCursor(0, 1);
    lcd.print("    DETECTED     ");
    sendSMS();
    delay(700);
  }

  
//PART TWO: BOTH IR NOT ON BLACK LIGHT
  else if (digitalRead(IR1) == LOW && digitalRead(IR2) == LOW && rf_switch_state == 0 && mt_switch_state == 0) //IR not on black line
  {
    move_forward();
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    //lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  MOVEMENT MODE   ");
    lcd.setCursor(0, 1);
    lcd.print("  NO DETECTION    ");

  }

  else if (digitalRead(IR1) == LOW && digitalRead(IR2) == LOW && rf_switch_state == 1 && mt_switch_state == 1) //IR not on black line
  {
    stop_motors();
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0, 0);
    lcd.print("   RF AND METAL    ");
    lcd.setCursor(0, 1);
    lcd.print("    DETECTED     ");
    sendSMS();
    delay(700);
  }

  else if (digitalRead(IR1) == LOW && digitalRead(IR2) == LOW && rf_switch_state == 1 && mt_switch_state == 0) //IR not on black line
  {
    stop_motors();
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0, 0);
    lcd.print(" RADIO FREQUENCY ");
    lcd.setCursor(0, 1);
    lcd.print("    DETECTED     ");
    sendSMS();
    delay(700);
  }

  else if (digitalRead(IR1) == LOW && digitalRead(IR2) == LOW && rf_switch_state == 0 && mt_switch_state == 1) //IR not on black line
  {
    stop_motors();
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0, 0);

    lcd.clear();
    lcd.print("      METAL      ");
    lcd.setCursor(0, 1);
    lcd.print("     DETECTED     ");
    sendSMS();
    delay(700);
  }

  
//PART THREE: LEFT IR SENOSOR ON BLACK LINE
  else if (digitalRead(IR1) == HIGH && digitalRead(IR2) == LOW && rf_switch_state == 0 && mt_switch_state == 0)
  {
    move_left();
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  MOVEMENT MODE   ");
    lcd.setCursor(0, 1);
    lcd.print("  NO DETECTION    ");
  }

  else if (digitalRead(IR1) == HIGH && digitalRead(IR2) == LOW && rf_switch_state == 1 && mt_switch_state == 1)
  {
    stop_motors();
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   RF AND METAL    ");
    lcd.setCursor(0, 1);
    lcd.print("    DETECTED     ");
    sendSMS();
    delay(700);
  }

  else if (digitalRead(IR1) == HIGH && digitalRead(IR2) == LOW && rf_switch_state == 1 && mt_switch_state == 0)
  {
    stop_motors();
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" RADIO FREQUENCY ");
    lcd.setCursor(0, 1);
    lcd.print("    DETECTED     ");
    sendSMS();
    delay(700);
  }

  else if (digitalRead(IR1) == HIGH && digitalRead(IR2) == LOW && rf_switch_state == 0 && mt_switch_state == 1)
  {
    stop_motors();
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("      METAL      ");
    lcd.setCursor(0, 1);
    lcd.print("     DETECTED     ");
    sendSMS();
    delay(700);
  }

//PART FOUR: RIGHT IR SENSOR ON THE BLACK LINE
  else if (digitalRead(IR1) == LOW && digitalRead(IR2) == HIGH && rf_switch_state == 0 && mt_switch_state == 0)
  {
    move_right();
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  MOVEMENT MODE   ");
    lcd.setCursor(0, 1);
    lcd.print("  NO DETECTION    ");
  }

  else if (digitalRead(IR1) == LOW && digitalRead(IR2) == HIGH && rf_switch_state == 1 && mt_switch_state == 1)
  {
   stop_motors();
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   RF AND METAL    ");
    lcd.setCursor(0, 1);
    lcd.print("    DETECTED     ");
    sendSMS();
    delay(700);
  }

  else if (digitalRead(IR1) == LOW && digitalRead(IR2) == HIGH && rf_switch_state == 1 && mt_switch_state == 0)
  {
   stop_motors();
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" RADIO FREQUENCY ");
    lcd.setCursor(0, 1);
    lcd.print("    DETECTED     ");
    sendSMS();
    delay(700);
  }

  else if (digitalRead(IR1) == LOW && digitalRead(IR2) == HIGH && rf_switch_state == 0 && mt_switch_state == 1)
  {
   stop_motors();
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("     METAL    ");
    lcd.setCursor(0, 1);
    lcd.print("    DETECTED     ");
    sendSMS();
    delay(700);
  }

  else
  {
   void stop_motors();
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.print("  MOVEMENT MODE    ");
    lcd.setCursor(0, 1);
    lcd.print("   NO DETECTION    ");
    delay(200);
  }
} 



void stop_motors(){
  //Stop both motors
  digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, LOW);
  analogWrite (enA, 0);
  analogWrite (enB, 0);
}

void move_forward(){
  //Move forward
  digitalWrite(MotorAip1, HIGH);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, HIGH);
  digitalWrite(MotorBip2, LOW);
  analogWrite (enA, 60);
  analogWrite (enB, 60);
}

void move_left(){
  //Move left
  digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, HIGH);
  digitalWrite(MotorBip1, HIGH);
  digitalWrite(MotorBip2, LOW);
  analogWrite (enA, 30);
  analogWrite (enB, 40);
  delay(10);  
}

void move_right(){
  // Move right
  digitalWrite(MotorAip1, HIGH);    // If I want to turn right then the speed of the right wheel should be less than that of the left wheel, here, let a be the right wheel
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, HIGH);
  analogWrite (enA, 40);
  analogWrite (enB, 30);
  delay(10);
}


//SMS SENDING FUNCTION
void sendSMS(){
  Serial.println("AT + CMGF=1\r"); // Set the module in text mode
  delay(100);
  Serial.println("AT+CMGS=\"xxxxxxxxxxxx\"\r");  //Replace xxxxxxxxxxxx with your phone number starting with country code
  delay(100);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   SMS SENT TO    ");
  lcd.setCursor(0, 1);
  lcd.print("  +255678985227   ");
  
  Serial.println("PHONE DETECTED");
  delay(200);
  Serial.println((char)26); //ASII code for CTL + Z
  delay(100);
}
