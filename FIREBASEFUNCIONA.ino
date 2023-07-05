#include <SoftwareSerial.h>
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define WIFI_SSID "UAT_Personal"
#define WIFI_PASSWORD "UtvmTezo123$"

#define FIREBASE_HOST "https://bastonint-5ee6c-default-rtdb.firebaseio.com"  //Change to your Firebase RTDB project ID e.g. Your_Project_ID.firebaseio.com
#define FIREBASE_AUTH "jj0vm6m7iARRLgREtFUs2sWzApFv19qkRvFv3IF8" //Change to your Firebase RTDB secret password


String dato="";
void setup() {
  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println();
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
      Serial.print(".");
      delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

}


//Definir objetos de datos de Firebase
FirebaseData firebaseData1;

int numero = 0;

void loop() {

 
  numero = numero +1;
  dato=numero;
  if (Firebase.setString(firebaseData1, "Ubi/ejemplo",dato))
  {
    Serial.println("Datos enviados correctamente");
  }
  else
  {
      Serial.println("Datos enviados con falla");
  }
  delay(2000);
}
}
