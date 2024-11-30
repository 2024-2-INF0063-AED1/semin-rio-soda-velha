# Projeto do jogo da velha

Autores: Erick Marinho Fleury  
	  Maria Luiza Monteiro Espindola Cardoso

O trabalho tem como objetivo explorar e adaptar o clássico "jogo da velha" para as plataformas virtuais, trabalhando com algoritmos"fora da reta" buscando experimentar e explorar as maneiras de adaptar as mecânicas características do jogo da velha original para a máquina de modo a produzir resultados do jogo de uma forma alternativa às opções atuais presentes na internet.

Palavras-chave: jogo da velha, jogo, algoritmo.

# 1 Introdução

## 1.1 Problema

O problema em pauta é a adaptação de um jogo clássico ao ambiente virtual de forma a expandir, se possível, os conceitos do jogo. Tendo como objetivo explorar ao máximo as opções do jogo base e adicionar novas ideias adquiridas ao longo de pesquisas na internet, tendo como objetivo 3 possíveis modos de jogo, o jogo clássico que segue as regras originais do jogo, uma opção que expande o tamanho do tabuleiro de forma personalizada pelo jogador, adicionando novas casas e possibilidades estratégicas e por fim um novo modo de jogo (jogo da velha infinito) que dinamiza e evita resultados inconclusivos do jogo (o jogo resulta em "velha", sem ganhadores).

## 1.2 Literatura

Tomamos como referência alguns sites e um vídeo que influenciaram na criação de novos modos de jogo e dos algoritmos aplicados no código. Dentre essas referências se encontram:

[https://en.wikipedia.org/wiki/Tic-tac-toe](https://en.wikipedia.org/wiki/Tic-tac-toe)

A página da wikipedia do jogo da velha em inglês é mais completa quando comparada à página em portugues portanto é uma boa fonte de informações a respeito de como o jogo da velha e suas estratégias funcionam.

[https://pt.wikipedia.org/wiki/Jogo\_da\_velha](https://pt.wikipedia.org/wiki/Jogo_da_velha)

Mesmo não sendo tão completa como a página em inglês, a versão em portuges ainda auxilia bastante no entendimento dos conceitos do jogo de forma aprofundada.

[https://vm.tiktok.com/ZMh7Yq8dm/](https://vm.tiktok.com/ZMh7Yq8dm/)

Este é um exemplo dos vídeos que motivaram a criação do modo de jogo dinâmico no projeto.

## 1.3 Dataset

Os datasets a serem utilizados serão as entradas dos usuários que serão armazenadas durante a execução do jogo.

## 1.4 Métodos

Explorar as possibilidades do jogo e criar algoritmos que possuam propriedades matemáticas mais aparentes, e usar de métodos pouco utilizados para forçar uma aparência maior de experiência, a fim de promover um *take* mais experimental e evitar repetições de códigos já previamente inscritos.  
Utilizaremos muito conhecimentos adquiridos durante as classes de Estrutura de Dados 1 para executar maior parte da lógica que foi desenvolvida em grupo.

## 1.5 Avaliação

Os resultados serão medidos através de testes feitos pela equipe visando encontrar “*bugs*” ou outros tipos de erros que possam aparecer durante a execução do programa. O projeto será classificado como finalizado quando os objetivos forem atingidos e todos (ou caso não seja possível, a maioria) dos problemas sejam resolvidos.

# 2 Fundamentos Teóricos

A ideia principal do projeto, por ser experimental, será utilizar métodos que não são amplamente utilizados para desenvolver a lógica/algoritmos de jogos da velha, especificamente utilizando matrizes de segunda ordem. Com isso iremos trabalhar em cima de um único vetor, se possível, para trabalhar com operações aritméticas e matemática de possibilidades para concluirmos uma vitória ou uma possível “*velha”*.   
	Também procurando aplicar os conhecimentos das aulas de Estrutura de Dados 1, será feito um encaixe do que for possível de recortes do conteúdo ministrado em aulas para nosso projeto, a fim de auxiliar no que for possível em fazer um código com resultados mais promissores, dignos de ser considerado um experimento.

# 3 Metodologia

![Captura de tela 2024-11-21 152858](https://github.com/user-attachments/assets/8081fba0-0e8e-4633-b5ea-4a6d545ac7d3)


# 4 Resultados

Os resultados foram positivos, foi possível criar o jogo em console com uma interface gráfica que não deixa tudo muito poluído, com funções que limpam a cada nova jogada deixando tudo bem fluido. Foi possível limpar bastante o código com métodos inovativos, como o grid search para verificar as vitórias do jogo e também o uso de vetores para gerar o jogo.
![image](https://github.com/user-attachments/assets/d7443c84-b5a1-46da-87f6-1fd0a5dff581)
Nesta imagem podemos ver o modo de jogo padrão que foi implementado em nosso grupo, fortificando ainda nossa metodologia que serviu como um norte para o resultado final.

Praticamente temos funções que preparam o jogo para ser executado e também que exibem o jogo inicialmente, e rodamos um loop no método principal que possuí algoritmos de checagem em grid, para fazer boa parte do jogo funcionar. O jogo funciona dentro de um "do/while" quase infinito mas que por depender das entradas não necessáriamente é infinito e se uma condição de vitória for alcançada o jogo irá voltar ao menu.


# 5 Conclusões

Concluímos que é possível criar um jogo da velha "xique" usando métodos sofisticados de estrutura de dados aplicados em vetores, usando a linguagem C e técnicas de estrutura de dados como Grid Search e métodos de planificação de vetores.

# Referências

[https://en.wikipedia.org/wiki/Tic-tac-toe](https://en.wikipedia.org/wiki/Tic-tac-toe)  
[https://pt.wikipedia.org/wiki/Jogo\_da\_velha](https://pt.wikipedia.org/wiki/Jogo_da_velha)  
[https://vm.tiktok.com/ZMh7Yq8dm/](https://vm.tiktok.com/ZMh7Yq8dm/)
