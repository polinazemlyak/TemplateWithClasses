#include "resource.h"
#include "laba1.h"
#include <iostream>
#include <string>
using namespace std;


money::money()

{
	//установить сумму деняк
	sign = "+";
	rub = 1000;
	kop = 0;
}


//реализация конструктора с тремя параметрами
money::money(string s, int r, int k)
{
	sign = s;
	rub = r+k/100;
	kop = k%100;
}

void money::operator=(money& m2)
{
	this->sign = m2.sign;
	this->rub = m2.rub;
	this->kop = m2.kop;
}

money money::operator+(money& m2)
{
	if (this->sign == m2.sign)
	{
		return money(this->sign, this->rub + m2.rub, this->kop + m2.kop);
	}
	else 
	{
		int k = this->kop - m2.kop;
		int r = this->rub - m2.rub;
		if (k == 0 && r == 0)
		{
			return money("+",0,0);
		}
		if (k < 0)
		{
			if (r <= 0)
			{
				return money(m2.sign, -r, -k);

			}
			else
			{
				return money(this->sign, r - 1, k+100);
			}

		}
		else
		{
			if (r < 0)
			{
				return money(m2.sign, -r - 1, -(k-100));

			}
			else
			{
				return money(this->sign, r, k);
			}
		}
	}
}


money money::operator-(money& m2)
{
	string temp = m2.sign;

	if (m2.sign == "+")
	{
		m2.sign = "-";

	}
	else
	{
		m2.sign = "+";
	}
	money result = *this + m2;
	m2.sign = temp;
	return result;
}


money money::operator*(double x)
{
	money result;
	if (x < 0)
	{
		if (this->sign == "+")
		{
			result.sign = "-";

		}
		else
		{
			result.sign = "+";
		}
	}
	result.rub = abs((this->rub * x) + ((this->kop * x) / 100));
	result.kop = abs(int(this->kop * x) % 100);
	return result;
}


money money::operator/(double x)
{
	money result;
	int y;
	y = this->rub * 100 + this->kop;
	if (x < 0)
	{
		if (this->sign == "+")
		{
			result.sign = "-";

		}
		else
		{
			result.sign = "+";
		}
	}

	result.rub = abs(int(y / x) / 100);
	result.kop = abs(int(y / x) % 100);
	return result;
}
bool money::operator==(money& m2)
{
	if (this->sign == m2.sign && this->rub == m2.rub && this->kop == m2.kop)
	{
		return true;
	}

	else
	{
		return false;
	}
}
bool money::operator<=(money& m2)
{
	if (*this == m2 || *this < m2)
	{
		return true;

	}
	else
	{
		return false;

	}
}
bool money::operator>=(money& m2)
{
	if (*this == m2 || *this > m2)
	{
		return true;

	}
	else
	{
		return false;

	}
}
bool money::operator!=(money& m2)
{
	return !(*this == m2);

}
bool money::operator<(money& m2)
{
	if (this->sign == "-" && m2.sign == "+")
	{
		return true;

	}
	else if (this->sign == "-" && m2.sign == "-")
	{
		if (this->rub > m2.rub)
		{
			return true;
		}
		else if (this->rub == m2.rub && this->kop > m2.kop)
		{
			return true;
		}
		else return false;

	}
	else if (this->sign == "+" && m2.sign == "+")
	{
		if (this->rub < m2.rub)
		{
			return true;
		}
		else if (this->rub == m2.rub && this->kop < m2.kop)
		{
			return true;
		}
		else return false;
	}
	else
	{
		return false;
	}
}

bool money::operator>(money& m2)
{
	if (this->sign == "+" && m2.sign == "-")
	{
		return true;

	}
	else if (this->sign == "-" && m2.sign == "-")
	{
		if (this->rub < m2.rub)
		{
			return true;
		}
		else if (this->rub == m2.rub && this->kop < m2.kop)
		{
			return true;
		}
		else return false;

	}
	else if (this->sign == "+" && m2.sign == "+")
	{
		if (this->rub > m2.rub)
		{
			return true;
		}
		else if (this->rub == m2.rub && this->kop > m2.kop)
		{
			return true;
		}
		else return false;
	}
	else
	{
		return false;
	}
}

ostream& operator<< (ostream& out, const money& money)
{
	out << money.sign << " Rubles: " << money.rub << " Kopeiky: " << money.kop;
	return out;

}

istream& operator>> (istream& in, money& money)
{
	in >> money.sign >> money.rub >> money.kop;
	if (money.kop > 100)
	{
		money.rub = money.rub + money.kop / 100;
		money.kop = money.kop % 100;
	}
	return in;
}
