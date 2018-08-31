/*
 * Program to send the motion details on a webserver using nodemcu
 * Author:ianuj03
 */
#include<ESP8266WiFi.h>
#define MOTION D7
WiFiClient web;
const char* ssid="ianuj03";//Change to wifi SSID
const char* pswd="PASW";//Change 

const char* host="";
//In case of localhost, IP in the network; else the static IP of your web

String GET="GET /nodemcu/motion.php?state=";
//PHP URL to enter the data in the database
void setup(){
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);//is used to connect to the network
  WiFi.begin(ssid,pswd);//connect to the network
  delay(300);//time delay to complete the task, used to overcome the systemtic error
  Serial.println(WiFi.status());//get the status of connection
  pinMode(MOTION,OUTPUT);
}
String GET1;//will be used as a temperoary variable
void loop(){
  if(web.connect(host,80)){//connects to the server and then returns the status of the connection
    GET1=GET;
    GET1+=String(digitalRead(MOTION));
    web.println(GET1);//sends the request to server
    delay(500);//time delay to complete the task, usually becuase of the network issue
    if(web.available()){
      String data=web.readString();
      Serial.println(data);
    }
    delay(3000);//Minimum time for PIR to reset is 3 sec
  }
}
