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
	unsigned int broj;
}Object3D;

Object3D* unosi();
void zapisuje_bin(Object3D*);
void zapisuje_txt(Object3D*);
void brise(Object3D*);