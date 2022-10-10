#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int mystrlen(char* str) {
	int i;
	for (i = 0; str[i] != '\0'; i++)
		;
	return i;
}
char* mystrcpy(char* str1, char* str2) {

	int i, j, k = mystrlen(str2);
	char str[100];
	for (i = 0; str1[i] != '\0'; i++)
	{
		str[i] = str1[i];
	}
	for (j = 0; str2[j] != '\0'; i++, j++)
	{
		str[j] = str2[j];
	}

	str[j] = '\0';
	return str;

}
int mystrcmp(const char* str1, const char* str2) {
	int x = mystrlen(str1), y = mystrlen(str2);
	int i;
	for (i = 0; (str1[i] != '\0' || str2[i] != '\0'); i++) {
		if (str1[i] < str2[i]) {
			return -1;
		}
		else if (str1[i] > str2[i]) {
			return 1;
		}
	}
	return 0;
}
char* mystrcat(char* str, const char* source) {
	int x = mystrlen(str), y = mystrlen(source);
	char* destination = (char*)malloc(x + y + sizeof(char));
	int i;
	for (i = 0; i < x; i++) {
		destination[i] = str[i];
	}
	for (i = 0; i < y; i++, x++) {
		destination[x] = source[i];
	}
	destination[x] = '\0';
	return destination;
};
char* mystrstr(const char* str1, const char* str2) {
	int i, k;
	for (i = 0; str1[i] != '\0'; i++) {
		k = i;
		int j = 0;
		while (str2[j] != '\0') {
			if (str1[i] == str2[j]) {
				j++;
				i++;
			}
			else
			{
				i = k;
				break;
			}
		}
		if (j == mystrlen(str2))
			return str1[k];
	}
	return 0;
}
char* reverse(char* str1, char* str2) {
	int i = mystrlen(str1), j = mystrlen(str2);
	char* str = (char*)malloc(i + j + sizeof(char));
	int x,y=i+j;
	for (x = 0; x < y; x++) {
		if (x < j) {
			str[x] = str2[x];
		}
		else {
			str[x] = str1[--i];
		}
	}
	str[y] = '\0';
	return str;
}
void main() {

	char str1[] = "aaaab";
	char str2[] = "aab";
	int lenght_str1 = mystrlen(str1);
	int lenght_str2 = mystrlen(str2);
	char* c = mystrcpy(str1, str2);
	int x = mystrcmp(str1, str2);
	char* c2 = mystrcat(str1, str2);
	char *y = mystrstr(str1, str2);
	printf_s("%p\n", y);
	char *str = reverse(str1, str2);


}