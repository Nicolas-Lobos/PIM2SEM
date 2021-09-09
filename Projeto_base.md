**PROJETO PARA O PIM DO 2º SEMESTRE DE 2021**

## OBJETIVO

//@Nicolas_Lobos Desenvolver um software de gerenciamento de tarefas para as olimpíadas de 2024 em PARIS
baseado na linguagem C com armazenamento de dados em arquivos (.txt), possibilidade
de incluir na tela de inicio do programa um simbolo para as olimpiadas feitos em 0 e 1
(torre eiffel)

//@Nicolas_Lobos Deve possuir uma tela de login que autentique o usuário

//@Nicolas_Lobos Consultar com o Professor Cordeiro a possibilidade de usar um banco de dados ao 
invés de arquivos .txt

//@Nicolas_Lobos Utilizar um randomizer para atribuir pontuações

//@Nicolas_Lobos Criar um Cod_Usu auto incrementado para os usuário?

## TIPOS DE USUÁRIO DO SISTEMA

Existem 4 tipos de usuarios para o software
    -Atletas
    -Técnicos
    -Médicos
    -Staff (administração) *SuperUser*

Tarefas a realizar por usuario 
    
    (1)Atletas
        -realiza consultas
        -calendário e resultados
        -solicita transferência de alojamento

    (2)Técnicos
        -Registra Atletas
        -Realiza escala de time
        -Consultas ao calendário e resultados

    (3)Médicos
        -Consulta internados
        -Consulta relatórios
        -Emiti Alta de paciente
        -Emiti Recomendação de Desistência


## PROCESSO PARA OS MENUS

Cada usuário vai ter acesso a uma parte especifica do menu padrão
O médico terá acesso a um menu personalizado
Staff possui acesso a todos os itens de menu

MENU                                        USUARIO QUE TEM ACESSO
    (1)Consultar Agenda                     1   2   3
    (2)Consultar Resultados                 1   2   3
    (3)Solicitar Transferência              1   3
    (4)Programar Escala                     1   3
    (5)Adicionar Evento                     1   3
    (6)Realizar Evento                      1
    (7)Realiza Transferência                1
    (8)Cadastra Atleta                      1   3
    (9)Cadastra Técnicos                    1
    (10)Cadastra Médicos                    1
    (11)Cadastra STAFF                      1

MENU MÉDICO
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
        Equipe Olimpica
        Alojamento Atribuido
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
        Clinica Atribuida
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

O menu de eventos pode conter informações como 

    - INICIAR PARTIDA
    - ATRIBUIR MEDALHAS
    - RELATÓRIO DE ACIDENTES