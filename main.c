#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
// #include "lib.c"
#include "geral.h"

main(){
	setlocale(LC_ALL, "Portuguese");
	opening_logo();
	printf("\n");
	system("pause");
	printf("\n\n");
	printf("\tParis Task Manager 2024 V0.0\n\tDeveloped by NL/IL/JM\n\tUNIP-SJC2021\n");
	printf("\n");
	system("pause");
	login();
	initial();
	// menu();
}
