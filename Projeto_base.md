# **PROJETO PARA O PIM DO 2º SEMESTRE DE 2021**

## OBJETIVO

//@Nicolas_Lobos Desenvolver um software de gerenciamento de tarefas para as olimp�adas de 2024 em PARIS
baseado na linguagem C com armazenamento de dados em arquivos (.txt), possibilidade
de incluir na tela de in�cio do programa um s�mbolo para as olimpiadas feito com a palavra PARIS
(PARIS 2024)

//@Nicolas_Lobos Deve possuir uma tela de login que autentique o usu�rio

//@Nicolas_Lobos Consultar com o Professor Cordeiro a possibilidade de usar um banco de dados ao 
inv�s de arquivos .txt (**possibilidade negada**)

//@Nicolas_Lobos Utilizar um randomizer para atribuir pontua��es

//@Nicolas_Lobos Criar um Cod_Usu auto incrementado para os usu�rio?

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
        -solicita transfer�ncia de alojamento

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

### MENU                                        USUARIO QUE TEM ACESSO
    (1)Consultar Agenda                     1    2   3
    (2)Consultar Resultados                 1    2   3
    (3)Solicitar Transfer�ncia              1    3
    (4)Programar Escala                     1    3
    (5)Adicionar Evento                     1    3
    (6)Realizar Evento                      1
    (7)Realiza Transfer�ncia                1
    (8)Cadastra Atleta                      1
    (9)Cadastra T�cnicos                    1
    (10)Cadastra M�dicos                    1
    (11)Cadastra STAFF                      1

### MENU M�DICO
    (1)Consultar Internados
    (2)Consultar relat�rios
    (3)Emitir Alta
    (4)Emitir Recomenda��o de Desist�ncia

## PROCESSO DE CADASTRO DE USUÝRIOS (INFOS)

    Cad_Atletas {
        Nome Completo
        Passaporte
        E-Mail
        TU (Tipo de Usuário)
        Login
        Senha
        Status
        Pa�s de Origem
        Idade
        Sexo
        Modalidade
        Equipe Olimpica
        Alojamento Atribuido
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

## PROCESSO PARA A REALIZAÇÃO DE EVENTOS

O menu de eventos pode conter informações como 

    - INICIAR PARTIDA
    - ATRIBUIR MEDALHAS
    - RELAT�RIO DE ACIDENTES
