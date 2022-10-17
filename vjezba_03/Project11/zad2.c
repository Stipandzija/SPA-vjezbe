#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void main() {
	FILE* fp = fopen("zad1.bin", "rb");
	if (!fp)
		return NULL;
	while (!feof(fp)) {
		int s = 0;
		fread(&s, 1, sizeof(int), fp);
		if(feof(fp))
			break;
		printf_s("%d\n", s);
	}
	fclose(fp);
}