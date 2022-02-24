#pragma once
#include "resource.h"
#include <iostream>
#include <string>
using namespace std;

class money
{

public:

	string sign;
	int rub;
	int kop;

	//конструкторы

	money(void); //конструктор по умолчанию
	money(string s, int r, int k); //конструктор с 3 параметрами


	//методы

	void operator=(money&);
	money operator+(money&);
	money operator-(money&);
	money operator*(double);
	money operator/(double);
	bool operator==(money&);
	bool operator<=(money&);
	bool operator>=(money&);
	bool operator!=(money&);
	bool operator<(money&);
	bool operator>(money&);

	friend ostream& operator<< (ostream& out, const money& money);
	friend istream& operator>> (istream& in,  money& money);

};

