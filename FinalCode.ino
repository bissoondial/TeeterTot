int pump_time = 3000; //Actually 22000
int drain_time = 1000; //Actually 22000
int delay_value = 1000;
int relay1_pin = 13;
int relay2_pin = 12;
int relay3_pin = 11;
int relay4_pin = 10;
int button_pin = A5;
int button2_pin = A4;
int button3_pin = A3;
int button_state;
int previous_button_state = HIGH;
int button2_state;
int previous_button2_state = HIGH;
int button3_state;
int previous_button3_state = HIGH;

//Defining a Function to check if buttons were pressed
void CheckButtons() {
  
  button_state = digitalRead(button_pin);
  button2_state = digitalRead(button2_pin);
  button3_state = digitalRead(button3_pin);

  // check if the button was just pressed
  if (button_state == LOW && previous_button_state == HIGH) { 
  delay_value = 1500; // toggle delay_value for 30 minute cycle
  Serial. print("Button 1 Toggle");
}
  if (button2_state == LOW && previous_button2_state == HIGH) { 
  delay_value = 2000; // toggle delay_value for 45 minute cycle
  Serial. print("Button 2 Toggle");
}
  if (button3_state == LOW && previous_button3_state == HIGH) { 
  delay_value = 2500; // toggle delay_value for 60 minute cycle
  Serial. print("Button 3 Toggle");
}
  // remember the current button state for the next iteration
  previous_button_state = button_state;
  previous_button2_state = button2_state;
  previous_button3_state = button3_state;

}

void setup() { 
  pinMode(relay1_pin, OUTPUT); 
  pinMode(relay2_pin, OUTPUT);
  pinMode(relay3_pin, OUTPUT);
  pinMode(relay4_pin, OUTPUT);
  pinMode(button_pin, INPUT_PULLUP);
  pinMode(button2_pin, INPUT_PULLUP);
  pinMode(button3_pin, INPUT_PULLUP);
  digitalWrite(relay1_pin, HIGH);
  digitalWrite(relay2_pin, HIGH);
  digitalWrite(relay3_pin, HIGH);
  digitalWrite(relay4_pin, HIGH);
  // High is Off, Low is On for this Relay, idk why
  Serial. begin(9600);
}

void loop() { 
  digitalWrite(relay4_pin, LOW); //Inflate
 
  // delay -> Time to Inflate (35 seconds)
  for (int i = 0; i < 35; i++) {
   delay(1000);
   CheckButtons();
  }
  
  digitalWrite(relay4_pin, HIGH); //Stop Inflating
  delay(100); //Time between inflate and deflate
  digitalWrite(relay3_pin, LOW); //Start Deflate
    
  // delay -> Time to Deflate (35 seconds)
  for (int i = 0; i < 35; i++) {
   delay(1000);
   CheckButtons();
  }
  
  digitalWrite(relay3_pin, HIGH); //Stop deflate
  
  // delay -> Time in between 
  for (int i = 0; i < 900; i++) {
   delay(delay_value);
   CheckButtons();
}
  
  digitalWrite(relay2_pin, LOW); // Start other inflate 

  // delay -> Time to Inflate (35 seconds)
  for (int i = 0; i < 35; i++) {
   delay(1000);
   CheckButtons();
  }
  
  digitalWrite(relay2_pin, HIGH); //Stop inflating
  delay(100); //Time between inflate and deflate  
  digitalWrite(relay1_pin, LOW); //Start deflate
  
  // delay -> Time to Deflate (35 seconds)
  for (int i = 0; i < 35; i++) {
   delay(1000);
   CheckButtons();
  }
  
  digitalWrite(relay1_pin, HIGH); //End deflate

  // delay -> Time in between
  for (int i = 0; i < 900; i++) {
   delay(delay_value);
   CheckButtons();
}
}
