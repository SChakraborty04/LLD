#include<bits/stdc++.h>
using namespace std;

class Car {
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
public:
    Car(string b, string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }
    void startEngine() {
        isEngineOn = true;
        cout << brand <<" "<< model << " Engine started." << endl;
    }
    void stopEngine() {
        isEngineOn = false;
        cout << brand <<" "<< model << " Engine stopped." << endl;
    }
    void brake() {
        if (currentSpeed > 0) {
            currentSpeed -= 10;
            cout << brand <<" "<< model << " Braked. Current speed: " << currentSpeed << " km/h." << endl;
        } else {
            cout << brand <<" "<< model << " Already stopped." << endl;
        }
    }
    void accelerate() {
        if (isEngineOn) {
            currentSpeed += 10;
            cout << brand <<" "<< model << " Accelerated. Current speed: " << currentSpeed << " km/h." << endl;
        } else {
            cout << brand <<" "<< model << " Engine is off. Cannot accelerate." << endl;
        }
    }
};
class ManualCar : public Car {
private:
    int currentGear;
public:
    ManualCar(string b, string m) : Car(b, m) {
        currentGear = 0;
    }
    void shiftGear(int gear) {
        if (!isEngineOn) {
            cout << brand <<" "<< model << " Engine is off. Cannot shift gears." << endl;
            return;
        }
        if (gear < 0 || gear > 6) {
            cout << brand <<" "<< model << " Invalid gear." << endl;
            return;
        }
        currentGear = gear;
        cout << brand <<" "<< model << " Shifted to gear " << currentGear << "." << endl;
    }
};
class ElectricCar : public Car {
private:
   int batteryLevel;
public:
    ElectricCar(string b, string m) : Car(b, m) {
        batteryLevel = 100; // Battery level starts at 100%
    }
    void chargeBattery(int amount) {
        batteryLevel += amount;
        if (batteryLevel > 100) {
            batteryLevel = 100;
        }
        cout << brand <<" "<< model << " Battery charged to " << batteryLevel << "%." << endl;
    }
};
int main(){
    ManualCar myManualCar("Toyota", "Corolla");
    myManualCar.startEngine();
    myManualCar.shiftGear(2);
    myManualCar.accelerate();
    myManualCar.brake();
    myManualCar.stopEngine();

    ElectricCar myElectricCar("Tesla", "Model S");
    myElectricCar.startEngine();
    myElectricCar.accelerate();
    myElectricCar.chargeBattery(20);
    myElectricCar.brake();
    myElectricCar.stopEngine();

    return 0;
}