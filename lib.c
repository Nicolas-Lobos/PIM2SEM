#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

//@nicolas_lobos => Arquivo biblioteca para todas as fun��es utilizadas no main



///processo para a consulta da agenda de eventos (concluido)
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

/// processo para consulta ao resultado de eventos (a revisar remo��o)
void cslta_resultado(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para solicitar uma transferencia de alojamento
void slcta_transferencia(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para programar a escala (a revisar remo��o)
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

/// processo para realizar uma transferencia de alojamento (a revisar remo��o)
void rlz_transferencia(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para cadastrar um atleta
void cad_atleta(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para cadastrar um t�cnico
void cad_tecnico(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para cadastrar um m�dico
void cad_medico(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para cadastrar admin de sistema e STAFF
void cad_STAFF(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para exibir o menu m�dico
void menu_med(){
	printf("em progresso");
}

/// processo para cadastrar usu�rios e gerar suas autentica��es (concluido)
void cad_user(){
	printf("Autentica��o");
		//declara��o de vari�veis
	char username[200];
	char password[200];
	char login_cad[200];
	char password_cad[200];
	int opt_y_n;
	int opt_auth;
	int logado;
	int i;
	int k;
	char comparadora_psw_login[400][200];
	char buffer[200];
	//@nicolas_lobos => declara��o de ponteiros
	FILE *f_auth;
	FILE *f_login;
	//@nicolas_lobos => defini��o de valor para o estado "logado" do usu�rio
	logado = 0;
	
	//@nicolas_lobos => in�cio da fun��o de login
	//@nicolas_lobos => abrindo o arquivo de dados do login
	f_auth = fopen("auth3.txt", "r");
	//@nicolas_lobos => verifica se a abertura foi concluida com sucesso
	if(!f_auth){
		printf("Error:File not found");
		system("pause");
		exit(0);
	}
	//@nicolas_lobos => prosseguindo caso sucesso
	else{
		printf("\nQual ser� o tipo de usu�rio?");
		printf("\n(1)ATLETA");
		printf("\n(2)ADMIN");
		printf("\n(3)M�DICO");
		printf("\n(4)T�CNICO");
		scanf("%d",&opt_auth);
		switch(opt_auth){
			case 1:
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

				while(fscanf(f_auth,"%s",buffer)==1){
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
				printf("Usu�rio n�o autorizado, tente novamente!");
			} while(!logado);
			//@nicolas_lobos => mensagem de sucesso
			
			printf("\n\n\t\aUSU�RIO AUTENTICADO!\n\n");
			system("pause");
			
			f_login = fopen("login.txt", "a");
			
			if(!f_login){
			printf("Error:File not found");
			system("pause");
			exit(0);
			}

			else{
				do{
					fflush(stdin);
					printf("\n\n\tCadastro de Usu�rios do Sistema");
					printf("\n\tUsu�rio TIPO ATLETA");
					printf("\n\tPor favor Insira um login para cadastrar: ");
					gets(login_cad);
					fflush(stdin);
					printf("\n\tPor favor Insira um login para cadastrar: ");
					gets(password_cad);

					strcat(login_cad,password_cad);

					for(i=0; login_cad[i]; i++) {
						putc(login_cad[i],f_login);
					}
					fprintf(f_login,"\n");

					printf("\nCADASTRO EFETUADO COM SUCESSO!\n\n");
					printf("\nDeseja cadastrar outro usu�rio?");
					printf("\n(1)SIM");
					printf("\n(2)N�O\n");
					scanf("%d",&opt_y_n);

				}while(opt_y_n!=2);

			fclose(f_login);
			
			}
			break;

			case 2:
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

				while(fscanf(f_auth,"%s",buffer)==1){
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
			printf("Usu�rio n�o Autorizado, tente novamente!");
			} while(!logado);
			//@nicolas_lobos => mensagem de sucesso
			
			printf("\n\n\t\aUSU�RIO AUTENTICADO!\n\n");
			system("pause");
			
			f_auth = fopen("auth3.txt", "a");
			
			if(!f_auth){
				printf("Error:File not found");
				system("pause");
				exit(0);
			}

			else{
				do{
					fflush(stdin);
					printf("\n\n\tCadastro de Usu�rios do Sistema");
					printf("\n\tUsu�rio TIPO ADMINISTRADOR");
					printf("\n\tPor favor Insira um login para cadastrar: ");
					gets(login_cad);
					fflush(stdin);
					printf("\n\tPor favor Insira uma senha para cadastrar: ");
					gets(password_cad);

					strcat(login_cad,password_cad);

					for(i=0; login_cad[i]; i++) {
						putc(login_cad[i],f_auth);
					}
					fprintf(f_auth,"\n");
					
					f_login = fopen("login.txt","a");
					if(!f_login){
						printf("Error:File not found");
						system("pause");
						exit(0);
					}
					else{
						for(i=0; login_cad[i]; i++) {
						putc(login_cad[i],f_login);
						}
						fprintf(f_login,"\n");
					}
					fclose(f_login);

					printf("\n\tCADASTRO EFETUADO COM SUCESSO!\n\n");
					printf("\n\tDeseja cadastrar outro usu�rio?");
					printf("\n\t(1)SIM");
					printf("\n\t(2)N�O\n");
					scanf("%d",&opt_y_n);

				}while(opt_y_n!=2);

			fclose(f_auth);
			
			}
			break;

			case 3:
			do{
				//@nicolas_lobos => flush pra evitar erro de teclado
				fflush(stdin);
				printf("\n\n\tInsira seu usu�rio:\n");
				gets(username);
				fflush(stdin);
				printf("\n\tInsira sua senha:\n");
				gets(password);
				
				//@nicolas_lobos => junta a string password com a string username
				strcat(username,password);
				
				i= 0;
				
				/*@nicolas_lobos =>
				copia todas as strings do arquivo 
				login.txt para uma matriz de compara��o*/

				while(fscanf(f_auth,"%s",buffer)==1){
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
			printf("Usu�rio n�o Autorizado, tente novamente!");
			} while(!logado);
			//@nicolas_lobos => mensagem de sucesso
			
			printf("\n\n\t\aUSU�RIO AUTENTICADO!\n\n");
			system("pause");
			
			f_auth = fopen("auth1.txt", "a");
			
			if(!f_auth){
				printf("Error:File not found");
				system("pause");
				exit(0);
			}

			else{
				do{
					fflush(stdin);
					printf("\n\n\tCadastro de Usu�rios do Sistema");
					printf("\n\tUsu�rio TIPO M�DICO");
					printf("\n\tPor favor Insira um login para cadastrar: ");
					gets(login_cad);
					fflush(stdin);
					printf("\n\tPor favor Insira uma senha para cadastrar: ");
					gets(password_cad);

					strcat(login_cad,password_cad);

					for(i=0; login_cad[i]; i++) {
						putc(login_cad[i],f_auth);
					}
					fprintf(f_auth,"\n");
					
					f_login = fopen("login.txt","a");
					if(!f_login){
						printf("Error:File not found");
						system("pause");
						exit(0);
					}
					else{
						for(i=0; login_cad[i]; i++) {
						putc(login_cad[i],f_login);
						}
						fprintf(f_login,"\n");
					}
					fclose(f_login);

					printf("\n\tCADASTRO EFETUADO COM SUCESSO!\n\n");
					printf("\n\tDeseja cadastrar outro usu�rio?");
					printf("\n\t(1)SIM");
					printf("\n\t(2)N�O\n");
					scanf("\t%d",&opt_y_n);

				}while(opt_y_n!=2);

			fclose(f_auth);
			
			}
			break;

			case 4:
			do{
				//@nicolas_lobos => flush pra evitar erro de teclado
				fflush(stdin);
				printf("\n\n\tInsira seu usu�rio:\n");
				gets(username);
				fflush(stdin);
				printf("\n\tInsira sua senha:\n");
				gets(password);
				
				//@nicolas_lobos => junta a string password com a string username
				strcat(username,password);
				
				i= 0;
				
				/*@nicolas_lobos =>
				copia todas as strings do arquivo 
				login.txt para uma matriz de compara��o*/

				while(fscanf(f_auth,"%s",buffer)==1){
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
			printf("Usu�rio n�o Autorizado, tente novamente!");
			} while(!logado);
			//@nicolas_lobos => mensagem de sucesso
			
			printf("\n\n\t\aUSU�RIO AUTENTICADO!\n\n");
			system("pause");
			
			f_auth = fopen("auth2.txt", "a");
			
			if(!f_auth){
				printf("Error:File not found");
				system("pause");
				exit(0);
			}

			else{
				do{
					fflush(stdin);
					printf("\n\n\tCadastro de Usu�rios do Sistema");
					printf("\n\tUsu�rio TIPO T�CNICO");
					printf("\n\tPor favor Insira um login para cadastrar: ");
					gets(login_cad);
					fflush(stdin);
					printf("\n\tPor favor Insira uma senha para cadastrar: ");
					gets(password_cad);

					strcat(login_cad,password_cad);

					for(i=0; login_cad[i]; i++) {
						putc(login_cad[i],f_auth);
					}
					fprintf(f_auth,"\n");
					
					f_login = fopen("login.txt","a");
					if(!f_login){
						printf("Error:File not found");
						system("pause");
						exit(0);
					}
					else{
						for(i=0; login_cad[i]; i++) {
						putc(login_cad[i],f_login);
						}
						fprintf(f_login,"\n");
					}
					fclose(f_login);

					printf("\n\tCADASTRO EFETUADO COM SUCESSO!\n\n");
					printf("\n\tDeseja cadastrar outro usu�rio?");
					printf("\n\t(1)SIM");
					printf("\n\t(2)N�O\n");
					scanf("\t%d",&opt_y_n);

				}while(opt_y_n!=2);

			fclose(f_auth);
			
			}
			break;

			default:
			printf("\n\tOP��O INV�LIDA");
			break;
		}
	}
	system("pause");
}

///Fun��o para exibir o processo de login (concluido)
void login(){
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
		printf("Usu�rio/Senha Inv�lidos, tente novamente!");
		} while(!logado);
		//@nicolas_lobos => mensagem de sucesso
		printf("\n\n\t\aLOGIN EFETUADO COM SUCESSO!\n\n");
		system("pause");
	}
}

///Fun��o para exibir logo do software (concluido)
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

///Fun��o para criar o menu para usuario STAFF (concluido)
void menu(){
	
	//@nicolas_lobos => Declara��o de vari�veis
	int option_menu;
	//@nicolas_lobos => in�cio da estrutura de repeti��o 
	do {
		//@nicolas_lobos => exibi��o do menu
		printf("\n\a");
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
		printf("\t(12) Cadastro de usu�rio\n");
		printf("\t(13) �rea M�dica\n");
		printf("\t(14) SAIR\n\n");
		printf("\tPor gentileza, digite o n�mero da op��o desejada:\n");
		//@nicolas_lobos => leitura do input do usuario
		scanf("\t%d", &option_menu);
		//@nicolas_lobos => inicio da estrutura de condi��o
		switch (option_menu) {
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

			case 12:
			cad_user();

			case 13:
			menu_med();
			break;

			default:
			printf("Op��o inv�lida! Tente novamente");
			break;
		}
		option_menu=NULL;
	}
	//@nicolas_lobos => condi��o de execu��o
	while(option_menu != 14);
}