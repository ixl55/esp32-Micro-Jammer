# esp32-Micro-Jammer

A program to jam all things that operate at a frequency of 2.4 KHz and cut off and stop their work 
But it is designed to work with ESP32 C3 to be small in size

# Bonding steps
<table>
  <thead>
    <tr>
      <th>nrf</th>
      <th>esp32_c3</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>VCC</td>
      <td>3.3V</td>
    </tr>
    <tr>
      <td>GND</td>
      <td>GND</td>
    </tr>
    <tr>
      <td>CE</td>
      <td>GPIO 20</td>
    </tr>
     <tr>
      <td>CNS</td>
      <td>GPIO 21</td>
    </tr>
     <tr>
      <td>SCK</td>
      <td>GPIO 4</td>
    </tr>
    </tr>
     <tr>
      <td>MOSI</td>
      <td>GPIO 6</td>
    </tr>
    <tr>
      <td>MISO</td>
      <td>GPIO 5</td>
    </tr>
  </tbody>
</table>


# Installation and commissioning steps for ESP32-C3
1. Arduino IDE Installation
Download and install the Arduino IDE software on your device.
[Arduino IDE](https://www.arduino.cc/en/software)

2. Added ESP32 support to Arduino
Open the Arduino IDE program.
Go to:
File → Preferences
In the Additional Board Manager URLs box, add the following link:
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
Now head to:
Tools → Board → Boards Manager
Find esp32 and install the official package from Espressif Systems.

3. Connecting ESP32-C3 Super Mini
Connect the board using a USB-C cable.
If your computer doesn't recognize them, you may need to install definitions

CH340 driver :[ch340](https://sparks.gogo.co.nz/ch340.html)

 CP210x driver :[CP210x](https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers)

5. Board Settings
Go to the Tools menu and then adjust the following settings:

Board: Select ESP32C3 Dev Module

Upload Speed: Make it 115200

Port: Choose the correct port


# end
![goost fase](https://github.com/user-attachments/assets/240a771a-7620-4323-8c2e-825f120c3634)


**Use it legally..**
