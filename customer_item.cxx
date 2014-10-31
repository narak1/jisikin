#include <iostream>
using namespace std;

class Customer
{
private:
	string name;
	string address;
	string datePurchase;
	int quantity;
public:
	Customer(string name,string address,string datePurchase,int quantity);//Constructor
	string getName() { return name; };
	string getAddress() { return address; };
	int getQuantity() { return quantity; };
	~Customer() {};
	friend ostream& operator<<(ostream& os, Customer& c);
};

//=================

Customer::Customer(string name,string address,string datePurchase,int quantity)
{
	this->name=name;
	this->address=address;
	this->datePurchase=datePurchase;
	this->quantity=quantity;
}

ostream& operator<<(ostream& os, Customer& c)
{
	os.width(9);
	os << std::left << c.name;
	os.width(9);
	os << std::left << c.address;
	os << c.quantity;
	return os;
}

//=================

class Item
{
protected:
	int barCode;
	string description;
	double price;
public:
	Item(int id, string, double);
	virtual ~Item() {}; //Destructor
	virtual void displayInformation(); //virtual function for polymorphic effect
	virtual void addCustomerPurchase(Customer&, int)=0;//pure virtual function
	void changePrice(double);
};

class Clothes : public Item
{
private:
	string size; // 1 small, 2 medium , 3 large
	Customer** customerPurchase;
	static const int MaxCustomer = 5;
public:
	Clothes(int, string , double , string);
	void displayInformation(); // override the method to display course & classes
	void addCustomerPurchase(Customer& newCustomer,int);
	void changeSize(int size);	
};

class Meat : public Item
{
private:
	double weight; // 1 kilos, pound etc
	Customer** customerPurchase;
	static const int MaxCustomer = 10;
public:
	Meat (int, string, double, double);
	void displayInformation(); // override the method to display course & classes
	void addCustomerPurchase(Customer& newCustomer,int);
	void changeDatePurchase(string newDate);	
};

//=================

Item::Item(int bcode=0, string des="", double prc=0)
{
	barCode=bcode;
	description=des;
	price=prc;
}

void Item::displayInformation()
{
	cout << "BarCode : " << this->barCode << endl;
	cout << "Description : " << this->description << endl;
	cout << "Price   : " << this->price << endl;
}

//=================

Clothes::Clothes(int bcode=0, string des="", double prc=0, string sz="")
 : Item(bcode, des, prc), size(sz)
{
	//barCode=bcode;
	//description=des;
	//price=prc;
	//size=sz;
	customerPurchase=new Customer* [MaxCustomer]();
}

void Clothes::addCustomerPurchase(Customer& newCustomer, int x)
{
	if( x < MaxCustomer )
		this->customerPurchase[x] = &newCustomer;
}

void Clothes::changeSize(int sz)
{
	size=sz;
}

void Clothes::displayInformation()
{
	cout << "--------CLOTHES---------------------" << endl;
	cout << endl;
	Item::displayInformation();
	cout << "Size    : " << this->size << endl;
	cout << "Order details:" << endl;
	int quantity = 0;
	for( int i=0 ; i<MaxCustomer ; i++ ) {
		if( this->customerPurchase[i] != NULL )
		{
			Customer *c = this->customerPurchase[i];
			quantity += c->getQuantity();
			cout << "        " << *c << endl;
		}
	}
	cout << "-------------------------------" << endl;
	cout << "Total quantity sold       : " << quantity << endl;
	cout << "Total amount slaes        : " << quantity * price << endl;
	cout << endl;
}

//=================

Meat::Meat(int bcode=0, string des="", double prc=0, double wt=0.0)
 : Item(bcode, des, prc), weight(wt)
{
	customerPurchase=new Customer* [MaxCustomer]();
}

void Meat::addCustomerPurchase(Customer& newCustomer, int x)
{
	if( x < MaxCustomer )
		this->customerPurchase[x] = &newCustomer;
}

void Meat::displayInformation()
{
	cout << "--------MEAT---------------------" << endl;
	cout << endl;
	Item::displayInformation();
	cout << "Weight  : " << this->weight << " kilogram" << endl;
	cout << "Order details:" << endl;
	int quantity = 0;
	for( int i=0 ; i<MaxCustomer ; i++ ) {
		if( this->customerPurchase[i] != NULL )
		{
			Customer *c = this->customerPurchase[i];
			quantity += c->getQuantity();
			cout << "        " << *c << endl;
		}
	}
	cout << "-------------------------------" << endl;
	cout << "Total quantity sold       : " << quantity << endl;
	cout << "Total amount slaes        : " << quantity * price << endl;
	cout << endl;
}

//==================

int main()
{
	Item* item1= new Meat(101,"chicken",1.5);
	Item* item2= new Meat(101,"chicken",1.5,12.4); //barcode, Description, price, weight, 
	Item* item3= new Clothes(102,"Pants",200.00,"Medium"); //barcode, Description, price, size 
	Item* item4= new Clothes(103,"Shorts",150.00,"Medium");
	
	Customer c1("Park","Korea","02-11-2014",12); // Name, Address, date Purchase, Quantity 
	Customer c2("Obama","USA","01-20-2014",15); 
	Customer c3("Putin","Russia","03-09-2014",20); 
	Customer c4("Merkel","Germany","06-10-2014",15);

	item2->addCustomerPurchase(c1,0); 
	item2->addCustomerPurchase(c2,1); 
	item3->addCustomerPurchase(c3,0); 
	item3->addCustomerPurchase(c4,1); 
	item3->addCustomerPurchase(c1,2); 
	item1->displayInformation(); //Output display
	
	Item* i2=item2; //Another way to display using Polymorphism 
	Item* i3=item3; 
	i2->displayInformation(); //Output 
	i3->displayInformation();
}

