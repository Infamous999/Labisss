#include <iostream>
#include <cmath>
using namespace std;
typedef struct Compl {
	double Re;
	double Im;
	double Modul;
	double Arg;
} complex;
complex summation(complex z1, complex z2) {
	complex sum;
	sum.Re = z1.Re + z2.Re;
	sum.Im = z1.Im + z2.Im;
	return sum;
}
complex subtract(complex z1, complex z2) {
	complex sub;
	sub.Re = z1.Re - z2.Re;
	sub.Im = z1.Im - z2.Im;
	return sub;
}
complex multiply(complex z1, complex z2) {
	complex mult;
	mult.Re = (z1.Re * z2.Re) - (z1.Im * z2.Im);
	mult.Im = (z1.Im * z2.Re) + (z2.Im * z1.Re);
	return mult;
}
complex divide(complex z1, complex z2) {
	complex div;
	div.Re = (z1.Re * z2.Re + z1.Im * z2.Im) / (pow(z2.Re, 2) + pow(z2.Im, 2));
	div.Im = (z1.Im * z2.Re - z2.Im * z1.Re) / (pow(z2.Re, 2) + pow(z2.Im, 2));
	return div;
}
void AlForm(Compl& number); 
void TrForm(Compl& complex); 
int question();
int main() {
	complex	complex_1, complex_2;
	cout << "Enter |z| for first complecs number: ";
	cin >> complex_1.Modul;
	cout << "Enter ar(z) for first complecs number: ";
	cin >> complex_1.Arg;
	cout << "First complex number: " << complex_1.Modul << " * (cos(" << complex_1.Arg << ") + i * sin(" << complex_1.Arg << "))" << endl;
	cout << endl;
	cout << "Enter |z| for second complecs number: ";
	cin >> complex_2.Modul;
	cout << "Enter ar(z) for second complecs number: ";
	cin >> complex_2.Arg;
	cout << "Second complex number: " << complex_2.Modul << " * (cos(" << complex_2.Arg << ") + i * sin(" << complex_2.Arg << "))" << endl;

	AlForm(complex_1);
	AlForm(complex_2);

	int answer = question();
	switch (answer) {
	case 1:
		complex sum = summation(complex_1, complex_2);
		TrForm(sum);
		cout << "Addition these numbers in trigonometry form = " << sum.Modul << "exp(i" << sum.Arg << ")" << endl;
		break;
	case 2:
		complex sub = subtract(complex_1, complex_2);
		TrForm(sub);
		cout << "Differens these numbers in trigonometry form = " << sub.Modul << "exp(i" << sub.Arg << ")" << endl;
		break;
	case 3:
		complex div = divide(complex_1, complex_2);
		TrForm(div);
		cout << "Quotient these numbers in trigonometry form = " << div.Modul << "exp(i" << div.Arg << ")" << endl;
		break;
	case 4:
		complex mult = multiply(complex_1, complex_2);
		TrForm(mult);
		cout << "Multiplication these numbers in trigonometry form = " << mult.Modul << "exp(i" << mult.Arg << ")" << endl;
		break;
	default:
		cout << "This is not on the list" << endl;
		break;
	}
}
void AlForm(Compl& number) {
	number.Re = number.Modul * cos(number.Arg);
	number.Im = number.Modul * sin(number.Arg);
}
void TrForm(Compl& complex) {
	complex.Modul = sqrt(complex.Re * complex.Re + complex.Im * complex.Im);
	complex.Arg = asin(double(complex.Im / complex.Modul));
}
int question() {
	int answer;
	while (true) {
		cout << "Enter what you want to choose: addition(1), subtraction(2), division(3), multiplication(4)." << endl;
		cin >> answer;
		if (cin.fail() || answer < 0) {
			cin.clear();
			cin.ignore(32657, '\n');
			cout << "Eror, re-enter" << endl;
		}
		else return answer;
	}
}
