#include <iostream>
#include <cmath>

using namespace std;

double value();  
double value_2();

class equation {  
public:

	double a;	
	double b;
	double c;
};
int main() {   

	cout << "This program solves an equation of the form: a*sin(x) + b*cos(x) = c" << endl;

	equation task;   
	task.a = value();  
	task.b = value_2();
	task.c = 0;

	double res_div = task.b / task.a;

	cout << "Number c = 0" << endl;                                                                               
	cout << "equation: " << task.a << "*sin(x) + " << task.b << "*cos(x) = " << task.c << endl;
	cout << "divide this equation by: cos x, we get " << task.a << "*tg(x) + " << task.b << " = 0" << endl;
	cout << "divide both sides of the equation by: " << task.a << ", we get: tg(x) = " << -res_div << endl;
	if (task.c == 0)
		cout << "x = arctg " << -res_div << " + Pi * n" << endl;
}
double value()
{
	while (true) {
		double number;                                                         
		cout << "Enter number a: ";
		cin >> number;
		if (cin.fail() || number <= 0) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Error, please enter again" << endl;
		}
		else {
			return number;
			 }
	}
}
double value_2()														      
{
	while (true) {
		double number;
		cout << "Enter number b: ";
		cin >> number;
		if (cin.fail() || number <= 0) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Error, please enter again" << endl;
		}
		else {
			return number;
			 }
	}
}