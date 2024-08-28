
# Two-wheeled Mobile Robot with Obstacle Avoidance System

This project is a two-wheeled mobile robot with a obstacle avoidance algorithm implemented mainly using ultrasonic sensors. The main objective of this mobile robot is to autonomously navigate through a designed wall obstacle maze. 

This project is developed together with my three classmates, Thomas Anthony Ortiz, Jam Montecillo, and Paulo Agustin as a part of the completion of our Microprocessor-Based Design course.

![mobot_trial_run](https://github.com/aaroncanillas/test-repo/blob/a5b17c969276940a82b78faa019596407022771d/download.gif)

## Materials

- **Two DC Geared Motors (6-12V)**

Two 6V geared motors were chosen for their balance of torque and speed,
deemed suitable for maze traversal. These were securely mounted onto the chassis
using brackets and screws.

- **Dual H-Bridge Motor Driver (L298N)**

The L298N driver facilitated independent control of both motors. It was
connected to the Arduino UNO and power banks via jumper cables, ensuring proper
voltage and current supply.

- **Power Bank**

The power bank serves as the power supply for the motors and microcontroller board to operate.

- **Arduino UNO**

The Arduino UNO microcontroller board serves as the central processing unit, receiving sensor data,interpreting it, and sending control signals to the motor driver. It is mounted on the chassis of the mobile robot.

- **HC-SR04 Ultrasonic Sensor**

Instead of a single sensor, three HC-SR04 sensors were employed. One was strategically placed at the front for forward obstacle detection, while the other two were mounted on the left and right sides near the front, providing additional situational awareness and enhancing precision in wall-following. Each sensor had its operating voltage ensured through separate connections.

## Design

**Hardware Design**

A sturdy yet lightweight chassis was constructed using multiple layers of cardboard, glued together for added rigidity.The motors were positioned at opposite ends of the chassis for balanced movement. The HC-SR04 sensor was strategically placed at the front, maximizing its detection range for obstacle avoidance. All wires were securely routed and organized within the chassis using cable ties, minimizing entanglement and potential damage.

![hardware design](https://github.com/aaroncanillas/test-repo/blob/a5b17c969276940a82b78faa019596407022771d/Screenshot%202024-08-28%20191756.png)

**Fine-tuning of mobot control parameters**

While the algorithm lays the foundation for the mobot's navigation, its effectiveness hinges on careful calibration of its physical movements and sensor interpretations. This section explores the process of fine-tuning these control parameters to achieve optimal performance for obstacle detection.

**Virtual Testing Ground**

Before venturing into the obstacle maze, the mobot's code found its first proving ground within the virtual realm of Tinkercad's simulation environment. This digital testing platform offered a safe and controlled space to experiment with different parameter values and observe their effects on the mobot's behavior, without risking damage to the physical hardware or navigating physical obstacles.

![tinkercad](https://github.com/aaroncanillas/test-repo/blob/a5b17c969276940a82b78faa019596407022771d/Screenshot%202024-08-28%20201352.png)

**Motor Calibration**

The mobot's movement, orchestrated by the two rear motors, demanded precise control to ensure smooth navigation and accurate obstacle avoidance. The calibration process involved:
- *Speed Adjustments.* Finding the ideal speed for forward and turning maneuvers that balance speed with control, preventing overshooting turns or collisions.
- *Wheel Synchronization.* Ensuring the motors operated in perfect harmony to maintain straight trajectories and execute precise turns, avoiding unintended deviations.
- *Front Wheel Integration.* Accounting for the unique characteristics of the front caster wheel, ensuring its smooth rotation and seamless integration with the motor-controlled rear wheels.

## Tech Stack

**Programming Language:** C++

**Arduino UNO R3, Embedded Systems**

