#include "Header.h"

int Composter::count_of_composters = 0;
const char* file_with_composters = "composters.txt";
const char* file_with_tickets = "tickets.txt";

struct NUMBERS
{
	char nmbr[BUFSIZ];
	struct NUMBERS* next;
} *NUMBERShead, * Nptr1, * Nptr2, * NUMBERStail;

struct COMPOSTERS
{
	Composter cmpstr;
	struct COMPOSTERS* next;
} *COMPOSTERShead, * Cptr1, * Cptr2, * COMPOSTERStail;

struct TICKETS
{
	Tickets tckt;
	struct TICKETS* next = NULL;
} *TICKETShead, * Tptr1, * Tptr2, * TICKETStail;

void Composter::SetNumber(const char* nmbr)
{
	strcpy(number, nmbr);
	cout << endl << "запускається SetNumber()";
}

void Composter::SetEncryption(const char* encrptn)
{
	strcpy(encryption, encrptn);
	cout << endl << "запускається SetEncryption()";
}

void Composter::SetNumber_of_bus()
{
	const int count_of_digits = 3;
	char digit[2], nmbr[11];
	do
	{
		strcpy(nmbr, "A");
		for (int i = 0; i < count_of_digits; i++)
		{
			itoa(rand() % 10, digit, 10);
			strcat(nmbr, digit);
		}
	} while (IsSameNumber(nmbr));
	strcpy(number_of_bus, nmbr);

	AddNumberToNUMBERS(nmbr);
	cout << endl << "запускається SetNumber_of_bus()";
}

void Composter::SetNumber_of_journey()
{
	const int count_of_digits = 2;
	char digit[2], nmbr[11];
	do
	{
		strcpy(nmbr, "KL ");
		for (int i = 0; i < count_of_digits; i++)
		{
			itoa(rand() % 10, digit, 10);
			strcat(nmbr, digit);
		}
	} while (IsSameNumber(nmbr));
	strcpy(number_of_journey, nmbr);
	AddNumberToNUMBERS(nmbr);
	cout << endl << "запускається SetNumber_of_journey()";
}

void Composter::AddMassive_numbers_of_used_tickets(const char* nt)
{
	strcpy(Cptr1->cmpstr.massive_numbers_of_used_tickets[Cptr1 -> cmpstr.count_of_used_tickets - 1], nt);
}

void Composter::SetCurrentTime(char* buffer)
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char format[BUFSIZ];

	strcpy(format, "%H:%M:%S");
	strftime(buffer, BUFSIZ, format, timeinfo);
	cout << endl << "запускається SetCurrentTime()";
}

void Composter::SetTime_of_commissioning(char* buffer)
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char format[BUFSIZ];
	strcpy(format, "%Y %m %d %H %M %S");
	strftime(buffer, BUFSIZ, format, timeinfo);
	cout << endl << "запускається Time_of_commissioning()";
}

int Composter::GetCount_of_composters()
{
	return count_of_composters;
}

char* Composter::GetNumber()
{
	return number;
	cout << endl << "запускається GetNumber()";
}

char* Composter::GetEncryption()
{
	return encryption;
	cout << endl << "запускається GetEncryption()";
}

char* Composter::GetCount_working_hours(char* ptr_toc)

{
	int toc[6];
	char str_toc[BUFSIZ];
	strcpy(str_toc, ptr_toc);
	for (int i = 0; i < 6; i++)
	{
		toc[i] = atoi(str_toc);
		if (i < 5)
		{
			strcpy(str_toc, strchr(str_toc, ' '));
			strcpy(str_toc, strchr(str_toc, str_toc[1]));
		}
	}
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	int ct[6];
	char str_ct[BUFSIZ];
	char format[BUFSIZ];
	strcpy(format, "%Y %m %d %H %M %S");
	strftime(str_ct, BUFSIZ, format, timeinfo);

	for (int i = 0; i < 6; i++)
	{
		ct[i] = atoi(str_ct);
		if (i < 5)
		{
			strcpy(str_ct, strchr(str_ct, ' '));
			strcpy(str_ct, strchr(str_ct, str_ct[1]));
		}
	}

	int temp_number[6];
	char str_temp_number[BUFSIZ];
	
	for (int i = 0; i < 6; i++)
	{

		temp_number[i] = ct[i] - toc[i];
	}

	strcpy(count_working_hours, "");
	if (temp_number[1] < 0) { temp_number[0]--; temp_number[1] += 12; }
	
	itoa(temp_number[0], str_temp_number, 10);
	strcat(count_working_hours, str_temp_number);
	strcat(count_working_hours, " рiк ");
	
	if (temp_number[2] < 0) { temp_number[1]--; temp_number[2] += 31; }
	
	itoa(temp_number[1], str_temp_number, 10);
	strcat(count_working_hours, str_temp_number);
	strcat(count_working_hours, " мiсяць ");
	
	if (temp_number[3] < 0) { temp_number[2]--; temp_number[3] += 24; }
	
	itoa(temp_number[2], str_temp_number, 10);
	strcat(count_working_hours, str_temp_number);
	strcat(count_working_hours, " день ");
	
	if (temp_number[4] < 0) { temp_number[3]--; temp_number[4] += 60; }
	
	itoa(temp_number[3], str_temp_number, 10);
	strcat(count_working_hours, str_temp_number);
	strcat(count_working_hours, " година ");
	
	if (temp_number[5] < 0) { temp_number[4]--; temp_number[5] += 60; }
	
	itoa(temp_number[4], str_temp_number, 10);
	strcat(count_working_hours, str_temp_number);
	strcat(count_working_hours, " хвилина ");
	itoa(temp_number[5], str_temp_number, 10);
	strcat(count_working_hours, str_temp_number);
	strcat(count_working_hours, " секунда ");
	
	return count_working_hours;
	cout << endl << "запускається GetCount_working_hours()";
}

void Composter::CreateUniqueNumber()
{
	const int count_of_digits = 4;

	char digit[2], nmbr[11];
	do
	{
		strcpy(nmbr, "UA");
		
		for (int i = 0; i < count_of_digits; i++)
		{
			itoa(rand() % 10, digit, 10);
			strcat(nmbr, digit);
		}
	} while (IsSameNumber(nmbr));
	
	SetNumber(nmbr);
	AddNumberToNUMBERS(nmbr);
}

int Composter::ChoiceTicket()
{
	char nmbr[BUFSIZ];
	Tptr1 = TICKETShead;
	cout << "введiть номер потрiбного квитка: ";
	cin.getline(nmbr, BUFSIZ);
	
	while (Tptr1 != NULL && strcmp(Tptr1->tckt.number_of_ticket, nmbr))
	{
		Tptr1 = Tptr1->next;
	}
	
	if (Tptr1 == NULL || Tptr1 == NULL && TICKETShead != NULL)
	{
		cout << endl << "квитка не iснує!" << endl;
		return false;
	}
	
	return true;
}

int Composter::ChoiceComposter()

{
	char nmbr[BUFSIZ];
	Cptr1 = COMPOSTERShead;
	cout << "введiть номер потрiбного квитка: ";
	cin.getline(nmbr, BUFSIZ);
	
	while (Cptr1 != NULL && strcmp(Cptr1->cmpstr.GetNumber(), nmbr))
	{
		Cptr1 = Cptr1->next;
	}
	
	if (Cptr1 == NULL || Cptr1 == NULL && COMPOSTERShead != NULL)
	{
		cout << endl << "компостера не iснує!" << endl;

	}
	
	return true;
}

void Composter::Checkeing()
{
	if (Tptr1)
	{
		if (!strcmp(Tptr1->tckt.encryption_of_ticket, ""))
		{
			Control(true);
		}
		else
		{
			cout << endl << "квиток уже використовується" << endl;
		}
	}
}

void Composter::Control()
{
	cout << endl << "час введення в експлуатацiю: " << time_of_commissioning << endl;
}

void Composter::Control(bool something)
{
	strcpy(Tptr1->tckt.encryption_of_ticket, Cptr1->cmpstr.encryption);
	SetCurrentTime(Cptr1->cmpstr.time_last_checking);
	Cptr1->cmpstr.count_of_used_tickets += 1;
	AddMassive_numbers_of_used_tickets(Tptr1->tckt.number_of_ticket);
}

void Composter::InputData()
{
	cout << endl;
	cout << "------------------Компостер-------------------" << endl;
	cout << "введiть шифрування : "; cin.getline(encryption, BUFSIZ - 1);
	cout << "введiть номер автобуса : "; cin.getline(number_of_bus, BUFSIZ - 1);
	cout << "введiть номер поїздки : "; cin.getline(number_of_journey, BUFSIZ - 1);
	cout << "---------------------Кiнець----------------------" << endl;
}

void Composter::AddComposterToCOMPOSTERS()
{
	bool exist;
	(COMPOSTERShead) ? (exist = true) : (exist = false);
	Cptr2 = new COMPOSTERS{ true };
	
	if (!exist)
	{
		COMPOSTERShead = Cptr2;
		Cptr1 = Cptr2;
		COMPOSTERStail = Cptr2;
		Cptr2->cmpstr = *this;

		cout << endl << "параметри об'єкта " << number << " скопійовано до нового об’єкта в COMPOSTERS" << endl;
			exist = true;
	}
	else
	{
		Cptr2->cmpstr = *this;
		COMPOSTERStail->next = Cptr2;
		COMPOSTERStail = Cptr2;
		cout << endl << "параметри об'єкта " << number << " скопійовано до нового об’єкта в COMPOSTERS" << endl;
	}
	Cptr2 = NULL;
	COMPOSTERStail->next = NULL;
}

int Composter::InputDataToFile()
{
	ofstream fout(file_with_composters, ios::app | ios::binary);
	
	if (!fout)
	{
		cout << "Файл " << file_with_composters << " не знайдено!" << endl;
		return false;
	}
	
	fout.write((char*)&*this, sizeof(Composter));
	fout.close();

	return true;
}

int Composter::ReInputDataToFile()
{
	ofstream fout(file_with_composters, ios::out | ios::binary);
	
	if (!fout)
	{

		cout << "Файл " << file_with_composters << " не знайдено!" << endl;
		return false;
	}
	
	Cptr1 = COMPOSTERShead;
	
	while (Cptr1)
	{
		fout.write((char*)&Cptr1->cmpstr, sizeof(Composter));
		Cptr1 = Cptr1->next;
	}
	
	fout.close();
	return true;
}

void Composter::OutputData()
{
	SetCurrentTime(current_time);
	GetCount_working_hours(time_of_commissioning);
	cout << endl;
	cout << "------------------Компостер-------------------" << endl;
	cout << "номер: " << number << endl;
	cout << "шифрування: " << encryption << endl;
	cout << "номер автобуса: " << number_of_bus << endl;
	cout << "кiлькiсть проїзду: " << number_of_journey << endl;
	cout << "кiлькiсть використаних квиткiв: " << count_of_used_tickets << endl;
	cout << "величезна кiлькiсть використаних квиткiв: " << endl;
	
	for (int i = 0; i < count_of_used_tickets; i++)
	{
		cout << i + 1 << ". " << massive_numbers_of_used_tickets[i] << endl;
	}

	cout << "поточний час: " << current_time << endl;
	cout << "час останньої перевiрки: " << time_last_checking << endl;
	cout << "рахувати робочi години: " << count_working_hours << endl;
	cout << "---------------------Кiнець----------------------" << endl;

}

void Composter::OutputAllCOMPOSTERS()
{
	if (COMPOSTERShead)
	{
		COMPOSTERShead->cmpstr.OutputData();
		Cptr1 = COMPOSTERShead;
		
		while (Cptr1->next)
		{
			Cptr1 = Cptr1->next;
			Cptr1->cmpstr.OutputData();
		}
	}
	else
	{
		cout << endl << "На даний момент компостерiв немає" << endl;
	}
}

int Composter::OutputDataFromFile()
{
	ifstream fin(file_with_composters, ios::in | ios::binary);
	
	if (!fin)
	{
		cout << endl << "Файл " << file_with_composters << " не знайдено!" << endl;
		return 0;
	}

	cout << endl << "тимчасовий файл:";
	Composter temporary_composter;
	
	while (fin.read((char*)&temporary_composter, sizeof(Composter)))
	{
		temporary_composter.AddComposterToCOMPOSTERS();

	}

	fin.close();
	cout << endl << "тимчасовий об'єкт з файлу:";
	
	return 1;
}

void Composter::DeleteCOMPOSTERS()
{
	Cptr2 = COMPOSTERShead->next;
	delete COMPOSTERShead;
	
	while (Cptr2)
	{
		Cptr1 = Cptr2;
		Cptr2 = Cptr2->next;
		delete Cptr1;
	}
}

Composter::Composter()
{
	CreateUniqueNumber();
	strcpy(encryption, "o o o");
	SetNumber_of_bus();
	SetNumber_of_journey();
	count_of_used_tickets = 0;
	SetCurrentTime(current_time);
	strcpy(count_working_hours, "");
	SetTime_of_commissioning(time_of_commissioning);
	strcpy(time_last_checking, "");
	count_of_composters++;
	cout << endl << "запуск конструктора" << endl;
	cout << "Створений об’єкт: " << number << endl;
	cout << "кiлькiсть компостерiв = " << GetCount_of_composters() << endl;

}

Composter::Composter(bool empty)
{
	strcpy(number, "");
	strcpy(encryption, "");
	SetNumber_of_bus();
	SetNumber_of_journey();
	count_of_used_tickets = 0;
	SetCurrentTime(current_time);
	strcpy(count_working_hours, "");
	SetTime_of_commissioning(time_of_commissioning);
	strcpy(time_last_checking, "");
	count_of_composters++;
	cout << endl << "запуск порожнього конструктора" << endl;
	cout << "Створений об’єкт: " << number << endl;
	cout << "кiлькiсть компостерiв = " << GetCount_of_composters() << endl;
}

Composter::Composter(const char* encrptn)
{
	CreateUniqueNumber();
	strcpy(encryption, encrptn);
	SetNumber_of_bus();
	SetNumber_of_journey();
	count_of_used_tickets = 0;
	SetCurrentTime(current_time);
	strcpy(count_working_hours, "");
	SetTime_of_commissioning(time_of_commissioning);
	strcpy(time_last_checking, "");
	count_of_composters++;
	cout << endl << "запуск конструктора з параметрами (" << encryption << ")" << endl;
	cout << "Створений об’єкт: " << number << endl;
	cout << "кiлькiсть компостерiв = " << GetCount_of_composters() << endl;
}

Composter::Composter(const Composter& objct)
{
	strcpy(number, objct.number);
	strcpy(encryption, objct.encryption);
	strcpy(number_of_bus, objct.number_of_bus);
	strcpy(number_of_journey, objct.number_of_journey);
	count_of_used_tickets = objct.count_of_used_tickets;
	strcpy(current_time, objct.current_time);
	strcpy(time_last_checking, objct.time_last_checking);
	strcpy(count_working_hours, objct.count_working_hours);
	strcpy(time_of_commissioning, objct.time_of_commissioning);
	count_of_composters++;
	cout << endl << "запуск конструктора копiювання" << endl;
	cout << "скопiйований об'єкт: " << number << endl;
	cout << "кiлькiсть компостерiв = " << GetCount_of_composters() << endl;
}

Composter::~Composter()
{
	count_of_composters--;
	cout << endl << "Об'єкт: " << number << endl;
	cout << "запуск деструктора" << endl;
	cout << "кiлькiсть компостерiв = " << GetCount_of_composters() << endl;
}

void Tickets::SetNumber_of_ticket(const char* nmbr)
{
	strcpy(number_of_ticket, nmbr);
}

void Tickets::CreateUniqueNumber_of_ticket()
{
	const int count_of_digits = 6;
	char digit[2], nmbr[7];
	
	do
	{
		strcpy(nmbr, "");
		
		for (int i = 0; i < count_of_digits; i++)
		{
			itoa(rand() % 10, digit, 10);
			strcat(nmbr, digit);
		}
	} while (IsSameNumber(nmbr));
	
	SetNumber_of_ticket(nmbr);
	AddNumberToNUMBERS(nmbr);
}

void Tickets::AddTicketToTICKETS()
{
	bool exist;
	(TICKETShead) ? (exist = true) : (exist = false);
	Tptr2 = new TICKETS;
	
	if (!exist)
	{
		TICKETShead = Tptr2;
		Tptr1 = Tptr2;
		TICKETStail = Tptr2;
		Tptr2->tckt = *this;
		exist = true;
	}
	else

	{
		Tptr2->tckt = *this;
		TICKETStail->next = Tptr2;
		TICKETStail = Tptr2;
	}

	Tptr2 = NULL;
	TICKETStail->next = NULL;
}

int Tickets::InputDataToFile()
{
	ofstream fout(file_with_tickets, ios::app | ios::binary);
	
	if (!fout)
	{
		cout << "Файл" << file_with_tickets << " не знайдено!" << endl;
		return false;
	}
	
	fout.write((char*)&*this, sizeof(Tickets));
	fout.close();
	
	return true;
}

int Tickets::ReInputDataToFile()
{
	ofstream fout(file_with_tickets, ios::out | ios::binary);
	
	if (!fout)
	{
		cout << "Файл " << file_with_tickets << " не знайдено!" << endl;
		return false;
	}
	
	Tptr1 = TICKETShead;
	
	while (Tptr1)
	{

		fout.write((char*)&Tptr1->tckt, sizeof(Tickets));
		Tptr1 = Tptr1->next;
	}
	
	fout.close();
	return true;
}

void Tickets::OutputData()
{
	cout << endl;
	cout << "-------------------Квиток--------------------" << endl;
	cout << "номер: " << number_of_ticket << endl;
	cout << "шифрування: " << encryption_of_ticket << endl;
	cout << "--------------------Кiнець----------------------" << endl;
}

void Tickets::OutputAllTICKETS()
{
	if (TICKETShead)
	{
		TICKETShead->tckt.OutputData();
		Tptr1 = TICKETShead;
		
		while (Tptr1->next)
		{
			Tptr1 = Tptr1->next;
			Tptr1->tckt.OutputData();
		}
	}
	else
	{
		cout << endl << "На даний момент немає квиткiв" << endl;
	}
}

int Tickets::OutputDataFromFile()
{
	ifstream fin(file_with_tickets, ios::in | ios::binary);
	
	if (!fin)
	{
		cout << "Файл " << file_with_tickets << " не знайдено!" << endl;
		return 0;
	}
	
	Tickets temporary_tickets;
	
	while (fin.read((char*)&temporary_tickets, sizeof(Tickets)))
	{
		temporary_tickets.AddTicketToTICKETS();
	}
	
	fin.close();
	return 1;
}

Tickets::Tickets()
{
	CreateUniqueNumber_of_ticket();
	strcpy(encryption_of_ticket, "");
}

int InputCorrectInteger()
{
	char str[BUFSIZ];
	cin.getline(str, BUFSIZ - 1);
	int integer = atoi(str);
	return integer;
}

bool IsSameNumber(const char* nmbr)

{
	bool same = false;
	Nptr1 = NUMBERShead;
	
	while (Nptr1)
	{
		if (!strcmp(nmbr, Nptr1->nmbr))
		{
			same = true;
			break;
		}
		
		Nptr1 = Nptr1->next;
	}
	
	return same;
}

void AddNumberToNUMBERS(const char* number)
{
	bool exist;
	(NUMBERShead) ? (exist = true) : (exist = false);
	Nptr2 = new NUMBERS;
	
	if (!exist)
	{
		NUMBERShead = Nptr2;
		Nptr1 = Nptr2;
		NUMBERStail = Nptr2;
		strcpy(NUMBERShead->nmbr, number);
		exist = true;
	}
	else
	{
		strcpy(Nptr2->nmbr, number);
		NUMBERStail->next = Nptr2;
		NUMBERStail = Nptr2;

	}

	Nptr2 = NULL;
	NUMBERStail->next = NULL;
}

void Menu()
{
	bool exit = false;
	
	while (!exit)
	{
		cout << endl << "Тимчасовий для меню:";
		Composter temporary_composter;
		Tickets temporary_ticket;
		cout << endl << "введiть 1, щоб створити компостер";
		cout << endl << "введiть 2, щоб створити компостер з унiкальним шифруванням";
		cout << endl << "введiть 3, щоб вивести iснуючi компостери";
		cout << endl << "введiть 4, щоб створити квиток";
		cout << endl << "введiть 5, щоб вивести наявнi квитки";
		cout << endl << "введiть 6, щоб скласти квиток";
		cout << endl << "введiть 7, щоб отримати час введення в експлуатацiю компостера";
		cout << endl << "введiть 0, щоб завершити програму";
		cout << endl << "ваш вибiр: ";
		
		switch (InputCorrectInteger())
		{
		case 1:
			temporary_composter.AddComposterToCOMPOSTERS();
			temporary_composter.InputDataToFile();
			break;
		case 2:
			temporary_composter.InputData();
			temporary_composter.AddComposterToCOMPOSTERS();
			temporary_composter.InputDataToFile();

			break;
		case 3:
			temporary_composter.OutputAllCOMPOSTERS();
			break;
		case 4:
			temporary_ticket.AddTicketToTICKETS();
			temporary_ticket.InputDataToFile();
			break;
		case 5:
			temporary_ticket.OutputAllTICKETS();
			break;
		case 6:
			
			if (temporary_composter.ChoiceTicket())
			{
				if (temporary_composter.ChoiceComposter())
				{
					temporary_composter.Checkeing();
					temporary_composter.ReInputDataToFile();
					temporary_ticket.ReInputDataToFile();
				}
			}
			break;
		case 7:
			
			if (temporary_composter.ChoiceComposter())
			{
				temporary_composter.Control();
			}
			break;
		case 0:
			temporary_composter.DeleteCOMPOSTERS();
			exit = true;
			break;
		default:
			cout << endl << "Будь ласка, введiть номер знизу!" << endl;
		}
		cout << endl << "Тимчасовий об'єкт з меню:";
	}
}