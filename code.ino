#include<ESP8266WiFi.h>
#define WIFI_SSID "***CODE***"
#define WIFI_PASS "arduino"

void setup() {
    
  Serial.begin(9600);
  pinMode(D1, OUTPUT);
  pinMode(D2, INPUT);
  WiFi.begin(WIFI_SSID,WIFI_PASS);

  Serial.print("Connecting.");

  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
  }

  Serial.println("Connected to:");
  Serial.print(WiFi.localIP());
}

long.duration,distance;

void loop() {
  
  digitalWrite(D1, LOW);
  delayMicroseconds(2);
  digitalWrite(D1, HIGH);
  delayMicroseconds(5);
  digitalWrite(D1, LOW);
  duration = pulseln(D2, HIGH);
  distance = duration * 0.034 / 2;                                        // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  Serial.println();
  delay(100);

}
