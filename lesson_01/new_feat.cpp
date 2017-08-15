int a;
char b;
b = (int)a;

int* a = (char*) b;

static_cast<>

reinterpret_cast<>
const_cast<>

int a = static_cast<int> b;

const char c;
char cc = const_cast<char> c;
c = const_cast<const char> cc;

int* i;
char *ccc = reinterpret_cast<char*> i;

^^^ новые касты

========= ссылки =================

void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = *c;
}

swap(&a, &b);

void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

swap(a, b);

int c;
int& cc = c;

=========== прегрузка функций =================

void swap(int &a, int &b);
void swap(double &a, double &b);
int swap(int &a, int &b);//error

swap(a, b);

void foo(int &x);
void foo(int x);

int i;
foo(4);//ok
foo(i);//не ок

из этого следует, что всегда нужны h файлы, если много файлов в программе.

================ new delete =================

int *a = malloc(...);
free(a);

-----------

int *a = new int;
int *b = new int[10]; //массив из 10 элементов

delete a;
delete[] b; //удалит массив

class vector {...};

vector* a = new vector[100]; // вызывает 100 конструкторов 
delete[] vector; // проходит по всему массиву и вызывает деструкторы

======== библиотеки ===============

#include <iostream>
#include <string.h>// старый стиль, набор функций
#include <cstring> // новый стиль

#include <string> //другой файл, с классом string

======== классы ===================

array.cpp
---------

class array {
private:
	int *data = NULL;// поле класса
	int sz;
public:
	array() {
		int *data = new int[10];
		sz = 10;
	}

	array(int size) {//имя класса - конструктор
		int *data = new int[size];
		sz = size;
	}

	

	~array() {//деструктор
		delete[] data;
		data = NULL;
	}

	//конструктор, деструктор и конструктор копирования - они должны быть все, если есть хоть что-то
	array(const array &A) {
		//пройдёмся по А и прекопируем
	}

	void set(int i, int x);// метод класса
	int get(int i) const { // этот метод не меняент полей класса
		if (int i < 0 || i >= sz)
			return -1;

		return data[i];
	}
};


int joj() {
	return 42;
}

int main() {
	array a;
	a.set(1, 5);
	std::cout << a.get(1);

	const array c(a);// вызовется конструктор копирования
	c.set(1, 5);//ошибка
	c.get(1); //работает

	array *b;
	b->set();
	return 0;
}

чем отличается структура от класса?
ничем. почти
class A {
	int a;//private
public:
	int b;
private:
	int c;
};

struct B {
	int a;//public
public:
	int b;
private:
	int c;
};

struct point {
	int x, y;
}

class queue {
	int* data;

}

=============

A.h
----

class A {
	int foo();
};

A.cpp
-----

#include <A.h>

int A::foo() {

}

int MyVector::get(int i) {

}