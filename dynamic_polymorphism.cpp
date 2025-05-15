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
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual ~Car() {}
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
    void accelerate(){
        if (isEngineOn) {
            currentSpeed += 20;
            cout << brand <<" "<< model << " Accelerated. Current speed: " << currentSpeed << " km/h." << endl;
        } else {
            cout << brand <<" "<< model << " Engine is off. Cannot accelerate." << endl;
        }
    }
    void brake(){
        if (currentSpeed > 0) {
            currentSpeed -= 20;
            cout << brand <<" "<< model << " Braked. Current speed: " << currentSpeed << " km/h." << endl;
        } else {
            cout << brand <<" "<< model << " Already stopped." << endl;
        }
    }
};
class ElectricCar : public Car {
private:
    int batteryLevel;
public:
    ElectricCar(string b, string m) : Car(b, m) {
        batteryLevel = 100; // Full battery
    }
    void chargeBattery(int amount) {
        batteryLevel += amount;
        if (batteryLevel > 100) {
            batteryLevel = 100; // Max battery level
        }
        cout << brand <<" "<< model << " Battery charged. Current battery level: " << batteryLevel << "%" << endl;
    }
    void accelerate(){
        if (isEngineOn && batteryLevel > 0) {
            currentSpeed += 10;
            batteryLevel -= 5; // Consumes battery
            cout << brand <<" "<< model << " Accelerated. Current speed: " << currentSpeed << " km/h. Battery level: " << batteryLevel << "%" << endl;
        } else if (batteryLevel <= 0) {
            cout << brand <<" "<< model << " Battery empty. Cannot accelerate." << endl;
        } else {
            cout << brand <<" "<< model << " Engine is off. Cannot accelerate." << endl;
        }
    }
    void brake(){
        if (currentSpeed > 0) {
            currentSpeed -= 10;
            cout << brand <<" "<< model << " Braked. Current speed: " << currentSpeed << " km/h." << endl;
        } else {
            cout << brand <<" "<< model << " Already stopped." << endl;
        }
    }
};
int main(){
    Car* myCar1 = new ManualCar("Toyota", "Corolla");
    myCar1->startEngine();
    myCar1->accelerate();
    myCar1->brake();
    delete myCar1;

    Car* myCar2 = new ElectricCar("Tesla", "Model S");
    myCar2->startEngine();
    myCar2->accelerate();
    myCar2->brake();
    delete myCar2;

    return 0;
}