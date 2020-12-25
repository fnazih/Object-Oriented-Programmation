#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;

#define max 100
enum couleur{noir, blanc, rouge, bleu};

class Vehicule
{
private :
	string nom;
	int nb_chvx;
	int nb_roues;
	couleur color;
public :
	Vehicule(string n, int chvx, int roues, couleur coul):nom(n), nb_chvx(chvx), nb_roues(roues), color(coul){}
	virtual void Affichage();
	string getNom() { return nom; }
	int getChvx() { return nb_chvx; }
	int getRoues() { return nb_roues; }
	couleur getCouleur() { return color; }
};


class Moto :public Vehicule{
private:
	int cylindree;
public:
	Moto(string n, int chvx, int roues, couleur coul, int cyl):Vehicule(n, chvx, roues, coul), cylindree(cyl){}
	void Affichage();
};

int main()
{
	Vehicule V1("Mercedes", 200, 4, noir);
	V1.Affichage();
	Moto V2("Ducatti ", 300, 2, noir, 125);
	V2.Affichage();
	return 0;
}


void Vehicule::Affichage()
{
	cout << "Nom : " << nom << endl;
	cout << "Nombre de chevaux : " << nb_chvx << endl;
	cout << "Nombre de roues : " << nb_roues << endl;
	cout << "Couleur : ";
	if(color == noir)
	{
		cout << "Noir" << endl;
	}
	if(color == blanc)
	{
		cout << "Blanc" << endl;
	}
	if(color == rouge)
	{
		cout << "Rouge" << endl;
	}
	if(color == bleu)
	{
		cout << "Bleu" << endl;
	}
}


void Moto::Affichage()
{
	cout << "Nom : " << getNom() << endl;
	cout << "Nombre de chevaux : " << getChvx() << endl;
	cout << "Nombre de roues : " << getRoues() << endl;
	cout << "Couleur : ";
	if(getCouleur() == noir)
	{
		cout << "Noir" << endl;
	}
	if(getCouleur() == blanc)
	{
		cout << "Blanc" << endl;
	}
	if(getCouleur() == rouge)
	{
		cout << "Rouge" << endl;
	}
	if(getCouleur() == bleu)
	{
		cout << "Bleu" << endl;
	}
	cout << "Cylindree : "<< cylindree << endl;

}
