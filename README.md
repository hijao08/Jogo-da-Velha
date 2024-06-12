# Jogo da Velha em C

Este é um simples Jogo da Velha (Tic-Tac-Toe) implementado em C. O jogo permite dois jogadores se enfrentarem e inclui funcionalidades como controle de tempo para cada jogada, exibição de placar e a possibilidade de pausar o jogo.

## Funcionalidades

1. **Início do Jogo:**

   - O jogo começa com um menu que permite ao usuário iniciar um novo jogo ou sair.
   - No primeiro jogo, os nomes dos jogadores e a dificuldade (fácil, médio, difícil) devem ser inseridos.

2. **Jogabilidade:**

   - O tabuleiro é representado por uma matriz 3x3.
   - Os jogadores fazem suas jogadas alternadamente, informando a linha e a coluna onde desejam colocar sua marca ('X' ou 'O').
   - Existe um limite de tempo para cada jogada, que varia conforme a dificuldade escolhida.

3. **Controle de Tempo:**

   - Fácil: 20 segundos por jogada
   - Médio: 10 segundos por jogada
   - Difícil: 5 segundos por jogada

4. **Pausa e Reinício:**

   - Os jogadores podem pausar o jogo a qualquer momento e escolher entre continuar jogando, reiniciar o jogo ou sair.

5. **Placar:**
   - O placar exibe o número de vitórias de cada jogador e a quantidade de empates.
   - O placar é atualizado após cada jogo.
