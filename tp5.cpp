#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;


class Rationnel
{
private :
	long num;	//numerateur
	long den;	//denominateur
	static long PGCD(long x, long y);
public :
	Rationnel() { num = 0; den = 1; }
	Rationnel(long n, long d = 1):num(n), den(d){ if(d == 0) { n = 0;} }
	Rationnel operator*(const Rationnel& R2) const;
	Rationnel operator+(const Rationnel& R2) const;
	Rationnel operator-(const Rationnel& R2) const;
	Rationnel operator/(const Rationnel& R2) const;
	Rationnel operator+=(const Rationnel& R2);
	Rationnel operator-=(const Rationnel& R2);
	Rationnel operator*=(const Rationnel& R2);
	Rationnel operator/=(const Rationnel& R2);
	bool operator<(Rationnel& R2);
	bool operator>(Rationnel& R2);
	bool operator==(Rationnel& R2);
	bool operator!=(Rationnel& R2);
	bool operator<=(Rationnel& R2);
	bool operator>=(Rationnel& R2);
	friend ostream& operator<<(ostream& os, Rationnel& R)
	{
		os << "Fraction : " << R.num << "/" << R.den << "\n";
		os << "Reel : " << R.ConversionR() << "\n";
		return os;
	}
	float ConversionR();
};


void suiteGeometrique(int q, int N);


int main()
{
	Rationnel R1(7, 5), R2(3,4);
	cout << "R1 : " << R1;
	Rationnel R3;
	R3 = R1*R2;
	cout << "R3 : " << R3;
	R3 += R1;
	cout << "R3 : " << R3;
	suiteGeometrique(5, 5000);
	
	return 0;
}



Rationnel Rationnel::operator*(const Rationnel& R2) const
{
	long num_multiplication = num*R2.num;
	long den_multiplication = den*R2.den;
	Rationnel multiplication(num_multiplication, den_multiplication);
	return multiplication;
}



Rationnel Rationnel::operator+(const Rationnel& R2) const
{
	Rationnel somme(num*R2.den + den*R2.num, den*R2.den);
	return somme;
}



Rationnel Rationnel::operator-(const Rationnel& R2) const
{
	Rationnel diff(num*R2.den - den*R2.num, den*R2.den);
	return diff;
}



Rationnel Rationnel::operator/(const Rationnel& R2) const
{
	Rationnel R3(R2.den, R2.num);
	return *this*R3;
}



Rationnel Rationnel::operator+=(const Rationnel& R2)
{
	*this = *this + R2;
	return *this;
}
Rationnel Rationnel::operator-=(const Rationnel& R2)
{
	*this = *this - R2;
	return *this;
}
Rationnel Rationnel::operator*=(const Rationnel& R2)
{
	*this = *this*R2;
	return *this;
}
Rationnel Rationnel::operator/=(const Rationnel& R2)
{
	Rationnel R3(R2.den, R2.num);
	*this = *this*R3;
	return *this;
}




bool Rationnel::operator<(Rationnel& R2)
{
	float F1 = (float)num/den;
	float F2 = (float)R2.num/R2.den;
	if(F1 < F2)
		return true;
	else if(F2 >= F1)
		return false;
}


bool Rationnel::operator>(Rationnel& R2)
{
	float F1 = (float)num/den;
	float F2 = (float)R2.num/R2.den;
	if(F1 > F2)
		return true;
	else if(F2<= F1)
		return false;
}


bool Rationnel::operator==(Rationnel& R2)
{
	float F1 = (float)num/den;
	float F2 = (float)R2.num/R2.den;
		if(F1 == F2)
		return true;
	else if(F2 > F1 || F2 < F1)
		return false;
}


bool Rationnel::operator!=(Rationnel& R2)
{
	float F1 = (float)num/den;
	float F2 = (float)R2.num/R2.den;
	if(F1 != F2)
		return true;
	else if(F2 == F1)
		return false;
}


bool Rationnel::operator<=(Rationnel& R2)
{
	float F1 = (float)num/den;
	float F2 = (float)R2.num/R2.den;
	if(F1 <= F2)
		return true;
	else if(F2 > F1)
		return false;
}


bool Rationnel::operator>=(Rationnel& R2)
{
	float F1 = (float)num/den;
	float F2 = (float)R2.num/R2.den;
	if(F1 >= F2)
		return true;
	else if(F2 < F1)
		return false;
}


float Rationnel::ConversionR()
{
	float F = (float)num/den;
	return F;
}


long Rationnel::PGCD(long x, long y)
{
	long pgcd;
	if(x%y == 0)
		pgcd = y;

	else
		pgcd = PGCD(y, x%y);

	return pgcd;
}


//suite geometrique u(n + 1) = u(n) + 1/q :

void suiteGeometrique(int q, int N)
{
	int n = 1;
	Rationnel u(1);	//premier terme
	Rationnel qinv(1);

	while(n <= N)
	{
		cout << " n = " << n << " | " << "u(n) = " << u;
		n++;
		qinv /= q;
		u += qinv;
	}
}

