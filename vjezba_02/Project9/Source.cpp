#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
	float x;
	float y;
}Tocka;
typedef struct {
	int n;
	Tocka* t;
}Poligon;

int* podniz(int* arr, int start, int stop) {
	int* niz = (int*)malloc((stop - start) * sizeof(int));
	if (!niz)
		return NULL;
	int i, j;
	for (i = start, j = 0; i < stop; i++, j++) {
		*(niz + j) = *(arr + i);
	}
	return niz;
}
int* filtriraj(int* niz, int n, int th, int* nth) {
	*nth = 1;
	int* arr = (int*)malloc(sizeof(int));
	if (!arr)
		return NULL;
	for (int i = 0; i < n; i++) {
		if (*(niz + i) < th) {
			arr[*nth - 1] = niz[i];
			*nth += 1;
			arr = (int*)realloc(arr, *nth * sizeof(int));
		}
	}
	*nth -= 1;
	return arr;
}
int** podijeli(int* niz, int n) {
	int* x = (int*)malloc(sizeof(int)), * y = (int*)malloc(sizeof(int));
	x = &niz[0];
	if (!x || !y)
		return NULL;
	if (n % 2 == 0)
		y = &niz[n / 2];
	else
		y = &niz[abs(n / 2)];

	int** strct = (int**)malloc(2 * sizeof(int*));
	if (!strct)
		return NULL;
	strct[0] = x;
	strct[1] = y;
	return strct;
}
Poligon* novi_poligon(float* niz_x, float* niz_y, int n) {
	Poligon* p = (Poligon*)malloc(sizeof(Poligon));
	if (!p)
		return NULL;
	Tocka* tck = (Tocka*)malloc(n*sizeof(Tocka));
	if (!tck)
		return NULL;
	for (int i = 0; i < n; i++) {
		tck[i].x = niz_x[i];
		tck[i].y = niz_y[i];
	}
	p->t = tck;
	p->n = n;
	return p;
}
Tocka** pozitivni(Poligon* p, int* np) {
	Tocka** tck = (Tocka**)malloc(sizeof(Tocka*));
	if (!tck)
		return NULL;
	for (int i = 0; i < p->n; i++) {
		if ((p->t[i].x > 0) && (p->t[i].y > 0)) {
			tck[*np] = &(p->t[i]);
			*np += 1;
		}
	}
	return tck;
}

int main() {
	int niz[] = { 4,8,2,26,18 };
	int* funk1 = podniz(niz, 2, 4);
	int duzina;
	int* funk2 = filtriraj(niz, 5, 10, &duzina);
	int** funk3 = podijeli(niz, 5);
	
	float arr1[3] = {-0.2,1.5,3.6};
	float arr2[3] = { -3.5,6.5,-7.6 };

	Poligon* p = novi_poligon(arr1, arr2, 3);
	if (!p)
		return NULL;
	int np=0;
	Tocka** t = pozitivni(p, &np);
	if(!t)
		return NULL;

	free(funk1);
	free(funk2);
	free(funk3);
	free(p);
	free(t);
	return 0;
}