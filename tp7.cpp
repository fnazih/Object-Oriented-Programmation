#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;

const int MAX_ANIMAUX = 100;


class Animal{
private:
	string nom;
	string carac;
public:
	Animal(string n, string ca):nom(n), carac(ca){}
	string getNom() const { return nom; }
	string getCarac() const { return carac; }
	virtual string cri() const = 0;		//fonction virtuelle pure ==> la classe est donc abstraite
	virtual void Afficher() const
	{
		cout << "Nom : " << nom << endl;
		cout << "Caracteristique : " << carac << endl;
		cout << "Cri : " << cri() << endl;
	}
};

class Chien :public Animal{
public:
	Chien(string n, string ca = "fidele"): Animal(n, ca) {}
	string cri() const { return " aboie "; }
	void Afficher() const
	{
		cout << "Espece : Chien" << endl;
		cout << "Nom : " << getNom() << endl;
		cout << "Caracteristique : " << getCarac() << endl;
		cout << "Cri : " << cri() << endl;
	}
};


class Cheval :public Animal{
public:
	Cheval(string n, string ca = "galope"): Animal(n, ca) {}
	string cri() const { return " hennit "; }
	void Afficher() const
	{
		cout << "Espece : Cheval" << endl;
		cout << "Nom : " << getNom() << endl;
		cout << "Caracteristique : " << getCarac() << endl;
		cout << "Cri : " << cri() << endl;
	}
};


class Oiseau :public Animal{
public:
	Oiseau(string n, string ca = "vole"): Animal(n, ca) {}
};

class Pigeon :public Oiseau{
public:
	Pigeon(string n, string ca = "vole"): Oiseau(n, ca) {}
	string cri() const { return " roucoule "; }
	void Afficher() const
	{
		cout << "Espece : Pigeon" << endl;
		cout << "Nom : " << getNom() << endl;
		cout << "Caracteristique : " << getCarac() << endl;
		cout << "Cri : " << cri() << endl;
	}
};

class Corbeau :public Oiseau{
public:
	Corbeau(string n, string ca = "vole"): Oiseau(n, ca) {}
	string cri() const { return "croasse "; }
	void Afficher() const
	{
		cout << "Espece : Corbeau" << endl;
		cout << "Nom : " << getNom() << endl;
		cout << "Caracteristique : " << getCarac() << endl;
		cout << "Cri : " << cri() << endl;
	}
};


class Rossignol :public Oiseau{
public:
	Rossignol(string n, string ca = "vole"): Oiseau(n, ca) {}
	string cri() const { return " chante "; }
	void Afficher() const
	{
		cout << "Espece : Rossignol" << endl;
		cout << "Nom : " << getNom() << endl;
		cout << "Caracteristique : " << getCarac() << endl;
		cout << "Cri : " << cri() << endl;
	}
};


class ListeAnimaux
{
private:
	Animal *ListeA[MAX_ANIMAUX];
	int nb_animaux;
public:
	ListeAnimaux()
	{
		nb_animaux = 0;
	}
	void Ajouter(Animal &animal);
	void Afficher() const;
};


int main(void)
{
	Chien dog("Doggy");
	Cheval horse("Horsy");
	Pigeon pigeon("Debile");

	ListeAnimaux Liste;
	Liste.Ajouter(dog);
	Liste.Ajouter(horse);
	Liste.Ajouter(pigeon);

	Liste.Afficher();

	
	return 0;
}



void ListeAnimaux::Ajouter(Animal &animal)
{
	if(nb_animaux < MAX_ANIMAUX)
	{
		ListeA[nb_animaux] = &animal;
		nb_animaux++;
	}
}


void ListeAnimaux::Afficher() const
{
	for(int i = 0; i < nb_animaux; i++)
	{
		cout << "**************" << endl;
		ListeA[i]->Afficher();
		cout << "**************" << endl;
	}
}


