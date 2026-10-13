# Tactical Rocket Flight Simulation

A 2D tactical missile trajectory simulation developed in **C++** using the **Raylib** library. This project models real-time flight physics, aerodynamic drag, barometric atmospheric density, and dynamic pitch angle orientation.

<img width="987" height="825" alt="Ekran görüntüsü 2026-10-13 155715" src="https://github.com/user-attachments/assets/38370a99-61b8-44b6-b7c9-62b7fb2a09ef" />
<img width="987" height="827" alt="Ekran görüntüsü 2026-10-13 154540" src="https://github.com/user-attachments/assets/35bbec7f-da12-4d78-b1c2-ff4bc0dc0775" />
<img width="985" height="827" alt="Ekran görüntüsü 2026-10-13 154601" src="https://github.com/user-attachments/assets/14a3c8b7-3136-42aa-8fbd-19c35c81dc77" />



## Features
- **Flight Physics Engine:** 2D Euler numerical integration calculating acceleration, velocity, and position state vectors.
- **Dynamic Pitch Angle:** Automatically aligns the rocket's orientation with the instantaneous velocity vector (`gravity turn`) using `std::atan2`.
- **Aerodynamic Drag:** Quadratic air resistance opposing the velocity vector (Drag Coefficient Cd = 0.38).
- **Atmospheric Model:** Exponential air density calculation based on altitude (barometric formula).
- **Real-Time Telemetry:** Live tracking of altitude, Mach-regime velocity, propellant consumption, and downrange distance.

## Simulation Parameters (Default Tactical Profile)
Configuration values used in this simulation profile:
- **Launch Angle:** `45.0°`
- **Initial Fuel:** `6.0 kg` (Total mass: 21 kg)
- **Max Thrust:** `3900.0 N`
- **Burn Rate:** `2.5 kg/s`
- **Drag Coefficient (Cd):** `0.38`
- **Reference Cross-Sectional Area:** `0.005 m²`

## Tech Stack
- **Language:** C++ (ISO C++20 standard)
- **Graphics Library:** Raylib
- **IDE:** Visual Studio

## How to Run
1. Clone the repository.
2. Open the project in Visual Studio (x64).
3. Ensure the Raylib library is correctly linked, then build and run `main.cpp`.
