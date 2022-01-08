
double randNumber_klein;
double randNumber_gross;

void setup() {

   Serial.begin(9600);

  randomSeed(analogRead(0));
  // put your setup code here, to run once:

}

void loop() {

  randNumber_klein = random(10000, 20000);
  randNumber_gross = random(50000, 60000);

  Serial.println(randNumber_klein);
  Serial.println(randNumber_gross);

  delay(5000);
  // put your main code here, to run repeatedly:

}

//Fazit: Random funktioniert
