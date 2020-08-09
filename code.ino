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
  
  sendData("AT+RST\r\n",2000,DEBUG);            // command to reset the module
  sendData("AT+CWMODE=2\r\n",1000,DEBUG);       // This will configure the mode as access point
  sendData("AT+CIFSR\r\n",1000,DEBUG);          // This command will get the ip address
  sendData("AT+CIPMUX=1\r\n",1000,DEBUG);       // This will configure the esp for multiple connections
  sendData("AT+CIPSERVER=1,80\r\n",1000,DEBUG); // This command will turn on the server on port 80
    
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
  distance = duration * 0.034 / 2;     // Speed of sound wave divided by 2 (go and back)
    
  if(esp8266.available())
  {    
    if(esp8266.find("+IPD,"))
    {
     delay(1000);
     int connectionId = esp8266.read()-48; 
     String webpage = "<h1>IOT Garbage Monitoring System</h1>";
       webpage += "<p><h2>";   
       if (distance<5)
       {
        webpage+= " Trash can is Full";
        }
        else{
          webpage+= " Trash can is Empty";
          }
       webpage += "</h2></p></body>"; 
        
     sendData(closeCommand,3000,DEBUG);

  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  Serial.println();
  delay(100);

}
      
 String sendData(String command, const int timeout, boolean debug)
{
    String response = "";   
    esp8266.print(command); 
    long int time = millis();
    while( (time+timeout) > millis())
    {
      while(esp8266.available())
      {
        char c = esp8266.read(); 
        response+=c;
      }  
    }
    if(debug)
    {
      Serial.print(response);
    }
    return response;
}
