#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	float x, y;
}Koordinata;

void append(FILE* fp, Koordinata k) {
	fseek(fp, 0, SEEK_END);
	for (int i = 0; i < 2; i++) {
		fwrite(&k, sizeof(k), 1, fp);
	}
}
void main() {
	Koordinata k;
	printf_s("Nova Koordinata");
	printf_s("Unesi tocku x: ");
	scanf_s("%f", &k.x);
	printf_s("Unesi tocku y: ");
	scanf_s("%f", &k.y);

	FILE* fp = fopen("zad3.bin", "a");
	if (!fp)
		return NULL;
	append(fp, k);
	fclose(fp);

	FILE* fpp = fopen("zad3.bin", "r+");
	if (!fpp)
		return NULL;
	fclose(fpp);
}