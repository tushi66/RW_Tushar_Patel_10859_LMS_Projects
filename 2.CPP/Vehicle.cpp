#include <iostream>
using namespace std;

class Vehicle{
protected:
    int vehicleID;
    string modelname;
    string manufacturer;
    int year;
    static int totalcount;

public:
    Vehicle() {

        vehicleID = 0;
        modelname = "";
        manufacturer = "";
        year = 0;
        totalcount++;
    }

    Vehicle(int id, string mod, string m, int y) {
        vehicleID = id;
        modelname = mod;
        manufacturer = m;
        year = y;
        totalcount++;
    }

    ~Vehicle() {
        totalcount--;
    }

    void setvehicle(int id, string mod, string m, int y) {
        vehicleID = id;
        modelname = mod;
        manufacturer = m;
        year = y;
    }

    void display() {
        cout << "Vehicle ID     :-  " << vehicleID << endl;
        cout << "Vehicle Model  :-  " << modelname << endl;
        cout << "Vehicle Manfac :-  " << manufacturer << endl;
        cout << "Vehicle Year   :-  " << year << endl;
    }

    int getid() {
        return vehicleID;
    }

    string getmodelname() {
        return modelname;
    }

    string getmanufacturer() {
        return manufacturer;
    }

    int getyear() {
        return year;
    }

    static int getcount() {
        return totalcount;
    }
};

int Vehicle::totalcount = 0;

class Car : public Vehicle {
public:
    string fueltype;

    void setFuel(string fuel) {
        fueltype = fuel;
    }

    void displayFuel() {
        cout << "Fuel Type     :-  " << fueltype << endl;
    }
};

class Eletriccar : public Car {
public:
    string batterycapacity;

    void setBattery(string cap) {
        batterycapacity = cap;
    }

    void displayBattery() {
        cout << "Battery Cap.  :-  " << batterycapacity << endl;
    }
};


class Sportscar : public Eletriccar {
public:
    int speed;

    void setSpeed(int s) {
        speed = s;
    }

    void displaySpeed() {
        cout << "Top Speed    :-  " << speed << " km/h" << endl;
    }
};

class Flyingcar : public Eletriccar {
public:
    string fly;

    void setFly(string f) {
        fly = f;
    }

    void displayFly() {
        cout << "Is Flying    :-  " << fly << endl;
    }
};

class Sedan : public Car {
            
};

class Suv : public Car {
    
};

class VehicleRegister {
private:

    int totalcount;
    int type[100]; 

    Car cars[100];
    Eletriccar ecars[100];
    Sportscar sports[100];
    Flyingcar flycars[100];
    Sedan sedans[100];
    Suv suvs[100];

public:
    VehicleRegister() {
        totalcount = 0;
    }

    void addVehicle(int vtype, int id, string mod, string m, int y, string fuel = "", string battery = "", string fly = "", int speed = 0) {
        if (totalcount >= 100) {
            cout << "Registry is full." << endl;
            return;
        }

        switch (vtype) {

        case 1:
            cars[totalcount].setvehicle(id, mod, m, y);
            cars[totalcount].setFuel(fuel);
            type[totalcount] = 1;
            break;
        case 2:
            ecars[totalcount].setvehicle(id, mod, m, y);
            ecars[totalcount].setFuel(fuel);
            ecars[totalcount].setBattery(battery);
            type[totalcount] = 2;
            break;
        case 3:
            sports[totalcount].setvehicle(id, mod, m, y);
            sports[totalcount].setFuel(fuel);
            sports[totalcount].setBattery(battery);
            sports[totalcount].setSpeed(speed);
            type[totalcount] = 3;
            break;
        case 4:
            flycars[totalcount].setvehicle(id, mod, m, y);
            flycars[totalcount].setFuel(fuel);
            flycars[totalcount].setBattery(battery);
            flycars[totalcount].setFly(fly);
            type[totalcount] = 4;
            break;
        case 5:
            sedans[totalcount].setvehicle(id, mod, m, y);
            sedans[totalcount].setFuel(fuel);
            type[totalcount] = 5;
            break;
        case 6:
            suvs[totalcount].setvehicle(id, mod, m, y);
            suvs[totalcount].setFuel(fuel);
            type[totalcount] = 6;
            break;
        default:
            cout << "Invalid vehicle type." << endl;
            return;
        }

        totalcount++;
    }

    void displayall() {
        if (totalcount == 0) {
            cout << "No vehicles in registry." << endl;
            return;
        }

        for (int i = 0; i < totalcount; i++) {
            cout << "\n----- Vehicle " << i + 1 << " -----" << endl;

            switch (type[i]) {
            case 1:
                cars[i].display();
                cars[i].displayFuel();
                break;
            case 2:
                ecars[i].display();
                ecars[i].displayFuel();
                ecars[i].displayBattery();
                break;
            case 3:
                sports[i].display();
                sports[i].displayFuel();
                sports[i].displayBattery();
                sports[i].displaySpeed();
                break;
            case 4:
                flycars[i].display();
                flycars[i].displayFuel();
                flycars[i].displayBattery();
                flycars[i].displayFly();
                break;
            case 5:
                sedans[i].display();
                sedans[i].displayFuel();
                break;
            case 6:
                suvs[i].display();
                suvs[i].displayFuel();
                break;
            }
        }
    }

    void searchid(int id) {
        for (int i = 0; i < totalcount; i++) {
            bool found = false;
            switch (type[i]) {
            case 1:
                if (cars[i].getid() == id) {
                    cout << "Vehicle found:" << endl;
                    cars[i].display();
                    cars[i].displayFuel();
                    found = true;
                }
                break;
            case 2:
                if (ecars[i].getid() == id) {
                    cout << "Vehicle found:" << endl;
                    ecars[i].display();
                    ecars[i].displayFuel();
                    ecars[i].displayBattery();
                    found = true;
                }
                break;
            case 3:
                if (sports[i].getid() == id) {
                    cout << "Vehicle found:" << endl;
                    sports[i].display();
                    sports[i].displayFuel();
                    sports[i].displayBattery();
                    sports[i].displaySpeed();
                    found = true;
                }
                break;
            case 4:
                if (flycars[i].getid() == id) {
                    cout << "Vehicle found:" << endl;
                    flycars[i].display();
                    flycars[i].displayFuel();
                    flycars[i].displayBattery();
                    flycars[i].displayFly();
                    found = true;
                }
                break;
            case 5:
                if (sedans[i].getid() == id) {
                    cout << "Vehicle found:" << endl;
                    sedans[i].display();
                    sedans[i].displayFuel();
                    found = true;
                }
                break;
            case 6:
                if (suvs[i].getid() == id) {
                    cout << "Vehicle found:" << endl;
                    suvs[i].display();
                    suvs[i].displayFuel();
                    found = true;
                }
                break;
            }

            if (found) return;
        }
        cout << "Vehicle not found with ID: " << id << endl;
    }
};

int main() {
    VehicleRegister registry;
    int choice;

    do {
        cout << "\n====== Vehicle Registry Menu ======" << endl;
        cout << "1. Add Vehicle" << endl;
        cout << "2. View All Vehicles" << endl;
        cout << "3. Search Vehicle by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int type;
            cout << "\nSelect Vehicle Type:" << endl;
            cout << "1. Car" << endl;
            cout << "2. Electric Car" << endl;
            cout << "3. Sports Car" << endl;
            cout << "4. Flying Car" << endl;
            cout << "5. Sedan" << endl;
            cout << "6. SUV" << endl;
            cout << "Enter type: ";
            cin >> type;

            int id, year, speed = 0;
            string mod, man, fuel, battery, fly;

            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Model: ";
            cin >> mod;
            cout << "Enter Manufacturer: ";
            cin >> man;
            cout << "Enter Year: ";
            cin >> year;

            if (type >= 1 && type <= 6) {
                cout << "Enter Fuel Type: ";
                cin >> fuel;
            }

            if (type == 2 || type == 3 || type == 4) {
                cout << "Enter Battery Capacity: ";
                cin >> battery;
            }

            if (type == 3) {
                cout << "Enter Top Speed (km/h): ";
                cin >> speed;
            }

            if (type == 4) {
                cout << "Is it flying? (yes/no): ";
                cin >> fly;
            }

            registry.addVehicle(type, id, mod, man, year, fuel, battery, fly, speed);
            break;
        }

        case 2:
            registry.displayall();
            break;

        case 3: {
            int searchID;
            cout << "Enter Vehicle ID to search: ";
            cin >> searchID;
            registry.searchid(searchID);
            break;
        }

        case 4:
            cout << "Exiting Vehicle Registry System." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
