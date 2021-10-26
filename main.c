#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include "lib.c"


main(){
    setlocale(LC_ALL, "Portuguese");
    opening_logo();
    printf("\n");
    system("pause");
    printf("\n\n");
    printf("\tParis Task Manager 2024 V0.0\n\tDeveloped by NL/DC/JM\n\tUNIP-SJC2021\n");
    printf("\n");
    system("pause");
    

    //@nicolas_lobos => a ser implementado
    login();
    menu();
}