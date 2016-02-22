int led = 9;
int state;
int flag=0;        //makes sure that the serial only prints once the state

void setup() {
    pinMode(led, OUTPUT);
    Serial1.begin(9600);
    //Serial.begin(9600);
}

void loop() {
    //if some date is sent, reads it and saves in state
  if(Serial1.available() > 0){ 
      //Serial.write(Serial1.read()); 
       //if (Serial1.available()) Serial.write(Serial1.read());
      // if (Serial.available()) Serial1.write(Serial.read());   
      state = Serial1.read();   
      flag=0;
    }   
    if (state == '0') {
        digitalWrite(led, LOW);
        if(flag == 0){
          Serial1.println("LED: Off"); // Off the LED
          flag=1;
        }
    }
    else if (state == '1') {
       digitalWrite(led, HIGH); // On the LED
        if(flag == 0){
          Serial1.println("LED: On");
          flag=1;
        }
    }
    else if (state == '2') {
        digitalWrite(led, HIGH);
        delay(100);
        digitalWrite(led, LOW);
        delay(500);
        if(flag == 0){
          Serial1.println("LED: Flash");
          flag=1;
        }
    }
}
