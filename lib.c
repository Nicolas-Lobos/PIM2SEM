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
	
	agenda_jogos = fopen("query_files\\agenda_jogos.txt", "r");
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

/// processo para programar a escala
void prgma_escala(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para adicionar um evento olimpico (concluido)
void add_evento(){
	setlocale(LC_ALL, "Portuguese");
	printf("Autentica��o");
	//declara��o de vari�veis
	char username[200];
	char password[200];
	char modalidade[200];
	char data[200];
	int opt_y_n;
	int opt_auth;
	int logado;
	int i;
	int k;
	char comparadora_psw_login[400][200];
	char buffer[200];
	//@nicolas_lobos => declara��o de ponteiros
	FILE *f_auth;
	FILE *f_jogos;
	//@nicolas_lobos => defini��o de valor para o estado "logado" do usu�rio
	logado = 0;
	
	//@nicolas_lobos => in�cio da fun��o de login
	//@nicolas_lobos => abrindo o arquivo de dados do login
	f_auth = fopen("auth_files\\auth_adm.txt", "r");
	//@nicolas_lobos => verifica se a abertura foi concluida com sucesso
	if(!f_auth){
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
			auth_adm
 			para uma matriz de compara��o*/
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
		//@nicolas_lobos => abre o arquivo de login para salvar novo usu�rio
		f_jogos = fopen("query_files\\agenda_jogos.txt", "a");
		//@nicolas_lobos => caso n�o encontre ou falhe
		if(!f_jogos){
		printf("Error:File not found");
		system("pause");
		exit(0);
		}
		//@nicolas_lobos => se sucesso
		else{
			//@nicolas_lobos => estrutura de repeti��o para cadastro do evento
			do{
				// exibi��o do nome da atividade
				printf("\n\tAGENDAMENTO DE EVENTOS OLIMPICOS\n");
				printf("\t=================================\n");
				//@nicolas_lobos => solicita��o de input do usu�rio
				fflush(stdin);
				printf("\tPor gentileza insira a modalidade do esporte:\n\t");
				gets(modalidade);
				fflush(stdin);
				printf("\n\tPor gentileza insira a data no padr�o DD/MM/YYYY:\n\t");
				gets(data);
				fflush(stdin);
				//@nicolas_lobos => escrevendo a modalidade no arquivo agenda_jogos.txt
				for(i=0; modalidade[i]; i++){
					putc(modalidade[i], f_jogos);
				}
				// @nicolas_lobos => adicionando espa�o em branco
				fprintf(f_jogos, "\n");
				// @nicolas_lobos => adicionando a data do evento no arquvio agenda_jogos.txt
				for(i=0; data[i]; i++){
					putc(data[i], f_jogos);
				}
				fprintf(f_jogos, "\n");
				// nicolas_lobos => mensagem de sucesso e an�lise da repeti��o
				printf("\n\tCADASTRO REALIZADO COM SUCESSO\a, \n\tDESEJA MARCAR OUTRO EVENTO?");
				printf("\n\t(1)SIM\n");
				printf("\n\t(2)N�O\n\t");
				scanf("%d", &opt_y_n);
			}while(opt_y_n !=2);
		}
	}
}

/// processo para realizar um evento olimpico
void rlz_evento(){
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
	setlocale(LC_ALL, "Portuguese");
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
	f_auth = fopen("auth_files\\auth_adm.txt", "r");
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
		//@nicolas_lobos => la�o de decis�o para o tipo de usu�rio
		switch(opt_auth){
			//@nicolas_lobos => usu�rio do tipo atleta
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
				auth_adm
 para uma matriz de compara��o*/

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
			//@nicolas_lobos => abre o arquivo de login para salvar novo usu�rio
			f_login = fopen("auth_files\\login.txt", "a");
			//@nicolas_lobos => caso n�o encontre ou falhe
			if(!f_login){
			printf("Error:File not found");
			system("pause");
			exit(0);
			}
			//@nicolas_lobos => se sucesso
			else{
				//@nicolas_lobos => la�o de repeti��o para cadastro
				do{
					//flush para evitar erro de buffer de teclado
					fflush(stdin);
					/*@nicolas_lobos => informa��o sobre o tipo de cadastro
					e solicita��o de input das informa��es a serem registradas*/
					printf("\n\n\tCadastro de Usu�rios do Sistema");
					printf("\n\tUsu�rio TIPO ATLETA");
					printf("\n\tPor favor Insira um login para cadastrar: ");
					gets(login_cad);
					fflush(stdin);
					printf("\n\tPor favor Insira um login para cadastrar: ");
					gets(password_cad);
					// @nicolas_lobos => concatena��o para salvar o registro
					strcat(login_cad,password_cad);
					//@nicolas_lobos => salvando em arquivo a informa��o de login
					for(i=0; login_cad[i]; i++) {
						putc(login_cad[i],f_login);
					}
					fprintf(f_login,"\n");
					//@nicolas_lobos => mensagem de sucesso
					printf("\nCADASTRO EFETUADO COM SUCESSO!\n\n");
					printf("\nDeseja cadastrar outro usu�rio?");
					printf("\n(1)SIM");
					printf("\n(2)N�O\n\t");
					//@nicolas_lobos => op��o de escolha para novo cadastro
					scanf("%d",&opt_y_n);

				}while(opt_y_n!=2);
			// fechamento do arquivo de login
			fclose(f_login);
			
			}
			break;
			//@nicolas_lobos => usu�rio do tipo admnistrador
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
			// abertura do arquivo auth_adm para salvar o novo usu�rio
			f_auth = fopen("auth_files\\auth_adm.txt", "a");
			
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
					
					f_login = fopen("auth_files\\login.txt","a");
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
					printf("\n\t(2)N�O\n\t");
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
			
			f_auth = fopen("auth_files\\auth_med.txt", "a");
			
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
					
					f_login = fopen("auth_files\\login.txt","a");
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
					printf("\n\t(2)N�O\n\t");
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
			
			f_auth = fopen("auth_files\\auth_tec.txt", "a");
			
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
					
					f_login = fopen("auth_files\\login.txt","a");
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
					printf("\n\t(2)N�O\n\t");
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
	setlocale(LC_ALL, "Portuguese");
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
	f_login = fopen("auth_files\\login.txt", "r");
	//@nicolas_lobos => verifica se a abertura foi concluida com sucesso
	if(!f_login){
		printf("Error:File not found");
		system("pause");
		exit(0);
	}
	//@nicolas_lobos => prosseguindo caso sucesso
	else{int x = 4;
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
			//contador de tentativas de login
			x = x-1;
			if(!logado) {
			printf("\nUsu�rio/Senha Inv�lidos, tente novamente!\n");
			printf("Restam %d tentativas.\n",x);
			}
			// se excedido o limite de tentativas, encerra a tela de login
			if(x == 0) {exit(0);}
		} while(!logado);
		//@nicolas_lobos => mensagem de sucesso
		printf("\n\n\t\aLOGIN EFETUADO COM SUCESSO!\n\n");
		system("pause");
	}
}

///Fun��o para exibir logo do software (concluido)
void opening_logo(){
	setlocale(LC_ALL, "Portuguese");
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

///Fun��o para criar o menu para usuario (concluido)
void menu(){
	setlocale(LC_ALL, "Portuguese");
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
		printf("\t(3) Programar Escala\n");
		printf("\t(4) Adicionar Evento\n");
		printf("\t(5) Realizar Evento\n");
		printf("\t(6) Cadastro de Atleta\n");
		printf("\t(7) Cadastro de T�cnicos\n");
		printf("\t(8) Cadastro de M�dicos\n");
		printf("\t(9) Cadastro de STAFF\n");
		printf("\t(10) Cadastro de usu�rio\n");
		printf("\t(11) �rea M�dica\n");
		printf("\t(12) SAIR\n\n");
		printf("\tPor gentileza, digite o n�mero da op��o desejada:\n\t");
		//@nicolas_lobos => leitura do input do usuario
		scanf("%d", &option_menu);
		/*@nicolas_lobos => inicio da estrutura de condi��o
		cada uma das op��es abaixo referencia uma fun��o acima */
		switch (option_menu) {
			case 1:
			cslta_agenda();
			break;
			
			case 2:
			cslta_resultado();
			break;

			case 3:
			prgma_escala();
			break;

			case 4:
			add_evento();
			break;

			case 5:
			rlz_evento();
			break;

			case 6:
			cad_atleta();
			break;

			case 7:
			cad_tecnico();
			break;

			case 8:
			cad_medico();
			break;

			case 9:
			cad_STAFF();
			break;

			case 10:
			cad_user();

			case 11:
			menu_med();
			break;

			default:
			printf("Op��o inv�lida! Tente novamente");
			break;
		}
		
	}
	//@nicolas_lobos => condi��o de execu��o
	while(option_menu != 12);
}