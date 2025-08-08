Heating Control System with LCD and DHT22
📌 Project Overview
This project is a temperature-based heater control system implemented using an Arduino Uno, DHT22 temperature sensor, LCD with I2C module, heater simulation, and a buzzer.
It continuously reads the temperature and adjusts the heater state accordingly while displaying the status on both the Serial Monitor and LCD.

The system operates in the following states:

Idle – System is on but no heating required.

Heating – Heater is ON, raising temperature.

Stabilizing – Temperature is near the target.

Target Reached – Desired temperature achieved.

Overheat – Temperature exceeds safety limit, buzzer alerts.

🛠 Components Used
Arduino Uno

DHT22 Temperature Sensor

16x2 LCD with I2C Interface (0x27)

Buzzer

Heater (simulated with LED)

Jumper Wires

Breadboard

📐 Circuit Connections
Component	Arduino Pin
DHT22 Data Pin	D2
LCD SDA	A4
LCD SCL	A5
Heater (LED)	D8
Buzzer	D9
Power (VCC)	5V
Ground (GND)	GND

⚙️ Working Principle
The DHT22 sensor measures the ambient temperature.

Based on thresholds:

< 25°C → Heating (Heater ON)

25°C to < 28°C → Stabilizing

28°C to < 30°C → Target Reached

>= 30°C → Overheat (Buzzer ON, Heater OFF)

Status is displayed on both:

Serial Monitor

16x2 LCD

Updates every 2 seconds.

📋 Features
✅ Real-time temperature monitoring
✅ State-based heating control
✅ LCD display with temperature & state info
✅ Serial Monitor logging
✅ Overheat protection with buzzer alert

📊 Future Roadmap
Overheating Protection – More advanced shutdown and alert system.

Multiple Heating Profiles – Adjustable target temperatures for different use cases.

Wireless Monitoring – Integrating Wi-Fi/Bluetooth for remote control.

Data Logging – Store temperature readings for analysis.

📦 How to Run the Project
Open Wokwi Simulation Link.
https://wokwi.com/projects/438699119046673409

Click Start Simulation.

Observe temperature readings and state changes on both LCD & Serial Monitor.

📜 License
This project is open-source under the MIT License.
