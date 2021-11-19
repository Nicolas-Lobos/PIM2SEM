/**
 * @file createUser.h
 * @jonatasrmoura
 * @author Jonatas Rosa Moura (jonatas.rmoura@outlook.com)
 * @Nicolas-Lobos
 * @author Nicolas Lobos ()
 * @version 0.1
 * @date 2021-11-15
 * REFATURAÇÃO E TESTE PARA CRIÇÃO DOS USUÁRIOS DO SISTEMA
 * 
 * @copyright Copyright (c) 2021
 * 
*/

#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

typedef struct data Data;

typedef struct country Country;
struct country {
	char name[30];
	char olympicCommitte[30];
};

typedef struct category Category;
struct category {
	char modality[30];
	char genre[10];
};
struct data
{
	char day[2];
	char month[2];
	char year[4];
};

typedef struct document Document;
struct document
{
	char passport[30];
	char rg[30];
	char cpf[30];
	char genre[10];
};

// Usuário normal
typedef struct user User;
struct user {
	char name[30];
	Data brithDay;
	char email[50];
	char password[30];
	char password_cad[30]; // observação
	Document documentation;
};

typedef struct technician Technician;
struct technician {
	User personalData;
	Country countryOrigin;
	Category team;
};

/// processo para cadastrar usu�rios e gerar suas autentica��es (concluido)
void cad_user(int opt_auth){
	setlocale(LC_ALL, "Portuguese");
	printf("Autenticação");
	//declara��o de vari�veis
	char username[200];
	char password[200];
	char login_cad[200];
	char password_cad[200];
	int opt_y_n;
	// int opt_auth;
	int logado;
	// int i;
	// int k;
	char comparadora_psw_login[400][200];
	char buffer[200];
	//@nicolas_lobos => declara��o de ponteiros
	FILE *f_auth;
	FILE *f_login;
	//@nicolas_lobos => defini��o de valor para o estado "logado" do usu�rio
	logado = 0;
	
	//@nicolas_lobos => verifica se a abertura foi concluida com sucesso
	if(!f_auth){
		printf("Error:File not found");
		system("pause");
		exit(0);
	}
	//@nicolas_lobos => prosseguindo caso sucesso
	else {
    create(
      opt_auth,
      username,
      password,
      f_auth,
      buffer,
      comparadora_psw_login,
      f_login,
      logado,
      login_cad,
      password_cad,
      opt_y_n
    );
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

	char type_user[100];

	//@nicolas_lobos => in�cio da estrutura de repeti��o 
	do {
		setlocale(LC_ALL, "Portuguese");

		//@nicolas_lobos => exibi��o do menu
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
		printf("\tPor gentileza, digite o número da opção desejada:\n\t");
		//@nicolas_lobos => leitura do input do usuario
		scanf("%d", &option_menu);
		/*@nicolas_lobos => inicio da estrutura de condi��o
		cada uma das op��es abaixo referencia uma fun��o acima */
		switch (option_menu) {
			case 6:
			cad_user(6);
      break;

      case 7:
			cad_user(7);
      break;

      case 8:
			cad_user(8);
      break;

      case 9:
			cad_user(9);
      break;

      case 10:
			cad_user(10);
      break;

			default:
			printf("Opção inválida! Tente novamente");
			break;
		}
	}
	//@nicolas_lobos => condi��o de execu��o
	while(option_menu != 12);
}

int create(
  int opt_auth,
  char username[200],
  char password[200],
  FILE *f_auth,
  char buffer[200],
  char comparadora_psw_login[400][200],
	FILE *f_login,
  int logado,
  char login_cad[200],
	char password_cad[200],
  int opt_y_n
) {
  //@nicolas_lobos => in�cio da fun��o de login
	//@nicolas_lobos => abrindo o arquivo de dados do login
	f_auth = fopen("auth_files\\auth_adm.txt", "r");

  int i, k;
	char type_user[100];

  //@nicolas_lobos => laço de decisão para o tipo de usuário
  switch(opt_auth) {
    //@nicolas_lobos => usu�rio do tipo atleta
    case 6:
    printf("Cadastro atleta...");
		char type_user[50] = "Atleta";
    puts("==========================");
    break;

    case 7:
    printf("Cadastro de Técnico...");
		char type_user[50] = "Técnico";
    puts("==========================");
    break;

    case 8:
    printf("Cadastro de Médicos...");
		char type_user[50] = "Médico";
    puts("==========================");
    break;

    case 9:
    printf("Cadastro de STAFF...");
		char type_user[50] = "STAFF";
    puts("==========================");
    break;

    case 10:
    printf("Cadastro de Funcionário...");
		char type_user[50] = "Funcionário";
    puts("==========================");
    break;

    default:
    printf("Opção inválida! tente novamente");
    break;
  }

  do {
    //@nicolas_lobos => flush pra evitar erro de teclado
    fflush(stdin);
    printf("\n\nInsira seu usuário:\n");
    gets(username);
    fflush(stdin);
    printf("\nInsira sua senha:\n");
    gets(password);
  
    //@nicolas_lobos => junta a string password com a string username
    strcat(username,password);
    
    i = 0;
  
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
    printf("Usuário não autorizado, tente novamente!");
  } while(!logado);

  //@nicolas_lobos => mensagem de sucesso
  printf("\n\n\t\aUSUÁRIO AUTENTICADO!\n\n");
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
      printf("\n\n\tCadastro de Usuário(s) do Sistema");
      printf("\n\tUsuário TIPO %s", type_user);
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
      printf("\nDeseja cadastrar outro usuário?");
      printf("\n(1)SIM");
      printf("\n(2)NÃO\n\t");
      //@nicolas_lobos => op��o de escolha para novo cadastro
      scanf("%d",&opt_y_n);

    }while(opt_y_n!=2);
    // fechamento do arquivo de login
    fclose(f_login);
  }
}
