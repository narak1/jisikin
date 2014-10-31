#include <iostream>
using namespace std;

class Person
{
public:
	Person();
	Person(string, string, string);
	string getName();
	string getSSN();
	string getAddress();
	void setName(string n) { Name = n; };
	void setSSN(string);
	void setAddress(string);
	Person& operator=(const Person&);
	void print();
private:
	string Name;
	string SSN;
	string address;
};

Person::Person(string n, string s, string a)
 : Name(n), SSN(s), address(a)
{
	;
}

void Person::print()
{
	cout << "Owner    :      " << Name << endl;
	cout << "Address  :      " << address << endl;
	cout << "SSNumber :      " << SSN << endl;
}

class Engine
{
	int cylinders;
	int power;
	string model;
	string manufacturer;
public:
	Engine();
	Engine(int , int , string , string );
	void setCylinders(int);	
	void setPower(int);
	void setModel(string);
	void setManufacturer(string);
	int getCylinders();
	int getPower();
	string getModel();
	string getManufacturer();
	void print();
};

Engine::Engine(int c, int p, string mo, string ma)
 : cylinders(c), power(p), model(mo), manufacturer(ma)
{
	;
}

void Engine::print()
{
	cout << "Engine Model        :    " << model << endl;
	cout << "Engine Manufacturer :    " << manufacturer << endl;
	cout << "Engine Power        :    " << power << endl;
	cout << "Engine Cylinders    :    " << cylinders << endl;
}

class Vehicle
{
private:
	Engine *engine;
	Person *owner;
	string manufacturer;
	int capacityLoad;
public:
	Vehicle() : engine(NULL), owner(NULL), capacityLoad(0) { ; };
	Vehicle(Engine *,Person *, string ,int);
	void setEngine(Engine *e) { engine = e;	};
	void setOwner(Person *p) { owner = p; };
	void setManufacturer(string m) { manufacturer = m; };
	void setCapacityLoad(int);
	Engine* getEngine() { return engine; };
	Person* getOwner() { return owner; };
	string getManufacturer() { return manufacturer; };
	int getLoadCapacity();
};

class Truck : public Vehicle
{
private:
	double loadCapacity;
	int towingCapacity;
public:
	Truck();
	Truck(double lc,int tc) : loadCapacity(lc), towingCapacity(tc) { ; }; 
	void setCapacityLoad(double);
	void setTowingCapacity(int);
	double getLoadCapacity();
	int getTowingCapacity();
	void print();// print information about the Truck
};

void Truck::print()
{
	cout << "===================================" << endl;
	this->getOwner()->print();
	cout << endl;
	this->getEngine()->print();
	cout << endl;
	cout << "Truck Manufacturer    : " << this->getManufacturer() << endl;
	cout << "Truck Capacity        : " << this->loadCapacity << endl;
	cout << "Truck Towing Capacity : " << this->towingCapacity << endl;
	cout << endl;
}

class Car
{
private:
	int seats;
	string size;
	string color;
public:
	Car();
	Car(int ,string , string );
	void setSeats(int);
	void setSize(string);
	void setColor(string);
	int getSeats();
	string getSize();
	string getColor();
	void print();  // print information about the car
};

Car::Car(int s, string sz, string cl)
 : seats(s), size(sz), color(cl)
{
	;
}

int select_menu();

int main()
{
	Person p1("Putin","123","RUSSIA");//Name SSN address
	Person p2("Obama","123","USA");
	Person p3("Park","1234","KOREA");
	
	Engine e1(30,20,"1990","Isuzu");// cylinders power model manufacturer 
	Engine e2(40,10,"2010","Hyundae");
	
	Car c1(4,"medium","Black");// seats =1 size="Small" color= "White"; 
	Car c2(6,"Big","Gray");
	
	Truck t1(1500,4);// double loadCapacity int towingCapacity; 
	Truck t2(1000,3);
	
	t1.setEngine(&e1);
	t1.setOwner(&p1);
	t1.setManufacturer("Ford");

	int menu;
	do {
		t1.print();
		menu = select_menu();
		if( menu == 1 ) {
			cout << " Enter owner's Name" << endl;
			string owner_name;
			cin >> owner_name;
			Person *p = t1.getOwner();
			p->setName(owner_name);
		}
		else if( menu == 2 ) {
			;
		}
		else {
			;
		}
	} while( menu != 4 );
}

int select_menu()
{
	int m;
	string menu_str =
"===================================\n"
" UPDATE VEHICLE REGISTRATION\n"
"1. Change the Owner's Name\n"
"2. Change the Engine Model\n"
"3. Change the Engine Manufacturer\n"
"4. Exit the Program:\n"
"\n"
"Please choose one of the above options: ";

	cout << menu_str;
	cin >> m;
	return m;
}
