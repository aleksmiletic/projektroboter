#include <NewPing.h>

#define TRIG_PIN_L 9
#define ECHO_PIN_L 8
#define MAX_DIST_L 400

#define TRIG_PIN_R 11
#define ECHO_PIN_R 10
#define MAX_DIST_R 400

NewPing sonar_L(TRIG_PIN_L, ECHO_PIN_L, MAX_DIST_L);
NewPing sonar_R(TRIG_PIN_R, ECHO_PIN_R, MAX_DIST_R);


void setup() {

  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {

  delay(50);
  double distanceCM_L = sonar_L.ping_cm();
// Serial.println(distanceCM_L);
// double distanceCM_R = sonar_R.ping_cm();
  if (distanceCM_L <= 30){
  Serial.println(distanceCM_L);
  }

  delay(500);
  
  
  // put your main code here, to run repeatedly:

}


// Fazit: +/- 1cm genau wenn beide gleichzeitig gerade auf Hinderniss
