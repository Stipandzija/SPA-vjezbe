#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stl.h"

Objekt3D* funk1() {
	FILE* fp = fopen("primjerbin.stl", "rb");
	if (!fp)
		return NULL;
	Objekt3D* obj = (Objekt3D*)malloc(sizeof(Objekt3D));

	fseek(fp, 80, SEEK_SET);
	fread(&obj->broj_trokuta,sizeof(obj->broj_trokuta),1,fp);
	obj->t = (Trokut*)malloc(obj->broj_trokuta * sizeof(Trokut));

	for (int i = 0; i < obj->broj_trokuta; i++) {
		
		fread(&obj->t[i].normala, sizeof(obj->t->normala), 1, fp);

		for (int j = 0; j < 3; j++) {
			fread(&obj->t[i].v[j], sizeof(obj->t[i].v[j]), 1, fp);
		}

		fread(&obj->t[i].boja, sizeof(obj->t[i].boja), 1, fp);

		
	}
	/*for (int i = 0; i < obj->broj_trokuta; i++) {
		printf_s("%d, %f\n",i, obj->t[i].normala);
		for(int j=0;j<3;j++)
			printf_s("%d, ( %f,%f,%f )\n", i, obj->t[i].v[j].x, obj->t[i].v[j].y, obj->t[i].v[j].z);
	}
	*/
	fclose(fp);
	return obj;
}

void zapisuje_bin(Objekt3D* o) {
	FILE* fp = fopen("bin.stl", "wb");
	if (!fp)
		return NULL;
	int buffer[80];
	for (int i = 0; i < 80; i++)
		buffer[i] = 0;
	fwrite(&buffer,1, sizeof(int)*20, fp);
	fwrite(&o->broj_trokuta, sizeof(o->broj_trokuta), 1, fp);

	for (int i = 0; i < o->broj_trokuta; i++) {
		fwrite(&o->t[i].normala, sizeof(o->t[i].normala), 1, fp);
		for (int j = 0; j < 3; j++)
			fwrite(&o->t[i].v[j], sizeof(o->t[i].v[j]), 1, fp);
		fwrite(&o->t[i].boja, sizeof(o->t[i].boja), 1, fp);
	}
	fclose(fp);
}

void zapisuje_txt(Objekt3D* o) {
	FILE* fp = fopen("bin.txt", "wt");
	char top[21]="solid OpenSCAD_Model";
	fprintf(fp, "%s\n", top);
	fprintf(fp, "%d\n", o->broj_trokuta);
	for (int i = 0; i < o->broj_trokuta; i++) {
		fprintf(fp, "%s %f %f %f\n", "facet normal", o->t[i].normala.x, o->t[i].normala.y, o->t[i].normala.z);
		fprintf(fp, "%s\n", "   outer loop");
		for (int j = 0; j < 3; j++) {
			fprintf(fp, "%s %f %f %f\n", "    vertex", o->t[i].v[j].x, o->t[i].v[j].y, o->t[i].v[j].z);
		}
		fprintf(fp, "%s\n", "   endloop");
		fprintf(fp, "%s\n", "endfacet");
	}
	fclose(fp);
}

void brise(Objekt3D* obj) {
	free(obj);
}

