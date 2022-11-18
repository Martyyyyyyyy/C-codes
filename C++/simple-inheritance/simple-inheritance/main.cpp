#include "Header.h"


int main()
{
	setlocale(LC_ALL, "ukr");
	srand(time(NULL));

	// оголошуємо масив вказівників на базовий клас Station
	Station* station[4] =
	{
	new Street("Broadway"),
	new Avenue("5th Avenue"),
	new Square("Times Square"),
	new Park("Central Park")
	};

	for (int k = 0; k < OBJ; k++)
	{
		station[k]->print();
		delete station[k];
	}

	Menu();
	return 0;
}