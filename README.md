# antares-mqtt-sim800-esp32

<h2>
Menghubungkan Platform antares dengan protokol MQTT  (SIM 800L - ESP WROOM 32)
</h2>

<br>
NOTE ://<br>
Gunakan Arduino IDE Terbaru : 
dan 
Siapkan Library terbaru dari : 

#include <TinyGsmClient.h> <br>
#include <PubSubClient.h> <br>
#include <ArduinoJson.h> <br>


Pastikan Power dari SIM800L Stabil. <br>



Subscribe Topic: <br>
/oneM2M/resp/antares-cse/8b175a2ca85aa24e:11e5aae47db9ef5d/json <br>




Publish Topic:  <br>
/oneM2M/req/8b175a2ca85aa24e:11e5aae47db9ef5d/antares-cse/json <br>

<p> <br>
Payload :  <br>
{ <br>
   "m2m:rqp":{  <br>
      "fr":"8b175a2ca85aa24e:11e5aae47db9ef5d", <br>
      "to":"/antares-cse/antares-id/Monitoring_Suhu/esp32-sim", <br>
      "op":1, <br>
      "rqi":123456, <br>
      "pc":{ <br>
         "m2m:cin":{ <br>
            "cnf":"message", <br>
            "con":"{\"suhu\":23,\"kelembaban\":84}" <br>
         } <br>
      }, <br>
      "ty":4 <br>
   } <br>
} <br>


