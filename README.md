This repository is to show one solution to the problem that was give to us about FIFA system and we had to solve using C language involving functions, structs and Macros. The problem is explained down here.

A FIFA para acompanhar de perto qualquer situação associada à corrupção nos jogos da Copa
do Mundo, junto às demais iniciativas resolveu efetuar um controle das arrecadações através do
desenvolvimento de um programa em Linguagem C para o qual você foi contratado.
Para a solução crie e utilize três estruturas: Presidente, Cidade, Jogo.
---------------------------
Para cada jogo serão controladas as seguintes informações:

• Identificação do jogo - número único fornecido pelo usuário da FIFA, sendo esse número
superior a 300 e inferior a 999. O número de identificação será fornecido em todos os cadastros e
não pode se repetir, utilize funções.

• Valor arrecadado no jogo com a venda dos ingressos - que deverá estar no intervalo $ 1001 e $
1000000, utilize funções.

• Código da cidade - onde foi realizado o jogo, cidade previamente cadastrada pelo usuário.

---------------------------
Cada cidade terá as seguintes informações:

• Código único - Atribuído e sequencial, sendo a primeira cidade cadastrada com código 1 (no
máximo 9 cidades), utilize funções para leitura e validações.
• Nome da cidade - Não será aceito nome de cidade com nenhum caractere ou superando o
tamanho da string definida na diretiva de substituição de texto denominada (#define
TAM_CIDADE) com valor de 16;
• Os nomes das cidades sempre serão armazenados em letras maiúsculas, devendo ser utilizadas
as funções de manipulação de string apresentadas na disciplina.

---------------------------
Para o cadastro do presidente:

• Além das informações descritas anteriormente, (o programa deverá solicitar assim que for
iniciado) os dados (nome, idade e nacionalidade) do Presidente da FIFA, O nome do Presidente
não poderá ser vazio e nem ultrapassar a quantidade máxima de caracteres definida na diretiva
de substituição de texto MAX_NOME. O nome do Presidente deverá ser normalizado para
primeiras letras maiúsculas e demais minúsculas, "GIANNI INFANTINO" deverá ser
normalizado para "Gianni Infantino" por exemplo. Também deverá ser considerado que a idade
do Presidente deverá ser validada também por uma função onde validará os valores entre 30 e
70 anos.

Durante todo o campeonato está previsto uma quantidade máxima de 32 jogos, que deverá ser
definida em uma diretiva de substituição de texto no programa fonte com o nome MAX_JOGOS.
O programa deverá disponibilizar ao usuário, através de um menu, as seguintes opções:
(a) PRESIDENTE
(b) CADASTRAR CIDADE
(c) CADASTRAR JOGO
(d) LISTAR JOGOS
(e) EXIBIR JOGOS POR CIDADE
(f) ENCERRAR

---------------------------
PRESIDENTE - Para alteração dos dados do Presidente, já que ele deverá ser a primeira
informação cadastrada no sistema. (1 presidente)

CADASTRAR CIDADE - Para cadastro das cidades. (Máximo 9 cidades)

CADASTRAR JOGO - Cadastro em memória, das informações de um jogo por vez garantindo
que a identificação do jogo não se repita. (Máximo 32 jogos)

Ldem crescente do código da Cidade, com as informações
complementares: IdentificaçãISTAR JOGOS - Apresentação dos dados de todos os jogos cadastrados em forma de tabela
(exemplo abaixo), totalmente indentada, com o nome do Presidente, seguida de uma linha com o
cabeçalho constituído, na oro do jogo e Valor arrecadado com as vendas dos ingressos. Os dados
de cada jogo deverão serem apresentados em apenas uma linha, após o cabeçalho, respeitando a
formatação da tabela, ao final na última linha será apresentado o total arrecadado na competição
até o momento. Exemplo:
 FIFA - Relatorio de Arrecadacao
 Presidente: Juan Pablo
---------------------------------------------------
COD CIDADE CIDADE COD JOGO ARRECADACAO
---------------------------------------------------
1 DOHA 303 $5000
2 AL KHOR 301 $4990
---------------------------------------------------
TOTAL: $9990
EXIBIR JOGOS POR CIDADE - Consulta dos jogos cadastrados realizados em uma cidade
fornecida pelo usuário (utilizando o código da cidade). Caso na cidade escolhida não tenha sido
realizado nenhum jogo uma mensagem orientadora deverá ser apresentada ao usuário (ex: "Em
DOHA ainda nao estao cadastrados jogos "). Nesta consulta o resultado deverá ser
ordenado pelo código do jogo, lembre-se que em uma cidade podem ser realizados vários jogos;
ENCERRAR - Encerra o programa.