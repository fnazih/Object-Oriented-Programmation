#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;


class String
{
private :
	char* ch;
	friend class Compte;
public :
	String(const char* mot);	//constructeur
	String(const String& ch2)	//constructeur par copie
	{
		int lg = strlen(ch);
		ch = new char[lg];
		strcpy(ch, ch2.ch);
	}
	void Affichage_CDC() { cout << ch << "\n"; };
	void Maj();
	bool estEgal(const String& str2);
};


class Compte
{
private :
	String nom;
	float montant;
	static Compte* Tete;
	static float taux;
	Compte* suiv;
public :
	Compte(const char* mot, float nb = 0):nom(mot), montant(nb){}
	void Modif_Taux(float nvtaux);
	void Versement();
	void Actualisation() { montant = montant*(1 + taux); }
	void Affichage_Compte();
};


int main()
{
	Compte cpt("Laville", 5);
	cpt.Modif_Taux(0.05);
	cpt.Actualisation();
	cpt.Affichage_Compte();
	return 0;
}

String::String(const char* mot)
{
	int lg;
	lg = strlen(mot);
	ch = new char[lg];
	strcpy(ch, mot);
}

void String::Maj()
{
	int lg = strlen(ch);
	
	for(int i = 0; i < lg; i++)
	{
		ch[i] = toupper(ch[i]);
	}
	
}

bool String::estEgal(const String& str2)
{
	if(strcmp(str2.ch, ch) == 0)
	{
		return true;
	}
	else return false;
}


void Compte::Modif_Taux(float nvtaux)
{
	taux = nvtaux;
}

void Compte::Versement()
{
	int somme;
	cout << "Combien voulez-vous verser sur le compte ?\n";
	cin >> somme;
	montant += somme;
}

void Compte::Affichage_Compte()
{
	cout << nom.ch << "\n";
	cout << montant << "\n";
}
