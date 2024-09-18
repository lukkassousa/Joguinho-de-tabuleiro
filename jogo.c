#include <stdio.h>

#define MAX_POSICAO 10

void mostrarTabuleiro(int pos1, int pos2) {
    for (int i = 1; i <= MAX_POSICAO; i++) {
        if (i == pos1) {
            printf("A "); // Jogador 1
        } else if (i == pos2) {
            printf("B "); // Jogador 2
        } else {
            printf(". "); // Espaço vazio
        }
    }
    printf("\n");
}

int main() {
    int pos1 = 1; // Posição do Jogador 1
    int pos2 = 1; // Posição do Jogador 2
    int jogando = 1;
    int turno = 1;

    while (jogando) {
        mostrarTabuleiro(pos1, pos2);
        printf("Turno do Jogador %d\n", turno);
        printf("Digite o número de casas para mover (1 a 3): ");

        int movimento;
        scanf("%d", &movimento);

        if (movimento < 1 || movimento > 3) {
            printf("Movimento inválido. Tente novamente.\n");
            continue;
        }

        if (turno == 1) {
            pos1 += movimento;
            if (pos1 >= MAX_POSICAO) {
                printf("Jogador 1 ganhou!\n");
                jogando = 0;
            }
            turno = 2;
        } else {
            pos2 += movimento;
            if (pos2 >= MAX_POSICAO) {
                printf("Jogador 2 ganhou!\n");
                jogando = 0;
            }
            turno = 1;
        }
    }

    return 0;
}
