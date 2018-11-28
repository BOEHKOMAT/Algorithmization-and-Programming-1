#include "pch.h"
#include <iostream>
using namespace std;

typedef struct complexI { int Re, Im; };
typedef struct complexF { float Re, Im; };
typedef struct complexD { double Re, Im; };

complexI subC(complexI z1, complexI z2)
{
	complexI sub;
	sub.Re = z1.Re - z2.Re;
	sub.Im = z1.Im - z2.Im;
	return sub;
}
complexF subC(complexF z1, complexF z2)
{
	complexF sub;
	sub.Re = z1.Re - z2.Re;
	sub.Im = z1.Im - z2.Im;
	return sub;
}
complexD subC(complexD z1, complexD z2)
{
	complexD sub;
	sub.Re = z1.Re - z2.Re;
	sub.Im = z1.Im - z2.Im;
	return sub;
}

template<typename R>
R sub(R a, R b)
{
	return a - b;
}

int main(void)
{
	setlocale(LC_ALL, "Ukrainian");

	complexI zi1;
	zi1.Re = 2;
	zi1.Im = 4;
	complexI zi2;
	zi2.Re = 5;
	zi2.Im = -2;
	complexI subI = subC(zi1, zi2);

	complexF zf1;
	zf1.Re = -9.5;
	zf1.Im = 11.6;
	complexF zf2;
	zf2.Re = 3.4;
	zf2.Im = -4.6;
	complexF subF = subC(zf1, zf2);

	complexD zd1;
	zd1.Re = 2.86;
	zd1.Im = -1.82;
	complexD zd2;
	zd2.Re = -4.54;
	zd2.Im = -4.2;
	complexD subD = subC(zd1, zd2);

	cout << "Рiзницi дiйсних чисел" << endl;
	cout << "---------------------------------" << endl;
	cout << "Результат типу int: " << sub(2, 6) << endl;
	cout << "Результат типу float: " << sub(5.2, 0.2) << endl;
	cout << "Результат типу double: " << sub(2.2, 6.1) << endl;
	cout << "=================================" << endl << endl;
	cout << "Рiзницi комплексних чисел" << endl;
	cout << "---------------------------------" << endl;
	cout << "Результат типу int: " << subI.Re << " + " << subI.Im << "i" << endl;
	cout << "Результат типу float: " << subF.Re << " + " << subF.Im << "i" << endl;
	cout << "Результат типу double: " << subD.Re << " + " << subD.Im << "i" << endl;
	cout << "=================================" << endl;
}