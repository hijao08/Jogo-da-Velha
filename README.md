Jogo da Velha em C
Este é um simples Jogo da Velha (Tic-Tac-Toe) implementado em C. O jogo permite dois jogadores se enfrentarem e inclui funcionalidades como controle de tempo para cada jogada, exibição de placar e a possibilidade de pausar o jogo.

Funcionalidades
Início do Jogo:

O jogo começa com um menu que permite ao usuário iniciar um novo jogo ou sair.
No primeiro jogo, os nomes dos jogadores e a dificuldade (fácil, médio, difícil) devem ser inseridos.
Jogabilidade:

O tabuleiro é representado por uma matriz 3x3.
Os jogadores fazem suas jogadas alternadamente, informando a linha e a coluna onde desejam colocar sua marca ('X' ou 'O').
Existe um limite de tempo para cada jogada, que varia conforme a dificuldade escolhida.
Controle de Tempo:

Fácil: 20 segundos por jogada
Médio: 10 segundos por jogada
Difícil: 5 segundos por jogada
Pausa e Reinício:

Os jogadores podem pausar o jogo a qualquer momento e escolher entre continuar jogando, reiniciar o jogo ou sair.
Placar:

O placar exibe o número de vitórias de cada jogador e a quantidade de empates.
O placar é atualizado após cada jogo.

Uso
Início:

Execute o jogo e escolha entre iniciar um novo jogo ou sair.
Se for o primeiro jogo, insira os nomes dos jogadores e a dificuldade.
Jogabilidade:

Os jogadores devem informar a linha e a coluna onde desejam jogar (por exemplo, "1 1").
Para pausar o jogo, insira "4 4".
Pausa:

Durante a pausa, escolha entre continuar jogando, reiniciar ou sair.
Final do Jogo:

O jogo termina quando um jogador ganha ou há um empate.
O placar é exibido e o jogo pode ser reiniciado ou encerrado.
Exemplo de Uso
sh
Copiar código
Bem-vindo ao Jogo da Velha!

1. Iniciar Jogo
2. Sair
   Escolha uma opcao: 1
   Digite o nome do Jogador 1 (X): Alice
   Digite o nome do Jogador 2 (O): Bob
   Escolha a dificuldade (1: Facil, 2: Medio, 3: Dificil): 2

|     |
| --- | --- | --- |
|     |
| --- | --- | --- |
|     |

Jogador Alice (X), informe a linha e a coluna (Exemplo: 1 1) ou (4 4) para pausar: 1 1

| X   |     |
| --- | --- | --- |
|     |
| --- | --- | --- |
|     |

Contribuição
Sinta-se à vontade para fazer fork deste repositório e contribuir com melhorias. Pull requests são bem-vindos.
