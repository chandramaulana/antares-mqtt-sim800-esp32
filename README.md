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



<p>Subscribe :&nbsp;</p>
<p>/oneM2M/resp/antares-cse/8b175a2ca85aa24e:11e5aae47db9ef5d/json</p>
<p><br></p>
<p><br></p>
<p><br></p>
<p><br></p>
<p>Publish :&nbsp;</p>
<p>/oneM2M/req/b07f83b1409132e9:84c6cc0b97b86892/antares-cse/json</p>
<p>{</p>
<p> &quot;m2m:rqp&quot;:{</p>
<p> &quot;fr&quot;:&quot;b07f83b1409132e9:84c6cc0b97b86892&quot;,</p>
<p> &quot;to&quot;:&quot;/antares-cse/antares-id/MQTT_Testing/device1&quot;,</p>
<p> &quot;op&quot;:1,</p>
<p> &quot;rqi&quot;:123456,</p>
<p> &quot;pc&quot;:{</p>
<p> &quot;m2m:cin&quot;:{</p>
<p> &quot;cnf&quot;:&quot;message&quot;,</p>
<p> &quot;con&quot;:&quot;{\&quot;suhu\&quot;:23,\&quot;kelembaban\&quot;:84}&quot;</p>
<p> }</p>
<p> },</p>
<p> &quot;ty&quot;:4</p>
<p> }</p>
<p>}</p>

