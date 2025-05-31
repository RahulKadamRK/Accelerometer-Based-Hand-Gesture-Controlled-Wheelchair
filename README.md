# Accelerometer-Based-Hand-Gesture-Controlled-Wheelchair
A completely wireless, hand-gesture-controlled wheelchair designed to improve mobility and independence for individuals with physical disabilities.

---

## Table of Contents
- [Motivation](#motivation)
- [Project Description](#project-description)
- [Components](#components)
- [Methodology](#methodology)
- [Getting Started](#getting-started)

---

## Motivation
Gesture recognition in electronics aims to minimize the gap between the physical and digital worlds. Traditional wheelchairs can be physically exhausting to operate and often require assistance from others, particularly for elderly or physically challenged individuals.

This project presents a prototype of a hand-gesture-controlled wheelchair, enabling users to move freely and independently with minimal effort using simple hand gestures.

---

## Project Description
The prototype consists of two primary sections:

**Transmitter Section (Wristband/glove):**
Worn by the user, this section detects hand movements. Tilting gestures — right, left, forward (up), and backward (down) are used to control the wheelchair's direction wirelessly.

**Receiver Section (Wheelchair Base):**
Mounted on the wheelchair, it receives gesture signals and drives the motors accordingly. An integrated obstacle detection system ensures user safety by halting the wheelchair when an obstacle is detected and sounding an alarm.

---

## Components

**Transmitter (Wristband):**

- Arduino Uno
- 434 MHz RF Transmitter
- ADXL335 Accelerometer (MEMS-based)
- 9V Battery

**Receiver (Wheelchair Base):**

- Arduino Uno
- 434 MHz RF Receiver
- Ultrasonic Sensor (for obstacle detection)
- Buzzer/Alarm
- DC Motors and Wheels
- L293D Motor Driver IC

---

## Methodology

**Transmitter Section:**

The ADXL335 accelerometer senses the tilt of the hand and outputs corresponding analog voltages.
The Arduino Uno reads the accelerometer data and sends encoded directional signals via the RF Transmitter.
Each hand gesture (right, left, forward, backward) corresponds to a specific signal.

**Receiver Section:**

The RF Receiver captures the transmitted signals and feeds them to the Arduino Uno.
Based on the decoded signals, the Arduino controls the wheelchair motors using the L293D Motor Driver to move in the desired direction.
The Ultrasonic Sensor constantly scans for obstacles. If an obstacle is detected within a preset range, the wheelchair stops immediately and activates the buzzer to alert the user.
