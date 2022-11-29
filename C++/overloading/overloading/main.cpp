#include "Header.h"


int main() {
	srand(unsigned(time(0)));
	
	string f_name = "f.txt";
	string f1_name = "f1.txt";
	string f_bin_name = "binarfile.txt";
	
	cout << "\nNumber of objects: " << Composter::getCount() << endl;
	
	Composter bus, bus_("#tr00", "head", 6, 6, 6, 25);
	cout << bus_; cout << bus;
	
	bus_.fileBinSaveData(f_bin_name);
	{ cout << "Number of objects: " << Composter::getCount() << endl;
	Composter bus, bus_;
	bus_.fileBinSaveData(f_bin_name);
	cout << "Number of objects: " << Composter::getCount() << endl; }
	bus.fileBinSaveData(f_bin_name);
	cout << "Number of objects: " << Composter::getCount() << endl;
	bus.curTime.EnterDate(2004, 6, 22);
	bus.curTime.EnterTime(15, 25, 55);
	bus.timeExpluat.EnterDate(2021, 1, 3);
	bus.timeExpluat.EnterTime(4, 55, 1);
	bus.lastAudit.EnterDate(2021, 2, 2);
	bus.lastAudit.EnterTime(2, 6, 5);
	cout << "Number of objects: " << Composter::getCount() << endl;
	cout << "\nNumber: " << bus.getNumber() << endl;
	cout << "Shyfr: " << bus.getShyfr() << endl;
	cout << "Ticket: " << bus.ticket << endl;
	cout << "Bus number: " << bus.getNumberBus() << endl;
	cout << "Race number: " << bus.getNumberRace() << endl;
	cout << bus;
	bus.curTime.showDate1();
	bus.timeExpluat.showDate2();
	bus.lastAudit.showDate3();
	bus.Control(manyTime);
	bus.consoleInit();
	cout << "\nNumber: " << bus.getNumber() << endl;
	cout << "Shyfr: " << bus.getShyfr() << endl;
	cout << "Ticket: " << bus.ticket << endl;
	bus.fileBinSaveData(f_bin_name);
	bus.printObject();
	bus.fileSaveData(f1_name);
	Composter bus1{ "#tr05","cls",8, 5, 9, 25 };
	cout << "Number of objects: " << Composter::getCount() << endl;
	cout << "\nNumber: " << bus1.getNumber() << endl;
	cout << "Shyfr: " << bus1.getShyfr() << endl;
	cout << "Ticket: " << bus1.ticket << endl;
	bus1.printObject();

	bus1.fileBinSaveData(f_bin_name);
	cout << bus1;
	bus1.fileSaveData(f1_name);
	{Composter bus1{ "#prt6","tck",12, 15, 10, 30 };
	cout << "Number of objects: " << Composter::getCount() << endl;
	cout << "\nNumber: " << bus1.getNumber() << endl;
	cout << "Shyfr: " << bus1.getShyfr() << endl;
	cout << "Ticket: " << bus1.ticket << endl;
	bus1.ticket = "tck2";
	bus1.setNumber(readNumber("Number"));
	bus1.setShyfr("#ookg");
	bus1.printObject();
	bus1.fileBinSaveData(f_bin_name);
	bus1.fileSaveData(f1_name);
	bus1.Control();
	}
	cout << "\nNumber: " << bus1.getNumber() << endl;
	cout << "Shyfr: " << bus1.getShyfr() << endl;
	cout << "Ticket: " << bus1.ticket << endl;
	bus1.setNumberBus(50);
	bus1.setNumberRace(4);
	bus1.printObject();
	Composter::printArrOfNumWor();
	Composter bus2 = bus1;
	cout << "Number of objects: " << Composter::getCount() << endl;
	cout << "\nNumber: " << bus2.getNumber() << endl;
	cout << "Shyfr: " << bus2.getShyfr() << endl;
	cout << "Ticket: " << bus2.ticket << endl;
	cout << bus2;
	bus2.printObject();
	bus2.Control(oneTime);
	Composter::printArrOfNumWor();
	bus2.fileSaveData(f1_name);
	Composter* bus3 = new Composter("#gho3", "tck1", 1, 2, 5, 5);
	cout << "Number of objects: " << Composter::getCount() << endl;
	cout << "\nNumber: " << bus3->getNumber() << endl;
	cout << "Shyfr: " << bus3->getShyfr() << endl;
	cout << "Ticket: " << bus3->ticket << endl;
	cout << "Bus number: " << bus3->getNumberBus() << endl;
	cout << "Race number: " << bus3->getNumberRace() << endl;
	bus3->fileSaveData(f1_name);
	delete bus3;
	Composter* bus4 = &bus;
	cout << "Number of objects: " << Composter::getCount() << endl;
	cout << "\nNumber: " << bus4->getNumber() << endl;
	cout << "Shyfr: " << bus4->getShyfr() << endl;
	cout << "Ticket: " << bus4->ticket << endl;
	bus4->printObject();
	bus4->fileSaveData(f1_name);
	Composter bus5(bus2);
	cout << "Number of objects: " << Composter::getCount() << endl;
	cout << "\nNumber: " << bus5.getNumber() << endl;
	cout << "Shyfr: " << bus5.getShyfr() << endl;
	cout << "Ticket: " << bus5.ticket << endl;
	bus5.printObject();

	bus5.fileBinSaveData(f_bin_name);
	bus5.fileSaveData(f1_name);
	Composter bus6;
	cout << "Number of objects: " << Composter::getCount() << endl;
	if (bus6.fileInit(f_name)) {
		cout << "\nNumber: " << bus6.getNumber() << endl;
		cout << "Shyfr: " << bus6.getShyfr() << endl;
		cout << "Ticket: " << bus6.ticket << endl;
		bus6.printObject();
		bus6.fileSaveData(f1_name);
	}
	Composter::printArrOfNumWor();
	Composter bus7;
	cout << "Number of objects: " << Composter::getCount() << endl;
	cin >> bus7;
	cout << bus7;
	bus7.fileSaveData(f1_name);
	int n = 0;
	Composter* Com_arr;
	fileBinInit(f_bin_name, Com_arr, n);
	printArrBus(Com_arr, n);
	QuickSortArray(Com_arr, 0, n - 1);
	printArrBus(Com_arr, n);
	cout << "\n---------\n";
	if (bus6 < bus7) cout << bus7;
	else cout << bus6;
	if (bus6 == bus7) cout << "\nEqual\n";
	else cout << "\nNot equal\n";
	if (bus6 > bus7) cout << bus6;
	else cout << bus7;
	delete[] Com_arr;
	cout << "\nEnd of programme\a";
	return 0;
}