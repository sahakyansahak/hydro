#define chan 2

int relay[chan] = {8, 13};
int butt[chan] = {50, 51};

bool butt_states[chan] = {false, false};

float curr_time1 = 0;
float curr_time2 = 0;

bool what_do[chan] = {true, true};

int t[4] = {7, 5, 4, 5};

bool relState = false;
bool relState1 = false;

void setup() {

  Serial.begin(9600);

  for(int i = 0; i < chan; ++i){

      pinMode(relay[i], OUTPUT);
      pinMode(butt[i], INPUT);
    
    }
}

void get_butts(){
   for(int i = 0; i < chan; ++i){
      butt_states[i] = digitalRead(butt[i]);
    }
  }

void loop() {


    get_butts();
  
    if(butt_states[0]){
      
      if(curr_time1 < t[0] && what_do[0]){
        if(curr_time1 > 2){
          if(relState1){
              Serial.println("RELAY1 ON");
              digitalWrite(relay[0], !HIGH); 
              relState = false ;
          }
          else{
                digitalWrite(relay[0], HIGH);
                relState = true;
                curr_time1 = 0;
            }
        }
        }
       else if(curr_time1 < t[1] && !what_do[0]){
          Serial.println("RELAY1 OFF");
          digitalWrite(relay[0], !LOW);
          relState = true  ;
        }
       else{curr_time1 = 0; what_do[0] = !what_do[0];Serial.println("TIME1 CHANGE");}
       
      }
    else{digitalWrite(relay[0], !LOW);what_do[0] = true;curr_time1 = 0;relState = true;}
    
    if(butt_states[1]){ 
      Serial.println(curr_time2);
       if(curr_time2 < t[2] && what_do[1]){
        if(curr_time2 > 2){
        if(relState){
          Serial.println("RELAY2 ON");
          digitalWrite(relay[1], !HIGH);
          relState1 = false ;
        }
                else{
          digitalWrite(relay[1], HIGH);
          curr_time2 = 0;
          relState1 = true ;
          }   
        } 
                        else{
          digitalWrite(relay[1], HIGH);
           relState1 = true ;

          }   
        }
       else if(curr_time2 < t[3] && !what_do[1]){
        
            Serial.println("RELAY2 OFF");
            digitalWrite(relay[1], !LOW);
            relState1 = true ;
        
        }
       else{curr_time2 = 0; what_do[1] = !what_do[1]; Serial.println("TIME2 CHANGE");}
       
     }
  
    else{digitalWrite(relay[1], !LOW);what_do[1] = true;curr_time2 = 0;relState1 = true ;}
    delay(100);
    Serial.println(relState);
    curr_time1 += 0.1;
    curr_time2 += 0.1; 

}
