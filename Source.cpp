#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Header.h"
using namespace std;
int main()
{
	setlocale(0, "");
	Fraction t(5, 6);
	Fraction d(5, 6);
	
	if (d > t)
	{
		cout << "да" << endl;
	}
	else
	{
		cout << "нет" << endl;
	}
	

}


