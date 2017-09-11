int button = 4;
int relay = 3;

int latch_state;
int button_delay;

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(relay, OUTPUT);

  button_delay = 0;
  latch_state = 0;
}

void loop() {
  
  while (button == HIGH){
  button_delay++;
  delay(100);
  button = digitalRead(button);
 
  if(button_delay == 10){ //no need to wait for user to release
    void hold();
    break;
  }        
 
  }
  if(button_delay < 10) { //short press
    void latch();
  }

  button_delay = 0;
  
}

void latch(){

  if (latch_state = 0){
    digitalWrite(relay, HIGH);
    latch_state = 1; 
  }
  else{
    digitalWrite(relay, LOW);
    latch_state = 0;
  }
}

