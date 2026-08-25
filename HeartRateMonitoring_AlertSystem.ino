#include <SoftwareSerial.h>

// SIM800 GSM
SoftwareSerial gsm(10, 11); // RX, TX

// Emergency contacts
char num1[] = "+91xxxxxxxxxx";
char num2[] = "+91xxxxxxxxxx";
char num3[] = "+91xxxxxxxxxx";

// Pulse sensor pin
int pulsePin = A0;

// Thresholds
int lowBPM = 80;
int highBPM = 120;

bool alertSent = false;

void setup() {
  Serial.begin(9600);
  gsm.begin(9600);

  delay(2000);
  Serial.println("System Starting...");

  initGSM();
}

void loop() {
  int sensorValue = analogRead(pulsePin);

  // Simple BPM estimation (basic project method)
  int bpm = map(sensorValue, 0, 1023, 40, 180);

  Serial.print("BPM: ");
  Serial.println(bpm);

  if ((bpm < lowBPM || bpm > highBPM) && !alertSent) {
    Serial.println("Abnormal Heart Rate Detected!");

    sendSMS(num1, bpm);
    delay(3000);
    sendSMS(num2, bpm);
    delay(3000);
    sendSMS(num3, bpm);

    alertSent = true; // stop repeated SMS
  }

  if (bpm >= lowBPM && bpm <= highBPM) {
    alertSent = false; // reset when normal
  }

  delay(1000);
}

void initGSM() {
  gsm.println("AT");
  delay(1000);

  gsm.println("AT+CMGF=1"); // SMS mode
  delay(1000);

  Serial.println("GSM Initialized");
}

void sendSMS(char number[], int bpm) {
  gsm.println("AT+CMGF=1");
  delay(1000);

  gsm.print("AT+CMGS=\"");
  gsm.print(number);
  gsm.println("\"");
  delay(1000);

  gsm.print("EMERGENCY ALERT! Abnormal Heart Rate detected. BPM = ");
  gsm.print(bpm);

  delay(500);
  gsm.write(26); // CTRL+Z
  delay(3000);

  Serial.print("SMS sent to: ");
  Serial.println(number);
}