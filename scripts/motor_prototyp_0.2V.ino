// Script for motor - pwm
// by skajer

// Start date: 11/22/2022 - 18.30
// end date: -


// TODO:

// - Read state of switches -> if statements
// - Make start/stop to both sites.
// - Serial.println -> psuedo logs
//

//! motor, 2 switches, regulacja obrotów, odczyt stanów, ewn. logi
//!


#define button_state_motor_left 2
#define button_state_motor_right 3
#define button_state_motor_stop 4
#define switch_motor_left 6
#define switch_motor_right 9
#define diode_work_g 12
#define diode_work_not_g 13

bool button1 = false;
bool button2 = false;
bool if_clicked = false;
bool left_backup = false;
bool right_backup = false;

int i = 0;
int switch_motor_left_state = digitalRead(2);
int switch_motor_right_state = digitalRead(3);
int switch_motor_stop = digitalRead(4);
int switches_state = (digitalRead(switch_motor_left_state), (digitalRead(switch_motor_right_state)));  // state of switches
int potentiometer_value = analogRead(A0);




void setup() {


  Serial.begin(9600);


  pinMode(button_state_motor_left, INPUT);
  pinMode(button_state_motor_right, INPUT);
  pinMode(button_state_motor_stop, INPUT);
  pinMode(switch_motor_left, OUTPUT);
  pinMode(switch_motor_right, OUTPUT);
  pinMode(diode_work_g, OUTPUT);
  pinMode(diode_work_not_g, OUTPUT);

  digitalWrite(button_state_motor_left, HIGH);
  digitalWrite(button_state_motor_right, HIGH);
  digitalWrite(button_state_motor_stop, HIGH);
  digitalWrite(diode_work_g, LOW);
  digitalWrite(diode_work_not_g, LOW);
  
  digitalWrite(switch_motor_left, LOW);   // {
  digitalWrite(switch_motor_right, LOW);  // Low, cuz something was wrong (didn't know how to repair it :( )
  digitalWrite(switch_motor_stop, LOW);   //  }

  if (switches_state == 1) {

    Serial.println("Switches state - LOW... ");

  }

  else {
    Serial.print("Something is wrong... ");
    exit(0);
  }

}

void loop() {

  potentiometer_value = analogRead(A0);


  if ((digitalRead(button_state_motor_left) == LOW) and (right_backup == false)) {

      potentiometer_value = analogRead(A0);
      delay(80);
      analogWrite(switch_motor_left, potentiometer_value);
      left_backup = true;
      Serial.println("Start motor - left... ");

  }

  if ((digitalRead(button_state_motor_right) == LOW) and (left_backup == false)) {

      potentiometer_value = analogRead(A0);
      delay(80);
      analogWrite(switch_motor_right, potentiometer_value);
      right_backup = true;
      Serial.println("Start motor - right... ");

  }

  else if (digitalRead(button_state_motor_stop) == LOW) {

      digitalWrite(switch_motor_left, LOW);
      digitalWrite(switch_motor_right, LOW);
      Serial.println("Motor - stop... ");
      right_backup = false;
      left_backup = false;
      

    }

  if ((digitalRead(button_state_motor_left) == LOW) || (digitalRead(button_state_motor_right) == LOW)) {


    digitalWrite(diode_work_g, HIGH);
    digitalWrite(diode_work_not_g, LOW);

  }


  else{

    digitalWrite(diode_work_g, LOW);
    digitalWrite(diode_work_not_g, HIGH);

  }

}












