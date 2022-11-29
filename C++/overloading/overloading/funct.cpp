#include "Header.h"

int Composter::count = 0;
int Composter::digit = 999;
int Composter::count_wor_ticket = 0;
int* Composter::arr_num = 0;

Composter::Composter() {
	shyfr = "#0000";
	ticket = "tck13";
	number = generate_number();
	bus_numb = generate_number();
	race_num = generate_number();
	hoursWorked = 10;
	cout << "\nThe object is created\n";
	count++;

}
Composter::Composter(string shyf, string tick, int num, int b_n, int r_n, int h_w) {
	shyfr = shyf;
	ticket = tick;
	number = num;
	bus_numb = b_n;
	race_num = r_n;
	hoursWorked = h_w;
	cout << "\nThe object is created\n";
	count++;
}
Composter::Composter(const Composter& A) {
	shyfr = A.shyfr;
	ticket = A.ticket;
	number = A.number;
	bus_numb = A.bus_numb;
	race_num = A.race_num;
	hoursWorked = A.hoursWorked;
	cout << "\nThe object is created\n";
	count++;
}
Composter::~Composter() {
	cout << "\nThe object is deleted\n";
	cout << "Number of objects: " << --count << endl;
}
string Composter::getShyfr() {
	return shyfr;
}
int Composter::getNumber() {
	return number;
}
int Composter::getNumberBus() {
	return bus_numb;
}
int Composter::getNumberRace() {

	return race_num;
}
void Composter::setNumber(int num) {
	number = num;
}
void Composter::setNumberBus(int num) {
	bus_numb = num;
}
void Composter::setNumberRace(int num) {
	race_num = num;
}
void Composter::setShyfr(string shyf) {
	shyfr = shyf;
}
void Composter::printObject() {
	cout << "\nNumber: " << number << endl;
	cout << "Shyfr: " << shyfr << endl;
	cout << "Ticket: " << ticket << endl;
	cout << "Bus number: " << bus_numb << endl;
	cout << "Race number: " << race_num << endl;
}
int readNumber(string msg) {
	cout << msg << "= ";
	string str;
	cin >> str; cin.ignore(1, '\n');
	getline(cin, str);
	return stoi(str);
}
void Composter::consoleInit() {
	cout << "\nConsoleInit() work\n";
	cout << "\nEnter number: "; number = readNumber(" ");
	cout << "\nEnter bus number: "; bus_numb = readNumber(" ");
	cout << "\nEnter race number: "; race_num = readNumber(" ");
	cout << "\nEnter ticket: "; cin >> ticket;
	cout << "\nEnter shyfr: "; cin >> shyfr;

}
int Composter::fileInit(string f_name) {
	const int size = 10;
	char str[size + 1];
	cout << "\nFileInit() work\n";
	ifstream fin(f_name);
	if (!fin)
	{
		cout << "\nFile " << f_name << " is not found\n";
		return 0;
	}
	fin.getline(str, size);
	number = stoi(str);
	fin.getline(str, size);
	bus_numb = stoi(str);
	fin.getline(str, size);
	race_num = stoi(str);
	fin.getline(str, size);
	ticket = str;
	fin.getline(str, size);
	shyfr = str;
	fin >> *this;
	fin.close();
	return 1;
}
int Composter::fileSaveData(string f_name) {
	cout << "\nfileSaveData() work\n";
	fstream fout(f_name, ios_base::out | ios_base::app);
	if (!fout)
	{
		cout << "\nFile " << f_name << " is not found\n";
		return 0;
	}
	fout << endl << number << endl;
	fout << bus_numb << endl;

	fout << race_num << endl;
	fout << ticket << endl;
	fout << shyfr << endl;
	fout << *this;
	fout.close();
	return 1;
}
int fileBinInit(string f_name, Composter*& arr, int& n) {
	const int size = 10;
	char str[size + 1];
	cout << "\nfileBinInit() work\n";
	ifstream fin(f_name, ios_base::binary);
	if (!fin.is_open())
	{
		cout << "\nFile " << f_name << " is not found\n";
		return 0;
	}
	fin.getline(str, size);
	fin.read((char*)arr, sizeof(Composter) * n);
	fin.seekg(0, 2);
	n = fin.tellg() / sizeof(Composter);
	cout << "\nSize:" << n << endl;
	arr = new Composter[n];
	fin.seekg(0);
	for (int i = 0; i < n; i++) {
		fin > arr[i];
	}
	cout << "\nArray is ready\n";
	fin.close();
	return 1;
}
int Composter::fileBinSaveData(string f_name) {
	cout << "\nfileBinSaveData() work\n";
	fstream fout(f_name, ios_base::out | ios_base::app | ios_base::binary);
	if (!fout.is_open())

	{
		cout << "\nFile " << f_name << " is not found\n";
		return 0;
	}
	fout << endl << number << endl;
	fout << bus_numb << endl;
	fout << race_num << endl;
	fout << ticket << endl;
	fout << shyfr << endl;
	fout.write((char*)&number, sizeof number);
	fout.write((char*)&bus_numb, sizeof bus_numb);
	fout.write((char*)&race_num, sizeof race_num);
	fout.write((char*)&ticket, sizeof ticket);
	fout.write((char*)&shyfr, sizeof shyfr);
	fout.write((char*)this, sizeof(this));
	fout.close();
	return 1;
}
int Composter::getCount() {
	return count;
}
int Composter::generate_number() {
	int gen_num = rand() % digit + 1;
	return gen_num;
}
void Composter::Control(int type) {
	cout << "\nPerehruz. Control(int) work";
	++count_wor_ticket;
	if (!arr_num) arr_num = new int[count_wor_ticket];
	arr_num[count_wor_ticket - 1] = number;
	switch (type) {
	case 0: cout << "\n Ticket used but buy new one next time\n"; break;
	case 1: cout << "\n You have ManyTime Ticket \n"; break;
	case 2: cout << "\nTicket is used buy new one! \n"; break;
	}

}
void Composter::Control() {
	cout << "\nPerehruz. Control() work";
	if (hoursWorked > 24) {
		cout << "\n Ticket is unsuitable for work! \n";
	}
	else {
		cout << "\n Ticket is suitable! \n";
	}
	++count_wor_ticket;
	if (!arr_num) arr_num = new int[count_wor_ticket];
	arr_num[count_wor_ticket - 1] = number;
}
void Composter::printArrOfNumWor() {
	cout << "\nNumbers of worked tickets:";
	for (int i = 0; i < count_wor_ticket; i++) {
		cout << "\t" << arr_num[i];
	}
}
ostream& operator <<(ostream& os, const Composter& C) {
	os << "\nNumber: " << C.number << endl
		<< "Bus number: " << C.bus_numb << endl
		<< "Race number: " << C.race_num << endl
		<< "Ticket: " << C.ticket << endl
		<< "Shyfr: " << C.shyfr << endl;
	return os;
}
istream& operator >>(istream& is, Composter& A) {
	cout << "\nEnter number: "; A.number = readNumber(" ");
	cout << "\nEnter bus number: "; A.bus_numb = readNumber(" ");
	cout << "\nEnter race number: "; A.race_num = readNumber(" ");
	cout << "\nEnter ticket: "; is >> A.ticket;
	cout << "\nEnter shyfr: "; is >> A.shyfr;
	return is;
}

ofstream& operator <<(ofstream& ofs, const Composter& A) {
	ofs << endl << A.number << endl;
	ofs << A.bus_numb << endl;
	ofs << A.race_num << endl;
	ofs << A.ticket << endl;
	ofs << A.shyfr << endl;
	return ofs;
}
ifstream& operator >>(ifstream& ifs, Composter& A) {
	string str;
	ifs >> str; A.number = stoi(str);
	ifs >> str; A.bus_numb = stoi(str);
	ifs >> str; A.race_num = stoi(str);
	ifs >> A.ticket; ifs.ignore(1, '\n');
	ifs >> A.shyfr; ifs.ignore(1, '\n');
	return ifs;
}
ifstream& operator >(ifstream& ifs, Composter& C) {
	ifs.read((char*)&C.number, sizeof C.number);
	ifs.read((char*)&C.bus_numb, sizeof C.bus_numb);
	ifs.read((char*)&C.race_num, sizeof C.race_num);
	ifs.read((char*)&C.ticket, sizeof C.ticket);
	ifs.read((char*)&C.shyfr, sizeof C.shyfr);
	return ifs;
}
bool Composter::operator < (const Composter& B) {
	cout << "\n Compare by:" << "\n 0 - exit\n 1 - number\n 2 - bus number\n 3 - race number\n 4 - ticket\n 5 -shyfr";
		int choice = readNumber("\nYour choice ");
	while (choice) {
		switch (choice) {
		case 0: break;
		case 1:
			if (number < B.number) return true; break;

		case 2:
			if (bus_numb < B.bus_numb) return true; break;
		case 3:
			if (race_num < B.race_num) return true; break;
		case 4:
			if (ticket.compare(B.ticket) < 0) return true; break;
		case 5:
			if (shyfr.length() < B.shyfr.length()) return true; break;
		default: break;
		}
	}
	return false;
}
bool Composter::operator > (const Composter& B) {
	cout << "\n Compare by:" << "\n 0 - exit\n 1 - number\n 2 - bus number\n 3 - race number\n 4 - ticket\n 5 -shyfr";
		int choice = readNumber("\nYour choice ");
	while (choice) {
		switch (choice) {
		case 0: break;
		case 1:
			if (number > B.number) return true; break;
		case 2:
			if (bus_numb > B.bus_numb) return true; break;
		case 3:
			if (race_num > B.race_num) return true; break;
		case 4:
			if (ticket.compare(B.ticket) > 0) return true; break;
		case 5:
			if (shyfr.length() > B.shyfr.length()) return true; break;
		default: break;
		}
	}
	return false;

}
bool Composter::operator == (const Composter& B) {
	cout << "\n Compare by:" << "\n 0 - exit\n 1 - number\n 2 - bus number\n 3 - race number\n 4 - ticket\n 5 -shyfr";
		int choice = readNumber("\nYour choice ");
	while (choice) {
		switch (choice) {
		case 0: break;
		case 1:
			if (number == B.number) return true; break;
		case 2:
			if (bus_numb == B.bus_numb) return true; break;
		case 3:
			if (race_num == B.race_num) return true; break;
		case 4:
			if (!ticket.compare(B.ticket)) return true; break;
		case 5:
			if (shyfr.length() < B.shyfr.length()) return true; break;
		default: break;
		}
	}
	return false;
}
void sortBus(Composter* C_arr, int n) {
	int flag = 1, k = n;
	while (flag && k > 1) {
		flag = 0; k--;
		for (int i = 0; i < k; i++) {
			if (C_arr[i] < C_arr[i + 1]) {
				flag = 1;
				swap(C_arr[i], C_arr[i + 1]);
			}
		}
	}

	printArrBus(C_arr, n);
}
void QuickSortArray(Composter* array, int first, int last)
{
	Composter v;
	int left, right;
	left = first; right = last;
	int middle = (left + right) / 2;
	v = array[middle];
	while (left <= right)
	{
		while (array[left] < v)
			left = left + 1;
		while (array[right] > v)
			right = right - 1;
		if (left <= right)
		{
			swap(array[left], array[right]);
			left = left + 1;
			right = right - 1;
		}
	}
	if (first < right)
		QuickSortArray(array, first, right);
	if (left < last)
		QuickSortArray(array, left, last);
	cout << "\nArray is sorted\n";
}
void printArrBus(Composter* Arr, int n) {
	cout << "\nBuses: ";
	for (int i = 0; i < n; i++, cout << endl) {
		cout << Arr[i];
	}
}
Date::Date()

{
	year = month = day = hour = minute = second = 0;
}
void Date::setDay(int d)
{
	day = d;
}
void Date::setMonth(int m)
{
	month = m;
}
void Date::setYear(int y)
{
	year = y;
}
void Date::setHour(int h) {
	while (h < 0 || h>23) {
		cout << "\nPlease enter correct hour:\a ";
		h = readNumber(" ");
	}
	hour = h;
}
void Date::setMin(int m) {
	while (m < 0 || m>59) {
		cout << "\nPlease enter correct minute:\a ";
		m = readNumber(" ");
	}
	minute = m;
}
void Date::setSec(int s) {
	while (s < 0 || s>59) {
		cout << "\nPlease enter correct second:\a ";
		s = readNumber(" ");
	}
	second = s;

}
void Date::showDate1()
{
	cout.fill('0');
	cout << setw(2) << month << "/" << setw(2) << day << "/" << year;
	cout << " " << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second <<
		endl;
	cout.fill(' ');
}
void Date::showDate2()
{
	string monthName[] = { "January", "February", "March",
	"April", "May", "June", "July",
	"August", "September", "October",
	"November", "December" };
	cout.fill('0');
	cout << monthName[month - 1] << " " << setw(2) << day << " " << year;
	cout << " " << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second <<
		endl;
}
void Date::showDate3()
{
	string monthName[] = { "January", "February", "March",
	"April", "May", "June", "July",
	"August", "September", "October",
	"November", "December" };
	cout << setw(2) << day << " " << monthName[month - 1] << " " << year;
	cout << " " << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second <<
		endl;
}
bool Date::IncorrectDate()
{
	if (month < 1 || month > 12 || day < 1 || day > 31)
	{
		cout << "\nIncorrect date\n\a";
		return true;

	}
	bool rez = false;
	switch (month)
	{
	case 4: case 6: case 9: case 11: if (day == 31) rez = true; break;
	case 2:
		if (day > 29)
			rez = true;
		else
			rez = (day == 29) && (year % 4 || (year % 100 == 0 && year % 400)); break;
	}
	if (rez == true)
	{
		cout << "\nIncorrect date\n\a";
	}
	return rez;
}
void Date::EnterDate(int y, int m, int d) {
	setYear(y);
	setMonth(m);
	setDay(d);
	while (IncorrectDate()) {
		cout << "\nPlease enter correct date:";
		cout << "\n Year: ";
		year = readNumber(" ");
		cout << "\n Month: ";
		month = readNumber(" ");
		cout << "\n Day: ";
		day = readNumber(" ");
	}
}
void Date::EnterTime(int h, int m, int s) {
	setHour(h);
	setMin(m);
	setSec(s);

	cout << endl;
}