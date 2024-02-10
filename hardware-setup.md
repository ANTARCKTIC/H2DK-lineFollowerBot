# Hardware Setup

Follow these steps to set up the hardware for the Line Follower Arduino Bot:

## Components

Before you begin, ensure you have all the required hardware components:

- 1 x Arduino Uno
- 1 x L298n H-Bridge Motor Driver
- 5 x Infrared Sensors
- 3 x Ultrasonic Sensors
- 3 x Ultrasonic Sensor Supports
- 3 x 2500 mAh Batteries
- 1 x 3-Port Battery Holder
- 1 x Breadboard (Plack a essai)
- 20 x Male-Male Jumper Wires
- 20 x Male-Female Jumper Wires
- Free-Wheeling Casters
- 2 x GA12-N20 Polulu Motors
- 2 x Wheels
- 2 x Hexagonal Couplings (4mm)
- 2 x Motor Mounts

## Assembly Instructions

1. **Mounting Motors:**
   - Attach the GA12-N20 Polulu Motors to the designated motor mounts on the robot chassis.

2. **Wheel Installation:**
   - Securely mount the wheels onto the motor shafts.

3. **Infrared Sensor Placement:**
   - Attach the 5 infrared sensors to the front of the robot in a line.
   - Adjust the sensor angles for optimal line detection.

4. **Ultrasonic Sensor Placement:**
   - Mount the 3 ultrasonic sensors on the Ultrasonic Sensor Supports.
   - Attach the supports at suitable locations for obstacle detection.
   - Adjust the sensor angles based on your robot's design.

5. **Power Supply:**
   - Insert the 2500 mAh batteries into the 3-Port Battery Holder.
   - Connect the battery holder to the power input of the Arduino Uno and the L298n motor driver.

6. **H-Bridge Motor Driver Connection:**
   - Connect the L298n H-Bridge Motor Driver to the specified motor pins on the Arduino board.
   - Connect the control pins of the H-bridge to the specified digital pins on the Arduino board.
   - Connect the power supply and ground connections of the H-bridge as per the datasheet.

7. **Wiring Connections:**
   - Use the provided Male-Male and Male-Female Jumper Wires to connect the sensors, motors, and other components to the Arduino Uno and breadboard.
   - Follow the wiring diagram for proper connections.

8. **Breadboard Usage:**
   - Utilize the breadboard for creating organized and secure connections between components.

## Wiring Diagram

Include a wiring diagram to illustrate the connections between the Arduino board, motors, H-bridge, infrared sensors, ultrasonic sensors, and other components.

![Wiring Diagram](path/to/wiring_diagram.png)

## Sensor Calibration

Before running the robot, it's essential to calibrate the infrared sensors for accurate line detection. Refer to the [Sensor Calibration](path/to/sensor_calibration.md) instructions for detailed steps.

## Testing

1. Power on the robot.
2. Place the robot on a track with a visible line.
3. Observe the robot's movement and ensure it follows the line accurately.
4. Test the ultrasonic sensors by placing obstacles in the robot's path and verifying obstacle detection.

## Troubleshooting

If you encounter any issues during the hardware setup, refer to the [Troubleshooting Guide](path/to/troubleshooting.md) for common problems and solutions.

## Next Steps

With the hardware successfully set up, you can now proceed to the [Software Setup](path/to/software_setup.md) to configure the Arduino code for line following.

Happy building!