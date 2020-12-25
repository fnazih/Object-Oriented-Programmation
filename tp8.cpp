#include <iostream>
#include <cstring>
using namespace std;


class Vehicule
{
private:
	int vmax;
public:


};


class Terrestre :public Vehicule
{
private:
	int nb_roues;
public:

};


class Marin :public Vehicule
{
private:
	float tirant_eau;
public:

};


class Amphibie :public Vehicule :public Vehicule
{
private:
	int nb_roues;
	float tirant_eau;
public:


}
