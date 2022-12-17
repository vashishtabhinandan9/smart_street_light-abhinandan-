int ip = 18;

int val = 0;

int led = 22;
int p=0;

void setup() {

  Serial.begin(9600);

  pinMode (ip, INPUT);

  pinMode (led, OUTPUT);

}


void loop() {

  val = digitalRead(ip);

  Serial.println(val, DEC);

  if(val > 0)

  {

    digitalWrite(led, HIGH);
    Serial.println("detected");
  }

  else

  {
    digitalWrite(led, LOW);
    Serial.println("nada" );
    Serial.println(p++);
    

  }

  delay(1000);


}
