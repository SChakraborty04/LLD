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
    virtual void accelerate(int speed) = 0;
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
    void accelerate(int speed){
        if (isEngineOn) {
            currentSpeed += speed;
            cout << brand <<" "<< model << " Accelerated by " << speed << " km/h. Current speed: " << currentSpeed << " km/h." << endl;
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
    void accelerate(){
        if (isEngineOn) {
            currentSpeed += 10;
            batteryLevel -= 5; // Consumes battery
            cout << brand <<" "<< model << " Accelerated. Current speed: " << currentSpeed << " km/h. Battery level: " << batteryLevel << "%" << endl;
        } else {
            cout << brand <<" "<< model << " Engine is off. Cannot accelerate." << endl;
        }
    }
    void accelerate(int speed){
        if (isEngineOn) {
            currentSpeed += speed;
            batteryLevel -= speed / 2; // Consumes battery
            cout << brand <<" "<< model << " Accelerated by " << speed << " km/h. Current speed: " << currentSpeed << " km/h. Battery level: " << batteryLevel << "%" << endl;
        } else {
            cout << brand <<" "<< model << " Engine is off. Cannot accelerate." << endl;
        }
    }
    void brake(){
        if (currentSpeed > 0) {
            currentSpeed -= 15;
            cout << brand <<" "<< model << " Braked. Current speed: " << currentSpeed << " km/h." << endl;
        } else {
            cout << brand <<" "<< model << " Already stopped." << endl;
        }
    }
};

int main(){
    ManualCar myManualCar("Toyota", "Corolla");
    myManualCar.startEngine();
    myManualCar.shiftGear(2);
    myManualCar.accelerate();
    myManualCar.brake();

    ElectricCar myElectricCar("Tesla", "Model S");
    myElectricCar.startEngine();
    myElectricCar.accelerate(30);
    myElectricCar.brake();

    return 0;
}