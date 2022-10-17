#pragma once
typedef struct {
	float x, y, z;
}Vrh;

typedef struct {
	Vrh normala;
	Vrh v[3];
	unsigned short boja;
}Trokut;

typedef struct {
	Trokut* t;
	unsigned int broj_trokuta;
}Objekt3D;

Objekt3D* funk1();
void zapisuje_bin(Objekt3D*);
void zapisuje_txt(Objekt3D*);
void brise(Objekt3D*);