#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

//@nicolas_lobos => Arquivo biblioteca para todas as funções utilizadas no main


/// processo para a consulta da agenda de eventos
void cslta_agenda(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para consulta ao resultado de eventos
void cslta_resultado(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para solicitar uma transferencia de alojamento
void slcta_transferencia(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para programar a escala
void prgma_escala(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para adicionar um evento olimpico
void add_evento(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para realizar um evento olimpico
void rlz_evento(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para realizar uma transferencia de alojamento
void rlz_transferencia(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para cadastrar um atleta
void cad_atleta(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para cadastrar um técnico
void cad_tecnico(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para cadastrar um médico
void cad_medico(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para cadastrar admin de sistema e STAFF
void cad_STAFF(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}


///Fun��o para exibir o processo de login
void login(){
	//@nicolas_lobos => a ser desenvolvido
	//declara��o de vari�veis
	char username[200];
	char password[200];
	int usertype;
	int logado;
	int i;
	int k;
	char comparadora_psw_login[1024][200];
	char buffer[1024];
	FILE *f_login;

	//defini��o de valores para login e senha
	logado = 0;
	
	//inicio da fun��o de login
	//abrindo o arquivo de dados do login
	f_login = fopen("login.txt", "r");
	//verifica se a abertura foi concluida com sucesso
	if(!f_login){
		printf("Error:File not found");
		system("pause");
		exit(0);
	}
	//prosseguindo caso sucesso
	else{
		do{
			fflush(stdin);
			printf("\n\nInsira seu usu�rio:\n");
			gets(username);
			printf("\nInsira sua senha:\n");
			gets(password);
			
			strcat(username,password);
			i= 0;
			while(fscanf(f_login,"%s",buffer)==1){
				strcpy(comparadora_psw_login[i],buffer);
				i++;
			}
			for(i=0; i < 5; i++) {
    			if(!(strcmp(comparadora_psw_login[i],username))){
        		printf("encontrei a senha dessa porra FILHA DA PUTA");
				logado=1;
        		break;
    			}
			}

		} while(!logado);
		printf("\n\nSUCESSO\n\n");
		system("pause");
	}
}


///Fun��o para exibir logo do software
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

///Fun��o para criar o menu para usuario STAFF
void menu_staff(){
	
	//@nicolas_lobos => Declaração de variaveis
	int option;
	//@nicolas_lobos => inicio da estrutura de repetição 
	do {
		//@nicolas_lobos => exibição do menu
		printf("\n");
		printf("\tBem vindo, por favor selecione uma op��o abaixo:\n");
		printf("\t================================================\n");
		printf("\t(1) Consultar Agenda\n");
		printf("\t(2) Consultar Resultado\n");
		printf("\t(3) Solicitar Transfer�ncia\n");
		printf("\t(4) Programar Escala\n");
		printf("\t(5) Adicionar Evento\n");
		printf("\t(6) Realizar Evento\n");
		printf("\t(7) Realiza Transfer�ncia\n");
		printf("\t(8) Cadastro de Atleta\n");
		printf("\t(9) Cadastro de T�cnicos\n");
		printf("\t(10) Cadastro de M�dicos\n");
		printf("\t(11) Cadastro de STAFF\n");
		printf("\t(12) SAIR\n\n");
		printf("\tPor gentileza, digite o n�mero da op��o desejada:\n");
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
	//@nicolas_lobos => condi��o de execu��o
	while(option != 3);
}