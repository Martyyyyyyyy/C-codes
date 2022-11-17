#include "header.h"

int ReadingFile() { // функція для простого зчитування тексту з файлу
	char str[Len];
	FILE* file;
	file = fopen("read.txt", "r");
	if (file != NULL)
	{
		printf("Файл read.txt успiшно створенно!\n");
		fgets(str, Len, file);
		fprintf(stdout, "%s", str);
		fgets(str, Len, file);
		fprintf(stdout, "%s", str);
		fgets(str, Len, file);
		fprintf(stdout, "%s", str);
		fgets(str, Len, file);
		fprintf(stdout, "%s", str);
	}
	else
	{
		fprintf(stderr, "Не вдалося створити або вiдкрити файл read.txt\n");
		return 1;
	}
}

stack* LoadFileToStack() { // функція для зчитування тексту з файлу та створення стеку з рядків
		FILE* file;
	char size[Len];
	stack* head = new stack;
	stack* next = head;
	if (!(file = fopen("read.txt", "r")))
	{
		cout << "\aПомилка! Файл не вiдкрито\n";
		return 0;
	}
	fgets(size, Len, file);
	head->push(size);
	head->next = 0;
	while (fgets(size, Len, file))
	{
		next = new stack;
		next->push(size);
		next->next = head;
		head = next;
	}
	cout << "\n\n";
	fclose(file);
	return head;
}

void stack::push(char* t) { // фукція поміщення нового рядка у стек
	int n = strlen(t);
	for (size_t i = 0; i <= n; i++)
	{
		text[i] = t[i];
	}
}

void stack::pop() { // функція зчитування рядка зі стеку
	cout << text;
	if (text[strlen(text) - 1] != '\n') cout << endl;
}

void renumber(stack* head) { // ф-я перенумерації рядків
	stack* next = head;
	for (size_t i = 1; next; i++)
	{
		int n = strlen(next->text);
		for (int j = n; j >= 0; j--)
		{
			next->text[j + 3] = next->text[j];
		}
		next->text[0] = char(48 + i);
		next->text[1] = ':';
		next->text[2] = ' ';
		next = next->next;
	}
}

void purge(stack* head) { // вивід всіх рядків зі стеку і очищення пам'яті
	cout << "Модифiкованi рядки:\n\n";
	stack* next = head;
	while (head)

	{
		next = next->next;
		head->pop();
		delete head;
		head = next;
	}
}