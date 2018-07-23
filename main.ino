#include<ESP8266WiFi.h>
#include<ESP8266WiFiMulti.h> 
#include<ESP8266WebServer.h>
#include<ESP8266WebServerSecure.h>
#include<ESP8266mDNS.h>
#include "home.h"


ESP8266WiFiMulti wifiMulti;  
ESP8266WebServer server(443);

void handleRoot(){
    String page = homepage;
    server.send(200, "text/html", page);
}
void handleADC(){
    String ADCval = String(analogRead(A0));
    server.send(200, "text/plane", ADCval);
}

void setup(){
    Serial.begin(115200);
    wifiMulti.addAP("meth", "12346789");
    wifiMulti.addAP("Redmi5", "12345asdf");
    WiFi.mode(WIFI_STA);
    Serial.println("");
    while(wifiMulti.run() != WL_CONNECTED){
        delay(500);
        Serial.print("*");
    }
    Serial.println("");
    Serial.print("Connected to ");
//    Serial.println(WiFi.SSID);
    Serial.println(WiFi.localIP());
    if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
     }
    server.on("/", handleRoot);
    server.on("/readADC", handleADC);

    server.begin();
    Serial.print("Server Has Started");
}
void loop(){
    server.handleClient();
}
