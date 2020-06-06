
#pragma once
#include <iostream>
#include<cassert>

using namespace std;

class Fraction
{
	int c;
	int ch;
	int zn;
	void FSD();
	int NOD(int a, int b);
	void convert();
public:
	Fraction() :Fraction(0, 1) {}
	Fraction(int ch, int zn) :Fraction(0, ch, zn) {}
	Fraction(int c, int ch, int zn)
	{
		this->c = c;
		this->ch = ch;
		assert(zn != 0);
		this->zn = zn;
	}

	inline int getCh();
	inline int getZn();
	void print()const;


	Fraction operator+(Fraction b);
	Fraction operator+=(Fraction b);
	Fraction operator-(Fraction b);
	Fraction operator-=(Fraction b);
	Fraction operator*(Fraction b);
	Fraction operator*=(Fraction b);
	Fraction operator/(Fraction b);
	Fraction operator/=(Fraction b);
	bool operator>(Fraction b);
	bool operator>=(Fraction b);
	bool operator<(Fraction b);
	bool operator<=(Fraction b);
	bool operator!=(Fraction b);
	bool operator==(Fraction b);

};

inline int Fraction::getCh() {
	return ch;
}

inline int Fraction::getZn()
{
	return zn;
}

inline void Fraction::print() const
{
	if (c)
		cout << c << ".";
	if (ch != 0)
		cout << ch << "/" << zn << endl;
}

inline Fraction Fraction::operator+=(Fraction b)
{
	*this = *this + b;
	return *this;
}
inline Fraction Fraction::operator-=(Fraction b)
{
	*this = *this - b;
	return *this;
}
inline Fraction Fraction::operator*=(Fraction b)
{
	*this = *this * b;
	return *this;
}
inline Fraction Fraction::operator/=(Fraction b)
{
	*this = *this / b;
	return *this;
}
inline Fraction Fraction::operator+(Fraction b)
{
	Fraction c;
	c.c = this->c + b.c;
	c.ch = this->ch * b.zn + this->zn * b.ch;
	c.zn = this->zn * b.zn;
	c.FSD();
	return c;
}

inline Fraction Fraction::operator-(Fraction b)
{
	Fraction c;
	c.c = this->c + b.c;
	c.ch = this->ch * b.zn - this->zn * b.ch;
	c.zn = this->zn * b.zn;
	c.FSD();
	return c;
}

inline Fraction Fraction::operator*(Fraction b)
{
	Fraction c;
	this->convert();
	b.convert();
	c.ch = this->ch * b.ch;
	c.zn = this->zn * b.zn;
	c.FSD();
	this->FSD();
	return c;
}

inline Fraction Fraction::operator/(Fraction b)
{
	Fraction c;
	this->convert();
	b.convert();
	c.ch = this->ch * b.zn;
	c.zn = this->zn * b.ch;
	c.FSD();
	this->FSD();
	return c;
}

inline bool Fraction::operator>(Fraction b)
{
	this->convert();
	b.convert();
	bool res = (double)ch / zn > (double)b.ch / b.zn;
	this->FSD();
	return res;
}
inline bool Fraction::operator>=(Fraction b)
{
	this->convert();
	b.convert();
	bool res = (double)ch / zn >= (double)b.ch / b.zn;
	this->FSD();
	return res;
}

inline bool Fraction::operator<(Fraction b)
{
	this->convert();
	b.convert();
	bool res = (double)ch / zn < (double)b.ch / b.zn;
	this->FSD();
	return res;
}
inline bool Fraction::operator<=(Fraction b)
{
	this->convert();
	b.convert();
	bool res = (double)ch / zn <= (double)b.ch / b.zn;
	this->FSD();
	return res;
}
inline bool Fraction::operator!=(Fraction b)
{
	this->convert();
	b.convert();
	bool res = (double)ch / zn != (double)b.ch / b.zn;
	this->FSD();
	return res;
}
inline bool Fraction::operator==(Fraction b)
{
	this->convert();
	b.convert();
	bool res = (double)ch / zn == (double)b.ch / b.zn;
	this->FSD();
	return res;
}


inline void Fraction::FSD()
{
	if (ch)
	{
		this->c += this->ch / this->zn;
		this->ch %= this->zn;
		int nod = NOD(this->ch, this->zn);
		if (nod != 1)
		{
			this->ch /= nod;
			this->zn /= nod;
		}
	}
}

inline int Fraction::NOD(int a, int b)
{
	for (size_t i = abs(a); i >= 2; i--)
	{
		if (a % i == 0 && b % i == 0)
			return i;
	}
	return 1;
}

inline void Fraction::convert()
{
	this->ch += this->c * this->zn;
	this->c = 0;
}