# **PROJETO PARA O PIM DO 2¬∫ SEMESTRE DE 2021**

## OBJETIVO

//@Nicolas_Lobos Desenvolver um software de gerenciamento de tarefas para as olimpÌadas de 2024 em PARIS
baseado na linguagem C com armazenamento de dados em arquivos (.txt), possibilidade
de incluir na tela de inÌcio do programa um sÌmbolo para as olimpiadas feito com a palavra PARIS
(PARIS 2024)

//@Nicolas_Lobos Deve possuir uma tela de login que autentique o usu·rio

//@Nicolas_Lobos Consultar com o Professor Cordeiro a possibilidade de usar um banco de dados ao 
invÈs de arquivos .txt (**possibilidade negada**)

//@Nicolas_Lobos Utilizar um randomizer para atribuir pontuaÁıes

//@Nicolas_Lobos Criar um Cod_Usu auto incrementado para os usu·rio?

## TIPOS DE USU¡RIO DO SISTEMA

Existem 4 tipos de usuarios para o software
    -Atletas (3)
    -TÈcnicos (2)
    -MÈdicos (4)
    -Staff (administraÁ„o) *SuperUser* (1)

Tarefas a realizar por usu·rio 
    
    (3)Atletas
        -realiza consultas
        -calend·rio e resultados
        -solicita transferÍncia de alojamento

    (2)TÈcnicos
        -Registra Atletas
        -Realiza escala de time
        -Consultas ao calend·rio e resultados

    (4)MÈdicos
        -Consulta internados
        -Consulta relatÛrios
        -Emiti Alta de paciente
        -Emiti RecomendaÁ„o de DesistÍncia


## PROCESSO PARA OS MENUS

Cada usu·rio vai ter acesso a uma parte especifica do menu padr„o
O mÈdico ter·° acesso a um menu personalizado
Staff possui acesso a todos os itens de menu

### MENU                                        USUARIO QUE TEM ACESSO
    (1)Consultar Agenda                     1    2   3
    (2)Consultar Resultados                 1    2   3
    (3)Solicitar TransferÍncia              1    3
    (4)Programar Escala                     1    3
    (5)Adicionar Evento                     1    3
    (6)Realizar Evento                      1
    (7)Realiza TransferÍncia                1
    (8)Cadastra Atleta                      1
    (9)Cadastra TÈcnicos                    1
    (10)Cadastra MÈdicos                    1
    (11)Cadastra STAFF                      1

### MENU M…DICO
    (1)Consultar Internados
    (2)Consultar relatÛrios
    (3)Emitir Alta
    (4)Emitir RecomendaÁ„o de DesistÍncia

## PROCESSO DE CADASTRO DE USU√ùRIOS (INFOS)

    Cad_Atletas {
        Nome Completo
        Passaporte
        E-Mail
        TU (Tipo de Usu√°rio)
        Login
        Senha
        Status
        PaÌs de Origem
        Idade
        Sexo
        Modalidade
        Equipe Olimpica
        Alojamento Atribuido
        Equipamentos Necess·rios
        MÈdico Respons·vel
        TÈcnico Respons·vel
    }

    Cad_TÈcnicos {
        Nome Completo
        Passaporte
        PaÌs de Origem
        Idade
        Sexo
        E-Mail
        TU (Tipo de Usu·rio)
        Login
        Senha
        Equipe Respons·vel
        Alojamento Atribuido
    }

    Cad_MÈdico {
        Nome Completo
        Passaporte
        PaÌ≠s de Origem
        Sexo
        E-Mail
        TU (Tipo de Usu·rio)
        Login
        Senha
        CRM
        ClÌnica AtribuÌda
    }

    Cad_STAFF {
        Nome Completo
        Passaporte
        PaÌs de Origem (talvez todos sejam FranÁa)
        Sexo
        E-Mail
        TU (Tipo de Usu·rio)
        Login
        Senha
    }

## PROCESSO PARA A REALIZA√á√ÉO DE EVENTOS

O menu de eventos pode conter informa√ß√µes como 

    - INICIAR PARTIDA
    - ATRIBUIR MEDALHAS
    - RELAT”RIO DE ACIDENTES
