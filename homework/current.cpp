#include <iostream>
using namespace std;

class Vehicle
{
public:
    Vehicle(int tire_number, int vehicle_weight)
    {
        tire_number_ = tire_number, vehicle_weight_ = vehicle_weight; 
    }
    virtual ~Vehicle() {}
    virtual void speak() {
        cout << "This vehicle has " << tire_number_ << " tires, it weights " << vehicle_weight_ << "kg.\n"; 
    }
protected:
    int tire_number_;
    int vehicle_weight_;
};

class Car : Vehicle
{
public:
    Car(int tire_number, int vehicle_weight, int people_number) 
        : Vehicle(tire_number, vehicle_weight) {
        people_number_ = people_number; 
    }
    virtual ~Car() {}
    virtual void speak() {
        cout << "This car has " << tire_number_ << " tires, it weights " << vehicle_weight_ << "kg. ";
        cout << "There " << (people_number_>1 ? "are " : "is ") << people_number_ << " people on board.\n";
    }
private:
    int people_number_;
};

class Truck : Vehicle
{
public:
    Truck(int tire_number, int vehicle_weight, int people_number, int load_weight) 
        : Vehicle(tire_number, vehicle_weight) {
        people_number_ = people_number, load_weight_ = load_weight; 
    }
    virtual ~Truck() {}
    virtual void speak() {
        cout << "This truck has " << tire_number_ << " tires, it weights " << vehicle_weight_ << "kg. ";
        cout << "There " << (people_number_>1 ? "are " : "is ") << people_number_ << " people on board, ";
        cout << "and it carrys " << load_weight_ << "kg load.\n";
    }
private:
    int people_number_;
    int load_weight_;
};

int main()
{
    Vehicle vehicle(4, 10);
    Car car(4, 10, 2);
    Truck truck(12, 20, 1, 50);
    
    vehicle.speak();
    car.speak();
    truck.speak();
}
