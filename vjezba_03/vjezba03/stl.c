#include<stdio.h>
#include <stdlib.h>
#include "stl.h"

Object3D* unosi() {
	FILE* fp = fopen("primjerbin.stl", "rb");
	if (!fp)
		return NULL;
	fseek(fp, 80, SEEK_SET);
	Object3D* o = (Object3D*)malloc(sizeof(Object3D));
	fread(&o->broj, sizeof(o->broj), 1, fp);
	o->t = (Trokut*)malloc(o->broj * sizeof(Trokut));
	for (int i = 0; i < (int)o->broj; i++) {
		fread(&o->t[i].normala, sizeof(o->t[i].normala), 1, fp);
		for (int j = 0; j < 3; j++) {
			fread(&o->t[i].v[j], sizeof(o->t[i].v[j]), 1, fp);
		}
		fread(&o->t[i].boja, sizeof(o->t[i].boja), 1, fp);
	}

	/*for (int i = 0; i < o->broj; i++) {
		printf_s("%d %f %f %f\n", i, o->t[i].normala.x, o->t[i].normala.y, o->t[i].normala.z);
		for (int j = 0; j < 3; j++) {
			printf_s("%d (%f %f %f)\n",i, o->t[i].v[j].x, o->t[i].v[j].y, o->t[i].v[j].z);
		}
	}
	*/
	fclose(fp);
	return o;
}
void zapisuje_bin(Object3D* o) {
	FILE* fp = fopen("stl.bin", "wb");
	if (!fp)
		return NULL;
	int x[80];
	for (int i = 0; i < 80; i++)
		*(x + i) = 0;
	fwrite(&x, 1, 20*sizeof(int), fp);
	fwrite(&o->broj, sizeof(o->broj), 1, fp);
	for (int i = 0; i < (int)o->broj; i++) {
		fwrite(&o->t[i].normala, sizeof(o->t[i].normala), 1, fp);
		for (int j = 0; j < 3; j++) {
			fwrite(&o->t[i].v[j], sizeof(o->t[i].v[j]), 1, fp);
		}
		fwrite(&o->t[i].boja, sizeof(o->t[i].boja), 1, fp);
	}
	fclose(fp);
}
void zapisuje_txt(Object3D* o) {

	FILE* fp = fopen("stl.txt", "wt");
	if (!fp)
		return NULL;
	fprintf(fp, "%s\n", "solid OpenSCAD_Model");
	for (int i = 0; i < (int)o->broj; i++) {
		fprintf(fp, "%s %f %f %f\n", "facet normal", o->t[i].normala.x, o->t[i].normala.y, o->t[i].normala.z);
		fprintf(fp, "%s\n", "  outer loop");
		for (int j = 0; j < 3; j++) {
			fprintf(fp, "%s %f %f %f\n", "    vertex",o->t[i].v[j].x, o->t[i].v[j].y, o->t[i].v[j].z);
		}
		fprintf(fp, "%s\n", "  endloop");
		fprintf(fp, "%s\n", "endfacet");
	}
	fclose(fp);
}
void brise(Object3D* o) {
	free(o->t);
	o->t = NULL;
	free(o);
	o = NULL;
}