# Smart_Parking_System_ESP32

This project is a simple **Smart Parking System** simulation built using **ESP32** and **Ultrasonic Sensors** in [Wokwi](https://wokwi.com/projects/443415059472220161).  
It detects whether a parking slot is **occupied** or **available** and shows the status using LEDs.

## 🚗 Features
- Detects vehicles using Ultrasonic Sensor (HC-SR04)
- Red LED → Slot Occupied
- Green LED → Slot Available
- Displays status in Serial Monitor

## 🛠 Components Used
- ESP32
- Ultrasonic Sensor (HC-SR04)
- Red & Green LEDs

## ⚡ Working
1. ESP32 sends a 10µs pulse to the TRIG pin.
2. Ultrasonic sensor emits sound waves at 40kHz.
3. ECHO pin stays HIGH for the duration of the wave's round trip.
4. ESP32 calculates the distance using:  Distance = (time * 0.034) / 2
5. If distance < 150 cm → slot occupied (Red LED ON).  
If distance >= 150 cm → slot free (Green LED ON).

