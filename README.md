# 🌱 Automatic Smart Compost Bin

![Status](https://img.shields.io/badge/Status-Completed-success)
![Platform](https://img.shields.io/badge/Platform-ArduinoIDE-blue)
![Language](https://img.shields.io/badge/Language-C++-orange)
![IoT](https://img.shields.io/badge/IoT-Blynk-brightgreen)
![License](https://img.shields.io/badge/License-MIT-yellow)

An IoT-enabled Automatic Smart Compost Bin that converts organic waste into nutrient-rich compost and liquid fertilizer with minimal human intervention. The system monitors compost conditions in real time and automates mixing, aeration, and compost transfer using sensors, motors, and servos.

---

## 📖 Overview

Traditional composting requires frequent manual monitoring and mixing, making it time-consuming and inefficient.

This project automates the complete composting process using an ESP32 microcontroller, multiple sensors, DC motors, servo motors, and the Blynk IoT platform.

The system continuously monitors compost conditions and performs actions automatically to improve compost quality while reducing human effort.

---

## ✨ Features

- 🌡 Real-time Temperature Monitoring
- 💧 Moisture Monitoring
- 📦 Compost Level Detection
- 🔄 Automatic Mixing
- ⚙ Automatic Compost Transfer
- 📱 IoT Monitoring using Blynk
- 🌿 Liquid Fertilizer Collection
- ♻ Multi-Chamber Composting
- 🔔 Mobile Notifications

---

## 🛠 Hardware Used

| Component                  |  Quantity |
|----------------------------|-----------|
| ESP32                      |     1     |
| Arduino UNO                |     1     |
| DHT22 Sensor               |     1     |
| DS18B20 Temperature Sensor |     1     |  
| Capacitive Moisture Sensor |     1     |    
| Ultrasonic Sensors         |     3     |
| Servo Motors               |     2     |
| DC Gear Motors             |     2     |
| L298N Motor Driver         |     1     |
| Float Sensor               |     1     |
| Li-ion Battery             |     1     |

---

## 💻 Software Used

- Arduino IDE
- Blynk IoT
- C++
- ESP32 Libraries

---

## ⚙ Working Principle

```
Organic Waste
      │
      ▼
Waste Collection
      │
      ▼
Waste Chopping
      │
      ▼
Automatic Mixing
      │
      ▼
Temperature & Moisture Monitoring
      │
      ▼
IoT Dashboard (Blynk)
      │
      ▼
Automatic Compost Transfer
      │
      ▼
Finished Compost
      │
      ├────────► Liquid Fertilizer
      ▼
Organic Compost
```

---

## 🏗 Project Architecture

The system consists of four chambers:

### Chamber 1
- Detects lid opening using Ultrasonic Sensor
- Runs Motor 1 for chopping and mixing
- Detects compost level

### Chamber 2
- Monitors moisture
- Automatic mixing every two hours
- Transfers compost when temperature condition is satisfied

### Chamber 3
- Detects finished compost level
- Sends notification

### Chamber 4
- Collects liquid fertilizer
- Float sensor detects liquid level

---

## 📸 Project Images

### Prototype

<img width="510" height="713" alt="image" src="https://github.com/user-attachments/assets/f57957d8-6c85-4c11-8ae7-8a953b77bcb5" />


### CAD Model

<img width="1031" height="794" alt="image" src="https://github.com/user-attachments/assets/8177b455-6f1e-4994-af80-0259d9054eb5" />

### IoT Dashboard

<img width="794" height="648" alt="image" src="https://github.com/user-attachments/assets/38f320cf-2df9-429c-bbe4-94ccb6bf0029" />

### Flowchart

<img width="1004" height="860" alt="image" src="https://github.com/user-attachments/assets/46d68a9c-bb49-4bfe-8534-fc25d104978b" />

---

## 📂 Folder Structure

```
smart-compost-bin

├── code
│   └── mini_exh.ino

├── images

├── report
│   ├── Full_Project_Report.pdf
│   └── Mini_Report.pdf

├── presentation
│   └── Smart_Compost_Bin_Presentation.pptx

├── circuit

├── README.md

├── LICENSE

└── .gitignore
```

---

## 🚀 Future Improvements

- AI-based compost quality prediction
- Solar-powered operation
- Mobile Application
- Gas Sensors
- Automatic Nutrient Analysis
- Cloud Data Analytics

---

## 👩‍💻 Team

- Nishmitha
- Moolya Pratiksha Shekhar
- Prerana Shetty

Guide:
Mr. Ganesh Shetty

---

## 📜 License

This project is licensed under the MIT License.

---

## ⭐ If you like this project

Please consider giving it a ⭐ on GitHub.
