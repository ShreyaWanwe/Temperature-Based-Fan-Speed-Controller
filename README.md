# Temperature-Based Fan Speed Controller

## Overview
The motivation to create a temperature-based fan speed controller lies in achieving energy efficiency, noise reduction, and optimized cooling.

By adjusting fan speed based on temperature, this system ensures efficient cooling when needed, reduces energy consumption during lower temperature periods, extends fan lifespan, and provides a cost-effective, customizable solution for applications requiring precise temperature control.

Additionally, the system incorporates an **IR sensor** to detect motion. If no object is detected in the vicinity, the fan automatically turns off, further improving energy efficiency.

## Working Principle
- The **LM35 temperature sensor** senses the temperature and converts it into an electrical (analog) signal.
- This analog signal is applied to the **ATmega328 microcontroller** on the Arduino UNO board.
- The analog value is converted into a digital value using the microcontroller’s ADC (Analog-to-Digital Converter).
- The calculated percentage is sent to the **DC fan** through a **PWM (Pulse-Width Modulation) signal**, adjusting the fan speed by varying the duty cycle.
- The microcontroller dynamically controls the fan speed based on the temperature, allowing fast and responsive adjustments.
- The **sensed temperature (°C) and fan speed (%)** are displayed simultaneously on the **Serial Monitor**.
- The **IR sensor** detects motion and turns off the fan when no object is in the vicinity.

## Block Diagram
![image](https://github.com/user-attachments/assets/42a2e4a1-10bb-426f-9d5e-0bcc69a3bc4a)

## Features
- **Automatic fan speed adjustment** based on temperature variations.
- **Energy-efficient operation**, reducing power consumption when cooling demand is low.
- **Motion-based fan control**, turning off the fan when no object is detected.
- **Noise reduction** by minimizing unnecessary high-speed operation.
- **PWM-based speed control**, ensuring smooth transitions and precise control.
- **Real-time monitoring** via Serial Monitor.


## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/temp-fan-controller.git
   cd temp-fan-controller
2. Open the arduino_code.ino file in Arduino IDE.
3. Connect your Arduino UNO board to your computer.
4. Upload the code to the board.

## Usage
- Ensure the LM35 sensor and DC fan are connected properly.
- Upload the .ino file to the Arduino.
- Open the Serial Monitor to observe real-time temperature and fan speed readings.
