#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* unosi(int n) {
	int* arr = (int*)malloc(n * sizeof(int));
	if (!arr)
		return NULL;
	for (int i = 0; i < n; i++)
	{
		printf_s("Unesi broj: ");
		int x;
		scanf_s("%d", &x);
		arr[i] = x;
	}
	return arr;
}

void main() {
	printf_s("Unesi velicinu: ");
	int x; scanf_s("%d", &x);
	int* arr = unosi(x);
	if (!arr)
		return NULL;
	FILE* zad1 = fopen("zad1.bin", "wb");
	if (zad1==NULL)
		return NULL;
	int* ptr = &x;
	fwrite(ptr, sizeof(x), 1, zad1);
	fwrite(arr, sizeof(arr), x, zad1);
	fclose(zad1);
	free(ptr);
	free(arr);
}