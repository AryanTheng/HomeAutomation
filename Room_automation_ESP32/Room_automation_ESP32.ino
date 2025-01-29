#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "OnePlus Nord CE 2 Lite 5G";
const char* password = "b4h7357t";

WebServer server(80);

// GPIO pins for the relays
const int relay1 = 5;
const int relay2 = 18;
const int relay3 = 26;
const int relay4 = 14;

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    Serial.println("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting...");
    }
    Serial.println("Connected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    // Relay pin setup
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    pinMode(relay3, OUTPUT);
    pinMode(relay4, OUTPUT);
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);

    // Define server routes
    server.on("/light1/on", []() {
        digitalWrite(relay1, LOW); // Turn on relay1
        server.send(200, "text/plain", "Light 1 ON");
    });
    server.on("/light1/off", []() {
        digitalWrite(relay1, HIGH); // Turn off relay1
        server.send(200, "text/plain", "Light 1 OFF");
    });

    server.on("/light2/on", []() {
        digitalWrite(relay2, LOW); // Turn on relay1
        server.send(200, "text/plain", "Light 2 ON");
    });
    server.on("/light2/off", []() {
        digitalWrite(relay2, HIGH); // Turn off relay1
        server.send(200, "text/plain", "Light 2 OFF");
    });
    
    server.on("/light3/on", []() {
        digitalWrite(relay3, LOW); // Turn on relay1
        server.send(200, "text/plain", "Light 3 ON");
    });
    server.on("/light3/off", []() {
        digitalWrite(relay3, HIGH); // Turn off relay1
        server.send(200, "text/plain", "Light 3 OFF");
    });

    server.on("/light4/on", []() {
        digitalWrite(relay4, LOW); // Turn on relay1
        server.send(200, "text/plain", "Light 4 ON");
    });
    server.on("/light4/off", []() {
        digitalWrite(relay4, HIGH); // Turn off relay1
        server.send(200, "text/plain", "Light 4 OFF");
    });

    // Start server
    server.begin();
    Serial.println("Server started");
}

void loop() {
    server.handleClient();
}
