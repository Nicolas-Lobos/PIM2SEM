#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

//@nicolas_lobos => Arquivo biblioteca para todas as fun��es utilizadas no main


///processo para a consulta da agenda de eventos
void cslta_agenda(){
	//@nicolas_lobos => declara��o de vari�veis
	char buffer[1024];
	//@nicolas_lobos => declara��o de ponteiros
	FILE *agenda_jogos;
	
	agenda_jogos = fopen("agenda_jogos.txt", "r");
	//@nicolas_lobos => verifica se a abertura foi concluida com sucesso
	if(!agenda_jogos){
		printf("Error:File not found");
		system("pause");
		exit(0);
	}
	//@nicolas_lobos => prosseguindo caso sucesso
	else{
		//@nicolas_lobos => exibindo as informa��es da agenda de jogos
		printf("\n\tAGENDA OL�MPICA");
		while(fscanf(agenda_jogos,"%s",buffer)==1){
			printf("\n\t%s\n",buffer);
		}
		system("pause");
	}
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

void cad_user(){
	printf("em progresso");
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
	char comparadora_psw_login[400][200];
	char buffer[200];
	//@nicolas_lobos => declara��o de ponteiros
	FILE *f_login;

	//@nicolas_lobos => defini��o de valor para o estado "logado" do usu�rio
	logado = 0;
	
	//@nicolas_lobos => in�cio da fun��o de login
	//@nicolas_lobos => abrindo o arquivo de dados do login
	f_login = fopen("login.txt", "r");
	//@nicolas_lobos => verifica se a abertura foi concluida com sucesso
	if(!f_login){
		printf("Error:File not found");
		system("pause");
		exit(0);
	}
	//@nicolas_lobos => prosseguindo caso sucesso
	else{
		do{
			//@nicolas_lobos => flush pra evitar erro de teclado
			fflush(stdin);
			printf("\n\nInsira seu usu�rio:\n");
			gets(username);
			fflush(stdin);
			printf("\nInsira sua senha:\n");
			gets(password);
			
			//@nicolas_lobos => junta a string password com a string username
			strcat(username,password);
			
			i= 0;
			
			/*@nicolas_lobos =>
			copia todas as strings do arquivo 
			login.txt para uma matriz de compara��o*/

			while(fscanf(f_login,"%s",buffer)==1){
				strcpy(comparadora_psw_login[i],buffer);
				i++;
			}
			
			/*@nicolas_lobos =>
			compara o username concatenado, com as strings
			armazenadas na matriz comparadora*/

			for(k=0; k<=400; k++) {
    			/*@nicolas_lobos =>
				Se um usuario e senha correspondente
				for encontrado, para o la�o for*/
				
				if(!(strcmp(comparadora_psw_login[k],username))){
        		
				/*@nicolas_lobos =>
				a linha abaixo serve de teste para 
				confirmar se encontrou uma correspond�ncia
				printf("encontrei a senha");*/
				logado=1;
        		break;
    			}
			}

		} while(!logado);
		//@nicolas_lobos => mensagem de sucesso
		printf("\n\n\tLOGIN EFETUADO COM SUCESSO!\n\n");
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
	
	//@nicolas_lobos => Declara��o de vari�veis
	int option;
	//@nicolas_lobos => in�cio da estrutura de repeti��o 
	do {
		//@nicolas_lobos => exibi��o do menu
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
		//@nicolas_lobos => inicio da estrutura de condi��o
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
		
	//@nicolas_lobos => Declara��o de variaveis
	int option;
	//@nicolas_lobos => inicio da estrutura de repeti��o 
	do {
		//@nicolas_lobos => exibi��o do menu
		printf("\n");
		printf("Bem vindo, por favor selecione uma opção abaixo:\n");
		printf("(1) Consultar Agenda\n");
		printf("(2) Consultar Resultado\n");
		printf("(3) SAIR");
		printf("Por gentileza, digite o número da opção desejada:\n");
		//@nicolas_lobos => leitura do input do usuario
		scanf("%d", &option);
		//@nicolas_lobos => inicio da estrutura de condi��o
		switch (option) {
			case 1:
			cslta_agenda();
			break;
			
			case 2:
			cslta_resultado();
			break;
			
			default:
			printf("Op��o inv�lida! Tente novamente");
			break;
		}

	}
	//@nicolas_lobos => condi��o de execu��o
	while(option != 3);
}