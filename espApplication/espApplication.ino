#include <ESP8266WiFi.h>
#include <InfluxDbClient.h>

//wifi configs
String ssid = "wifi_ssid";
String password = "wifi_password";

// InfluxDB 2 server url, e.g. http://192.168.1.48:9999 (Use: InfluxDB UI -> Load Data -> Client Libraries)
#define INFLUXDB_URL "http://192.168.100.4:8086"
// InfluxDB v1 database name 
#define INFLUXDB_DB_NAME "arduinoDay"

#define DEVICE "Sensor Temperature 01"
//influx database user 
#define DB_USER "admin"
//influx database password 
#define DB_PASSWORD "admin"

// Data point to write on db
Point sensor("data");

// client that will connect with influx db
InfluxDBClient client(INFLUXDB_URL, INFLUXDB_DB_NAME);

void setup() {
  Serial.begin(9600);
  //connect on wifi
  setupWifi();

   //connect with influxdb
  client.setConnectionParamsV1(INFLUXDB_URL, INFLUXDB_DB_NAME, DB_USER, DB_PASSWORD);

  checkInflux();
  
  // Add constant tags - only once (tags are optional, just for organize the data or extra information)
  sensor.addTag("device", DEVICE); 
}

void checkInflux(){
  // Check server connection
  if (client.validateConnection()) {
    Serial.print("Connected to InfluxDB: ");
    Serial.println(client.getServerUrl());
  } 
  else {
      Serial.print("InfluxDB connection failed: ");
      Serial.println(client.getLastErrorMessage());
    }
 }

void setupWifi(){
  WiFi.begin(ssid.c_str(),password.c_str());
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) 
  {
     Serial.print(".");
     delay(500);
  }
  Serial.println();
  Serial.println("Connection successful"); 
}

void loop(){
  // Store measured value into point
  sensor.clearFields();
  
  //value read from sensor
  float data = 23.1;
  
  //write the data on "Temperature" collumn
  sensor.addField("Temperature", data);
  
  // Print what are we exactly writing
  Serial.print("Writing: ");
  Serial.println(sensor.toLineProtocol());

  // Write point
  if (!client.writePoint(sensor)) {
    Serial.print("InfluxDB write failed: ");
    Serial.println(client.getLastErrorMessage());
  }

  //Wait 1s
  Serial.println("Wait 1s");
  delay(1000);
}
