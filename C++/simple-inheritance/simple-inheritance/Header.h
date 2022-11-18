#pragma warning(disable : 4996)
#include <ctime>
#include <iostream>
#include <cstring>
#include <fstream>
#include <Windows.h>

using namespace std;
const int OBJ = 4;

class Composter
{
private:
	char number[BUFSIZ];
	static int count_of_composters;
protected:
	char encryption[BUFSIZ];
public:
	char number_of_bus[BUFSIZ];
	char number_of_journey[BUFSIZ];
	int count_of_used_tickets;
	char massive_numbers_of_used_tickets[BUFSIZ][8];
	char current_time[BUFSIZ];
	char time_last_checking[BUFSIZ];
	char count_working_hours[BUFSIZ];
	char time_of_commissioning[BUFSIZ];
	void SetNumber(const char* nmbr);
	void SetEncryption(const char* encrptn);
	void SetNumber_of_bus();
	void SetNumber_of_journey();
	void AddMassive_numbers_of_used_tickets(const char* nt);
	void SetCurrentTime(char* buffer);
	void SetTime_of_commissioning(char* buffer);
	char* GetNumber();
	char* GetEncryption();
	char* GetCount_working_hours(char* ptr_toc);
	int GetCount_of_composters();
	void CreateUniqueNumber();
	int ChoiceTicket();
	int ChoiceComposter();
	void Checkeing();
	void Control();
	void Control(bool something);
	void InputData();
	void AddComposterToCOMPOSTERS();
	int InputDataToFile();
	int ReInputDataToFile();
	void OutputData();
	void OutputAllCOMPOSTERS();
	int OutputDataFromFile();
	void DeleteCOMPOSTERS();
	Composter();
	Composter(bool empty);
	Composter(const char* encrptn);
	Composter(const Composter& objct);
	~Composter();
};

class Tickets : public Composter
{
public:
	char number_of_ticket[7];
	char encryption_of_ticket[BUFSIZ];
	void SetNumber_of_ticket(const char* nmbr);
	void CreateUniqueNumber_of_ticket();
	void AddTicketToTICKETS();
	int InputDataToFile();
	int ReInputDataToFile();
	void OutputData();
	void OutputAllTICKETS();
	int OutputDataFromFile();
	Tickets();
};

class Station //абстрактний базовий клас
{
	char name[20]; // назва станцій
public:
	// конструктор
	Station(const char* nam = "нiяка") { strcpy(name, nam); }
	char* getName() { return name; }
	virtual ~Station() { cout << "\n Об'єкт знищено!\n\n"; }
	// чисто віртуальний метод
	virtual void print() = 0;
};

class Street : public Station //клас вулиць
{
public:
	Street(const char* nam) : Station(nam) {};
	virtual void print() {
		cout << getName() << " - вулиця, через яку найчастiше проїжає автобус ";
	}
};

class Avenue : public Station //клас авеню
{
public:
	Avenue(const char* nam) : Station(nam) {};
	virtual void print() {
		cout << getName() << " - авеню, через яку найчастiше проїжає автобус ";
	}
};

class Square : public Station //клас скверів
{
public:
	Square(const char* nam) : Station(nam) {};
	virtual void print() {
		cout << getName() << " - сквер, через який найчастiше проїжає автобус ";
	}
};

class Park : public Square //клас парків
{
public:
	Park(const char* nam) : Square(nam) {};
	//virtual void print()
	//{
	// cout << getName() << " - парк, через який найчастiше проїжає автобус ";
	//}
	//virtual int print() // ПОМИЛКА КОМПІЛЯЦІЇ!
	//' // тип результату виконання не співрадає з прототипом
	//{
	// cout << getName() << " - парк, через який найчастiше проїжає автобус ";
	//return 0;
	//}
	virtual void print(int ups) // ПОМИЛКА ВИКОНАННЯ!
		// список формальних параметрів не співпадає з прототипом
	{
		cout << getName() << " - парк, через який найчастiше проїжає автобус ";
	}
};

int InputCorrectInteger();
bool IsSameNumber(const char* nmbr);
void AddNumberToNUMBERS(const char* number);
void Menu();
