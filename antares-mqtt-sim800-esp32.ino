#define TINY_GSM_MODEM_SIM800

#include <TinyGsmClient.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

const char apn[]  = "internet";
const char user[] = "";
const char pass[] = "";

String broker = "mqtt.antares.id";
String port = "1883";
String projectname = "Monitoring_Suhu";
String devicename = "esp32-sim";
String acceskey = "8b175a2ca85aa24e:11e5aae47db9ef5d";
String pesan;

TinyGsm modem(Serial2);
TinyGsmClient client(modem);
PubSubClient mqtt(client);

unsigned long previousMillis = 0;
const long interval = 5000;

void setup()
{
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, 16, 17);

  Serial.println("System start.");
  modem.restart();
  Serial.println("Modem: " + modem.getModemInfo());
  Serial.println("Searching for provider.");
  if (!modem.waitForNetwork())
  {
    Serial.println("fail");
    while (true);
  }
  Serial.println("Connected to provider.");
  Serial.println("Signal Quality: " + String(modem.getSignalQuality()));

  Serial.println("Connecting to GPRS network.");
  if (!modem.gprsConnect(apn, user, pass))
  {
    Serial.println("fail");
    while (true);
  }

  Serial.println("Connected to GPRS: " + String(apn));
  mqtt.setServer((char*) broker.c_str(), port.toInt());
  mqtt.setCallback(mqttCallback);
  Serial.println("Connecting to MQTT Broker: " + String(broker));
  while (mqttConnect() == false) continue;
  Serial.println();
}

void loop()
{

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval)
  {
    pesan = "";
    pesan += "{";
    pesan += "\\\"suhu\\\":";
    pesan += String(random(20, 40)) + ",";
    pesan += "\\\"kelembaban\\\":";
    pesan += String(random(80, 100));
    pesan += "}";

    pub_antares(projectname, devicename, acceskey, pesan);

    String topic_subscribe = "/oneM2M/resp/antares-cse/" + acceskey + "/json";
    char finalsubs2[topic_subscribe.length() + 1];
    topic_subscribe.toCharArray(finalsubs2, topic_subscribe.length() + 1);
    mqtt.subscribe(finalsubs2);
    previousMillis = currentMillis;
  }

  if (mqtt.connected())
  {
    mqtt.loop();
  }
}

void pub_antares(String projectName, String deviceName, String _accessKey, String _jsonDataString)
{
  String topic = "/oneM2M/req/" + _accessKey + "/antares-cse/json";
  String finalData;
  Serial.println(topic);
  finalData += "{";
  finalData += "\"m2m:rqp\": {";
  finalData += "\"fr\": \"" + _accessKey + "\",";
  finalData += "\"to\": \"/antares-cse/antares-id/" + projectName + "/" + deviceName + "\",";
  finalData += "\"op\": 1,";
  finalData += "\"rqi\": 123456,";
  finalData += "\"pc\": {";
  finalData += "\"m2m:cin\": {";
  finalData += "\"cnf\": \"message\",";
  finalData += "\"con\": \"" + _jsonDataString + "\"";
  finalData += "}";
  finalData += "},";
  finalData += "\"ty\": 4";
  finalData += "}";
  finalData += "}";

  char finalDataChar[finalData.length() + 1];
  char topicChar[topic.length() + 1];
  finalData.toCharArray(finalDataChar, finalData.length() + 1);
  topic.toCharArray(topicChar, topic.length() + 1);
  mqtt.publish(topicChar, finalDataChar);
  Serial.println();
  Serial.println(finalData);
  Serial.println();
  Serial.println();
}

boolean mqttConnect()
{
  if (!mqtt.connect("testing", "1", "1"))
  {
    Serial.print(".");
    return false;
  }
  Serial.println("Connected to broker.");
  return mqtt.connected();
}

void mqttCallback(char* topic, byte* payload, unsigned int length)
{
  String pay = parsing_subscribe(topic, payload, length);
  Serial.print("Data Payload Subscribe : ");
  Serial.println(pay);
}

String parsing_subscribe(char* topic, byte* payload, unsigned int length)
{
  String _receivedTopic = String(topic);
  String payloadString, parsedStringx;
  for (int i = 0; i < length; i++)
  {
    payloadString += char(payload[i]);
  }
  DynamicJsonDocument  jsonBuffer(1024);
  deserializeJson(jsonBuffer, payloadString);
  String parsedString = jsonBuffer["m2m:rsp"]["pc"]["m2m:cin"]["con"];
  parsedStringx = parsedString;

  return parsedStringx;
}
