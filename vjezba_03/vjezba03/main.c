#include<stdio.h>
#include <stdlib.h>
#include "stl.h"

void main() {
	Object3D* o = unosi();
	zapisuje_bin(o);
	zapisuje_txt(o);
	brise(o);
	
	
}