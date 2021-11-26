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
	char state[30];
	char city[30];
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
	int day;
	int month;
	int year;

	int hour;
	int minute;
	int second;
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

typedef struct technician Technician;
struct technician {
	User personalData;
};

typedef struct doctor Doctor;
struct doctor
{
	User personalData;
	Category team;
};

typedef struct team Team;
struct team
{
	char name[20];
	Country source;
	Technician technician;
	Category category;
	Doctor doctor;
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

typedef struct athlete Athlete;
struct athlete
{
	User personalData;
	Category team;
	int number;
	char position[20];
};



typedef struct olympicGamesVenue OlympicGamesVenue;
struct olympicGamesVenue
{
	Country countryData;
	char endereco[100];
	char description[250];
};

typedef struct accommodation Accommodation;
struct accommodation
{
	char name[30];
	char endereco[100];
	char description[250];
};

typedef struct match Match;
struct match
{
	char title[30];
	char descrition[100];
	Data schedule;
	Country local;
	Athlete teams;
	Voluntary voluntary;
	Employee employee;
};

char header(char title[25]);

void registerCountry();
void registerTeam();
void registerTechnician();
void registerAthlete();
void registerDoctor();
void registerEmployee();
void registerVoluntary();
void registerAccommodation();
void registerMatch(); // Jogos

void listCountry();
void listTeam();
void listTechnician();
void listAthlete();
void listDoctors();
void listEmployee();
void listVoluntaries();
void listAccommodation();

void login() {
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
	else {
		int x = 4;

		do{
			//@nicolas_lobos => flush pra evitar erro de teclado
			header("Login");

			fflush(stdin);
			printf("\n\tInsira seu usuário: ");
			gets(user.name);
			fflush(stdin);
			printf("\n\tInsira sua senha: ");
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
		printf("\n\n\t\aLOGIN EFETUADO COM SUCESSO!\n\n\t");
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
void initial(){
	//@nicolas_lobos => Declara��o de vari�veis
	int option_menu;

	char type_user[100];

	//@nicolas_lobos => in�cio da estrutura de repeti��o 
	do {
		setlocale(LC_ALL, "Portuguese");

		//@nicolas_lobos => exibi��o do menu
		printf("\n\a");
		header("Bem vindo(a), Tela inicial");

		printf("\t(1) Cadastrar Usuário\n");
		printf("\t(2) Cadastrar País\n");
		printf("\t(3) Cadastrar Jogos\n");
		printf("\t(4) Cadastrar de equipe\n");
		printf("\t(5) Listar Usuários\n");
		printf("\t(6) Listar Países\n");
		printf("\t(7) Listar Modalidades\n");
		printf("\t(8) Listar Locais dos Jogos\n");
		printf("\t(9) Listar Eventos\n");
		printf("\t(10) Listar Alojamentos\n");
		printf("\t(11) Pesquisar Usuário\n");
		printf("\t(12) Pesquisar País\n");
		printf("\t(13) Pesquisar Modalidade\n");
		printf("\t(14) Pesquisar Local do Jogo\n");
		printf("\t(15) Pesquisar Evento\n");
		printf("\t(16) Pesquisar Jogos\n");
		printf("\t(17) Calendário de Eventos\n");
		printf("\t(18) Calendário de Jogos\n");
		printf("\t(19) Cadastrar Evento\n");
		printf("\t(20) Sair do Programa\n\n");

		printf("\tPor gentileza, digite o número da opção desejada: ");
		//@nicolas_lobos => leitura do input do usuario
		scanf("%d", &option_menu);
		/*@nicolas_lobos => inicio da estrutura de condi��o
		cada uma das op��es abaixo referencia uma fun��o acima */

		switch (option_menu) {
			case 1:
				int chooseOption;
				do {
					header("Cadastros de Usuários");

					printf("\t(1) Cadastrar Atleta(s)\n");
					printf("\t(2) Cadastrar Tecnico(s)\n");
					printf("\t(3) Cadastrar Médico(s)\n");
					printf("\t(4) Cadastrar Funcionário(s)\n");
					printf("\t(5) Cadastrar Voluntário(s)\n");
					printf("\t(6) Cadastro de STAFF\n");
					printf("\t(7) Voltar Tela Inicial\n\n");

					scanf("%d", &chooseOption);

					switch (chooseOption) {
						case 1:
							registerAthlete();
						break;

						case 2:
							registerTechnician();
						break;

						case 3:
							registerDoctor();
						break;

						case 4:
							registerEmployee();
						break;

						case 5:
							registerVoluntary();
						break;

						case 6:
							printf("Em desenvolvimento");
							getch();
							initial();
						break;

						default:
							printf("\n\tOpção inválida! Tente novamente");
						break;
					}
				} while (chooseOption != 7);
			break;

			case 2:
				registerCountry();
			break;

			case 3:
				registerMatch();
			break;

			case 4:
				registerTeam();
			break;

			case 5:
				do {
					// int chooseOption;
					header("Listar Usuários");

					printf("\t(1) Listar Atleta(s)\n");
					printf("\t(2) Listar Técnico(s)\n");
					printf("\t(3) Listar Médico(s)\n");
					printf("\t(4) Listar Funcionário(s)\n");
					printf("\t(5) Listar Voluntário(s)\n");
					printf("\t(6) Listar de STAFF\n");
					printf("\t(7) Voltar Tela Inicial\n\n");

					scanf("%d", &chooseOption);

					switch (chooseOption) {
						case 1:
							listAthlete();
						break;

						case 2:
							listTechnician();
						break;

						case 3:
							listDoctors();
						break;

						case 4:
							listEmployee();
						break;

						case 5:
							listVoluntaries();
						break;

						case 6:
							listVoluntaries();
						break;

						case 7:
							listTeam();
						break;

						case 8:
							printf("Em desenvolvimento");
							getch();
							initial();
						break;

						case 9:
							printf("Em desenvolvimento");
							getch();
							initial();
						break;

						case 10:
							listAccommodation();
						break;

						default:
							printf("\n\tOpção inválida! Tente novamente");
						break;
					}
				} while (chooseOption != 8);
			break;

			case 6:
				listCountry();
			break;

			default:
				printf("\n\tOpção inválida! Tente novamente");
			break;
		}
	} while(option_menu != 19);
	system("cls");

	int exit;

	printf("\tDesejá sair do programa?\n");
	printf("\t(1) Sim\n");
	printf("\t(2) Voltar para a tela de login\n");

	scanf("%d", &exit);
	
	if(exit == 1) {
		system("exit");
	} else {
		login();
	}
}

// Cadastro de Jogos
void registerMatch() {
	FILE *file_match;

	Match match;

	file_match = fopen("outros/jogos.txt", "ab");

	if (file_match == NULL) {
		printf("Problema na abertura do arquivo de cadastro de JOGOS!\n");
	} else {
		do
		{
			header("Cadastro de Jogos");

			fflush(stdin);
			printf("Título do jogo: ");
			gets(match.title);

			fflush(stdin);
			printf("\nDescrição do jogo: ");
			gets(match.descrition);

			printf("\nLocal do jogo\n");

			fflush(stdin);
			printf("\nEstado: ");
			gets(match.local.state);

			fflush(stdin);
			printf("\nCidade: \n");
			gets(match.local.city);

			fflush(stdin);
			printf("\nMarcar a data do jogo\n");
			printf("\nEx: dia - mês - ano - hora - minuto - segundo:\n\t");
			scanf (
				"%d %d %d %d %d %d",
				match.schedule.day,
				match.schedule.month,
				match.schedule.year,
				match.schedule.hour,
				match.schedule.minute,
				match.schedule.second
			);

			fflush(stdin);
			printf("\nModalidade: ");
			gets(match.teams.team.modality);

			fflush(stdin);
			printf("\nCategoria(ex: Feminino Masculino): ");
			gets(match.teams.team.genre);

			int totalVoluntary;

			printf("\nDigite o total de volutário(s) para esse jogo: ");
			scanf("%d", &totalVoluntary);
			for (int i=0; i < totalVoluntary; i++) {
				printf("Insira o nome do %d° volutário: ", i);
				gets(match.teams.team.genre);
			}

			fwrite(&match, sizeof(Match), 1, file_match);

			printf("\n\nDeseja continuar(s/n)? ");
		} while (getche() == 's');
	
		fclose(file_match);

		system("cls");
		puts("=============================================");
		puts("Jogo(s), cadastrado com sucesso!");
		puts("=============================================");

		getch();
		initial();
	}
}

void registerCountry() {
	FILE *file_country;

	Country country;

	file_country = fopen("outros/paises.txt", "ab");

	if (file_country == NULL) {
		printf("Problema na abertura do arquivo!\n");
	} else {
		do
		{
			header("Cadastro de País");

			fflush(stdin);
			printf("Nome do País: ");
			gets(country.name);

			fflush(stdin);
			printf("\nComite olimpico do(a) %s: ", country.name);
			gets(country.olympicCommitte);

			fwrite(&country, sizeof(Country), 1, file_country);

			printf("\n\nDeseja continuar(s/n)? ");
		} while (getche() == 's');
	
		fclose(file_country);

		system("cls");
		puts("=============================================");
		puts("País(ses), cadastrado com sucesso!");
		puts("=============================================");
		
		getch();
		initial();
	}
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
			header("Cadastro de funcionário");

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
			scanf("%d %d %d", &employee.personalData.brithDay.day, &employee.personalData.brithDay.month, &employee.personalData.brithDay.year);

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

		system("cls");
		puts("=============================================");
		puts("Funcionário(os), cadastrado com sucesso!");
		puts("=============================================");
		
		getch();
		initial();
	}
}

void registerTeam() {
	FILE *file_team;
	FILE *file_technician;
	FILE *file_doctor;

	Team team;

	char technicianName;

	file_team = fopen("usuarios/equipes.txt", "ab");

	if (file_team == NULL) {
		printf("Problemas na abertura dos arquivos!\n");
	} else {
		do
		{
			header("Cadastro do time");

			fflush(stdin);
			printf("Nome: ");
			gets(team.name);

			fflush(stdin);
			printf("\nPais de origem: ");
			gets(team.source.name);

			fflush(stdin);
			printf("\nComite do Pais: ");
			gets(team.source.olympicCommitte);

			fflush(stdin);
			printf("\nCategoria(Feminino ou Masculino): ");
			gets(team.category.genre);

			fflush(stdin);
			printf("\nModalidade(ex: Basquete): ");
			gets(team.category.modality);

			fflush(stdin);
			printf("\nTecnico: ");
			gets(team.technician.personalData.name);

			fflush(stdin);
			printf("\nMédico: ");
			gets(team.doctor.personalData.name);

			fwrite(&team, sizeof(Team), 1, file_team);

			printf("\n\nDeseja continuar(s/n)? ");
		} while (getche() == 's');
		
		fclose(file_team);

		system("cls");
		puts("=============================================");
		puts("Equipe(s), cadastrado com sucesso!");
		puts("=============================================");
		
		getch();

		initial();
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
			header("Cadastro de Tecnico");

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

			technician.personalData.statusLogin = 0;

			fwrite(&technician, sizeof(Technician), 1, file_technician);

			printf("\n\nDeseja continuar(s/n)? ");
		} while (getche() == 's');
		
		fclose(file_technician);

		system("cls");
		puts("=============================================");
		puts("Técnico(s), cadastrado com sucesso!");
		puts("=============================================");
		
		getch();

		initial();
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
			header("Cadastro de atleta");

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

		system("cls");
		puts("=============================================");
		puts("Atleta(s), cadastrado com sucesso!");
		puts("=============================================");
		
		getch();
		initial();
	}
}

void registerDoctor() {
	FILE *file_doctor;
	Doctor doctor;

	file_doctor = fopen("usuarios/medicos.txt", "ab");

	if (file_doctor == NULL) {
		printf("Problema na abertura do arquivo!\n");
	} else {
		do
		{
			header("Cadastro de médico");

			fflush(stdin);
			printf("\tNome: ");
			gets(doctor.personalData.name);

			fflush(stdin);
			printf("\nNacionalidade de %s: ", doctor.personalData.name);
			gets(doctor.personalData.countryOrigin.name);

			fflush(stdin);
			printf("\nPassaporte de %s: ", doctor.personalData.name);
			gets(doctor.personalData.passport);

			printf("\nData de nascimento de %s: ", doctor.personalData.name);
			scanf("%d/%d/%d", &doctor.personalData.brithDay.day, &doctor.personalData.brithDay.month, &doctor.personalData.brithDay.year);

			fflush(stdin);
			printf("\nRG de %s: ", doctor.personalData.name);
			gets(doctor.personalData.rg);

			fflush(stdin);
			printf("\nCPF de %s: ", doctor.personalData.name);
			gets(doctor.personalData.cpf);

			fflush(stdin);
			printf("\nSexo de %s: ", doctor.personalData.name);
			gets(doctor.personalData.genre);

			fflush(stdin);
			printf("\nInsira Nick(único) de %s: ");
			gets(doctor.personalData.nickName);

			fflush(stdin);
			printf("\nSenha de acesso do(a) médico %s: ", doctor.personalData.name);
			gets(doctor.personalData.password);

			fflush(stdin);
			printf("\nModalidade do médico %s (ex: Futebol, Basquete, Vôlei, etc...): \n", doctor.personalData.name);
			gets(doctor.team.modality);

			fflush(stdin);
			printf("\nGênero da modalidade do médico %s: ", doctor.personalData.name);
			gets(doctor.team.genre);

			doctor.personalData.statusLogin = 0;

			fwrite(&doctor, sizeof(Doctor), 1, file_doctor);

			printf("\n\nDeseja continuar(s/n)? ");
		} while (getche() == 's');
		
		fclose(file_doctor);

		system("cls");
		puts("=============================================");
		puts("Médico(s), cadastrado com sucesso!");
		puts("=============================================");
		
		getch();
		initial();
	}
}

void registerAccommodation() {
	FILE *file_accommodation;

	Accommodation accommodation;

	file_accommodation = fopen("outros/alojamento.txt", "ab");

	if (file_accommodation == NULL) {
		printf("Problema na abertura do arquivo!\n");
	} else {
		do
		{
			header("Cadastro de Alojamento");

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

		header("Alojamento(s) para os atletas, cadastrado com sucesso!");
		system("cls");
		puts("============================================================");
		puts("Alojamento(s) para os atletas, cadastrado com sucesso!");
		puts("============================================================");
		
		getch();
		initial();
	}
}

void registerVoluntary() {
	FILE *file_voluntary;

	Voluntary voluntary;

	file_voluntary = fopen("usuarios/voluntarios.txt", "ab");

	if (file_voluntary == NULL) {
		printf("Problema na abertura do arquivo!\n");
	} else {
		do
		{
			header("Cadastro de voluntário");

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
			scanf("%d %d %d", &voluntary.personalData.brithDay.day, &voluntary.personalData.brithDay.month, &voluntary.personalData.brithDay.year);

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

		system("cls");
		puts("=============================================");
		puts("Voluntário(s), cadastrado com sucesso!");
		puts("=============================================");
		
		getch();
		initial();
	}
}

void listAthlete() {
	setlocale(LC_ALL, "Portuguese");

	FILE *file_athlete;
	Athlete athlete;

	file_athlete = fopen("usuarios/atletas.txt", "rb");

	header("Listagem de atletas");

	if (file_athlete == NULL) {
		printf("Problemas na abertura do arquivo!\n");
	} else {
		while (fread(&athlete, sizeof(Athlete), 1, file_athlete) == 1) {
			printf("\tNome: %s", athlete.personalData.name);
			printf("\n\tNacionalidade de %s: ", athlete.personalData.countryOrigin.name);
			printf("\n\tPassaporte de %s: ", athlete.personalData.passport);
			printf("\n\tData de nascimento de %d/%d/%d: ", athlete.personalData.brithDay.day, athlete.personalData.brithDay.month, athlete.personalData.brithDay.year);
			printf("\n\tRG de %s: ", athlete.personalData.rg);
			printf("\n\tCPF de %s: ", athlete.personalData.cpf);
			printf("\n\tSexo de %s: ", athlete.personalData.genre);
			printf("\n\tInsira Nick(único) de %s: ", athlete.personalData.nickName);
			printf("\n\tSenha de acesso do(a) atleta %s: ", athlete.personalData.password);
			printf("\n\tModalidade do atleta %s (ex: Futebol, Basquete, Vôlei, etc...): \n\t", athlete.team.modality);
			printf("\n\tGênero da modalidade do atleta %s: ", athlete.team.genre);
			printf("\n\tNúmero do(a) atleta %d: ", athlete.number);
			printf("\n\tPosição que o(a) atleta %s irá exercer: ", athlete.position);

      printf("\n======================================================================\n");
		}
	}

	fclose(file_athlete);
	getch();
	initial();
}

void listVoluntaries() {
  FILE *file_voluntary;
  Voluntary voluntary;

  file_voluntary = fopen("usuarios/voluntarios.txt", "rb"); // read

  header("Listar voluntarios");

  if (file_voluntary == NULL) {
    printf("Problemas na abertura do arquivo!\n");
  } else {
    while(fread(&voluntary, sizeof(Voluntary), 1, file_voluntary) == 1) {
			printf("\n\tNome: %s", voluntary.personalData.name);
			printf("\n\tNacionalidade: %s", voluntary.personalData.countryOrigin.name);
			printf("\n\tPassaporte: %s", voluntary.personalData.passport);
			printf("\n\tData de nascimento: %d/%d/%d", voluntary.personalData.brithDay.day, voluntary.personalData.brithDay.month, voluntary.personalData.brithDay.year);
			printf("\n\tRG: %s", voluntary.personalData.rg);
			printf("\n\tCPF: %s", voluntary.personalData.cpf);
			printf("\n\tSexo: %s", voluntary.personalData.genre);
			printf("\n\tNick Unico: %s", voluntary.personalData.nickName);
			printf("\n\tSenha: %s", voluntary.personalData.password);
      printf("\n\t================================================\n");
    }
  }

  fclose(file_voluntary);
  getch();
	initial();
}

void listTechnician() {
	FILE *file_technician;
  Technician technician;

  file_technician = fopen("usuarios/tecnicos.txt", "rb"); // read

  header("Listar Tecnicos");

  if (file_technician == NULL) {
    printf("Problemas na abertura do arquivo!\n");
  } else {
    while(fread(&technician, sizeof(Technician), 1, file_technician) == 1) {
			printf("\n\tNome: %s", technician.personalData.name);
			printf("\n\tNacionalidade: %s", technician.personalData.countryOrigin.name);
			printf("\n\tPassaporte: %s", technician.personalData.passport);
			printf("\n\tData de nascimento: %d/%d/%d", technician.personalData.brithDay.day, technician.personalData.brithDay.month, technician.personalData.brithDay.year);
			printf("\n\tRG: %s", technician.personalData.rg);
			printf("\n\tCPF: %s", technician.personalData.cpf);
			printf("\n\tSexo: %s", technician.personalData.genre);
			printf("\n\tInsira seu Nick(único): %s", technician.personalData.nickName);
      printf("\n\t================================================\n");
    }
  }

  fclose(file_technician);
  getch();
	initial();
}

void listDoctors() {
	FILE *file_doctor;
  Doctor doctor;

  file_doctor = fopen("usuarios/tecnicos.txt", "rb"); // read

  header("Listar de Medicos");

  if (file_doctor == NULL) {
    printf("Problemas na abertura do arquivo!\n");
  } else {
    while(fread(&doctor, sizeof(Doctor), 1, file_doctor) == 1) {
			printf("\n\tNome: %s", doctor.personalData.name);
			printf("\n\tNacionalidade: %s", doctor.personalData.countryOrigin.name);
			printf("\n\tPassaporte: %s", doctor.personalData.passport);
			printf("\n\tData de nascimento: %d/%d/%d", doctor.personalData.brithDay.day, doctor.personalData.brithDay.month, doctor.personalData.brithDay.year);
			printf("\n\tRG: %s", doctor.personalData.rg);
			printf("\n\tCPF: %s", doctor.personalData.cpf);
			printf("\n\tSexo: %s", doctor.personalData.genre);
			printf("\n\tNick Unico: %s", doctor.personalData.nickName);
			printf("\n\tModalidade para qual o medico ira ser designado: %s \n\t", doctor.team.modality);
			printf("\n\tCategoria da modalidade: %s", doctor.team.genre);
      printf("\n\t================================================\n");
    }
  }

  fclose(file_doctor);
  getch();
	initial();
}

void listEmployee() {
	FILE *file_employee;
  Employee employee;

  file_employee = fopen("usuarios/tecnicos.txt", "rb"); // read

  header("Listar de Medicos");

  if (file_employee == NULL) {
    printf("Problemas na abertura do arquivo!\n");
  } else {
    while(fread(&employee, sizeof(Employee), 1, file_employee) == 1) {
			printf("\n\tNome: %s", employee.personalData.name);
			printf("\n\tNacionalidade: %s", employee.personalData.countryOrigin.name);
			printf("\n\tPassaporte: %s", employee.personalData.passport);
			printf("\n\tData de nascimento: %d/%d/%d", employee.personalData.brithDay.day, employee.personalData.brithDay.month, employee.personalData.brithDay.year);
			printf("\n\tRG: %s", employee.personalData.rg);
			printf("\n\tCPF: %s", employee.personalData.cpf);
			printf("\n\tSexo: %s", employee.personalData.genre);
			printf("\n\tNick unico: %s", employee.personalData.nickName);
			printf("\n\t================================================\n");
    }
  }

  fclose(file_employee);
  getch();
	initial();
}

void listTeam() {
	FILE *file_team;
  Team team;

  file_team = fopen("usuarios/equipes.txt", "rb"); // read

  header("Listar de Medicos");

  if (file_team == NULL) {
    printf("Problemas na abertura do arquivo!\n");
  } else {
    while(fread(&team, sizeof(Employee), 1, file_team) == 1) {
			printf("Nome: %s", team.name);
			printf("\nPais de origem: %s", team.source.name);
			printf("\nComite do Pais: %s", team.source.olympicCommitte);
			printf("\nCategoria: %s", team.category.genre);
			printf("\nModalidade: %s", team.category.modality);
			printf("\nTecnico: %s", team.technician.personalData.name);
			printf("\nMédico: %s", team.doctor.personalData.name);
			printf("\n\t================================================\n");
    }
  }

  fclose(file_team);
  getch();
	initial();
}

void listCountry() {
	FILE *file_country;
  Country country;

  file_country = fopen("outros/paises.txt", "rb"); // read

  header("Listar de Medicos");

  if (file_country == NULL) {
    printf("Problemas na abertura do arquivo!\n");
  } else {
    while(fread(&country, sizeof(Employee), 1, file_country) == 1) {
			printf("Nome do País: ");
			gets(country.name);

			fflush(stdin);
			printf("\nComite Olimpico do(a) %s: ", country.name);
			gets(country.olympicCommitte);
			printf("\n\t================================================\n");
    }
  }

  fclose(file_country);
  getch();
	initial();
}

void listAccommodation() {
	FILE *file_accommodation;
  Accommodation accommodation;

  file_accommodation = fopen("outros/paises.txt", "rb"); // read

  header("Listar de Medicos");

  if (file_accommodation == NULL) {
    printf("Problemas na abertura do arquivo!\n");
  } else {
    while(fread(&accommodation, sizeof(Employee), 1, file_accommodation) == 1) {
			printf("Nome: %s", accommodation.name);
			printf("\nEndereço: %s", accommodation.endereco);
			printf("\nDescrição %s: ", accommodation.description);
			printf("\n\t================================================\n");
    }
  }

  fclose(file_accommodation);
  getch();
	initial();
}

char header(char title[25]) {
	system("cls");
	printf("\n\n\t===============================================================\n");
	printf("\t%s\n", title);
	printf("\t===============================================================\n\n");
}
