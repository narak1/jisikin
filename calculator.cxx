#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

void Help();
bool InputData(char& operation, double& operand);
double calculate(double total, char operation, double operand);

inline string bool_str(bool val)
{
	const string true_str = "True";
	const string false_str = "False";
	if( val ) return true_str;
	return false_str;
}

main()
{
	char operation;
	double operand;
	double accu_value = 0.0;
	bool run_flag = true;

	cout << "Welcome to the Super Dooper Calculator (SDC)." << endl;
	Help();
	while(run_flag)
	{
		cout << "total: " << fixed << setprecision(3) << accu_value << endl;
		
		bool flag = InputData(operation, operand);
		if( flag == false ) {
			continue;
		}

		switch( operation ) {
			case '+': accu_value += operand; break;
			case '-': accu_value -= operand; break;
			case '*': accu_value *= operand; break;
			case '/': accu_value /= operand; break;
			case '^': accu_value = pow(accu_value, operand); break;
			case '>': cout << bool_str(accu_value > operand) << endl; break;
			case '<': cout << bool_str(accu_value < operand) << endl; break;
			case '=': cout << bool_str(accu_value == operand) << endl; break;
			case 't':
			case 'T': accu_value += accu_value * operand / 100.0; break;
			case 'c':
			case 'C': accu_value = 0.0; break;
			case 'h':
			case 'H': Help(); break;
			case 'q':
			case 'Q': run_flag = false; break;
			default: cout << "\bBad input: '" << operation << "' is not a valid operator." << endl; 
		}
	}
	cout << "Good bye. Have a nice day!" << endl;	
}

void Help()
{
	const char *help_str =
"Usage: \n"
"Enter the operator followed by the operand and the \n"
" SDC will show you the accumulated total. \n"
"Enter C to clear the contents. \n"
"Enter Q to quit. \n"
"You can use the following operators: \n"
"+ add \n"
"- subtract \n"
"* multiply \n"
"/ divide \n"
"^ power \n"
"> greate than \n"
"< less than \n"
"= equal \n"
"t or T Taxes \n"
"c or C clear total \n"
"h or H show help \n"
"q or Q quit \n";
	cout << help_str;
}

bool InputData(char& operation, double& operand)
{
	char buf[1024];
	cin >> operation;
	cin.getline(buf, 1024);
	operand = strtod(buf, NULL);
	return true;
}

double calculate(double total, char operation, double operand)
{
	switch( operation ) {
		case '+': total += operand; break;
		case '-': total -= operand; break;
		case '*': total *= operand; break;
		case '/': total /= operand; break;
		case '^': total = pow(total, operand); break;
		case 't':
		case 'T': total += total * operand / 100.0; break;
		case 'c':
		case 'C': total = 0.0; break;
	}
	return total;
}
