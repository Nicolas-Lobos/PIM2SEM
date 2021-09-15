#include <conio.h>
#include <stdio.h>
#include <locale.h>

//@nicolas_lobos => Arquivo biblioteca para todas as funções utilizadas no main


/// processo para a consulta da agenda de eventos
void cslta_agenda(){
    //@nicolas_lobos => a ser desenvolvido
}

/// processo para consulta ao resultado de eventos
void cslta_resultado(){
    //@nicolas_lobos => a ser desenvolvido
}

/// processo para solicitar uma transferencia de alojamento
void slcta_transferencia(){
    //@nicolas_lobos => a ser desenvolvido
}

/// processo para programar a escala
void prgma_escala(){
    //@nicolas_lobos => a ser desenvolvido
}

/// processo para adicionar um evento olimpico
void add_evento(){
    //@nicolas_lobos => a ser desenvolvido
}

/// processo para realizar um evento olimpico
void rlz_evento(){
    //@nicolas_lobos => a ser desenvolvido
}

/// processo para realizar uma transferencia de alojamento
void rlz_transferencia(){
    //@nicolas_lobos => a ser desenvolvido
}

/// processo para cadastrar um atleta
void cad_atleta(){
    //@nicolas_lobos => a ser desenvolvido
}

/// processo para cadastrar um técnico
void cad_tecnico(){
    //@nicolas_lobos => a ser desenvolvido
}

/// processo para cadastrar um médico
void cad_medico(){
    //@nicolas_lobos => a ser desenvolvido
}

/// processo para cadastrar admin de sistema e STAFF
void cad_STAFF(){
    //@nicolas_lobos => a ser desenvolvido
}


///Função para exibir o processo de login
void login(){
    //@nicolas_lobos => a ser desenvolvido
    

}

///Função para exibir logo do software
void opening_logo(){

printf("    PARISPARISPARIS           PARISPARISPARISPARIS      PARISPARISPARIS           PARIS      PARISPARISPARISPARIS\n");
printf("    PARISPARISPARISPARIS      PARISPARISPARISPARIS      PARISPARISPARISPARIS      PARIS      PARISPARISPARISPARIS\n");
printf("    PARISPARISPARISPARIS      PARISPARISPARISPARIS      PARISPARISPARISPARIS      PARIS      PARISPARISPARISPARIS\n");
printf("    PARIS          PARIS      PARIS          PARIS      PARIS          PARIS      PARIS      PARIS\n");
printf("    PARIS          PARIS      PARIS          PARIS      PARIS          PARIS      PARIS      PARIS\n");
printf("    PARIS          PARIS      PARIS          PARIS      PARIS          PARIS      PARIS      PARIS\n");
printf("    PARIS          PARIS      PARIS          PARIS      PARIS          PARIS      PARIS      PARIS\n");
printf("    PARISPARISPARISPARIS      PARIS          PARIS      PARISPARISPARISPARIS      PARIS      PARIS\n");
printf("    PARISPARISPARISPARIS      PARIS          PARIS      PARISPARISPARISPARIS      PARIS      PARISPARISPARISPARIS\n");
printf("    PARISPARISPARIS           PARISPARISPARISPARIS      PARISPARISPARIS           PARIS      PARISPARISPARISPARIS\n");
printf("    PARIS                     PARISPARISPARISPARIS      PARIS       PARIS         PARIS      PARISPARISPARISPARIS\n");
printf("    PARIS                     PARISPARISPARISPARIS      PARIS          PARIS      PARIS                     PARIS\n");
printf("    PARIS                     PARIS          PARIS      PARIS          PARIS      PARIS                     PARIS\n");
printf("    PARIS                     PARIS          PARIS      PARIS          PARIS      PARIS                     PARIS\n");
printf("    PARIS                     PARIS          PARIS      PARIS          PARIS      PARIS                     PARIS\n");
printf("    PARIS                     PARIS          PARIS      PARIS          PARIS      PARIS      PARISPARISPARISPARIS\n");
printf("    PARIS                     PARIS          PARIS      PARIS          PARIS      PARIS      PARISPARISPARISPARIS\n");
printf("    PARIS                     PARIS          PARIS      PARIS          PARIS      PARIS      PARISPARISPARISPARIS\n");
printf("\n");
printf("\n");
printf("\n");
printf("    PARISPARISPARISPARIS        PARISPARISPARISPARIS        PARISPARISPARISPARIS             PARIS          PARIS\n");
printf("    PARISPARISPARISPARIS        PARISPARISPARISPARIS        PARISPARISPARISPARIS             PARIS          PARIS\n");
printf("    PARISPARISPARISPARIS        PARISPARISPARISPARIS        PARISPARISPARISPARIS             PARIS          PARIS\n");
printf("                   PARIS        PARIS          PARIS                       PARIS             PARIS          PARIS\n");
printf("                   PARIS        PARIS          PARIS                       PARIS             PARIS          PARIS\n");
printf("                   PARIS        PARIS          PARIS                       PARIS             PARIS          PARIS\n");
printf("                   PARIS        PARIS          PARIS                       PARIS             PARIS          PARIS\n");
printf("                   PARIS        PARIS          PARIS                       PARIS             PARIS          PARIS\n");
printf("                   PARIS        PARIS          PARIS                       PARIS             PARIS          PARIS\n");
printf("    PARISPARISPARISPARIS        PARIS          PARIS        PARISPARISPARISPARIS             PARISPARISPARISPARIS\n");
printf("    PARISPARISPARISPARIS        PARIS          PARIS        PARISPARISPARISPARIS             PARISPARISPARISPARIS\n");
printf("    PARISPARISPARISPARIS        PARIS          PARIS        PARISPARISPARISPARIS             PARISPARISPARISPARIS\n");
printf("    PARIS                       PARIS          PARIS        PARIS                                           PARIS\n");
printf("    PARIS                       PARIS          PARIS        PARIS                                           PARIS\n");
printf("    PARIS                       PARIS          PARIS        PARIS                                           PARIS\n");
printf("    PARIS                       PARIS          PARIS        PARIS                                           PARIS\n");
printf("    PARIS                       PARIS          PARIS        PARIS                                           PARIS\n");
printf("    PARISPARISPARISPARIS        PARISPARISPARISPARIS        PARISPARISPARISPARIS                            PARIS\n");
printf("    PARISPARISPARISPARIS        PARISPARISPARISPARIS        PARISPARISPARISPARIS                            PARIS\n");
printf("    PARISPARISPARISPARIS        PARISPARISPARISPARIS        PARISPARISPARISPARIS                            PARIS\n");
}

///Função para criar o menu para usuario STAFF
void menu_staff(){
    
    //@nicolas_lobos => Declaração de variaveis
    int option;
    //@nicolas_lobos => inicio da estrutura de repetição 
    do {
        //@nicolas_lobos => exibição do menu
        printf("\n");
        printf("Bem vindo, por favor selecione uma opção abaixo:\n");
        printf("(1) Consultar Agenda\n");
        printf("(2) Consultar Resultado\n");
        printf("(3) Solicitar Transferência\n");
        printf("(4) Programar Escala\n");
        printf("(5) Adicionar Evento\n");
        printf("(6) Realizar Evento\n");
        printf("(7) Realiza Transferência\n");
        printf("(8) Cadastro de Atleta\n");
        printf("(9) Cadastro de Técnicos\n");
        printf("(10) Cadastro de Médicos\n");
        printf("(11) Cadastro de STAFF\n");
        printf("(12) SAIR");
        printf("Por gentileza, digite o número da opção desejada:\n");
        //@nicolas_lobos => leitura do input do usuario
        scanf("%d", &option);
        //@nicolas_lobos => inicio da estrutura de condição
        switch (option) {
            case 1:
            cslta_agenda();
            break;
            
            case 2:
            cslta_resultado();
            break;

            case 3:
            slcta_transferencia();
            break;

            case 4:
            prgma_escala();
            break;

            case 5:
            add_evento();
            break;

            case 6:
            rlz_evento();
            break;

            case 7:
            rlz_transferencia();
            break;

            case 8:
            cad_atleta();
            break;

            case 9:
            cad_tecnico();
            break;

            case 10:
            cad_medico();
            break;

            case 11:
            cad_STAFF();
            break;

            default:
            printf("Opção invalida! Tente novamente");
            break;
        }

    }
    //@nicolas_lobos => condição de execução
    while(option != 12);
}


void menu_atleta(){
        
    //@nicolas_lobos => Declaração de variaveis
    int option;
    //@nicolas_lobos => inicio da estrutura de repetição 
    do {
        //@nicolas_lobos => exibição do menu
        printf("\n");
        printf("Bem vindo, por favor selecione uma opção abaixo:\n");
        printf("(1) Consultar Agenda\n");
        printf("(2) Consultar Resultado\n");
        printf("(3) SAIR");
        printf("Por gentileza, digite o número da opção desejada:\n");
        //@nicolas_lobos => leitura do input do usuario
        scanf("%d", &option);
        //@nicolas_lobos => inicio da estrutura de condição
        switch (option) {
            case 1:
            cslta_agenda();
            break;
            
            case 2:
            cslta_resultado();
            break;
            
            default:
            printf("Opção invalida! Tente novamente");
            break;
        }

    }
    //@nicolas_lobos => condição de execução
    while(option != 3);
}