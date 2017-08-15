#include <algorithm>

class BigInt {
private:
	int* data = nullptr;
	int size = 0;
	int& a;
public:
	BigInt(int size) : /*поле класса*/size(size/*аргумент из метода*/) {
		data = new int[size];
		std::fill(data, data + size, 0);
	}

	~BigInt() {
		delete[] data;
		data = nullptr;
	}

	explicit BigInt(const &BigInt obj) { //конструктор копирования
		size = obj.size;
		data = new int[size];
		std::copy(data, data + size, obj.data);
	}

	//Приведение типов
	/*
	
	BigInt a(5, 0); // [0][0][0][0][0]
	BigInt b(a); // аналог BigInt b = a; также вызовет оператор копировния

	BigInt c = 5; // сделает [0][0][0][0][0] вместо [0][0][0][0][5];
	//например float c = 5; здесь 5 превращается в 5.0

	приведение типов должно быть явным с explicit:
	BigInt c(5); //работает
	BigInt c = 4; //ошибка из-за explicit
	BigInt c = (BigInt)3; // работает
	*/

	// void operator=(const &BigInt obj) { //тупой оператор равно
	// }
	//Проблемы с такой реализацией:
	/*
	BigInt a, b, c;
	a = a; //это можно вылечить, если написать условие, что *this != obj
	a = b = c;
	*/

	BigInt& operator=(BigInt obj) { //оператор равно черезе copy-swap идиому
		swap(data, obj.data);
		size = obj.size;
		return *this;//здесь вызовется деструктор obj и подчистит память.
	}

	//вызывает конструктор копирование:
	/*
	BigInt a,b;
	a.operator=(b);//эквивалентно тому, что ниже
	a = b; // здесь создаётся копия b в объект obj, т.е. происходит BigInt obj(b); А потом внутри "a" оператор работает с obj
	
	a = b = c;
	a.operator=(b.operator=(c));
	*/

	BigInt& operator+=(const &BigInt obj) {
		if (size != obj.size)
			return;

		for (бла бла)
			прибавление поэлементно
		return *this;
	}

	void operator*=(...);

	void operator<();// &&, ||, >, >= ....

	// BigInt& operator+(const &BigInt right) {
	// 	BigInt left(*this);
	// 	left += right;
	// 	return left;
	// }

	//почему так сложно?
/*	c = a + b;
	здесь c.operator=(a.operator+(b));
	после применения operator+ не должен сломаться "a", и при этом должно быть возвращаемое значение
*/

	//Проблемы?
	/*
	c = a + 3;// c = a + (BigInt)3;
	c = 3 + a;// c = 3 + (int)a;
	*/
	//решение: оператор вне класса
	friend BigInt operator+(const& BigInt left, const& BigInt right);//friend означает, что функция имеет доступ к полям класса.
	//смотреть реализацию за классом

	BigInt& operator++() {//префиксный оператор ++a; <=> a.operator++()
		//действия
		return *this;
	}

	BigInt& operator++(size_t n) {//постфиксный оператор a++; <=> a.operator++(1);
 		tmp(*this);
 		//действия с самим классом
 		return tmp;
	}

};

BigInt operator+(const& BigInt left, const& BigInt right) {
	BigInt tmp(left);
	tmp += right;
	return tmp;
}


class Array {
private:
	int data* = nullptr;
	int size;
public:
	int& operator[](int ind) {
		return data[ind];
	}

	//В чём проблема?
	/*
	const Array a(5);
	foo(a[3]); вызываем неконстантый оператор

	мы хотим с квадратными скобками две вещи:
	a[i] = value;
	var = a[i];
	*/

	const/*понимает, что он справа*/ int& operator[](int ind) const {//оператор для работы с константными объектами 
		return data[ind];
	}
};

В c++ нет оператора [][]. Что с этим делать? Сложно, если объект сложный, нужно делать proxy класс внутри своего класса и пере

Proxy BaseClass::operator[](int ind) {
	Proxy a;
	return a;
}

int Proxy::operator[](int ind) {
	return _data[ind];
}


BaseClass d;
d[][] - здесь будет (d[]/*здесь создался прокси объект*/).operator[];

======================================================================

операторы приведения типов. 

BigInt a = 3; тип приводился через конструктор.
int b = a; нужен оператор приведения.

class A {
	operator int() {//оператор приведения класса A в int
		return 42;
	}
}

теперь можем писать так:
A obj;
int i = obj;
i == 42 //true

т.е. у нас работает запись (int)obj;

по аналогии:

operator bool() {
	...
}

например определили оператор бул, но не определили оператор <
A a,b;
if (a < b) {...}

здесь будет твориться адская вещь: 
неявное привидение к булу

if ((bool)a < (bool)b) {...}

чтобы этого избежать - нужно написать explicit;
explicit избавляет не от всех неявных преобразований, например
1. if (a)
2. a && b

Через оператор < можно выразить всё.

1. a > b : b < a
2. a >= b : !(a < b)
3. a <= b :	
4. a != b : a < b || b < a
5. a == b : 