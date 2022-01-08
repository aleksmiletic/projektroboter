

#include <NewPing.h>                                      //Bibliothek Ultraschall
                                                          
#define TRIG_PIN_L 9                                      //definierien PIN Trigger Ultraschall Links
#define ECHO_PIN_L 8                                      //definieren PIN Echo Ultraschall Links
#define MAX_DIST_L 800                                    //definieren Maximale Distanz

#define TRIG_PIN_R 11
#define ECHO_PIN_R 10
#define MAX_DIST_R 800

NewPing sonar_L(TRIG_PIN_L, ECHO_PIN_L, MAX_DIST_L);    
NewPing sonar_R(TRIG_PIN_R, ECHO_PIN_R, MAX_DIST_R);  

const int IN1 = 3;                                      //Motor Links Polarität PIN 3
const int IN2 = 4;                                      //" PIN 4
const int IN3 = 5;                                      //Motor Rechts Polarität PIN 5
const int IN4 = 6;                                      //" PIN 6

const int ENA = 2;                                      //PWM Motor Links PIN 2 
const int ENB = 7;                                      //PWM Motor Rechts PIN 7

double randNumber_klein;                                
double randNumber_gross;                                

void setup() {

  Serial.begin(9600);
  
  pinMode(IN1, OUTPUT);                                 //definieren der PINs als OUTPUT
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  randomSeed(analogRead(0));                            //Nicht benutzter Analog Eingang wird als Grösse benutzt um immer einen unterschiedlichen Random zu erhalten
  // put your setup code here, to run once:

}

void loop() {


  delay(50);
  double distanceCM_L = sonar_L.ping_cm();
  Serial.println(distanceCM_L);
  double distanceCM_R = sonar_R.ping_cm();
  Serial.println(distanceCM_R);
  delay(100);
  
  randNumber_klein = random(10000, 20000);            //Random Zahl zwischen 10000 und 20000
  randNumber_gross = random(10000, 20000);

   

    analogWrite(ENA, 125);
    analogWrite(ENB, 125);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);       //Fährt geradeaus


  
  if ((distanceCM_R <= 30 && distanceCM_R >= 1) && distanceCM_L >=32){        // Wenn Abstand Rechts kleiner gleich 30 und grösser 1 ist UND Abstand Links grösser 32, dann soll er Links ausweichen

    for(int i = 0; i < randNumber_klein; i++){

      analogWrite(ENA, 175);
      analogWrite(ENB, 175);

      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);       //Weicht nach Links aus
      
    }
    delay(100);    
  }


  if ((distanceCM_L <= 30 && distanceCM_L >= 1) && distanceCM_R >=32){    // Wenn Abstand Links kleiner gleich 30 und grösser 1 ist UND Abstand Rechts grösser 32, dann soll er Rechts ausweichen

    for(int j = 0; j < randNumber_klein; j++){

      analogWrite(ENA, 175);
      analogWrite(ENB, 175);

      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);       //Weicht nach Rechts aus
      
    }
    delay(100); 
  }


  if ((distanceCM_L <= 30 && distanceCM_L >= 1) && (distanceCM_R <= 30 && distanceCM_R >= 1)){      //Wenn beide Abstände kleiner gleich 30 UND grösser 1 sind, dann auch ausweichen

    for(int k = 0; k < randNumber_gross; k++){

      analogWrite(ENA, 175);
      analogWrite(ENB, 175);

      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);       //Weicht nach komplett aus
    }
    delay(100); 
  }

  // put your main code here, to run repeatedly:

}
