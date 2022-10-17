#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	float x, y;
}Koordinata;
void cita(FILE* fp) {
	int n;
	printf_s("Unesi indeks: ");
	scanf_s("%d", &n);
	fseek(fp, sizeof(int)+sizeof(Koordinata)*n, SEEK_SET);
	Koordinata k;
	fread(&k, sizeof(k), 1, fp);
	printf_s("%f,%f\n", k.x, k.y);


}
void main() {
	FILE* fp=fopen("zad3.bin","rb");
	if (!fp)
		return NULL;
	cita(fp);
	fclose(fp);
}