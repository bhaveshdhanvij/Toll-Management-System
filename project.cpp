#include <iostream>
#include <iomanip>
using namespace std;

// Abstract Base Class (Abstraction)
class Vehicle {
protected:
    string vehicleNumber;
    double tollPaid;
public:
    Vehicle(string number = "") {
        vehicleNumber = number;
        tollPaid = 0;
    }

    void setTollPaid(double amount) { tollPaid = amount; }
    double getTollPaid() { return tollPaid; }

    void setVehicleNumber(string number) { vehicleNumber = number; }
    string getVehicleNumber() { return vehicleNumber; }

    virtual string getType() = 0;  // Polymorphism: virtual function

    virtual ~Vehicle() {} // Destructor
};

// Derived Classes (Inheritance)
class Car : public Vehicle {
public:
    Car(string number = "") : Vehicle(number) {}
    string getType() { return "Car"; }
};

class Truck : public Vehicle {
public:
    Truck(string number = "") : Vehicle(number) {}
    string getType() { return "Truck"; }
};

class Bus : public Vehicle {
public:
    Bus(string number = "") : Vehicle(number) {}
    string getType() { return "Bus"; }
};

class Bike : public Vehicle {
public:
    Bike(string number = "") : Vehicle(number) {}
    string getType() { return "Bike"; }
};

// TollBooth Class (Encapsulation)
class TollBooth {
private:
    Vehicle* vehicles[100];  // Array to store vehicles
    int vehicleCount;
    double totalMoney;
    int carCount, truckCount, busCount, bikeCount;

public:
    TollBooth() {
        vehicleCount = 0;
        totalMoney = 0;
        carCount = truckCount = busCount = bikeCount = 0;
    }

    double calculateToll(string type) {
        if(type == "Car") return 50;
        else if(type == "Truck") return 100;
        else if(type == "Bus") return 75;
        else if(type == "Bike") return 30;
        else return 0;
    }

    void addVehicle(Vehicle &v, bool isPaid) {
        if(isPaid) {
            double toll = calculateToll(v.getType());
            v.setTollPaid(toll);
            totalMoney += toll;

            if(v.getType() == "Car") carCount++;
            else if(v.getType() == "Truck") truckCount++;
            else if(v.getType() == "Bus") busCount++;
            else if(v.getType() == "Bike") bikeCount++;
        }

        vehicles[vehicleCount] = &v;
        vehicleCount++;
    }

    void displaySummary() {
        cout << "\n===== Toll Booth Summary =====\n";
        cout << "Total vehicles: " << vehicleCount << endl;
        cout << "Total money collected: ₹" << totalMoney << endl;
        cout << "Cars: " << carCount << ", Trucks: " << truckCount
             << ", Buses: " << busCount << ", Bikes: " << bikeCount << endl;

        cout << "\nVehicle Details:\n";
        cout << setw(10) << left << "Number" 
             << setw(10) << left << "Type" 
             << "Toll Paid\n";

        for(int i=0; i<vehicleCount; i++) {
            cout << setw(10) << left << vehicles[i]->getVehicleNumber()
                 << setw(10) << left << vehicles[i]->getType()
                 << "₹" << vehicles[i]->getTollPaid() << endl;
        }
    }
};

int main() {
    TollBooth booth;
    string choice;

    // Array of Vehicle objects
    Vehicle* vehicleArray[100];
    int index = 0;

    do {
        cout << "\nEnter vehicle type (1.Car 2.Truck 3.Bus 4.Bike) or 0 to exit: ";
        int type;
        cin >> type;

        if(type == 0) break;

        cout << "Enter vehicle number: ";
        string number;
        cin >> number;

        Vehicle* v;

        switch(type) {
            case 1: v = new Car(number); break;
            case 2: v = new Truck(number); break;
            case 3: v = new Bus(number); break;
            case 4: v = new Bike(number); break;
            default: cout << "Invalid type, defaulting to Car\n"; v = new Car(number);
        }

        cout << "Has toll been paid? (y/n): ";
        char paid;
        cin >> paid;
        bool isPaid = (paid=='y' || paid=='Y');

        booth.addVehicle(*v, isPaid);
        vehicleArray[index++] = v;

    } while(true);

    booth.displaySummary();

    // Cleanup
    for(int i=0; i<index; i++)
        delete vehicleArray[i];

    return 0;
}
