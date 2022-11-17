#include "header.h"


int main() {
	setlocale(LC_ALL, "ukr");
	if (!ReadingFile()) return 0; // виконуємо 1 частину лабораторної
	stack* head;
	if (!(head = LoadFileToStack())) return 0;// виконуємо 2 частину лабораторної
	renumber(head);
	purge(head);
	return 1;
}