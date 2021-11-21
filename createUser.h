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

typedef struct athlete Athlete;
struct athlete
{
	User personalData;
	Category team;
	int number;
	char position[20];
};

typedef struct accommodation Accommodation;
struct accommodation
{
	char name[30];
	char endereco[100];
	char description[250];
};

void registervoluntary();
void registerEmployee();
void registerTechnician();
void registerAthlete();
void registerAccommodation();

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
				registerAthlete();
      break;

      case 7:
				registerTechnician();
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
				registervoluntary();
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
	char nickname[30];
	char password[30];
	char comparadora_psw_login[400][200];

  //@nicolas_lobos => in�cio da fun��o de login
	//@nicolas_lobos => abrindo o arquivo de dados do login
	f_auth = fopen("auth_files\\auth_adm.txt", "r");

  int i = 0, k = 0;
	// char type_user[100];

	printf("\t================================================\n");
	printf("\tCadastro de usuário:\n");
	printf("\t================================================\n");

  do {
		setlocale(LC_ALL, "Portuguese");

    //@nicolas_lobos => flush pra evitar erro de teclado
    fflush(stdin);
    printf("\n\nInsira seu usuário:\n");
    gets(nickname);
    fflush(stdin);
    printf("\nInsira sua senha:\n");
    gets(password);
  
    //@nicolas_lobos => junta a string password com a string username
    // strcat(user.name, user.password);
    
  
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

    for(k; k<=400; k++) {
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

	menu();
}

void registerEmployee() {
	FILE *file_employee;

	Employee employee;

	file_employee = fopen("usuarios/funcionarios.txt", "ab");

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

	file_voluntary = fopen("usuarios/voluntarios.txt", "ab");

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

	file_technician = fopen("usuarios/tecnicos.txt", "ab");

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

void registerAthlete() {
	FILE *file_athlete;
	Athlete athlete;

	file_athlete = fopen("usuarios/atletas.txt", "ab");

	if (file_athlete == NULL) {
		printf("Problema na abertura do arquivo!\n");
	} else {
		do
		{
			printf("\n\nNe\t================================================\n");
			printf("\tCadastro de atleta:\n");
			printf("\t================================================\n");

			fflush(stdin);
			printf("Nome: ");
			gets(athlete.personalData.name);

			fflush(stdin);
			printf("\nNacionalidade de %s: ", athlete.personalData.name);
			gets(athlete.personalData.countryOrigin.name);

			fflush(stdin);
			printf("\nPassaporte de %s: ", athlete.personalData.name);
			gets(athlete.personalData.passport);

			printf("\nData de nascimento de %s: ", athlete.personalData.name);
			scanf("%d %d %d", &athlete.personalData.brithDay.day, &athlete.personalData.brithDay.month, &athlete.personalData.brithDay.year);

			fflush(stdin);
			printf("\nRG de %s: ", athlete.personalData.name);
			gets(athlete.personalData.rg);

			fflush(stdin);
			printf("\nCPF de %s: ", athlete.personalData.name);
			gets(athlete.personalData.cpf);

			fflush(stdin);
			printf("\nSexo de %s: ", athlete.personalData.name);
			gets(athlete.personalData.genre);

			fflush(stdin);
			printf("\nInsira Nick(único) de %s: ");
			gets(athlete.personalData.nickName);

			fflush(stdin);
			printf("\nSenha de acesso do(a) atleta %s: ", athlete.personalData.name);
			gets(athlete.personalData.password);

			fflush(stdin);
			printf("\nModalidade do atleta %s (ex: Futebol, Basquete, Vôlei, etc...): \n", athlete.personalData.name);
			gets(athlete.team.modality);

			fflush(stdin);
			printf("\nGênero da modalidade do atleta %s: ", athlete.personalData.name);
			gets(athlete.team.genre);

			fflush(stdin);
			printf("\nNúmero do(a) atleta %s: ", athlete.personalData.name);
			scanf("%d", &athlete.number);

			fflush(stdin);
			printf("\nPosição que o(a) atleta %s irá exercer: ", athlete.personalData.name);
			gets(athlete.position);

			athlete.personalData.statusLogin = 0;

			fwrite(&athlete, sizeof(Athlete), 1, file_athlete);

			printf("\n\nDeseja continuar(s/n)? ");
		} while (getche() == 's');
		
		fclose(file_athlete);
		getch();
	}
}

void registerAccommodation() {
	FILE *file_accommodation;
	FILE *file_athlete;

	Accommodation accommodation;
	Athlete athlete;

	file_accommodation = fopen("outros/alojamento.txt", "ab");
	file_athlete = fopen("usuarios/atletas.txt", "rb");

	if (file_accommodation == NULL && file_athlete == NULL) {
		printf("Problema na abertura do arquivo!\n");
	} else {
		do
		{
			printf("\t================================================\n");
			printf("\tCadastro de Alojamento\n");
			printf("\t================================================\n");

			fflush(stdin);
			printf("Nome: ");
			gets(accommodation.name);

			fflush(stdin);
			printf("\nEndereço: ");
			gets(accommodation.endereco);

			fflush(stdin);
			printf("\nDescrição sobre o alojamento %s: ", accommodation.name);
			gets(accommodation.description);

			fwrite(&accommodation, sizeof(Accommodation), 1, file_accommodation);

			printf("\n\nDeseja continuar(s/n)? ");
		} while (getche() == 's');
		
		fclose(file_accommodation);
		getch();
	}
}
