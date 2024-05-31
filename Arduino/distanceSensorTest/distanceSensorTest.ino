#define ECHOPIN D5 // Pin to receive echo pulse
#define TRIGPIN D6 // Pin to send trigger pulse
#define CommonSenseMetricSystem
void setup() {
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}
 
void loop() {
  digitalWrite(TRIGPIN, LOW); // Set trigger pin low
  delayMicroseconds(2); // Wait for stable
  digitalWrite(TRIGPIN, HIGH); // Send 10us pulse
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  long duration = pulseIn(ECHOPIN, HIGH); // Measure pulse width of echo pin
  #ifdef CommonSenseMetricSystem
  float distance = duration * 0.034 / 2; // Convert pulse width to distance in cm
  #endif
  #ifdef ImperialNonsenseSystem
  float distance = (duration/2) / 73.914;
  #endif
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
 
  delay(500); // Wait before next measurement
}