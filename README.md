# esp32_cam_oled
========================================

This repository hosts ESP32 compatible driver for OV264 image sensors 0.96inch SSD1306 Oled display screen.


HW Kit:
========================================

CP2102 usb to serial port.

esp32-cam demo from Aithink.

ssd1306 oled(128*64).

2A/5VDC Power adapter.
========================================

Programming environment:

win10 64bit

Eclipse 2020-06


software install version:
========================================
esp-idf 4.0.1    --------https://docs.espressif.com/projects/esp-idf/en/v4.0.1/get-started/index.html

esp-idf-tools-setup-2.3.exe   --------https://docs.espressif.com/projects/esp-idf/en/v4.0.1/get-started/index.html

after this two steps,you can build example demo through ESP-IDF Command Prompt window, and then go on follow steps.

jdk-11.0.8_windows-x64_bin.exe   --------https://www.oracle.com/java/technologies/javase-jdk11-downloads.html

Git-2.21.0-64-bit.exe    --------https://git-scm.com/downloads

python-3.7.3-amd64.exe    --------https://www.python.org/downloads/release/python-373/

eclipse-inst-win64.exe    --------https://www.eclipse.org/downloads/packages/release/2020-06/r

eclipse-plugin install reference    --------https://github.com/espressif/idf-eclipse-plugin


environment reference document:
========================================
https://docs.espressif.com/projects/esp-idf/en/v4.0.1/get-started/index.html

https://github.com/espressif/idf-eclipse-plugin


OLED I2C HW interface:
========================================
SCL PORT14.

SDA PORT15.

PORT0.

MASTER FREQUENCY 100000.

I2C_SLAVE_ADDRESS 3C.


Demo function:
========================================
smart config.

camera ov2640.

exposure value adjustable.

0.9inch oled ssd1306.
