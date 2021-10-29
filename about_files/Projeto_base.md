# **PROJETO PARA O PIM DO 2º SEMESTRE DE 2021**

## OBJETIVO

//@Nicolas_Lobos => Desenvolver um software de gerenciamento de tarefas para as olimpí­adas de 2024 em PARIS
baseado na linguagem C com armazenamento de dados em arquivos (.txt), possibilidade
de incluir na tela de inï¿½cio do programa um sï¿½mbolo para as olimpiadas feito com a palavra PARIS
(PARIS 2024)

//@Nicolas_Lobos => Deve possuir uma tela de login que autentique o usuário

//@Nicolas_Lobos => Utilizar um randomizer para atribuir pontuações

//@Nicolas_Lobos => Criar um Cod_Usu auto incrementado para os usuário?

## TIPOS DE USUÁRIO DO SISTEMA

Existem 4 tipos de usuarios para o software
	-Atletas (3)
	-Técnicos (2)
	-Médicos (4)
	-Staff (administração) *SuperUser* (1)

Tarefas a realizar por usuário 
	
	(3)Atletas
		-realiza consultas
		-calendário e resultados

	(2)Técnicos
		-Registra Atletas
		-Realiza escala de time
		-Consultas ao calendário e resultados

	(4)Médicos
		-Consulta internados
		-Consulta relatórios
		-Emiti Alta de paciente
		-Emiti Recomendação de Desistência


## PROCESSO PARA OS MENUS

Cada usuário vai ter acesso a uma parte especifica do menu padrão
O médico terá acesso a um menu personalizado
Staff possui acesso a todos os itens de menu

### MENU								USUARIO QUE TEM ACESSO

	(1) Consultar Agenda				1	2	3
	(2) Consultar Resultado				1	2	3
	(3) Programar Escala				1		3
	(4) Adicionar Evento				1		3
	(5) Realizar Evento					1
	(6) Cadastro de Atleta				1
	(7) Cadastro de Técnicos			1
	(8) Cadastro de Médicos				1
	(9) Cadastro de STAFF				1
	(10) Cadastro de usuário			1
	(11) Área Médica								4
	(12) SAIR							1	2	3	4

### MENU MÉDICO
	(1)Consultar Internados
	(2)Consultar relatórios
	(3)Emitir Alta
	(4)Emitir Recomendação de Desistência

## PROCESSO DE CADASTRO DE USUÁRIOS (INFOS)

	Cad_Atletas {
		Nome Completo
		Passaporte
		E-Mail
		TU (Tipo de Usuário)
		Login
		Senha
		Status
		País de Origem
		Idade
		Sexo
		Modalidade
		Equipe Olímpica
		Alojamento Atribuído
		Equipamentos Necessários
		Médico Responsável
		Técnico Responsável
	}

	Cad_Técnicos {
		Nome Completo
		Passaporte
		País de Origem
		Idade
		Sexo
		E-Mail
		TU (Tipo de Usuário)
		Login
		Senha
		Equipe Responsável
		Alojamento Atribuido
	}

	Cad_Médico {
		Nome Completo
		Passaporte
		País de Origem
		Sexo
		E-Mail
		TU (Tipo de Usuário)
		Login
		Senha
		CRM
		Clínica Atribuída
	}

	Cad_STAFF {
		Nome Completo
		Passaporte
		País de Origem (talvez todos sejam França)
		Sexo
		E-Mail
		TU (Tipo de Usuário)
		Login
		Senha
	}

## PROCESSO PARA A REALIZAÇÃO DE EVENTOS

O menu de eventos pode conter informações como:

	- INICIAR PARTIDA
	- ATRIBUIR MEDALHAS
	- RELATÓRIO DE ACIDENTES