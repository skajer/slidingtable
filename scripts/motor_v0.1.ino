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


int motor = 1;
int switch_engine_left = 2;
int switch_engine_right = 3;
int switch_engine_stop = 4;
int limit_switch_left = 5;  // krańcówka_lewa
int limit_switch_right = 6 // krańcówka_prawa

int pwm_fill = 0;
int change_pwm = 5;

boolean state_of_switches = false;  // just an information to pass a another test



void setup() {

    Serial.begin(9600);

    pinMode(switch_engine_left, INPUT_PULLUP);
    pinMode(switch_engine_right, INPUT_PULLUP);

    int switch_engine_left_state = digitalRead(2);
    int switch_engine_right_state = digitalRead(3);

    Serial.println(digitalRead(switch_engine_left_state),(digitalRead(switch_engine_right_state))); // state of switches

    if (digitalRead(switch_engine_left_state == LOW) and digitalRead(switch_engine_right_state == LOW) {

        state_of_switches = 0;
        Serial.println("Switches okay... ");

    }
    
    else
    {
        Serial.println("Something is wrong... ");
        exit(0);
    }


}

void loop() {

  Serial.println("siema");

    if (state_of_switches == true) {
        
        if (digitalRead(switch_engine_left == LOW)) {

            Serial.println("G")
        
            if (pwm_fill < 255){

                pwm_fill = pwm_fill + change_pwm;
                
                analogWrite(motor, pwm_fill);
                Serial.println("Motor" + pwm_fill);

                //if na krańcówke ze jak dojedzie to chuj, zatrzymaj prace silnika cn sztyniwutko 😎😂😁😁
                
                if (digitalRead(limit_switch_left == HIGH)) {

                    analogWrite(motor, LOW);
                    Serial.println("Stopped motor...");

                }

            }
        }
       
        if (digitalRead(switch_engine_right == LOW)) {
        
            if (pwm_fill < 255){

                pwm_fill = pwm_fill + change_pwm;
                
                analogWrite(motor, pwm_fill);
                Serial.println("Motor" + pwm_fill);

                //if na krańcówke ze jak dojedzie to chuj, zatrzymaj prace silnika cn sztyniwutko 😎😂😁😁
                
                if (digitalRead(limit_switch_right == HIGH)) {

                    analogWrite(motor, 0);
                    Serial.println("Stopped motor...");

                }
            }           
        }


        if (digitalRead(switch_engine_stop == LOW)) {       //przycisk stop

            analogWrite(motor, 0);
            Serial.println("Stopped motor...");

        }
    }
}