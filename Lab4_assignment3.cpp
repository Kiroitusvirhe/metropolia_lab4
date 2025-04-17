#include <iostream>
#include <string>
#include <limits> // for numeric_limits
using namespace std;

class Car {
private:
    string model;
    int year;
    double price;

public:
    // Constructor with default values
    Car(string m = "", int y = 0, double p = 0.0) : model(m), year(y), price(p) {
        cout << "Car Constructor: " << model << " (" << year << ") - $" << price << endl;
    }

    // Destructor
    ~Car() {
        cout << "Car Destructor: " << model << " destroyed" << endl;
    }

    // Function to display car details
    void display() const {
        cout << "Model: " << model << ", Year: " << year << ", Price: $" << price << endl;
    }

    // Function to input car details
    void inputDetails(int carNumber) {
        cout << "\nEnter model for car " << carNumber << ": ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
        getline(cin, model);
        
        cout << "Enter year: ";
        cin >> year;
        
        cout << "Enter price: ";
        cin >> price;
    }
};

class CarCollection {
private:
    Car* cars;
    int size;

public:
    // Constructor
    CarCollection() {
        cout << "How many cars do you want to enter? ";
        cin >> size;
        
        cars = new Car[size];
        
        for (int i = 0; i < size; ++i) {
            cars[i].inputDetails(i + 1);
        }
        
        cout << "CarCollection initialized with " << size << " cars\n";
    }

    // Destructor
    ~CarCollection() {
        delete[] cars;
        cout << "CarCollection destroyed\n";
    }

    // Function to display all cars
    void displayCars() const {
        cout << "\n--- Car Collection ---\n";
        for (int i = 0; i < size; ++i) {
            cars[i].display();
        }
    }
};

int main() {
    CarCollection collection;
    collection.displayCars();
    return 0;
}