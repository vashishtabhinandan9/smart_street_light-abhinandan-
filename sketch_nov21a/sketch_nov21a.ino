/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-light-sensor
 */

// constants won't change
#define LIGHT_SENSOR_PIN  15  // ESP32 pin GIOP36 (ADC0) connected to light sensor for taking input
#define LED_PIN           22  // ESP32 pin GIOP22 connected to LED //output
#define ANALOG_THRESHOLD  500

#define TRIG_PIN 23 // ESP32 pin GIOP23 connected to Ultrasonic Sensor's TRIG pin
#define ECHO_PIN 13 // ESP32 pin GIOP13 connected to Ultrasonic Sensor's ECHO pin
bool  flag = false;

float duration_us, distance_cm;

void setup() {

   Serial.begin (9600);
   pinMode(LED_PIN, OUTPUT); // set ESP32 pin to output mode for ldr
  // configure the trigger pin to output mode for ultrasonic . this will send the pulses outwards
  pinMode(TRIG_PIN, OUTPUT);
  // output of ldr is input for ultrasonic 
  pinMode(ECHO_PIN, INPUT);


}

void loop() {
  int analogValue = analogRead(LIGHT_SENSOR_PIN); // read the value on analog pin //takes in the input od ldr sensor 

  if (analogValue > ANALOG_THRESHOLD){ // ultrasonic senosr begin the work i.e if thresold value is less // light need to be ON

   // generate 10-microsecond pulse to TRIG pin //this will send the pulses outwards at 10sec
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(20);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;
   if(distance_cm<200){
    flag=true;
     digitalWrite(LED_PIN, HIGH); // turn on LED
     Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  delay(500);
     
  }    
     
  else
   { digitalWrite(LED_PIN, LOW); 
    Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
    Serial.println(" => turn off");
   } // turn off LED
}
}
