# Tactical Rocket Flight Simulation

A 2D tactical missile trajectory simulation developed in **C++** using the **Raylib** library. It models real-time physics, aerodynamic drag, and barometric atmospheric density.

<img width="985" height="827" alt="Ekran görüntüsü 2026-10-13 154601" src="https://github.com/user-attachments/assets/a39b6dc2-c283-4777-aebe-4f3a30eeba03" />
<img width="987" height="827" alt="Ekran görüntüsü 2026-10-13 154540" src="https://github.com/user-attachments/assets/7e6a90d0-28dc-413f-8210-6bd8aedd84b9" />
<img width="990" height="826" alt="Ekran görüntüsü 2026-10-13 154516" src="https://github.com/user-attachments/assets/d004da58-56c4-4a5c-8cb4-507f4d4db09b" />

## Features
- **Rigid-Body Physics:** 2D Euler numerical integration.
- **Aerodynamics:** Quadratic drag opposing the velocity vector ($C_d = 0.38$).
- **Atmospheric Model:** Exponential air density calculation based on altitude.
- **Real-Time Telemetry:** Live tracking of altitude, Mach-regime velocity, fuel consumption, and downrange distance.

## Tech Stack
- **Language:** C++20
- **Library:** Raylib
- **IDE:** Visual Studio

## How to Run
1. Clone the repository.
2. Open the project in Visual Studio (x64).
3. Ensure Raylib is linked, then build and run `main.cpp`.
