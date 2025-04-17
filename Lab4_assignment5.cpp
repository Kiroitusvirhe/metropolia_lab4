#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    int year;
    float price;

public:
    Car() : model(""), year(0), price(0.0f) {}
    virtual ~Car() {}

    void inputBasic() {
        cout << "Enter model: ";
        cin.ignore();
        getline(cin, model);
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter price: $";
        cin >> price;
    }

    void displayBasic() const {
        cout << "Model: " << model << ", Year: " << year << ", Price: $" << price;
    }

    virtual void input() = 0;
    virtual void display() const = 0;
};

class ElectricCar : public Car {
private:
    float batterySize;

public:
    ~ElectricCar() {
        cout << "Destroying Electric Car: " << model << endl;
    }

    void input() override {
        inputBasic();
        cout << "Enter battery size (kWh): ";
        cin >> batterySize;
    }

    void display() const override {
        displayBasic();
        cout << ", Battery: " << batterySize << " kWh" << endl;
    }
};

class GasCar : public Car {
private:
    float fuelCapacity;

public:
    ~GasCar() {
        cout << "Destroying Gas Car: " << model << endl;
    }

    void input() override {
        inputBasic();
        cout << "Enter fuel capacity (L): ";
        cin >> fuelCapacity;
    }

    void display() const override {
        displayBasic();
        cout << ", Fuel: " << fuelCapacity << " L" << endl;
    }
};

class HybridCar : public Car {
private:
    float batterySize;
    float fuelCapacity;

public:
    ~HybridCar() {
        cout << "Destroying Hybrid Car: " << model << endl;
    }

    void input() override {
        inputBasic();
        cout << "Enter battery size (kWh): ";
        cin >> batterySize;
        cout << "Enter fuel capacity (L): ";
        cin >> fuelCapacity;
    }

    void display() const override {
        displayBasic();
        cout << ", Battery: " << batterySize << " kWh, Fuel: " << fuelCapacity << " L" << endl;
    }
};

int main() {
    int numCars;
    cout << "Enter total number of cars: ";
    cin >> numCars;

    Car** fleet = new Car*[numCars];
    int* types = new int[numCars];

    for (int i = 0; i < numCars; ++i) {
        cout << "\nCar " << i + 1 << " type:\n";
        cout << "[1] Electric\n[2] Gasoline\n[3] Hybrid\n";
        cout << "Enter choice: ";
        cin >> types[i];

        switch (types[i]) {
            case 1:
                fleet[i] = new ElectricCar();
                break;
            case 2:
                fleet[i] = new GasCar();
                break;
            case 3:
                fleet[i] = new HybridCar();
                break;
            default:
                cout << "Invalid choice, defaulting to Gas Car\n";
                fleet[i] = new GasCar();
                types[i] = 2;
        }
        fleet[i]->input();
    }

    cout << "\n--- Fleet Information ---\n";
    for (int i = 0; i < numCars; ++i) {
        fleet[i]->display();
    }

    cout << "\n--- Cleaning up fleet ---\n";
    for (int i = 0; i < numCars; ++i) {
        delete fleet[i];
    }
    delete[] fleet;
    delete[] types;

    return 0;
}