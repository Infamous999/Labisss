#include <iostream>

using namespace std;

template <class T>
T getSymbol();

template <class T> class twoDimenArray {
public:
	twoDimenArray(int sizeX, int sizeY) {
		this->sizeX = sizeX;
		this->sizeY = sizeY;
		mass = new T * [sizeX];
		for (int i = 0; i < sizeX; i++) {
			mass[i] = new T[sizeY];
		}
	};
	twoDimenArray* operator++(int) {
		twoDimenArray* TDA = this;
		T temp = TDA->mass[sizeX - 1][sizeY - 1];
		T* tempArray = new T[sizeX * sizeY];
		for (int i = 0, k = 0; i < sizeX; i++)
			for (int j = 0; j < sizeY; j++, k++)
				tempArray[k] = TDA->mass[i][j];
		for (int i = sizeX * sizeY - 1; i > 0; i--)
			tempArray[i] = tempArray[i - 1];
		tempArray[0] = temp;
		for (int i = 0, k = 0; i < sizeX; i++)
			for (int j = 0; j < sizeY; j++, k++)
				TDA->mass[i][j] = tempArray[k];
		return TDA;
	};
	void enterArray() {
		cout << "Введите массив: " << endl;
		for (int i = 0; i < sizeX; i++)
			for (int j = 0; j < sizeY; j++)
				mass[i][j] = getSymbol<T>();
	};
	void print() {
		cout << "Массив: " << endl;
		for (int i = 0; i < sizeX; i++) {
			for (int j = 0; j < sizeY; j++)
				cout << mass[i][j] << " ";
			cout << endl;
		}
	};
private:
	T** mass;
	int sizeX, sizeY;
};

int main() {
	setlocale(LC_ALL, "Ru");
	cout << "Введите размерность двумерного массива: ";
	int sizeX = getSymbol<int>();
	int sizeY = getSymbol<int>();
	twoDimenArray<double> TDA(sizeX, sizeY);
	TDA.enterArray();
	TDA.print();
	cout << endl << "Один инкремент: " << endl;
	TDA++;
	TDA.print();
	cout << endl << "Ещё два инкремента: " << endl;
	TDA++; TDA++;
	TDA.print();
	return 0;
}

template<class T>
T getSymbol()
{
	T symbol;
	{
		while (true)
		{
			cin >> symbol;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
			}
			else
				return symbol;
		}
	}
}
