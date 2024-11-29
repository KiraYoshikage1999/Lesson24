#include <iostream>
#include <string.h>

using namespace std;

class Automobile {
	static enum Colors {
		red = 0,
		green = 1,
		yellow = 2
	};

	int amountOfWheels;
	int speedOfCar;
	int colorOfCar;
	int amountOfDoors;

public:


	Automobile() {
		amountOfDoors = 4;
		amountOfWheels = 4;
		speedOfCar = 50;
		colorOfCar = 1;

	}


	Automobile(int amountOfWheels, int amountOfDoors, int colorOfCar, int speedOfCar) {
		this->amountOfDoors = amountOfDoors;
		this->amountOfWheels = amountOfWheels;
		this->colorOfCar = colorOfCar;
		this->speedOfCar = speedOfCar;

	}
	void PrintInfo() {
		cout << "COlor of CAR: " << colorOfCar << endl;
		cout << "Wheels: " << amountOfWheels << endl << "Doors: " << amountOfDoors << endl << "Speed of Car: " << speedOfCar << endl << "Color of Car: " << Color(colorOfCar) << endl << "<------------------------------>" << endl;;

	}

	int GetAmountOfWheels() {
		this->amountOfWheels = amountOfWheels;

	}

	int GetAmountOfDoors() {
		this->amountOfDoors = amountOfDoors;

	}

	int GetSpeedOfCar() {
		this->speedOfCar = speedOfCar;

	}

	static void SetColor(int userColor, Automobile& other) {

		other.colorOfCar = userColor;
	}

	int GetColor() {
		return colorOfCar;

	}

	void SetAmountOfWheels(int amountOfWheels) {
		this->amountOfWheels = amountOfWheels;

	}

	void SetAmountOfDoors(int amountOfDoors) {
		this->amountOfDoors = amountOfDoors;

	}

	void SetAmountOfSpeedOfCar(int speedOfCar) {
		this->speedOfCar = speedOfCar;

	}

	string Color(int colorOfCar) {
		if (colorOfCar == 1) {
			return "green";
		}
		else if (colorOfCar == 2) {
			return "yellow";
		}
		else if (colorOfCar == 0) {
			return "red";
		}
	}

};

class ParkingSlots {

	Automobile* parkingSlotsForCars = new Automobile[amountOfCars];
public:
	static int amountOfCars;
	ParkingSlots() {

	}

	void PrintInfo() {
		for (int i = 0; i < ParkingSlots::amountOfCars; i++) {
			parkingSlotsForCars[i].PrintInfo();
		}
	}

	void AddCar(const Automobile& other) {
		Automobile* tempArr = new Automobile[ParkingSlots::amountOfCars];
		for (int i = 0; i < ParkingSlots::amountOfCars; i++) {
			tempArr[i] = this->parkingSlotsForCars[i];
		}

		delete[] this->parkingSlotsForCars;
		ParkingSlots::amountOfCars++;

		this->parkingSlotsForCars = new Automobile[ParkingSlots::amountOfCars];

		for (int i = 0; i < ParkingSlots::amountOfCars - 1; i++) {
			this->parkingSlotsForCars[i] = tempArr[i];
		}

		this->parkingSlotsForCars[ParkingSlots::amountOfCars - 1] = other;
	}

	void DeleteCar() {
		if (ParkingSlots::amountOfCars < 1) {
			cout << "There's no Cars on Parking slots." << endl;
		}
		else {
			Automobile* tempArr = new Automobile[ParkingSlots::amountOfCars];
			for (int i = 0; i < ParkingSlots::amountOfCars; i++) {
				tempArr[i] = this->parkingSlotsForCars[i];
			}

			delete[] this->parkingSlotsForCars;
			ParkingSlots::amountOfCars--;

			this->parkingSlotsForCars = new Automobile[ParkingSlots::amountOfCars];

			for (int i = 0; i < ParkingSlots::amountOfCars - 1; i++) {
				this->parkingSlotsForCars[i] = tempArr[i];
			}
		}
	}

	void RenameCar(const Automobile& other) {
		int indexOfCar;
		cout << "Enter index of Car: " << endl;
		cin >> indexOfCar;
		for (int i = 0; i < ParkingSlots::amountOfCars; i++) {
			if (i = indexOfCar) {
				this->parkingSlotsForCars[i] = other;
			}
		}
	}
};

int ParkingSlots::amountOfCars = 1;

int main()
{
	Automobile obj;
	ParkingSlots obj1;
	int userColor;
	int userNumChoose;
	while (true) {
		cout << "Enter number of option that you want to do: 1 - Ride car in Parking lot; 2 - Ride off car from Parking lot; 3 - Show All cars;" << endl;;
		cout << "<--------------------->" << endl;
		cin >> userNumChoose;

		if (userNumChoose == 1) {
			cout << "Enter userColor from 0 to 3: " << endl;
			cin >> userColor;
			obj1.AddCar(Automobile(4, 4, userColor, 50 ));
		}
		else if (userNumChoose == 2) {
			obj1.DeleteCar();
		}
		
		else if (userNumChoose == 3) {
			obj1.PrintInfo();
		}


	}
}

