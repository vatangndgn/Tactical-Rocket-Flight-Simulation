#pragma once
#include <cmath>

class Rocket {
private:
   
    double massEmpty;
    double massFuel;
    double maxThrust;
    double burnRate;
    double dragCoefficient;
    double referenceArea;

    double x, y;
    double vx, vy;
    double ax, ay;
    double currentFuel;
    double angle;
    double flightTime;
    double hMax = 0.0;
    double Vmax = 0.0;

public:
    Rocket(double launchAngle, double initialFuel, double thrust, double burn, double drag, double area);

    double getAirDensity(double altitude);
    void updatePitchAngle();
    void update(double dt);

    double getX() const;
    double getY() const;
    double getSpeed() const;
    double getAngle() const;
    double getFuel() const;
    double gethMax() const;
    double getMaxV() const;
    double getFlightTime() const { return flightTime; }
};