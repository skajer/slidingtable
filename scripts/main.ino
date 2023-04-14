// Script for motor - pwm
// by skajer

// Start date: 11/22/2022 - 18.30
// end date: - 04/14/2023 - 21:04

//! motor, 2 switches, regulacja obrotÃ³w, odczyt stanÃ³w, ewn. logi

#define button_state_motor_left 2
#define button_state_motor_right 3
#define button_state_motor_stop 4
#define switch_motor_left 6
#define switch_motor_right 9
#define diode_blue 12
#define diode_yellow 11
#define diode_red 13
#define limit_switch_left 5
#define limit_switch_right 7

bool left_backup = false;
bool right_backup = false;

int potentiometer_value = analogRead(A0);
int switch_motor_left_state = digitalRead(2);
int switch_motor_right_state = digitalRead(3);
int switch_motor_stop = digitalRead(4);

void setup() {

  Serial.begin(9600);

  pinMode(button_state_motor_left, INPUT);
  pinMode(button_state_motor_right, INPUT);
  pinMode(button_state_motor_stop, INPUT);

  pinMode(switch_motor_left, OUTPUT);
  pinMode(switch_motor_right, OUTPUT);

  pinMode(diode_red, OUTPUT);
  pinMode(diode_blue, OUTPUT);
  pinMode(diode_yellow, OUTPUT);

  digitalWrite(button_state_motor_left, HIGH);
  digitalWrite(button_state_motor_right, HIGH);
  digitalWrite(button_state_motor_stop, HIGH);

  digitalWrite(limit_switch_left && limit_switch_right, LOW);

  digitalWrite(diode_red, LOW);
  digitalWrite(diode_blue, LOW);
  digitalWrite(diode_yellow, LOW);

  digitalWrite(switch_motor_left, LOW);   // {
  digitalWrite(switch_motor_right, LOW);  // Low, cuz something was wrong (didn't know how to repair it :( )
  digitalWrite(switch_motor_stop, LOW);   //  }

  bool left_backup = false;
  bool right_backup = false;
}

void loop() {

  potentiometer_value = analogRead(A0);
  bool left_backup = false;
  bool right_backup = false;

  digitalWrite(diode_yellow, LOW); //
  digitalWrite(diode_red, HIGH); //brak pracy silnika
  digitalWrite(diode_blue, LOW); // silnik pracuje

  //CHECKING BUTTONS -> MOTOR STARTS 
  if ((digitalRead(button_state_motor_left) == LOW) and (right_backup == false)) {            // lewo dziala takze nie ruszam tego deopkii nie zrobie reszty pzdr 600
      potentiometer_value = map(potentiometer_value, 0,1023,0,255);
      delay(80);
      analogWrite(switch_motor_left, potentiometer_value);
      left_backup = true;
      Serial.println("Start motor - left... ");
  }
  else if (digitalRead(switch_motor_left) == 1) {
    digitalWrite(diode_blue, HIGH);
  }

  if ((digitalRead(button_state_motor_right) == LOW) and (left_backup == false)) {
      potentiometer_value = map(potentiometer_value, 0,1023,0,255); //zobaczyc czy dziala jak to sie wywali
      delay(80);
      analogWrite(switch_motor_right, potentiometer_value);
      right_backup = true;
      Serial.println("Start motor - right... "); 
  }
  else if (digitalRead(switch_motor_right) == 1) {
    digitalWrite(diode_blue, HIGH);
  }
  if (digitalRead(button_state_motor_stop) == LOW) {
      digitalWrite(switch_motor_left, LOW);
      digitalWrite(switch_motor_right, LOW);
      Serial.println("Motor - stop... ");
      right_backup = false;
      left_backup = false;
  }

  else if (digitalRead(button_state_motor_stop) == 1) {
    digitalWrite(diode_red, HIGH);
  }

  // KRAŃCÓWKI
  if (digitalRead(limit_switch_left) == LOW || digitalRead(limit_switch_right) == LOW) {
    digitalWrite(switch_motor_left, LOW);
    digitalWrite(switch_motor_right, LOW);                
    Serial.println("Limit switch triggered - motor stopped");
  // Włącz diodę żółtą
    digitalWrite(diode_yellow, HIGH);
  // Odczekaj 2 sekundy przed wyłączeniem diody i resetem backupów
    delay(2000);
    digitalWrite(diode_yellow, LOW);
    left_backup = false;
    right_backup = false;
  }
  
  else if (left_backup || right_backup) {
    digitalWrite(diode_blue, HIGH);
    }
  else {
    digitalWrite(diode_blue, LOW);
  }


}



