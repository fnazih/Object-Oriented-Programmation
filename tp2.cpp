#include <iostream>
#include <cstdlib>
using namespace std;

#define taille_tab 100

class Entiers
{
private :
	int Tab[taille_tab];
	bool Contient(int val) const;
	int taille;
	bool egalite_ensembles(const Entiers& e2) const;
public :
	Entiers();		//constructeur
	void Ajout_Entier(int num);
	void Supprimer(int num);
	void Afficher();
	void Test_Egalite(const Entiers& Liste) const;
	Entiers Intersection(const Entiers& e2) const;
	Entiers Extraire_Nbs_Premiers() const;
};


int main()
{
	Entiers Liste_Entiers;
	Entiers Liste_Entiers2;
	Entiers Inter;
	Liste_Entiers.Ajout_Entier(1);
	Liste_Entiers.Ajout_Entier(2);
	Liste_Entiers.Ajout_Entier(4);
	Liste_Entiers.Ajout_Entier(7);
	Liste_Entiers.Afficher();
	Liste_Entiers2.Ajout_Entier(1);
	Liste_Entiers2.Ajout_Entier(2);
	Liste_Entiers2.Ajout_Entier(3);
	Liste_Entiers2.Ajout_Entier(12);
	Liste_Entiers2.Ajout_Entier(7);
	Liste_Entiers2.Afficher();
	Liste_Entiers.Test_Egalite(Liste_Entiers2);
	Inter = Liste_Entiers.Intersection(Liste_Entiers2);
	Inter.Afficher();
	return 0;
}


Entiers::Entiers()
{
	taille = 0;
}


void Entiers::Ajout_Entier(int num)
{
	if(!Contient(num))
	{
		Tab[taille] = num;
		taille++;
	}
	
	else
	{
		cout << "Erreur : le tableau contient deja la valeur " << num << "\n";
	}
}


bool Entiers::Contient(int val) const
{
	bool dedans = false;
	
	for(int i = 0; i < taille; i++)
	{
		if(Tab[i] == val)
		{
			dedans = true;
		}
	}

	return dedans;
}


void Entiers::Afficher()
{
	cout << "[";

	for(int i = 0; i < taille; i++)
	{
		cout << " " << Tab[i];
	}

	cout << " ]\n";
}
void Entiers::Supprimer(int num)
{
	for(int i = 0; i < taille; i++)
	{
		if(Tab[i] == num)
		{
			Tab[i] = Tab[taille - 1];
			taille--;
		}
	}
}


bool Entiers::egalite_ensembles(const Entiers& e2) const
{
	bool egaux = false;

	if(taille != e2.taille)
	{
		egaux = false;
	}

	else
	{
		int i = 0;
		while(i < taille && e2.Contient(Tab[i]))
		{
			i++;
		}

		if(i < taille)
			egaux = false;
		else
			egaux = true;
	}
	return egaux;
}

void Entiers::Test_Egalite(const Entiers& Liste) const
{
	if(egalite_ensembles(Liste))
	{
		cout << "Les deux listes sont egales\n";
	}
	else
		cout << "Les deux listes sont differentes\n";
}

Entiers Entiers::Intersection(const Entiers& e2) const
{
	 Entiers inter;
	
	int i = 0;
	while(i < taille)
	{
		if(e2.Contient(Tab[i]))
			inter.Ajout_Entier(Tab[i]);
		i++;
	}

	return inter;
}

Entiers Entiers::Extraire_Nbs_Premiers() const		//a completer
{
	Entiers premiers;
	int i = 0;
	while(i < taille)
	{
		if(Tab[i] < 2)
		{
			i++;
		}
		else
		{
			for(int j = 2; j < Tab[i]; j++)
			{
				if(Tab[i]%j != 0)
				{
					premiers.Ajouter(Tab[i]);
				}
			}
		}
	}
}

