#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <fstream>

#define Len 100
#pragma warning(disable : 4996);

// директива для ігнорування помилки 4996, що пов'язана з застарілістю функції 'fopen'
using namespace std;

struct stack // структура стек
{
	char text[Len]; // масив символів для рядка
	stack* next;
	void pop(); // функція зчитування рядка зі стеку
	void push(char*); // фукція поміщення нового рядка у стек
};

int ReadingFile(); // функція для простого зчитування тексту з файлу
stack* LoadFileToStack(); // функція для зчитування тексту з файлу та створення стеку з рядків
void renumber(stack*); // ф-я перенумерації рядків
void purge(stack*); // вивід всіх рядків зі стеку і очищення пам'яті