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
	
	agenda_jogos = fopen("query_files\\agenda_jogos.txt", "r");
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

/// processo para adicionar um evento olimpico
void add_evento(){
	printf("Igor está desenvolvendo");
	//@nicolas_lobos => a ser desenvolvido
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
	f_auth = fopen("auth_files\\auth_adm.txt", "r");
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
		//@nicolas_lobos => laço de decisão para o tipo de usuário
		switch(opt_auth){
			//@nicolas_lobos => usuário do tipo atleta
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
				auth_adm
 para uma matriz de comparação*/

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
			//@nicolas_lobos => abre o arquivo de login para salvar novo usuário
			f_login = fopen("auth_files\\login.txt", "a");
			//@nicolas_lobos => caso não encontre ou falhe
			if(!f_login){
			printf("Error:File not found");
			system("pause");
			exit(0);
			}
			//@nicolas_lobos => se sucesso
			else{
				//@nicolas_lobos => laço de repetição para cadastro
				do{
					//flush para evitar erro de buffer de teclado
					fflush(stdin);
					/*@nicolas_lobos => informação sobre o tipo de cadastro
					e solicitação de input das informações a serem registradas*/
					printf("\n\n\tCadastro de Usuários do Sistema");
					printf("\n\tUsuário TIPO ATLETA");
					printf("\n\tPor favor Insira um login para cadastrar: ");
					gets(login_cad);
					fflush(stdin);
					printf("\n\tPor favor Insira um login para cadastrar: ");
					gets(password_cad);
					// @nicolas_lobos => concatenação para salvar o registro
					strcat(login_cad,password_cad);
					//@nicolas_lobos => salvando em arquivo a informação de login
					for(i=0; login_cad[i]; i++) {
						putc(login_cad[i],f_login);
					}
					fprintf(f_login,"\n");
					//@nicolas_lobos => mensagem de sucesso
					printf("\nCADASTRO EFETUADO COM SUCESSO!\n\n");
					printf("\nDeseja cadastrar outro usuário?");
					printf("\n(1)SIM");
					printf("\n(2)NÃO\n");
					//@nicolas_lobos => opção de escolha para novo cadastro
					scanf("%d",&opt_y_n);

				}while(opt_y_n!=2);
			// fechamento do arquivo de login
			fclose(f_login);
			
			}
			break;
			//@nicolas_lobos => usuário do tipo admnistrador
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
			// abertura do arquivo auth_adm para salvar o novo usuário
			f_auth = fopen("auth_files\\auth_adm.txt", "a");
			
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
			
			f_auth = fopen("auth_files\\auth1.txt", "a");
			
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
			
			f_auth = fopen("auth_files\\auth2.txt", "a");
			
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
			//contador de tentativas de login
			x = x-1;
			if(!logado) {
			printf("\nUsuário/Senha Inválidos, tente novamente!\n");
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

///Função para criar o menu para usuario (concluido)
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
		printf("\t(3) Programar Escala\n");
		printf("\t(4) Adicionar Evento\n");
		printf("\t(5) Realizar Evento\n");
		printf("\t(6) Cadastro de Atleta\n");
		printf("\t(7) Cadastro de Técnicos\n");
		printf("\t(8) Cadastro de Médicos\n");
		printf("\t(9) Cadastro de STAFF\n");
		printf("\t(10) Cadastro de usuário\n");
		printf("\t(11) Área Médica\n");
		printf("\t(12) SAIR\n\n");
		printf("\tPor gentileza, digite o número da opção desejada:\n");
		//@nicolas_lobos => leitura do input do usuario
		scanf("\t%d", &option_menu);
		/*@nicolas_lobos => inicio da estrutura de condição
		cada uma das opções abaixo referencia uma função acima */
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
			printf("Opção inválida! Tente novamente");
			break;
		}
		
	}
	//@nicolas_lobos => condição de execução
	while(option_menu != 12);
}