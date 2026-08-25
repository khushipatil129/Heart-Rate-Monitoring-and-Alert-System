#  Heart Rate Monitoring & Emergency Alert System

**An Arduino-based real-time heart rate monitoring system that automatically sends SMS alerts to predefined emergency contacts when the detected heart rate falls below a configured threshold.**

---

##  Table of Contents

* [Project Overview](#-project-overview)
* [Problem Statement](#-problem-statement)
* [Objectives](#-objectives)
* [Key Features](#-key-features)
* [User Roles](#-user-roles)
* [Application Workflow](#-application-workflow)
* [Functional Requirements](#-functional-requirements)
* [Project Design](#-project-design)
* [Future Enhancements](#-future-enhancements)
* [Project Information](#-project-information)
* [Project Status](#-project-status)
* [License](#-license)

---

##  Project Overview

The **Heart Rate Monitoring & Emergency Alert System** is an Arduino-based embedded system designed to continuously monitor a person's heart rate and provide an automated emergency notification when the detected heart rate falls below a predefined threshold.

The system uses a **Pulse Sensor** to detect the user's heartbeat and an **Arduino UNO** to process the sensor readings and calculate the heart rate in **Beats Per Minute (BPM)**.

When the heart rate drops below the configured threshold of **60 BPM**, the Arduino communicates with a **SIM800 GSM module**, which sends an SMS alert to **three predefined emergency contacts**.

The project combines **sensor interfacing, embedded programming, signal processing, UART communication, and GSM technology** to create a simple prototype for emergency heart-rate monitoring.

> ⚠️ **Disclaimer:** This project is an educational prototype and is not intended to replace certified medical monitoring equipment or professional medical advice.

---

##  Problem Statement

Sudden changes in heart rate may require immediate attention, especially when a person is alone or when continuous supervision is not available.

Traditional monitoring systems may require a person to constantly observe the patient's heart rate and manually notify others during an emergency.

This project aims to develop a **low-cost automated monitoring system** that can:

* Continuously monitor heart rate.
* Detect when the heart rate falls below a predefined threshold.
* Automatically notify emergency contacts.
* Reduce the need for constant manual monitoring.
* Provide a simple and accessible embedded-system solution.

---

##  Objectives

The main objectives of this project are:

1. To continuously monitor heart rate using a pulse sensor.
2. To calculate and display the heart rate in BPM.
3. To establish communication between the Arduino UNO and SIM800 GSM module.
4. To detect when the heart rate falls below the configured threshold.
5. To automatically send an emergency SMS to predefined contacts.
6. To provide a simple, low-cost, and portable monitoring prototype.
7. To demonstrate the practical application of embedded systems in healthcare-related monitoring.

---

##  Key Features

* Real-time heart rate monitoring
* BPM calculation
* Automatic emergency detection
* SMS-based emergency notification
* Alert sent to three emergency contacts
* Pulse sensor interfacing
* SIM800 GSM communication
* Configurable heart-rate threshold
* Serial Monitor for system output
* Arduino UNO-based implementation
* Potential for portable operation

---

##  User Roles

The system involves the following roles:

### 1. User / Patient

The person whose heart rate is being monitored.

**Responsibilities:**

* Wear or place the pulse sensor correctly.
* Ensure the monitoring system is powered.
* Remain within suitable operating conditions for accurate readings.

### 2. Emergency Contact

A predefined person who receives an SMS when the system detects a heart rate below the configured threshold.

**Responsibilities:**

* Receive the emergency notification.
* Check on the monitored person.
* Take appropriate action when necessary.

### 3. System / Administrator

The person responsible for configuring and maintaining the system.

**Responsibilities:**

* Configure emergency contact numbers.
* Set the heart-rate threshold.
* Maintain the hardware.
* Upload or update the Arduino program.

---

##  Application Workflow

```text
              ┌───────────────────┐
              │   Start System    │
              └─────────┬─────────┘
                        ↓
              ┌───────────────────┐
              │ Initialize Arduino│
              │ & GSM Module      │
              └─────────┬─────────┘
                        ↓
              ┌───────────────────┐
              │ Read Pulse Sensor │
              └─────────┬─────────┘
                        ↓
              ┌───────────────────┐
              │ Calculate Heart   │
              │ Rate (BPM)        │
              └─────────┬─────────┘
                        ↓
                 ┌──────────────┐
                 │   BPM < 60?  │
                 └──────┬───────┘
                    NO  │  YES
                ┌───────┘  └────────┐
                ↓                   ↓
       Continue Monitoring    Send Emergency
                              SMS through GSM
                                    │
                                    ↓
                           Emergency Contacts
                                    │
                                    ↓
                            Continue Monitoring
```

### Workflow Description

1. The system is powered on.
2. The Arduino initializes the pulse sensor and GSM module.
3. The pulse sensor continuously detects heartbeat signals.
4. Arduino processes the signal and calculates BPM.
5. The BPM value is monitored against the configured threshold.
6. If the BPM is above the threshold, monitoring continues normally.
7. If the BPM falls below **60 BPM**, an emergency condition is triggered.
8. The Arduino sends commands to the SIM800 GSM module.
9. The GSM module sends an SMS to the three predefined emergency contacts.
10. The system resumes continuous heart-rate monitoring.

---

##  Functional Requirements

### FR1 — Heart Rate Detection

The system shall detect the user's heartbeat using a pulse sensor.

### FR2 — BPM Calculation

The system shall process the pulse signal and calculate the user's heart rate in BPM.

### FR3 — Continuous Monitoring

The system shall continuously monitor the detected heart rate while the system is operational.

### FR4 — Threshold Detection

The system shall compare the calculated BPM with the configured threshold value.

**Default threshold: 60 BPM**

### FR5 — Emergency Detection

The system shall identify a potentially abnormal condition when the detected BPM falls below the configured threshold.

### FR6 — GSM Communication

The Arduino shall communicate with the SIM800 GSM module using serial communication and GSM AT commands.

### FR7 — Emergency SMS

The system shall automatically send an emergency SMS when the threshold condition is detected.

### FR8 — Multiple Emergency Contacts

The system shall support sending alerts to three predefined emergency contacts.

### FR9 — Serial Monitoring

The system shall provide heart-rate readings and relevant system information through the Arduino Serial Monitor.

### FR10 — Configurability

The emergency contact numbers and heart-rate threshold shall be configurable through the Arduino program.

---

##  Project Design

### System Architecture

```text
┌──────────────────┐
│   Pulse Sensor   │
│                  │
│ Heartbeat Signal │
└────────┬─────────┘
         │
         ▼
┌──────────────────┐
│   Arduino UNO    │
│                  │
│ Signal Processing│
│ BPM Calculation  │
│ Threshold Check  │
└────────┬─────────┘
         │
         │ Emergency Condition
         ▼
┌──────────────────┐
│   SIM800 GSM     │
│     Module       │
└────────┬─────────┘
         │
         │ SMS
         ▼
┌──────────────────────────┐
│   Emergency Contacts     │
│                          │
│ Contact 1                │
│ Contact 2                │
│ Contact 3                │
└──────────────────────────┘
```

### Hardware Components

| Component             | Purpose                        |
| --------------------- | ------------------------------ |
| **Arduino UNO**       | Main microcontroller           |
| **Pulse Sensor**      | Detects heartbeat signals      |
| **SIM800 GSM Module** | Sends emergency SMS            |
| **SIM Card**          | Provides cellular connectivity |
| **Resistors**         | Voltage-level interfacing      |
| **Breadboard**        | Circuit prototyping            |
| **Jumper Wires**      | Electrical connections         |
| **Power Supply**      | Provides power to the system   |

### Software & Technologies

* Arduino IDE
* Embedded C / Arduino C++
* UART / Serial Communication
* GSM AT Commands
* Arduino UNO
* SIM800 GSM Module
* Pulse Sensor

### Basic Pin Configuration

#### Pulse Sensor → Arduino UNO

| Pulse Sensor | Arduino UNO  |
| ------------ | ------------ |
| VCC          | 5V           |
| GND          | GND          |
| Signal       | Analog Input |

#### SIM800 → Arduino UNO

| SIM800 | Arduino UNO                                  |
| ------ | -------------------------------------------- |
| TXD    | D10                                          |
| RXD    | D11 through voltage-level protection/divider |
| GND    | GND                                          |
| VCC    | Suitable external power supply               |

> **Important:** The SIM800 should be provided with a stable power source capable of handling its current requirements and bursts.

---

##  Future Enhancements

The project can be extended with several additional features:

* Dedicated Android/iOS mobile application
* Cloud-based heart-rate data storage
* Real-time heart-rate graphs
* GPS location sharing with emergency alerts
* Buzzer and LED indicators
* Historical heart-rate data logging
* Web-based monitoring dashboard
* Improved rechargeable battery system
* IoT-based remote monitoring
* Monitoring of additional health parameters
* Secure storage and transmission of user data

---

## Project Information

| Information                 | Details                                        |
| --------------------------- | ---------------------------------------------- |
| **Project Name**            | Heart Rate Monitoring & Emergency Alert System |
| **Project Type**            | Embedded Systems / IoT Prototype               |
| **Domain**                  | Healthcare Technology                          |
| **Microcontroller**         | Arduino UNO                                    |
| **Sensor**                  | Pulse Sensor                                   |
| **Communication Module**    | SIM800 GSM                                     |
| **Programming Language**    | Arduino C / C++                                |
| **Development Environment** | Arduino IDE                                    |
| **Alert Method**            | SMS                                            |
| **Emergency Contacts**      | 3                                              |
| **Default Alert Threshold** | Below 60 BPM                                   |
| **Project Purpose**         | Educational / Demonstration                    |

---

##  Project Status

**🟢 Completed — Prototype**

The current prototype successfully demonstrates:

* [x] Pulse sensor interfacing
* [x] Heart-rate monitoring
* [x] BPM calculation
* [x] Arduino-based processing
* [x] GSM module interfacing
* [x] Emergency threshold detection
* [x] SMS alert functionality
* [x] Multiple emergency contacts

### Planned Improvements

* [ ] Mobile application
* [ ] GPS integration
* [ ] Cloud data storage
* [ ] Real-time graphical dashboard
* [ ] Improved portable power system
* [ ] Additional health parameters

---

## 📜 License

This project is intended primarily for **educational and demonstration purposes**.



