#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;


class Point
{
private :
	float x,y;
	friend class Segment;
	friend class Polygone;
public :
	Point();
	Point(float choixX, float choixY);	//constructeur
	float getX() const	//retourne l'abscisse
	{
		cout << "Abscisse : " << x <<"\n";
	}
	float getY() const	//retourne l'ordonnee
	{
		cout << "Ordonnee : " << y <<"\n";
	}
	void setX(float nvX);	//change l'abscisse
	void setY(float nvY);	//change l'ordonnee
	void Afficher_Coordonnees();	//affiche les coordonnees du point 
	bool Test_Egalite(Point& point) const	//teste l'egalite entre deux points
	{
		if(point.x = x && point.y == y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	float Distance(Point& point) const	//retourne la distance entre deux points
	{
		float dist;
		dist = sqrt( pow(x - point.x, 2) + pow(y - point.y, 2) );
		//cout << "La distance entre les deux points est de : " << dist << "\n";
		return dist;
	}
};


class Segment
{
private :
	Point origine;
	Point extremite;
public :
	Segment(Point& o, Point& e):origine(o.x, o.y), extremite(e.x, e.y){}	//constructeur
	void Affichage_Segment();
	void Translation_Segment(int translationX, int translationY);
};


class Polygone
{
private :
	int nb_points;
	Point* Tableau_Points;
public :
	Polygone(int num, Point* tabpts);	//constructeur
	/*~Polygone()	//destructeur
	{
	cout << "Destruction polygone en cours\n";
	delete[] Tableau_Points;
	}*/
	void Afficher_Polygone();
	void Calcul_Perimetre();
};



int main()
{
	Point origine(0, 0), extremite(1, 1);
	Segment s(origine, extremite);
	s.Affichage_Segment();
	s.Translation_Segment(1, 1);
	s.Affichage_Segment();

	/*Point P1(0, 0), P2(1, 2), P3(3, 2);
	P1.Afficher_Coordonnees();
	P2.Afficher_Coordonnees();
	P3.Afficher_Coordonnees();
	return 0;*/

	Point tab_points[3] = { Point(0, 0), Point(0, 4), Point(2, 2) };
	Polygone pol(3, tab_points);
	pol.Afficher_Polygone();
	pol.Calcul_Perimetre();
}


Point::Point(float choixX, float choixY)
{
	x = choixX;
	y = choixY;
}


void Point::setX(float nvX)
{
	x = nvX;
}


void Point::setY(float nvY)
{
	y = nvY;
}


void Point::Afficher_Coordonnees()
{
	getX();
	getY();
}


void Segment::Affichage_Segment()
{
	cout << "Voici les coordonnees des points constituant votre segment :\n";
	cout << "Origine :\n";
	origine.Afficher_Coordonnees();
	cout << "Extremite :\n";
	extremite.Afficher_Coordonnees();
}


void Segment::Translation_Segment(int translationX, int translationY)
{
	origine.setX(origine.x + translationX);
	origine.setY(origine.y + translationY);

	extremite.setX(extremite.x + translationX);
	extremite.setY(extremite.y + translationY);
}

Polygone::Polygone(int num, Point* tabpts)
{
	cout << "Construction polygone en cours...\n";
	nb_points = num;
	Tableau_Points = tabpts;
}

void Polygone::Afficher_Polygone()
{
	for(int i = 0; i < nb_points; i++)
	{
		cout << "Point numero " << i + 1 << " :\n";
		Tableau_Points[i].Afficher_Coordonnees();
	}
}

void Polygone::Calcul_Perimetre()
{
	float perimetre = 0.0;
	perimetre+= Tableau_Points[nb_points - 1].Distance(Tableau_Points[0]);
	
	for(int i = 0; i < nb_points - 1; i++)
	{
		perimetre += Tableau_Points[i].Distance(Tableau_Points[i + 1]);
	}
	
	cout << "Perimetre du polygone : " << perimetre << "\n";
}

