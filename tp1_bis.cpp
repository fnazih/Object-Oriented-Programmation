#include <iostream>
#include <cstdlib>
using namespace std;

#define ANNEE_DE_BASE 1998

struct Date{
	int jour;
	int mois;
	int annee;
}


void init(Date &date, int j, int m, const int a = 2000);


int main()
{


	return 0;
}


void init(Date &date, int j, int m, const int a = 2000)
{
	date.jour = j;
	date.mois = m;
	date.annee = a;
}


