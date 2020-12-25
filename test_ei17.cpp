#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


#define NB_MAX_SALLES 100

class Salle
{
	public:
	Salle(string name, float l, float w, int capa ): nom(name),     {}



{nom = name; longueur = l; largeur = w ; capacite = capa; }
	Salle(){}
	virtual void Affichage()
	{
		cout <<"Nom : " << nom << endl
		<< "Longueur : " << longueur << endl
		<< "Largeur : " << largeur <<endl
		<< "Capacite : " << capacite <<endl;
		cout << " *************** " << endl;

	}
	string getN();
	float getLO();
	float getLA();
	int getC();
	bool operator<( Salle& S2)
	{
		return capacite < S2.capacite; 
	}
	bool operator==(Salle& S2)
	{
		return capacite == S2.capacite;
	}
	private:
	string nom;
	float longueur;
	float largeur;
	int capacite;
};

class SalleCours :public Salle{
private:
	bool Amphi;
public:
	SalleCours()
	{
		Amphi = false;
	}
	SalleCours(string name, float l, float w, int capa):Salle(name, l, w, capa) {}
	bool getAmphi() { return Amphi; }
	void setAmphi(bool am) { Amphi = am; }
	void Affichage()
	{
		cout <<"Nom : " << getN() << endl
		<< "Longueur : " << getLO() << endl
		<< "Largeur : " << getLA() <<endl
		<< "Capacite : " << getC() <<endl
		<< "Amphi (1 : oui, 0 : non) : " << getAmphi() << endl;
		cout << " *************** " << endl;
	}

};


class SalleInfo :public Salle
{
private:
	int nb_postes;
public:
	SalleInfo(string n, float l, float w, int capa): Salle(n, l, w, capa), nb_postes(0) {}
	int getNbP() { return nb_postes; }
	void setNbPostes(int nb) { nb_postes = nb; }
	void Affichage()
	{
		cout <<"Nom : " << getN() << endl
		<< "Longueur : " << getLO() << endl
		<< "Largeur : " << getLA() <<endl
		<< "Capacite : " << getC() <<endl;
	
		if(nb_postes > 0)
			cout << "Nombre de postes : " << getNbP() << endl;
		else if(nb_postes == 0)
			cout << "Postes portables" << endl;
		cout << " *************** " << endl;
	}
};


class ListeSalles
{
private:
	Salle* Liste[NB_MAX_SALLES];
	int nb_salles;
public:
	ListeSalles() { nb_salles = 0; }
	void AjouterSalle(Salle* salle);
	void Afficher_Liste() const;
	int getNbS() { return nb_salles; }
	int getIndSalle(Salle* salle);
	Salle* chercherSalle(const string& name);
	int chercherIndSalle(const string& name);
	ListeSalles operator+(ListeSalles& Liste2);
	Salle* getSalle_s(int ind) const;	//a faire
};


/*class exception
{
private:
	string msg;
public:
	

};*/



void LireFicSalles(const char* nomFic, ListeSalles* liste);



int main(void)
{
	/*Salle S1("bitch", 3.8, 2.7, 30 );
	Salle S2("pute", 4.9, 3.5, 20);
	S1.Affichage();
	string n = "b";
	n = S1.getN();
	float lon = S1.getLO();
	float lar = S1.getLA();
	int cap = S1.getC();
	cout << n << endl << lon << endl << lar << endl << cap << endl;
	cout << (S1<S2);

	SalleCours salle1("pute", 2.4, 3.6, 12, false);
	SalleCours s2("bedo", 5.6, 4.2, 30, true);

	salle1.Affichage();
	s2.Affichage();


	SalleInfo info("Info", 5.5, 8.6, 20);
	info.setNbPostes(5);
	info.Affichage();

	SalleInfo info2("Info2", 7.3, 8.6, 30);
	info2.Affichage();

	ListeSalles Ecole;
	Ecole.AjouterSalle(&salle1);
	Ecole.AjouterSalle(&s2);
	Ecole.AjouterSalle(&info);
	Ecole.AjouterSalle(&info2);
	Ecole.Afficher_Liste();

	Salle* s3;
	s3 =  Ecole.chercherSalle("pute");
	
	cout << endl << "Chercher Salle " << endl;
	s3->Affichage();

	int num_salle = Ecole.chercherIndSalle("rien");
	cout << "Num salle : " << num_salle << endl;
	
	int num = Ecole.getIndSalle(&info2);
	cout << "Indice info2 : " << num << endl;

	ListeSalles Ecole2;
	Ecole2.AjouterSalle(&salle1);
	Salle s4("salut", 4.5, 7.6, 20);
	Ecole2.AjouterSalle(&s4);

	ListeSalles Fusion;
	Fusion = Ecole + Ecole2;

	Fusion.Afficher_Liste();*/

	ListeSalles nvliste;
	LireFicSalles("salles.txt", &nvliste);

	nvliste.Afficher_Liste();

	return 0;
}


string Salle::getN()
{
	return nom;
}

float Salle::getLO()
{
	return longueur;
}

float Salle::getLA()
{
	return largeur;
}

int Salle::getC()
{
	return capacite;
}


void ListeSalles::AjouterSalle(Salle* salle)
{
	bool appartient = false;

	if(nb_salles == 0)
	{
		Liste[nb_salles] = salle;
		nb_salles++;
		appartient = true;
	}

	else
	{
		for(int i = 0; i < nb_salles; i++)
		{
			if(Liste[i]->getN() == salle->getN())
			{
				//cout << "La salle appartient deja a la liste" << endl;
				appartient = true;
			}
		}
	}
	
	if(!appartient)
	{
		Liste[nb_salles] = salle;
		nb_salles++;
	}
}


void ListeSalles::Afficher_Liste() const
{
	for(int i = 0; i < nb_salles; i++)
		Liste[i]->Affichage();
}


int ListeSalles::getIndSalle(Salle* salle)
{
	int cpt = 0;
	for(int i = 0; i < nb_salles; i++)
	{
		if(Liste[i]->getN() == salle->getN())
		{
			return cpt;
		}
		cpt++;
	}
	if(cpt >= nb_salles)
		return -1;
}



Salle* ListeSalles::chercherSalle(const string& name)
{
	for(int i = 0; i < nb_salles; i++)
	{
		if(Liste[i]->getN() == name)
		{
			return Liste[i];
		}
		else
		{
			return NULL;
		}
	}
}


int ListeSalles::chercherIndSalle(const string& name)
{
	int cpt = 0;
	for(int i = 0; i < nb_salles; i++)
	{
		if(Liste[i]->getN() == name)
			return cpt;
		else
			cpt++;
	}
	
	if(cpt >= nb_salles)
		return -1;
}



ListeSalles ListeSalles::operator+(ListeSalles& Liste2)
{
	ListeSalles Fusion;

	for(int i = 0; i < nb_salles; i++)
	{
		Fusion.AjouterSalle(Liste[i]);
	}

	for(int j = 0; j < Liste2.nb_salles; j++)
	{
		for(int k = 0; k < nb_salles; k++)
		{
			if(Liste2.Liste[j]->getN() != Liste[k]->getN())
				Fusion.AjouterSalle(Liste2.Liste[j]);
		}
	}

	return Fusion;
}


Salle* ListeSalles::getSalle_s(int ind) const
{


}


void LireFicSalles(const char* nomFic, ListeSalles* liste)
{
	ifstream fic(nomFic);

	string type_salle, nom_salle;
	float lg, lrg;
	int capa, nb_p;

	while(!fic.fail())
	{
		fic >> type_salle;
		if(type_salle == "SALLE_COURS")
		{
			fic >> nom_salle >> lg >> lrg >> capa;
			SalleCours *sallecours;
			sallecours = new SalleCours(nom_salle, lg, lrg, capa);
			sallecours->setAmphi(false);
			//sallecours.Affichage();
			liste->AjouterSalle(sallecours);
		}
		else if(type_salle == "AMPHI")
		{
			fic >> nom_salle >> lg >> lrg >> capa;
			SalleCours *amphi;
			amphi = new SalleCours(nom_salle, lg, lrg, capa);
			amphi->setAmphi(true);
			//amphi.Affichage();
			liste->AjouterSalle(amphi);
		}
		else if(type_salle == "SALLE_INFO")
		{
			fic >> nom_salle >> lg >> lrg >> capa >> nb_p;
			SalleInfo* info;
			info = new SalleInfo(nom_salle, lg, lrg, capa);
			info->setNbPostes(nb_p);
			//info.Affichage();
			liste->AjouterSalle(info);
		}
	}
}

