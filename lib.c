#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

//@nicolas_lobos => Arquivo biblioteca para todas as funções utilizadas no main



///processo para a consulta da agenda de eventos (concluido)
void cslta_agenda(){
	//@nicolas_lobos => declaração de variáveis
	char buffer[1024];
	//@nicolas_lobos => declaração de ponteiros
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
		//@nicolas_lobos => exibindo as informações da agenda de jogos
		printf("\n\tAGENDA OLÍMPICA");
		while(fscanf(agenda_jogos,"%s",buffer)==1){
			printf("\n\t%s\n",buffer);
		}
		system("pause");
	}
}

/// processo para consulta ao resultado de eventos (a revisar remoção)
void cslta_resultado(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para solicitar uma transferencia de alojamento
void slcta_transferencia(){
	printf("em progresso");
	//@nicolas_lobos => a ser desenvolvido
}

/// processo para programar a escala (a revisar remoção)
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

/// processo para realizar uma transferencia de alojamento (a revisar remoção)
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

/// processo para exibir o menu médico
void menu_med(){
	printf("em progresso");
}

/// processo para cadastrar usuários e gerar suas autenticações (concluido)
void cad_user(){
	printf("Autenticação");
		//declaração de variáveis
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
	//@nicolas_lobos => declaração de ponteiros
	FILE *f_auth;
	FILE *f_login;
	//@nicolas_lobos => definição de valor para o estado "logado" do usuário
	logado = 0;
	
	//@nicolas_lobos => início da função de login
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
		printf("\nQual será o tipo de usuário?");
		printf("\n(1)ATLETA");
		printf("\n(2)ADMIN");
		printf("\n(3)MÉDICO");
		printf("\n(4)TÉCNICO");
		scanf("%d",&opt_auth);
		switch(opt_auth){
			case 1:
			do{
				//@nicolas_lobos => flush pra evitar erro de teclado
				fflush(stdin);
				printf("\n\nInsira seu usuário:\n");
				gets(username);
				fflush(stdin);
				printf("\nInsira sua senha:\n");
				gets(password);
				
				//@nicolas_lobos => junta a string password com a string username
				strcat(username,password);
				
				i= 0;
				
				/*@nicolas_lobos =>
				copia todas as strings do arquivo 
				login.txt para uma matriz de comparação*/

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
					for encontrado, para o laço for*/
					
					if(!(strcmp(comparadora_psw_login[k],username))){
					
					/*@nicolas_lobos =>
					a linha abaixo serve de teste para 
					confirmar se encontrou uma correspondência
					printf("encontrei a senha");*/
					logado=1;
					break;
					}
				}
				printf("Usuário não autorizado, tente novamente!");
			} while(!logado);
			//@nicolas_lobos => mensagem de sucesso
			
			printf("\n\n\t\aUSUÁRIO AUTENTICADO!\n\n");
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
					printf("\n\n\tCadastro de Usuários do Sistema");
					printf("\n\tUsuário TIPO ATLETA");
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
					printf("\nDeseja cadastrar outro usuário?");
					printf("\n(1)SIM");
					printf("\n(2)NÃO\n");
					scanf("%d",&opt_y_n);

				}while(opt_y_n!=2);

			fclose(f_login);
			
			}
			break;

			case 2:
			do{
				//@nicolas_lobos => flush pra evitar erro de teclado
				fflush(stdin);
				printf("\n\nInsira seu usuário:\n");
				gets(username);
				fflush(stdin);
				printf("\nInsira sua senha:\n");
				gets(password);
				
				//@nicolas_lobos => junta a string password com a string username
				strcat(username,password);
				
				i= 0;
				
				/*@nicolas_lobos =>
				copia todas as strings do arquivo 
				login.txt para uma matriz de comparação*/

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
					for encontrado, para o laço for*/
					
					if(!(strcmp(comparadora_psw_login[k],username))){
					
					/*@nicolas_lobos =>
					a linha abaixo serve de teste para 
					confirmar se encontrou uma correspondência
					printf("encontrei a senha");*/
					logado=1;
					break;
					}
				}
			printf("Usuário não Autorizado, tente novamente!");
			} while(!logado);
			//@nicolas_lobos => mensagem de sucesso
			
			printf("\n\n\t\aUSUÁRIO AUTENTICADO!\n\n");
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
					printf("\n\n\tCadastro de Usuários do Sistema");
					printf("\n\tUsuário TIPO ADMINISTRADOR");
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
					printf("\n\tDeseja cadastrar outro usuário?");
					printf("\n\t(1)SIM");
					printf("\n\t(2)NÃO\n");
					scanf("%d",&opt_y_n);

				}while(opt_y_n!=2);

			fclose(f_auth);
			
			}
			break;

			case 3:
			do{
				//@nicolas_lobos => flush pra evitar erro de teclado
				fflush(stdin);
				printf("\n\n\tInsira seu usuário:\n");
				gets(username);
				fflush(stdin);
				printf("\n\tInsira sua senha:\n");
				gets(password);
				
				//@nicolas_lobos => junta a string password com a string username
				strcat(username,password);
				
				i= 0;
				
				/*@nicolas_lobos =>
				copia todas as strings do arquivo 
				login.txt para uma matriz de comparação*/

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
					for encontrado, para o laço for*/
					
					if(!(strcmp(comparadora_psw_login[k],username))){
					
					/*@nicolas_lobos =>
					a linha abaixo serve de teste para 
					confirmar se encontrou uma correspondência
					printf("encontrei a senha");*/
					logado=1;
					break;
					}
				}
			printf("Usuário não Autorizado, tente novamente!");
			} while(!logado);
			//@nicolas_lobos => mensagem de sucesso
			
			printf("\n\n\t\aUSUÁRIO AUTENTICADO!\n\n");
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
					printf("\n\n\tCadastro de Usuários do Sistema");
					printf("\n\tUsuário TIPO MÉDICO");
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
					printf("\n\tDeseja cadastrar outro usuário?");
					printf("\n\t(1)SIM");
					printf("\n\t(2)NÃO\n");
					scanf("\t%d",&opt_y_n);

				}while(opt_y_n!=2);

			fclose(f_auth);
			
			}
			break;

			case 4:
			do{
				//@nicolas_lobos => flush pra evitar erro de teclado
				fflush(stdin);
				printf("\n\n\tInsira seu usuário:\n");
				gets(username);
				fflush(stdin);
				printf("\n\tInsira sua senha:\n");
				gets(password);
				
				//@nicolas_lobos => junta a string password com a string username
				strcat(username,password);
				
				i= 0;
				
				/*@nicolas_lobos =>
				copia todas as strings do arquivo 
				login.txt para uma matriz de comparação*/

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
					for encontrado, para o laço for*/
					
					if(!(strcmp(comparadora_psw_login[k],username))){
					
					/*@nicolas_lobos =>
					a linha abaixo serve de teste para 
					confirmar se encontrou uma correspondência
					printf("encontrei a senha");*/
					logado=1;
					break;
					}
				}
			printf("Usuário não Autorizado, tente novamente!");
			} while(!logado);
			//@nicolas_lobos => mensagem de sucesso
			
			printf("\n\n\t\aUSUÁRIO AUTENTICADO!\n\n");
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
					printf("\n\n\tCadastro de Usuários do Sistema");
					printf("\n\tUsuário TIPO TÉCNICO");
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
					printf("\n\tDeseja cadastrar outro usuário?");
					printf("\n\t(1)SIM");
					printf("\n\t(2)NÃO\n");
					scanf("\t%d",&opt_y_n);

				}while(opt_y_n!=2);

			fclose(f_auth);
			
			}
			break;

			default:
			printf("\n\tOPÇÃO INVÁLIDA");
			break;
		}
	}
	system("pause");
}

///Função para exibir o processo de login (concluido)
void login(){
		//declaração de variáveis
	char username[200];
	char password[200];
	int usertype;
	int logado;
	int i;
	int k;
	char comparadora_psw_login[400][200];
	char buffer[200];
	//@nicolas_lobos => declaração de ponteiros
	FILE *f_login;

	//@nicolas_lobos => definição de valor para o estado "logado" do usuário
	logado = 0;
	
	//@nicolas_lobos => início da função de login
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
			printf("\n\nInsira seu usuário:\n");
			gets(username);
			fflush(stdin);
			printf("\nInsira sua senha:\n");
			gets(password);
			
			//@nicolas_lobos => junta a string password com a string username
			strcat(username,password);
			
			i= 0;
			
			/*@nicolas_lobos =>
			copia todas as strings do arquivo 
			login.txt para uma matriz de comparação*/

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
				for encontrado, para o laço for*/
				
				if(!(strcmp(comparadora_psw_login[k],username))){
        		
				/*@nicolas_lobos =>
				a linha abaixo serve de teste para 
				confirmar se encontrou uma correspondência
				printf("encontrei a senha");*/
				logado=1;
        		break;
    			}
			}
		printf("Usuário/Senha Inválidos, tente novamente!");
		} while(!logado);
		//@nicolas_lobos => mensagem de sucesso
		printf("\n\n\t\aLOGIN EFETUADO COM SUCESSO!\n\n");
		system("pause");
	}
}

///Função para exibir logo do software (concluido)
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

///Função para criar o menu para usuario STAFF (concluido)
void menu(){
	
	//@nicolas_lobos => Declaração de variáveis
	int option_menu;
	//@nicolas_lobos => início da estrutura de repetição 
	do {
		//@nicolas_lobos => exibição do menu
		printf("\n\a");
		printf("\tBem vindo, por favor selecione uma opção abaixo:\n");
		printf("\t================================================\n");
		printf("\t(1) Consultar Agenda\n");
		printf("\t(2) Consultar Resultado\n");
		printf("\t(3) Solicitar Transferência\n");
		printf("\t(4) Programar Escala\n");
		printf("\t(5) Adicionar Evento\n");
		printf("\t(6) Realizar Evento\n");
		printf("\t(7) Realiza Transferência\n");
		printf("\t(8) Cadastro de Atleta\n");
		printf("\t(9) Cadastro de Técnicos\n");
		printf("\t(10) Cadastro de Médicos\n");
		printf("\t(11) Cadastro de STAFF\n");
		printf("\t(12) Cadastro de usuário\n");
		printf("\t(13) Área Médica\n");
		printf("\t(14) SAIR\n\n");
		printf("\tPor gentileza, digite o número da opção desejada:\n");
		//@nicolas_lobos => leitura do input do usuario
		scanf("\t%d", &option_menu);
		//@nicolas_lobos => inicio da estrutura de condição
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
			printf("Opção inválida! Tente novamente");
			break;
		}
		option_menu=NULL;
	}
	//@nicolas_lobos => condição de execução
	while(option_menu != 14);
}