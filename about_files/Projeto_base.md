# **PROJETO PARA O PIM DO 2� SEMESTRE DE 2021**

## OBJETIVO

//@Nicolas_Lobos => Desenvolver um software de gerenciamento de tarefas para as olimp�adas de 2024 em PARIS
baseado na linguagem C com armazenamento de dados em arquivos (.txt), possibilidade
de incluir na tela de in�cio do programa um s�mbolo para as olimpiadas feito com a palavra PARIS
(PARIS 2024)

//@Nicolas_Lobos => Deve possuir uma tela de login que autentique o usu�rio

//@Nicolas_Lobos => Utilizar um randomizer para atribuir pontua��es

//@Nicolas_Lobos => Criar um Cod_Usu auto incrementado para os usu�rio?

## TIPOS DE USU�RIO DO SISTEMA

Existem 4 tipos de usuarios para o software
	-Atletas (3)
	-T�cnicos (2)
	-M�dicos (4)
	-Staff (administra��o) *SuperUser* (1)

Tarefas a realizar por usu�rio 
	
	(3)Atletas
		-realiza consultas
		-calend�rio e resultados

	(2)T�cnicos
		-Registra Atletas
		-Realiza escala de time
		-Consultas ao calend�rio e resultados

	(4)M�dicos
		-Consulta internados
		-Consulta relat�rios
		-Emiti Alta de paciente
		-Emiti Recomenda��o de Desist�ncia


## PROCESSO PARA OS MENUS

Cada usu�rio vai ter acesso a uma parte especifica do menu padr�o
O m�dico ter� acesso a um menu personalizado
Staff possui acesso a todos os itens de menu

### MENU								USUARIO QUE TEM ACESSO

	(1) Consultar Agenda				1	2	3
	(2) Consultar Resultado				1	2	3
	(3) Programar Escala				1		3
	(4) Adicionar Evento				1		3
	(5) Realizar Evento					1
	(6) Cadastro de Atleta				1
	(7) Cadastro de T�cnicos			1
	(8) Cadastro de M�dicos				1
	(9) Cadastro de STAFF				1
	(10) Cadastro de usu�rio			1
	(11) �rea M�dica								4
	(12) SAIR							1	2	3	4

### MENU M�DICO
	(1)Consultar Internados
	(2)Consultar relat�rios
	(3)Emitir Alta
	(4)Emitir Recomenda��o de Desist�ncia

## PROCESSO DE CADASTRO DE USU�RIOS (INFOS)

	Cad_Atletas {
		Nome Completo
		Passaporte
		E-Mail
		TU (Tipo de Usu�rio)
		Login
		Senha
		Status
		Pa�s de Origem
		Idade
		Sexo
		Modalidade
		Equipe Ol�mpica
		Alojamento Atribu�do
		Equipamentos Necess�rios
		M�dico Respons�vel
		T�cnico Respons�vel
	}

	Cad_T�cnicos {
		Nome Completo
		Passaporte
		Pa�s de Origem
		Idade
		Sexo
		E-Mail
		TU (Tipo de Usu�rio)
		Login
		Senha
		Equipe Respons�vel
		Alojamento Atribuido
	}

	Cad_M�dico {
		Nome Completo
		Passaporte
		Pa�s de Origem
		Sexo
		E-Mail
		TU (Tipo de Usu�rio)
		Login
		Senha
		CRM
		Cl�nica Atribu�da
	}

	Cad_STAFF {
		Nome Completo
		Passaporte
		Pa�s de Origem (talvez todos sejam Fran�a)
		Sexo
		E-Mail
		TU (Tipo de Usu�rio)
		Login
		Senha
	}

## PROCESSO PARA A REALIZA��O DE EVENTOS

O menu de eventos pode conter informa��es como:

	- INICIAR PARTIDA
	- ATRIBUIR MEDALHAS
	- RELAT�RIO DE ACIDENTES