#include <conio.h>
#include <stdio.h>
#include "opening_logo.c"
#include "login.c"




main(){
    
    //@nicolas_lobos => a função abaixo chama o design de inicio
    opening_logo();
    printf("\n\n    Pressione qualquer tecla para continuar...");
    getch();
    printf("\n");
    printf("    Paris Task Manager 2024 V0.0\n  Developed by NL/DC/JM ");
    printf("\n");
    printf("    Pressione qualquer tecla para fazer login...");
    getch();

    //@nicolas_lobos => a função abaixo lança a tela de Login
    //@nicolas_lobos => a ser implementado = 
    login();




}