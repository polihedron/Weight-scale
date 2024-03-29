# Weight-scale
Simple weight scale
features:
- sensor calibration (manual)
- save calibration data to memory
- restore factory calibration data
- touch the result on display to tare
- 20kg sensor
- fast TouchGFX app (LL SPI with DMA) 
- usb c charging port
<br><br>
made on request to control baby weight increase.
<br><br>
![set](https://github.com/polihedron/Weight-scale/blob/main/hardware/images/set.png)

![calibration](https://github.com/polihedron/Weight-scale/blob/main/hardware/images/calibration.png)

![keypad](https://github.com/polihedron/Weight-scale/blob/main/hardware/images/keypad.png)

![side](https://github.com/polihedron/Weight-scale/blob/main/hardware/images/side.png)


<br><br><br>
based on:

https://github.com/trteodor/TouchGFX_PortTo_STM32F407_ILI9341_XPT2046

https://www.youtube.com/playlist?list=PLfIJKC1ud8giOsk-C4BCOwSHtbXqTNb1W

<br><br><br>



BOM:
- WeAct v2 Blackpill STM32F411CEU dev board with soldered U3: FRAM 8kB chip: MB85RS64V (Adafruit 1897)
  
![WeAct-BlackPill-STM32F411CEU6](https://github.com/polihedron/Weight-scale/assets/46649005/a673c8fb-c529-4fd7-a067-855d05bcb38b)
![Adafruit 1897](https://github.com/polihedron/Weight-scale/assets/46649005/0777359c-920b-44ce-bacb-f0b146e66840)


- LCD SPI Display 2.8" ILI9341 controler
  
![2-8-240-320-ILI9341](https://github.com/polihedron/Weight-scale/assets/46649005/76b1ee89-46b1-46b1-a3c4-219409ef1f17)


- 20kg sensor with HX711 module
  
  ![HX711](https://github.com/polihedron/Weight-scale/assets/46649005/3c946ab7-b89d-4482-9f27-b4ced3ed8bf4)


- 18750 lithium battery 1S2P, or 1S1P with welding cable

  ![18650-Li-ion](https://github.com/polihedron/Weight-scale/assets/46649005/acbf18a0-dff7-4790-a5e0-cc70077a30d9)



- TPS63020 module
  
![XL63020-TPS63020](https://github.com/polihedron/Weight-scale/assets/46649005/953dd725-5dd0-478c-9b5c-fef0846f7044)



- TP4056 module
  
![TC4056A](https://github.com/polihedron/Weight-scale/assets/46649005/2ee10065-c3de-41d2-b03a-b316fe54d963)



