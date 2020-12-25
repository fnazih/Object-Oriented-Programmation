#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;


class Personne
{
private:
	string name;
	int age;
public:
	Personne(string n, int a): name(n), age(a) {}
	void Afficher();
};


void Afficher_Fichier(const char* NomFic);

int main(void)
{

	Afficher_Fichier("personnes.txt");

	return 0;
}

void Personne::Afficher()
{
	cout << "Nom : " << name << " | " << "Age : " << age << endl;
}


void Afficher_Fichier(const char* NomFic)
{
	ifstream fic(NomFic);
	Personne* pers;
	
	while(!fic.fail())
	{
		string nom;
		int a;
		fic >> nom >> a;
		cout << "Nom : " << nom << " | age : " << a << endl;
	}

}








