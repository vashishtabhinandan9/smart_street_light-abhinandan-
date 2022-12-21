#define IP  18

bool val= false;

#define LED_PIN  22
int p=0;


void setup() {

  Serial.begin(9600);

  pinMode (IP, INPUT);

  pinMode (LED_PIN, OUTPUT);

}


void loop() {

  val = digitalRead(IP);

  Serial.println(val);

  if(val==1)

  {
    Serial.print(p++);
   digitalWrite(LED_PIN, HIGH);

  }

  else

  {
    Serial.print("low");
   digitalWrite(LED_PIN, LOW);

  }

  delay(500);


}
