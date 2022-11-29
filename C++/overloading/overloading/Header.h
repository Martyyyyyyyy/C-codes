#pragma once
#include <iostream>
#include <iomanip>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;

int readNumber(string);
enum { oneTime, manyTime, used };

class Date {
	
	int month, day, year, hour, minute, second;
public:
	
	Date();
	Date(int, int, int);
	~Date() {};
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setHour(int);
	void setMin(int);
	void setSec(int);
	void showDate1();
	void showDate2();
	void showDate3();
	bool IncorrectDate();
	void EnterDate(int, int, int);
	void EnterTime(int, int, int);
};
class Composter {
	static int count;
	static int digit;
	int number;
	int bus_numb;
	int race_num;
	static int count_wor_ticket;
	static int* arr_num;
	int hoursWorked;
protected:
	string shyfr;
public:
	string ticket;
	Date curTime;
	Date timeExpluat;
	Date lastAudit;
	Composter();
	Composter(string, string, int, int, int, int);
	Composter(const Composter&);
	~Composter();
	string getShyfr();
	int getNumber();

	int getNumberBus();
	int getNumberRace();
	void setNumber(int);
	void setNumberBus(int);
	void setNumberRace(int);
	void setShyfr(string);
	void printObject();
	void consoleInit();
	int fileInit(string);
	int fileSaveData(string);
	int fileBinSaveData(string);
	void Control(int);
	void Control();
	static int getCount();
	static int generate_number();
	static void printArrOfNumWor();
	friend ostream& operator <<(ostream& os, const Composter&);
	friend istream& operator >>(istream& is, Composter&);
	friend ofstream& operator <<(ofstream&, const Composter&);
	friend ifstream& operator >>(ifstream&, Composter&);
	friend ifstream& operator >(ifstream&, Composter&);
	bool operator < (const Composter&);
	bool operator > (const Composter&);
	bool operator == (const Composter&);
};
void sortBus(Composter*, int);
void QuickSortArray(Composter*, int, int);
int fileBinInit(string, Composter*&, int&);
void printArrBus(Composter*, int);