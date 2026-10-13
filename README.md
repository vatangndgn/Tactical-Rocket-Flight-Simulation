# Tactical Rocket Flight Simulation

A 2D tactical missile trajectory simulation developed in **C++** using the **Raylib** library. This project models real-time flight physics, aerodynamic drag, barometric atmospheric density, and dynamic pitch angle orientation.

<img width="990" height="826" alt="Ekran görüntüsü 2026-10-13 154516" src="https://github.com/user-attachments/assets/d004da58-56c4-4a5c-8cb4-507f4d4db09b" />
<img width="987" height="827" alt="Ekran görüntüsü 2026-10-13 154540" src="https://github.com/user-attachments/assets/7e6a90d0-28dc-413f-8210-6bd8aedd84b9" />
<img width="985" height="827" alt="Ekran görüntüsü 2026-10-13 154601" src="https://github.com/user-attachments/assets/a39b6dc2-c283-4777-aebe-4f3a30eeba03" />

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
