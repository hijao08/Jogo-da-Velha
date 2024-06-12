#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

// Função para imprimir o tabuleiro
void print_board(char (*board)[3]) {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Função para verificar se alguém ganhou
int check_winner(char board[3][3], char player) {
    int i;
    // Verifica linhas e colunas
    for (i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    // Verifica diagonais
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

// Função para exibir o menu inicial
int display_menu(int *first_game) {
    int choice;
    printf("Bem-vindo ao Jogo da Velha!\n");
    if (*first_game) {
        printf("1. Iniciar Jogo\n");
    } else {
        printf("1. Continuar Jogando\n");
    }
    printf("2. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &choice);
    return choice;
}

// Função para exibir o placar
void display_score(char player1[], char player2[], int *score1, int *score2, int *draws) {
    printf("\nPlacar:\n");
    printf("%s: %d vitorias\n", player1, *score1);
    printf("%s: %d vitorias\n", player2, *score2);
    printf("Empates: %d\n\n", *draws);
}

// Função para pausar o jogo e exibir opções
int pause_game() {
    int choice;
    printf("Jogo pausado.\n");
    printf("1. Continuar Jogando\n");
    printf("2. Reiniciar Jogo\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &choice);
    return choice;
}

// Função para trocar de jogador
void switch_player(char *current_player) {
    *current_player = (*current_player == 'X') ? 'O' : 'X';
}

// Função principal
int main() {
    char board[3][3];
    int row, col;
    int moves;
    char player;
    char player1[50], player2[50];
    int first_game = 1; // Indica se é o primeiro jogo
    int score1 = 0, score2 = 0, draws = 0; // Placar inicial
    int difficulty; // Dificuldade do jogo

    while (1) {
        int choice = display_menu(&first_game);

        if (choice == 1) {
            if (first_game) {
                // Solicita o nome dos jogadores apenas no primeiro jogo
                printf("Digite o nome do Jogador 1 (X): ");
                scanf("%s", player1);
                printf("Digite o nome do Jogador 2 (O): ");
                scanf("%s", player2);
                printf("Escolha a dificuldade (1: Facil, 2: Medio, 3: Dificil): ");
                scanf("%d", &difficulty);
                first_game = 0; // Define que o primeiro jogo já ocorreu
            }

            // Inicializa o tabuleiro vazio
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    board[i][j] = ' ';
                }
            }
            moves = 0;
            player = 'X'; // Começa com o jogador X

            // Loop principal do jogo
            while (1) {
                // Imprime o tabuleiro
                print_board(board);

                // Tempo de jogada dependendo da dificuldade
                int time_limit;
                switch (difficulty) {
                    case 1: // Fácil
                        time_limit = 20;
                        break;
                    case 2: // Médio
                        time_limit = 10;
                        break;
                    case 3: // Difícil
                        time_limit = 5;
                        break;
                    default:
                        time_limit = 30; // Valor padrão para facilidade
                        break;
                }

                // Recebe a jogada do jogador atual
                printf("Jogador %s (%c), informe a linha e a coluna (Exemplo: 1 1) ou (4 4)para pausar: ", (player == 'X') ? player1 : player2, player);
                time_t start_time = time(NULL); // Obtém o tempo inicial
                scanf("%d %d", &row, &col);
                if (row == 4) {
                    int choice = pause_game();
                    if (choice == 1) {
                        continue; // Continua jogando
                    } else if (choice == 2) {
                        break; // Reiniciar o jogo
                    } else if (choice == 3) {
                        printf("Saindo do jogo. Ate a proxima!\n");
                        return 0; // Sair do jogo
                    }
                }

                // Verifica se o tempo acabou
                time_t end_time = time(NULL); // Obtém o tempo atual
                double elapsed_time = difftime(end_time, start_time); // Calcula o tempo decorrido
                if (elapsed_time > time_limit) {
                    printf("Tempo esgotado! Jogador %s (%c) excedeu o limite de tempo.\n", (player == 'X') ? player1 : player2, player);
                    switch_player(&player); // Troca o jogador
                    continue; // Continua o loop, permitindo que o próximo jogador faça sua jogada
                }

                // Verifica se a posição está vazia
                if (row < 1 || row > 3 || col < 1 || col > 3) {
                    printf("Posicao invalida. Por favor, escolha uma posicao de 1 a 3.\n");
                    continue; // Pula para a próximo loop
                }
                if (board[row - 1][col - 1] != ' ') {
                    printf("Posicao ocupada. Por favor, escolha outra.\n");
                    continue; // Pula para a próximo loop
                }

                board[row - 1][col - 1] = player; // Coloca a marca do jogador na posição escolhida
                moves++; // Incrementa o número de jogadas

                // Verifica se o jogador atual ganhou
                if (check_winner(board, player)) {
                    print_board(board);
                    printf("Jogador %s (%c) ganhou!\n", (player == 'X') ? player1 : player2, player);
                    if (player == 'X') {
                        score1++; // Incrementa o placar do jogador 1
                    } else {
                        score2++; // Incrementa o placar do jogador 2
                    }
                    break; // Sai do loop, jogo terminado
                }

                // Verifica se houve empate
                if (moves == 9) {
                    print_board(board);
                    printf("Empate!\n");
                    draws++; // Incrementa o número de empates
                    break; // Sai do loop, jogo terminado
                }

                // Troca de jogador
                switch_player(&player);
            }

            // Exibe o placar
            display_score(player1, player2, &score1, &score2, &draws);

        } else if (choice == 2) {
            printf("Saindo do jogo. Ate a proxima!\n");
            break; // Sai do loop, terminando o programa
        } else {
            printf("Opcao invalida. Por favor, escolha 1 ou 2.\n");
        }
    }

	return 0;
}