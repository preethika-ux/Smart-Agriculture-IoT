// === Device for Endangered Species (Simulation Version) ===
// PIR → pin 2, Potentiometer → A0, LED → 13

const int PIR_PIN = 2;
const int PULSE_PIN = A0;
const int LED_PIN = 13;
const int PULSE_THRESHOLD = 600; // adjust based on simulation values

void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.println("Simulation started...");
}

void loop() {
  int pulseRaw = analogRead(PULSE_PIN);
  int pirState = digitalRead(PIR_PIN);

  Serial.print("PulseRaw: ");
  Serial.print(pulseRaw);
  Serial.print("   PIR: ");
  Serial.println(pirState == HIGH ? "MOTION" : "NO MOTION");

  if (pulseRaw > PULSE_THRESHOLD || pirState == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    sendAlert(pulseRaw);
    delay(3000); // simulate sending SMS
    digitalWrite(LED_PIN, LOW);
  }

  delay(1000);
}

void sendAlert(int pulseVal) {
  Serial.println("⚠ ALERT TRIGGERED!");
  Serial.println("SIMULATED GSM: Sending SMS...");
  Serial.print("Animal in danger! PulseRaw: ");
  Serial.println(pulseVal);
  Serial.println("Location: [Simulated GPS Data]");
  Serial.println("=== ALERT SENT ===");
}
