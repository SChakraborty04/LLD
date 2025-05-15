#include <bits/stdc++.h>
using namespace std;

class Car {
public:
  virtual void startEngine() = 0;
  virtual void stopEngine() = 0;
  virtual void brake() = 0;
  virtual void accelerate() = 0;
  virtual void shiftGear(int gear) = 0;
  virtual ~Car() {}
};
class SportsCar : public Car {
public:
  string brand;
  string model;
  bool isEngineOn;
  int currentGear;
  int currentSpeed;
  SportsCar(string b, string m){
    this->brand = b;
    this->model = m;
    isEngineOn = false;
    currentGear = 0;
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

int main() {
  Car* myCar = new SportsCar("Ferrari", "488");
  myCar->startEngine();
  myCar->shiftGear(1);
  myCar->accelerate();
  myCar->brake();
  myCar->stopEngine();
  return 0;
}