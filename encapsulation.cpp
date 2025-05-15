#include<bits/stdc++.h>
using namespace std;

class SportsCar{
private:
    string brand;
    string model;
    bool isEngineOn;
    int currentGear;
    int currentSpeed;
    string tyre;
public:
    SportsCar(string b, string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        tyre = "Michelin";
    }
    //Getter and Setter methods to access private members
    int getCurrentSpeed() {
        return currentSpeed;
    }
    string getTyre() {
        return tyre;
    }
    void changeTyre(string newTyre) {
        tyre = newTyre;
        cout << brand <<" "<< model << " Tyre changed to " << tyre << "." << endl;
    }
    void startEngine() {
        isEngineOn = true;
        cout << brand <<" "<< model << " Engine started." << endl;
    }
    void stopEngine() {
        isEngineOn = false;
        cout << brand <<" "<< model << " Engine stopped." << endl;
        currentSpeed = 0;
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

int main(){
    SportsCar car("Ferrari", "488");
    car.startEngine();
    car.shiftGear(2);
    car.accelerate();
    car.accelerate();
    car.brake();
    car.stopEngine();
    cout<<"Current Speed: " << car.getCurrentSpeed() << " km/h." << endl;
    cout<<"Current Tyre: " << car.getTyre() << endl;
    car.changeTyre("MRF");
    delete &car;
    return 0;
}