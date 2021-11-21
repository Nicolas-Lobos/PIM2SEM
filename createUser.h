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
*/
//gcc main.c -g

#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

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

typedef struct data Data;
struct data
{
	char day[4];
	char month[4];
	char year[4];
};

// Usuário normal
typedef struct user User;
struct user {
	char name[30];
	Country countryOrigin;
	char passport[30];
	Data brithDay;
	char rg[30];
	char cpf[30];
	char genre[10];
	char nickName[50];
	char password[30];
	int statusLogin;


	char password_cad[30]; // ?observação?
};

typedef struct voluntary Voluntary;
struct voluntary {
	User personalData;
	char work;
	char description;
};

typedef struct employee Employee;
struct employee {
	User personalData;
	char work;
	char description;
};

typedef struct technician Technician;
struct technician {
	User personalData;
	Category team;
};

void registerEmployee();
void registerTechnician();

///Fun��o para exibir o processo de login (concluido)
void login(){
	setlocale(LC_ALL, "Portuguese");
	User user;

	int i;
	int k;
	char comparadora_psw_login[400][200];
	char buffer[200];

	FILE *f_login;

	//@nicolas_lobos => defini��o de valor para o estado "logado" do usu�rio
	user.statusLogin = 0;
	
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
			printf("\n\nInsira seu usuário:\n");
			gets(user.name);
			fflush(stdin);
			printf("\nInsira sua senha:\n");
			gets(user.password);
			
			//@nicolas_lobos => junta a string password com a string username
			strcat(user.name,user.password);
			
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
				
				if(!(strcmp(comparadora_psw_login[k],user.name))){
        		
					/*@nicolas_lobos =>
					a linha abaixo serve de teste para 
					confirmar se encontrou uma correspond�ncia
					printf("encontrei a senha");*/
					user.statusLogin=1;
					break;
				}
			}
			//contador de tentativas de login
			x = x-1;
			if(!user.statusLogin) {
				printf("\nUsuário/Senha Inválidos, tente novamente!\n");
				printf("Restam %d tentativas.\n",x);
			}

			// se excedido o limite de tentativas, encerra a tela de login
			if(x == 0) exit(0);

		} while(!user.statusLogin);

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
	//@nicolas_lobos => Declara��o de vari�veis
	int option_menu;

	char type_user[100];

	//@nicolas_lobos => in�cio da estrutura de repeti��o 
	do {
		setlocale(LC_ALL, "Portuguese");

		//@nicolas_lobos => exibi��o do menu
		printf("\n\a");
		printf("\t================================================\n");
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
		printf("\t(10) Cadastro de funcionário\n");
		printf("\t(11) Cadastro de voluntário\n");
		printf("\t(12) Área Médica\n");
		printf("\t(13) SAIR\n\n");
		printf("\tPor gentileza, digite o número da opção desejada:\n\t");
		//@nicolas_lobos => leitura do input do usuario
		scanf("%d", &option_menu);
		/*@nicolas_lobos => inicio da estrutura de condi��o
		cada uma das op��es abaixo referencia uma fun��o acima */
		switch (option_menu) {
			case 1:
				printf("Em desenvolvimento");
				menu();
      break;

			case 2:
				printf("Em desenvolvimento");
				menu();
      break;

			case 3:
				printf("Em desenvolvimento");
				menu();
      break;

			case 4:
				printf("Em desenvolvimento");
				menu();
      break;

			case 5:
				printf("Em desenvolvimento");
				menu();
      break;

			case 6:
				printf("Em desenvolvimento");
				menu();
      break;

      case 7:
				printf("Em desenvolvimento");
				menu();
      break;

      case 8:
				printf("Em desenvolvimento");
				menu();
      break;

      case 9:
				printf("Em desenvolvimento");
				menu();
      break;

      case 10:
				registerEmployee();
      break;

			case 11:
				printf("Em desenvolvimento");
				menu();
      break;

			case 12:
				printf("Em desenvolvimento");
				menu();
      break;

			default:
				printf("Opção inválida! Tente novamente");
			break;
		}
	}
	//@nicolas_lobos => condi��o de execu��o
	while(option_menu != 13);
}

void createUser(int opt_auth)
{
	setlocale(LC_ALL, "Portuguese");

	FILE *f_auth;
	FILE *f_login;
	
	User user;
	int opt_y_n;
	char buffer[200];
	char comparadora_psw_login[400][200];

  //@nicolas_lobos => in�cio da fun��o de login
	//@nicolas_lobos => abrindo o arquivo de dados do login
	f_auth = fopen("auth_files\\auth_adm.txt", "r");

  int i, k;
	// char type_user[100];

	printf("\t================================================\n");
	printf("\tCadastro de usuário:\n");
	printf("\t================================================\n");

  do {
		setlocale(LC_ALL, "Portuguese");

    //@nicolas_lobos => flush pra evitar erro de teclado
    fflush(stdin);
    printf("\n\nInsira seu usuário:\n");
    gets(user.name);
    fflush(stdin);
    printf("\nInsira sua senha:\n");
    gets(user.password);
  
    //@nicolas_lobos => junta a string password com a string username
    strcat(user.name, user.password);
    
    i = 0;
  
    /*@nicolas_lobos =>
    copia todas as strings do arquivo 
    auth_adm
    para uma matriz de compara��o*/

    while(fscanf(f_auth,"%s",buffer)==1) {
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
    
      if(!(strcmp(comparadora_psw_login[k],user.name))){
      
        /*@nicolas_lobos =>
        a linha abaixo serve de teste para 
        confirmar se encontrou uma correspond�ncia
        printf("encontrei a senha");*/
        user.statusLogin=1;
        break;
      }
    }
    printf("Usuário não autorizado, tente novamente!");
  } while(!user.statusLogin);

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
  else {
    //@nicolas_lobos => la�o de repeti��o para cadastro
    do {
			setlocale(LC_ALL, "Portuguese");

      //flush para evitar erro de buffer de teclado
      fflush(stdin);
      /*@nicolas_lobos => informa��o sobre o tipo de cadastro
      e solicita��o de input das informa��es a serem registradas*/
      printf("\n\n\tCadastro de Usuário(s) do Sistema");
      printf("\n\tUsuário TIPO %s", user);
      printf("\n\tPor favor Insira um login para cadastrar: ");
      gets(user.nickName);
			
      fflush(stdin);
      printf("\n\tPor favor Insira um login para cadastrar: ");
      gets(user.password_cad);
      // @nicolas_lobos => concatena��o para salvar o registro
      strcat(user.nickName, user.password_cad);
      //@nicolas_lobos => salvando em arquivo a informa��o de login
      for(i=0; user.nickName[i]; i++) {
        putc(user.nickName[i],f_login);
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

void registerEmployee() {
	FILE *file_employee;

	Employee employee;

	file_employee = fopen("funcionarios.txt", "ab");

	if (file_employee == NULL) {
		printf("Problema na abertura do arquivo!\n");
	} else {
		do
		{
			printf("\t================================================\n");
			printf("\tCadastro de Funcionário:\n");
			printf("\t================================================\n");

			fflush(stdin);
			printf("Nome: ");
			gets(employee.personalData.name);

			fflush(stdin);
			printf("\nNacionalidade: ");
			gets(employee.personalData.countryOrigin.name);

			fflush(stdin);
			printf("\nPassaporte: ");
			gets(employee.personalData.passport);

			printf("\nData de nascimento: ");
			scanf("%d/%d/%d", &employee.personalData.brithDay.day, &employee.personalData.brithDay.month, &employee.personalData.brithDay.year);

			fflush(stdin);
			printf("\nRG: ");
			gets(employee.personalData.rg);

			fflush(stdin);
			printf("\nCPF: ");
			gets(employee.personalData.cpf);

			fflush(stdin);
			printf("\nSexo: ");
			gets(employee.personalData.genre);

			fflush(stdin);
			printf("\nInsira seu Nick(único): ");
			gets(employee.personalData.nickName);

			fflush(stdin);
			printf("\nSenha: ");
			gets(employee.personalData.password);

			employee.personalData.statusLogin = 0;

			fwrite(&employee, sizeof(Employee), 1, file_employee);

			printf("\n\nDeseja continuar(s/n)? ");
		} while (getche() == 's');
	
		fclose(file_employee);
		getch();
	}
}

void registervoluntary() {
	FILE *file_voluntary;

	Voluntary voluntary;

	file_voluntary = fopen("voluntarios.txt", "ab");

	if (file_voluntary == NULL) {
		printf("Problema na abertura do arquivo!\n");
	} else {
		do
		{
			printf("\t================================================\n");
			printf("\tCadastro de voluntário:\n");
			printf("\t================================================\n");

			fflush(stdin);
			printf("Nome: ");
			gets(voluntary.personalData.name);

			fflush(stdin);
			printf("\nNacionalidade: ");
			gets(voluntary.personalData.countryOrigin.name);

			fflush(stdin);
			printf("\nPassaporte: ");
			gets(voluntary.personalData.passport);

			printf("\nData de nascimento: ");
			scanf("%d/%d/%d", &voluntary.personalData.brithDay.day, &voluntary.personalData.brithDay.month, &voluntary.personalData.brithDay.year);

			fflush(stdin);
			printf("\nRG: ");
			gets(voluntary.personalData.rg);

			fflush(stdin);
			printf("\nCPF: ");
			gets(voluntary.personalData.cpf);

			fflush(stdin);
			printf("\nSexo: ");
			gets(voluntary.personalData.genre);

			fflush(stdin);
			printf("\nInsira seu Nick(único): ");
			gets(voluntary.personalData.nickName);

			fflush(stdin);
			printf("\nSenha: ");
			gets(voluntary.personalData.password);

			voluntary.personalData.statusLogin = 0;

			fwrite(&voluntary, sizeof(Voluntary), 1, file_voluntary);

			printf("\n\nDeseja continuar(s/n)? ");
		} while (getche() == 's');
	
		fclose(file_voluntary);
		getch();
	}
}

void registerTechnician() {
	FILE *file_technician;
	Technician technician;

	file_technician = fopen("tecnicos.txt", "ab");

	if (file_technician == NULL) {
		printf("Problema na abertura do arquivo!\n");
	} else {
		do
		{
			printf("\t================================================\n");
			printf("\tCadastro de Tecnico:\n");
			printf("\t================================================\n");

			fflush(stdin);
			printf("Nome: ");
			gets(technician.personalData.name);

			fflush(stdin);
			printf("\nNacionalidade: ");
			gets(technician.personalData.countryOrigin.name);

			fflush(stdin);
			printf("\nPassaporte: ");
			gets(technician.personalData.passport);

			printf("\nData de nascimento: ");
			scanf("%d %d %d", &technician.personalData.brithDay.day, &technician.personalData.brithDay.month, &technician.personalData.brithDay.year);

			fflush(stdin);
			printf("\nRG: ");
			gets(technician.personalData.rg);

			fflush(stdin);
			printf("\nCPF: ");
			gets(technician.personalData.cpf);

			fflush(stdin);
			printf("\nSexo: ");
			gets(technician.personalData.genre);

			fflush(stdin);
			printf("\nInsira seu Nick(único): ");
			gets(technician.personalData.nickName);

			fflush(stdin);
			printf("\nSenha: ");
			gets(technician.personalData.password);

			fflush(stdin);
			printf("\nModalidade: (ex: Futebol, Basquete, Vôlei, etc...) ");
			gets(technician.team.modality);

			fflush(stdin);
			printf("\nGênero da modalidade : ");
			gets(technician.team.genre);

			technician.personalData.statusLogin = 0;

			fwrite(&technician, sizeof(Technician), 1, file_technician);

			printf("\n\nDeseja continuar(s/n)? ");
		} while (getche() == 's');
		
		fclose(file_technician);
		getch();
	}
}
