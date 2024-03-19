# Environmental Sensor     

# Kullanılan ürünler 

|Kullanılan ürünler|
| ----------- |
|[ESP Foto](https://www.direnc.net/esp32-wroom-32d-wifi-bluetooth-gelistirme-modulu-esp-board-espressif-50018-18-B.jpg)|
|[ZPHS01B Sensor](https://www.winsen-sensor.com/product/zphs01b.html)|
|voltage regulatör (12V to 5V)|
|power suply (12V 3A)|


# bağlantılar 
| Bağlantı pinleri     | | 
| ----------- | ----------- |
| ESP32-g17(tx) | ZPHS01B Sensor module rx pin |  
|ESP32-g16(rx) | ZPHS01B Sensor module tx pin | 
|ESP32-usb | PC   |
|ESP32- GND | ortak GND hattı  |
|ZPHS01B Sensor module GND pin | ortak GND hattı  |
|ZPHS01B Sensor module Vin pin | Voltage regulatör Vout pin|
|Voltage regulatör Vin pin | 12V power Suply|
|Voltage regulatör GND pin | ortak GND hattı|
|12V power Suply | ortak GND hattı|

