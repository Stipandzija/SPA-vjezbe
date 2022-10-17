#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float x, y;
}Koordinata;

Koordinata* ucitava(int n) {
	Koordinata* k= (Koordinata*)malloc(n * sizeof(Koordinata));
	for (int i = 0,j=1; i < n; i++,j++) {
		Koordinata x;
		x.x = j;
		x.y = j;
		k[i] = x;
	}
	return k;
}
void unos(Koordinata* k, FILE* fp,int x) {
	for (int i = 0; i < x; i++) {
		fwrite(&k[i], sizeof(k[i]), 1, fp);
	}
}
void main() {
	printf_s("Unesi broj: ");
	int x; scanf_s("%d", &x);
	FILE* fp = fopen("zad3.bin", "wb");
	if (!fp)
		return NULL;
	fwrite(&x, sizeof(int), 1, fp);
	Koordinata* k = ucitava(x);

	unos(k, fp, x);
	fclose(fp);
	free(k);
}