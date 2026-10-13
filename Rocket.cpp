#include "Rocket.h"
 
Rocket::Rocket(double launchAngle, double initialFuel, double thrust, double burn, double drag, double area) {
    x = 0.0;
    y = 0.0;
    vx = 0.0;
    vy = 0.0;
    ax = 0.0;
    ay = 0.0;
    Vmax = 0.0;
    hMax = 0.0;

    massEmpty = 15.0;
    massFuel = initialFuel;
    currentFuel = initialFuel;
    maxThrust = thrust;
    burnRate = burn;
    dragCoefficient = drag;
    referenceArea = area;

    angle = launchAngle * (3.14159265 / 180.0);
    flightTime = 0.0;
}

// Barometric atmospheric density model
double Rocket::getAirDensity(double altitude) {
    constexpr double SEA_LEVEL_DENSITY = 1.225;
    constexpr double SCALE_HEIGHT = 8500.0;

    if (altitude < 0.0) return SEA_LEVEL_DENSITY;
    return SEA_LEVEL_DENSITY * std::exp(-altitude / SCALE_HEIGHT);
}

// Align pitch angle with the instantaneous velocity vector
void Rocket::updatePitchAngle() {
    double V = std::sqrt(vx * vx + vy * vy);
    if (V > 1.0) {

        angle = std::atan2(vy, vx);
    }
}

// Numerical integration step
void Rocket::update(double dt) {
    // Fuel
    if (currentFuel > 0.0) {
        currentFuel -= (burnRate * dt);
        if (currentFuel < 0.0) currentFuel = 0.0;
    }
    double totalMass = massEmpty + currentFuel;

    // thrust force
    double F_Tx = 0.0;
    double F_Ty = 0.0;
    if (currentFuel > 0) {
  
        F_Tx = maxThrust * std::cos(angle);
        F_Ty = maxThrust * std::sin(angle);
    }

    // Speed
    double V = std::sqrt((vx * vx) + (vy * vy));
    double rho = getAirDensity(y);
    double F_Dx = 0.0;
    double F_Dy = 0.0;
    if (V > 0) {
        double F_D = 0.5 * rho * (V * V) * dragCoefficient * referenceArea;
        F_Dx = F_D * (vx / V);
        F_Dy = F_D * (vy / V);
    }

    constexpr double g = 9.81;
    double W = totalMass * g;
    double Fnet_x = F_Tx - F_Dx;
    double Fnet_y = F_Ty - F_Dy - W;
    if (V > Vmax ){
        Vmax = V;
    }

    ax = Fnet_x / totalMass;
    ay = Fnet_y / totalMass;
    //euler
    vx = vx + (ax * dt);
    x = x + (vx * dt);
    vy = vy + (ay * dt);
    y = y + (vy * dt);
    
    if (y < 0.0) {
        y = 0.0;
        vy = 0.0;
        vx = 0.0;
        ax = 0.0;
        ay = 0.0;
    }
    if (y > hMax) {
        hMax = y;
    }

    updatePitchAngle();
    flightTime += dt;
  
}

double Rocket::getX() const { return x; }
double Rocket::getY() const { return y; }
double Rocket::getSpeed() const { return std::sqrt(vx * vx + vy * vy); }
double Rocket::getAngle() const { return angle; }
double Rocket::getFuel() const { return currentFuel; }
double Rocket::gethMax() const { return hMax; }
double Rocket::getMaxV() const { return Vmax; }
