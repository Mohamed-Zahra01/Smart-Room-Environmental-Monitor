# Smart-Room-Environmental-Monitor
An Arduino-based system to monitor temperature and light intensity, display values on an LCD, and control a fan and LED based on conditions.
## 📌 Project Description
This project is an Arduino-based smart room system that monitors temperature and light conditions and automatically controls fan speed and lighting accordingly.
## 🎯 Objective
To design a simple smart environment system that can:
- Measure room temperature using LM35
- Measure light intensity using LDR
- Control fan speed based on temperature
- Control LEDs based on light conditions
- Display system status on LCD

## ⚙️ System Components
- Arduino Uno
- LM35 Temperature Sensor
- LDR (Light Sensor)
- 16x2 LCD with I2C
- 2 LEDs
- DC Fan

## 🔌 Circuit Connections
- LM35 → A0
- LDR → A1 (with resistor)
- LED1 → D8
- LED2 → D9
- Fan → D10 (PWM)
- LCD → SDA (A4), SCL (A5)

## 🧠 System Logic
The system works in three stages:

### 1. Sensing
- Reads temperature and light values

### 2. Processing
- Classifies temperature (Cold, Normal, Hot)
- Classifies light (Dark, Normal light, Bright)

### 3. Control
- Fan speed increases gradually with temperature
- LEDs turn on depending on light conditions

## 📊 LCD Display
The LCD displays:
- Temperature value
- Light condition
- Fan speed percentage
- Room status

## 💡 Smart Features
- Automatic fan speed control using PWM
- Multi-condition decision system
- Real-time display of system status

## 🚀 Conclusion
This project demonstrates how simple sensors can be integrated into a smart system that makes real-time decisions and controls outputs efficiently.
