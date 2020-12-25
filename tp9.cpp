#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;


class Point
{
private :
	float x,y;
	friend class Segment;
	friend class Polygone;
public :
	Point() : x(0.0), y(0.0) {}
	Point(float choixX, float choixY);	//constructeur
	float getX() const	//retourne l'abscisse
	{
		return x;
	}
	float getY() const	//retourne l'ordonnee
	{
		return y;
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
	float Distance(const Point& point) const	//retourne la distance entre deux points
	{
		float dist;
		dist = sqrt( pow(x - point.getX(), 2) + pow(y - point.getY(), 2) );
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
	void Translation_Segment();
	float TailleSeg();
};


class Forme
{
private:
	Forme* suiv;
public:
	void SetSuiv(Forme &forme);
	Forme* getSuiv() const;
	virtual double perimetre() = 0;
	virtual double surface() = 0;
	virtual void Afficher() const = 0;
};


class Cercle :public Forme
{
private:
	Point centre;
	float rayon;
public:
	Cercle(Point c, float r): centre(c), rayon(r) {}
	double perimetre() { return 2*3.14*rayon; }
	double surface() { return 3.14*rayon*rayon; }
	void Afficher() const;
};





void ecrire_pointsF(const char* ficSource, int distMax, const char* ficDest);

int main(void)
{
	ecrire_pointsF("points.txt", 5, "points_dist5.txt");
	ecrire_pointsF("points.txt", 10, "points_dist10.txt");

	Point P0(0, 0);
	Cercle C1(P0, 3);
	C1.Afficher();

	return 0;
}



void ecrire_pointsF(const char* ficSource, int distMax, const char* ficDest)
{
	Point P0(0.0, 0.0);
	ifstream fSource(ficSource);
	ofstream fDest(ficDest);
	int numPt = 0;
	
	while(!fSource.fail())
	{
		float x, y;
		fSource >> x >> y;

		if(!fSource.fail())
		{
			Point p(x, y);
			
			float dist = p.Distance(P0);
			if(dist <= distMax)
			{
				fDest << setfill('0') << setw(3) << numPt << " : " << "(" << x << "," << y << ")" << " | Distance = " << setprecision(2) << dist << endl;
				numPt++;
			}
		}
		
	}
}



Point::Point(float choixX, float choixY)
{
	x = choixX;
	y = choixY;
}


float Segment::TailleSeg()
{
	float taille;
	
	taille = sqrt((extremite.y - origine.y)/(extremite.x - origine.x));
	return taille;
}



void Cercle::Afficher() const
{
	cout << "Type : Cercle" << endl;
	cout << "Perimetre : " << perimetre() << endl;
	cout << "Surface : " << surface() << endl;
}
