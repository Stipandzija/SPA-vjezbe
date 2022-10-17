#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stl.h"

void main() {

	Objekt3D* obj = funk1();
	zapisuje_bin(obj);
	zapisuje_txt(obj);
	brise(obj);
}