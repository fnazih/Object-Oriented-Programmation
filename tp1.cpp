#include <iostream>
#include <cstdlib>
using namespace std;

struct Date
{
	int jour;
	int mois;
	int annee;
};

struct ListeDates
{
	int nb_dates;
	Date* dat;
};


void Init(Date& date, int jour, int mois, const int annee = 1998);
void Afficher_Date(const Date& date);
bool Compare(Date& date1, Date& date2);
bool Compare(Date& date, int jour, int mois, int annee);
void result_compare(Date& date1, Date& date2);
void Init(ListeDates& liste, int nb_jours);
void Remplissage_Liste(ListeDates& liste, int nb_jours, const int annee = 0);
void Affichage_ListeDates(const ListeDates& liste);
void Modifier_Liste(ListeDates& liste);


int main(void)
{
	Date Anniv, Anniv1, Anniv2;
	Init(Anniv, 03, 01);
	Afficher_Date(Anniv);

	Init(Anniv1, 15, 06);
	Afficher_Date(Anniv1);
	Init(Anniv2, 15, 06);
	Afficher_Date(Anniv2);

	Compare(Anniv1, Anniv2);
	result_compare(Anniv1, Anniv2);

	ListeDates liste;
	Init(liste, 200);
	Remplissage_Liste(liste, 200);
	Affichage_ListeDates(liste);
	Modifier_Liste(liste);
	Affichage_ListeDates(liste);

	return 0;
}

void Init(Date& date, int jour, int mois, const int annee) //initialise les caracteristiques d'une date
{
	date.jour = jour;
	date.mois = mois;
	date.annee = annee;
}


void Afficher_Date(const Date& date) //affiche la date sous forme " Date : ../../.. "
{
	cout << "Date : " << date.jour << "/" << date.mois << "/" << date.annee << "\n";
}


bool Compare(Date& date1, Date& date2) //compare deux dates et retourne true si elles sont identiques, false sinon
{
	return date1.jour == date2.jour && date1.mois == date2.mois && date1.annee == date2.annee;
}


bool Compare(Date& date, int jour, int mois, int annee)
{
	return date.jour == jour && date.mois == mois && date.annee == annee;
}


void result_compare(Date& date1, Date& date2)
{
	if(Compare(date1, date2))
	{
		cout << "Les dates sont les memes";
	}

	else{ cout << "Les dates sont differentes"; }

}



void Init(ListeDates& liste, int nb_jours)
{
	liste.nb_dates = nb_jours;
	liste.dat = new Date[liste.nb_dates];
}

void Remplissage_Liste(ListeDates& liste, int nb_jours, const int annee)
{
	nb_jours = liste.nb_dates;
	liste.dat[0].jour = 01;
	liste.dat[0].mois = 01;
	liste.dat[0].annee = annee;
	for(int i = 1; i < nb_jours; i++)
	{
		liste.dat[i].jour = 01;
		liste.dat[i].mois = 01;
		liste.dat[i].annee = liste.dat[i - 1].annee + 1;
	}
}

void Affichage_ListeDates(const ListeDates& liste)
{
	int i = 0;
	while(i < liste.nb_dates)
	{
		cout << liste.dat[i].jour << "/" << liste.dat[i].mois << "/" << liste.dat[i].annee << "\n";
		i++;
	}
}

void Modifier_Liste(ListeDates& liste)
{
	int rang;
	cout << "Quel rang voulez-vous modifier ?\n";
	cin >> rang;
	cout << "Par quel jour voulez-vous le remplacer ?\n";
	int jour;
	cin >> jour;
	liste.dat[rang - 1].jour = jour;
}


