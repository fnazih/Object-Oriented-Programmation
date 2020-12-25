#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


class Matrice
{
private:
	vector < vector < float > > Mat;
	int nb_lignes, nb_colonnes;
public:
	Matrice(int lignes, int colonnes);
	int getLignes() { return nb_lignes; }
	int getColonnes() { return nb_colonnes; }
	float getElement(int ligne, int col) const;
	void setElement(int ligne, int col, float val);
	void Afficher() const;
};


int main(void)
{
	Matrice mat(3, 3);
	/*mat.setElement(0, 0, 1);
	mat.setElement(0, 1, 1);
	mat.setElement(0, 2, 1);
	mat.setElement(1, 0, 1);
	mat.setElement(1, 1, 1);
	mat.setElement(1, 2, 1);
	mat.setElement(2, 0, 1);
	mat.setElement(2, 1, 1);
	mat.setElement(2, 2, 1);*/
	cout << "matrice finie " << endl;
	mat.Afficher();

	return 0;
}

Matrice::Matrice(int lignes, int colonnes)
{
	Mat.resize(lignes);
	for(int i = 0; i < lignes; i++)
	{
		Mat[i].assign(colonnes, 0);
	}
	
	this->nb_lignes = lignes;
	this->nb_colonnes = nb_colonnes;
}


void Matrice::setElement(int ligne, int col, float val)
{
	Mat[ligne][col] = val;
}


float Matrice::getElement(int ligne, int col) const
{
	return Mat[ligne][col];
}


void Matrice::Afficher() const
{
	for(int i = 0; i < nb_lignes; i++)
	{
		for(int j = 0; j < nb_colonnes; j++)
		{
			cout << "boubou";
			cout << setw(5) << getElement(i, j);
		}
		cout << endl;
	}
}




