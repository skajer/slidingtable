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


#define button_state_motor_left  2
#define button_state_motor_right  3
#define button_state_motor_stop  4
#define switch_motor_left 6
#define switch_motor_right  7

#define diode_work_g 12
#define diode_work_not_g 13


void setup() {

    Serial.begin(9600);

    pinMode(button_state_motor_left, INPUT);
    pinMode(button_state_motor_right, INPUT);
    pinMode(button_state_motor_stop, INPUT);
    pinMode(switch_motor_left, OUTPUT);
    pinMode(switch_motor_right, OUTPUT);

    int switch_motor_left_state = digitalRead(2);
    int switch_motor_right_state = digitalRead(3);
    int switch_motor_stop = digitalRead(4);
    

    Serial.println(digitalRead(switch_motor_left_state),(digitalRead(switch_motor_right_state))); // state of switches

    digitalWrite(button_state_motor_left, HIGH);
    digitalWrite(button_state_motor_right, HIGH);
    digitalWrite(button_state_motor_stop, HIGH);

    digitalWrite(diode_work_g, LOW);
    digitalWrite(diode_work_not_g, LOW);



    digitalWrite(switch_motor_left, LOW);
    digitalWrite(switch_motor_right, LOW);
    digitalWrite(switch_motor_stop, LOW);
    

}

void loop() {

  if (digitalRead(button_state_motor_left) == LOW) {

      digitalWrite(switch_motor_right, LOW);
      digitalWrite(switch_motor_left, HIGH);
      Serial.println("Start motor - left... ");


    }

  if (digitalRead(button_state_motor_right) == LOW) {

      digitalWrite(switch_motor_left, LOW);
      digitalWrite(switch_motor_right, HIGH);
      Serial.println("Start motor - right... ");
      

    }

  if (digitalRead(button_state_motor_stop) == LOW) {

      digitalWrite(switch_motor_left, LOW);
      digitalWrite(switch_motor_right, LOW);
      Serial.println("Motor - stop... ");
      

    }

  if ((digitalRead(switch_motor_left) == HIGH) || (digitalRead(switch_motor_right) == HIGH)) {


    digitalWrite(diode_work_g, HIGH);
    digitalWrite(diode_work_not_g, LOW);

  }


  else{
    digitalWrite(diode_work_g, LOW);
    digitalWrite(diode_work_not_g, HIGH);

  }


}


