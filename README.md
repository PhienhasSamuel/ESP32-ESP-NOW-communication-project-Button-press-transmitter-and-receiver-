# ESP32-ESP-NOW-communication-project-Button-press-transmitter-and-receiver-

## Description

This project demonstrates the use of **ESP-NOW**, a peer-to-peer wireless communication protocol, for real-time communication between two **ESP32** boards. One ESP32 board acts as a **transmitter** with a push button, and the other as a **receiver** that listens for the button press and displays the corresponding message on the Serial Monitor.

## How It Works

### Transmitter (Button Press)
- The transmitter board sends a signal to the receiver board via **ESP-NOW** when the button is pressed. The button is connected to GPIO 0 and uses the internal pull-up resistor.
- The signal sent is a simple `uint8_t` (1 for button pressed, 0 for not pressed).
- This message is transmitted to the receiver, where it is displayed.

### Receiver (Display Message)
- The receiver listens for incoming messages using **ESP-NOW** and displays the received data on the Serial Monitor.
- The **MAC address** of the transmitter is also displayed to ensure communication is working correctly.

## Key Features

- **Wireless Communication**: Leverages the ESP-NOW protocol for low-power, peer-to-peer communication between ESP32 devices.
- **Button Press Detection**: The transmitter sends a signal when the button is pressed and received by the receiver.
- **Receiver Feedback**: The receiver displays both the received button state and the **MAC address** of the sender for clear communication tracking.
- **No Internet**: ESP-NOW allows communication without the need for Wi-Fi, making it perfect for low-power IoT projects.

## Use Cases
- **Wireless Control Systems**: Can be used in IoT applications like remote switches, alarm systems, or wireless sensors.
- **Low Power Consumption**: Since ESP-NOW uses low energy, this can be ideal for battery-operated devices.
- **Short Range Communication**: Perfect for devices that need to communicate over short distances (up to 100 meters in open space).

## Components Required
- 2 × **ESP32 Development Boards**
- 1 × **Push Button**
- Jumper wires
- Breadboard (optional)

## Wiring Diagram

- **Transmitter (ESP32)**:
  - Push Button: One side to GPIO 0, other side to **GND**.
  - Internal pull-up resistor is enabled for the button pin.

- **Receiver (ESP32)**:
  - No additional components needed for the receiver (other than connecting the board to a USB power source).
