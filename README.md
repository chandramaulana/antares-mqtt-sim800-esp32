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
<p>/oneM2M/req/8b175a2ca85aa24e:11e5aae47db9ef5d/antares-cse/json</p>
<p><br></p>
<p><br></p>
<p>{</p>
<p>&nbsp; &nbsp;&quot;m2m:rqp&quot;:{</p>
<p>&nbsp; &nbsp; &nbsp; &quot;fr&quot;:&quot;8b175a2ca85aa24e:11e5aae47db9ef5d&quot;,</p>
<p>&nbsp; &nbsp; &nbsp; &quot;to&quot;:&quot;/antares-cse/antares-id/Monitoring_Suhu/esp32-sim&quot;,</p>
<p>&nbsp; &nbsp; &nbsp; &quot;op&quot;:1,</p>
<p>&nbsp; &nbsp; &nbsp; &quot;rqi&quot;:123456,</p>
<p>&nbsp; &nbsp; &nbsp; &quot;pc&quot;:{</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&quot;m2m:cin&quot;:{</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &quot;cnf&quot;:&quot;message&quot;,</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &quot;con&quot;:&quot;{\&quot;suhu\&quot;:23,\&quot;kelembaban\&quot;:84}&quot;</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;}</p>
<p>&nbsp; &nbsp; &nbsp; },</p>
<p>&nbsp; &nbsp; &nbsp; &quot;ty&quot;:4</p>
<p>&nbsp; &nbsp;}</p>
<p>}</p>

