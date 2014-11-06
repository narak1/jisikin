#include <iostream>
#include <fstream>
#include <iomanip>

int getRequest(); // get user¡¯s request
void new_item(); // create new recorde to item file (Writing to item file)
void new_sale(); // create new recorde to sale file (Writing to sale file)
void display_items(); // Display items from file (Reading from item file )
void display_sales(); // Display sales from file (Reading from sale file)
bool search(string); // search if a specific item exist in item file

string found_item[]={"","",""};// global variable for searching item

enum RequestType { NEW_ITEM = 1, SHOW_ITEMS, NEW_SALE, SHOW_SALES, END };

const char *items_filename = "Items.txt";
const char* sales_filename = "Sales.txt";

int main()
{
	// get user's request (e.g., zero, credit or debit balance)
	int request = getRequest();

	// process user's request
	while ( request != END )
	{
		switch ( request )
		{
			case NEW_ITEM:
				cout << "\n Entering a new Item to store:\n";
				new_item();
				break;
			case SHOW_ITEMS:
				cout << "\n List items of the store:\n";
				display_items();
				break;
			case NEW_SALE:
				cout << "\nEnter a new sale (Purchase):\n";
				new_sale();
				break;
			case SHOW_SALES:
				cout << "\n List sales (Purchases):\n";
				display_sales();
				break;
		} // end switch

		request = getRequest(); // get additional request from user
	}
	system("pause");
}

int getRequest()
{
	int menu;
	const char* menu_str =
"Enter request\n"
" 1 - Enter a new item to store\n"
" 2 - List items of the store\n"
" 3 - Enter a new sale (Purchase)\n"
" 4 - List sales (Purchases)]n"
" 5 - End of run\n"
"? ";
	cout << menu_str;
	cin >> menu;
	return menu;
}

void new_item()
{
	ofstream ofs(items_filename, ios_base::out | ios_base::app);
	if( !ofs ) {
		cerr << "Cannot open items file : " << items_filename << endl;
		return;
	}

	int item_id;
	char item_name[256];
	int item_price;

	cout << "\nEnter item ID: ";
	cin >> item_id;
	ofs << item_id;
	cout << "\nEnter item Name: ";
	cin >> item_name;
	ofs << " " << item_name;
	cout << "\nEnter item price: ";
	cin >> item_price;
	ofs << " " << item_price << endl;

	ofs.close();
	cout << "\n\tRecord saved..." << endl << endl;
}

void display_items()
{
	ifstream ifs(items_filename);
	if( !ifs ) {
		cerr << "Cannot open items file : " << items_filename << endl;
		return;
	}

	int item_id;
	char item_name[256];
	int item_price;

	cout << "\t=============== ITEM RECORDS =========" << endl;
	cout << "\tItem#\tDescription\tPrice" << endl;
	cout << endl;
	while( ! ifs.eof() ) {
		ifs >> item_id >> item_name >> item_price;
		cout << "\t" << item_id << "\t" << item_name << "\t" << item_price << endl;
	}
	cout << endl;

	ifs.close();
}

void new_sale()
{
	int item_id;
	char item_name[256];
	int item_price;

	char buyer_name[256];
	int quantity;
	double amount;

	cout << "\nEnter buyer's name: ";
	cin >> buyer_name;
	cout << "\nEnter item ID     : ";
	cin >> item_id;

// item info print
	bool flag = find_item_info(item_id, item_name, item_price);
	if( flag == false ) {
		cout << "Item Record is not found... try again" << endl;
		return;
	}
	cout << "\n\t\t" << item_id << "\t" << item_name << "\t" << item_price << endl;

	cout << "\nEnter quantity    : ";
	cin >> quantity;
	amount = item_price * quantity;

// sale info print
	cout << fixed << setprecision(2);	// for print amount
	cout << "\n\t\t" << buyer_name << "\t\t" << item_name << "\t" << amount << endl;

	ofstream ofs(sales_filename, ios_base::out | ios_base::app);
	if( !ofs ) {
		cerr << "Cannot open sales file : " << sales_filename << endl;
		return;
	}

	ofs << setw(30) << buyer_name << setw(30) << item_name << setw(30) << amount << endl;
	ofs.close();
	cout << "\nRecord saved..." << endl << endl;
}
