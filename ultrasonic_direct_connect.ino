const int groundPin = 8;
const int outPin = 9;
const int trigPin = 10;
const int echoPin = 11;
const int voltPin = 12;

const float speed_of_sound_meters_per_second = 331.5; // meters per second at 0 C
const float TCMS_const = 0.6; //speed of sound increases by 0.6 m/s per degree C
const float current_temperature_in_C = 20.0; //change this if you detect a different local temperature
float speed_of_sound_cm_per_microsecond; //will be calculated in setup

float duration_in_microseconds;
float distance_in_cm;

void setup() {
  pinMode(groundPin, OUTPUT);
  pinMode(outPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(voltPin, OUTPUT);
  
  Serial.begin(9600);

  digitalWrite(groundPin, LOW);
  digitalWrite(outPin, LOW);
  digitalWrite(trigPin, LOW);
  digitalWrite(voltPin, HIGH);

  //calculate multiplier constant here for transparency
  float temp_based_speed_of_sound = speed_of_sound_meters_per_second + (TCMS_const*current_temperature_in_C);
  float speed_of_sound_cm_per_second = temp_based_speed_of_sound * 100;
  speed_of_sound_cm_per_microsecond =  speed_of_sound_cm_per_second / 1000000;
}

void loop() {
  //Starting Low
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration_in_microseconds = pulseIn(echoPin, HIGH);
  distance_in_cm = (duration_in_microseconds/2.0) * speed_of_sound_cm_per_microsecond; //TODO calc this out

  Serial.print("Distance = ");
  if(distance_in_cm >= 400 || distance_in_cm <= 2) {
    Serial.println("Out of Range");    
  } else {
    Serial.print(distance_in_cm);
    Serial.println(" cm");
  }
  delay(500);  //don't want to ping too often
}
