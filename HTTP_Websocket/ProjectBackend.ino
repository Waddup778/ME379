/*
 * Name: Drink Composer - Backend
 * 
 * Written By: C. Abbey
 * Course: ME379
 * 
 * Date: FEB 18, 2024
 * 
 * Description: 
 *  This code is meant to run on a NodeMCU module. The code instructs
 *  the NodeMCU to generate a WiFi network with the given name and password
 *  It then establishes basic protocols like IP, gateway, and subnet.
 *  
 *  The program hosts an http webserver that allows http requests to be processed
 *  by the NodeMCU to accomplish tasks. It does this by accepting pre-determined 
 *  URLs which are handled by the ClientHandler function. The correct method is 
 *  called for the matching url, and a subroutine is initialized.
 */


#include <ESP8266WiFi.h>      //Import the ESP8266WiFi library
#include <ESP8266WebServer.h> //Import the ESP8266WebServer library

/* Put your SSID & Password */
const char* ssid = "DrinkComposer";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);    //Define the IP Address of the Access Point
IPAddress gateway(192,168,1,1);     //Define the Gateway address of the Access Point
IPAddress subnet(255,255,255,0);    //Define the subnet mask Identity

ESP8266WebServer server(80);     //Create a server object on port 80 (for SSH communication)

#define LED0pin D8    //Pin D8 named LED0pin

#define LED1pin D7    //Pin D7 named LED1pin

#define LED2pin D6    //Pin D6 named LED2pin

#define LED3pin D5    //Pin D5 named LED3pin

void setup() {
  Serial.begin(115200);     //Start sending serial data to the monitor at baud 115200

  pinMode(LED0pin, OUTPUT); //Set LED0Pin as an output
  pinMode(LED1pin, OUTPUT); //Set LED1pin as an output
  pinMode(LED2pin, OUTPUT); //Set LED2pin as an output 
  pinMode(LED3pin, OUTPUT); //Set LED3pin as an output

  WiFi.softAP(ssid, password);    //Start an access point (AP) with the entered SSID and password
  WiFi.softAPConfig(local_ip, gateway, subnet);   //Configure the network proxies
  delay(100);   //Wait 100 milliseconds

  // ==================== URL HANDLING ====================================
  server.on("/", handle_OnConnect);   //When the server sees "/", initialize handle_onConnect
  //server.on("/led1on", handle_led1on);
  //server.on("/led1off", handle_led1off);
  //server.on("/led2on", handle_led2on);
  //server.on("/led2off", handle_led2off);
  server.on("/orderAAL", handle_orderAAL);    //When the server sees "/orderAAL", initialize the void function
  server.on("/orderLaPlaya", handle_orderLaPlaya);
  server.on("/orderTequilaSun", handle_orderTequilaSun);
  server.on("/orderCapeCod", handle_orderCapeCod);
  server.onNotFound(handle_NotFound);
  
  server.begin();   //being the server
  Serial.println("HTTP server started");    //verify the server has initialized
}
void loop() {
  server.handleClient();    //Look for URLs, address handler defined in void setup()
}

void handle_orderAAL(){
  digitalWrite(LED1pin, HIGH);
  Serial.println("GPIO7 Status: ON | All American Lemonade Ordered...");
  //server.send(200, "text/html", SendHTML(true, LED2status));
  
  delay(5000);

  digitalWrite(LED1pin, LOW);
  Serial.println("GPIO7 Status: OFF");
  //server.send(200, "text/html", SendHTML(false, LED2status));
}

void handle_orderLaPlaya(){
  digitalWrite(LED2pin, HIGH);
  Serial.println("GPIO7 Status: ON | All American Lemonade Ordered...");
  //server.send(200, "text/html", SendHTML(true, LED2status));
  
  delay(5000);

  digitalWrite(LED2pin, LOW);
  Serial.println("GPIO7 Status: OFF");
  //server.send(200, "text/html", SendHTML(false, LED2status));
}

void handle_orderTequilaSun(){
  digitalWrite(LED0pin, HIGH);
  Serial.println("GPIO7 Status: ON | All Tequila Sunrise Ordered...");
  //server.send(200, "text/html", SendHTML(true, LED2status));
  
  delay(5000);

  digitalWrite(LED0pin, LOW);
  Serial.println("GPIO7 Status: OFF");
}

void handle_orderCapeCod(){
  digitalWrite(LED3pin, HIGH);
  Serial.println("GPIO7 Status: ON | Cape Cod Ordered...");
  //server.send(200, "text/html", SendHTML(true, LED2status));
  
  delay(5000);

  digitalWrite(LED3pin, LOW);
  Serial.println("GPIO7 Status: OFF");
}

void handle_OnConnect() {
  digitalWrite(LED1pin, LOW);
  digitalWrite(LED2pin, LOW);
  Serial.println("GPIO7 Status: OFF | GPIO6 Status: OFF");
  //server.send(200, "text/html", SendHTML(LED1status,LED2status)); 
}

void handle_led1on() {
  digitalWrite(LED1pin, HIGH);
  Serial.println("GPIO7 Status: ON");
  //server.send(200, "text/html", SendHTML(true,LED2status)); 
}

void handle_led1off() {
  digitalWrite(LED1pin, LOW);
  Serial.println("GPIO7 Status: OFF");
  //server.send(200, "text/html", SendHTML(false,LED2status)); 
}

void handle_led2on() {
  digitalWrite(LED2pin, HIGH);
  Serial.println("GPIO6 Status: ON");
  //server.send(200, "text/html", SendHTML(LED1status,true)); 
}

void handle_led2off() {
  digitalWrite(LED2pin, LOW);
  Serial.println("GPIO6 Status: OFF");
  //server.send(200, "text/html", SendHTML(LED1status,false)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(uint8_t led1stat,uint8_t led2stat){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>LED Control</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #1abc9c;}\n";
  ptr +=".button-on:active {background-color: #16a085;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>ESP8266 Web Server</h1>\n";
  ptr +="<h3>Using Access Point(AP) Mode</h3>\n";
  
   if(led1stat)
  {ptr +="<p>LED1 Status: ON</p><a class=\"button button-off\" href=\"/led1off\">OFF</a>\n";}
  else
  {ptr +="<p>LED1 Status: OFF</p><a class=\"button button-on\" href=\"/led1on\">ON</a>\n";}

  if(led2stat)
  {ptr +="<p>LED2 Status: ON</p><a class=\"button button-off\" href=\"/led2off\">OFF</a>\n";}
  else
  {ptr +="<p>LED2 Status: OFF</p><a class=\"button button-on\" href=\"/led2on\">ON</a>\n";}

  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
