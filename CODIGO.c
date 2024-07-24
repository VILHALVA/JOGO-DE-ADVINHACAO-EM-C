#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numero_secreto, tentativa, tentativas_restantes, max_tentativas = 5;
    srand(time(NULL));

    numero_secreto = rand() % 100 + 1;
    tentativas_restantes = max_tentativas;

    printf("Bem-vindo ao jogo de adivinhação!\n");
    printf("Tente adivinhar o número entre 1 e 100.\n");
    printf("Você tem %d tentativas.\n", max_tentativas);

    while (tentativas_restantes > 0) {
        printf("Digite o seu palpite: ");
        if (scanf("%d", &tentativa) != 1) {
            printf("Entrada inválida. Por favor, insira um número.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (tentativa < 1 || tentativa > 100) {
            printf("Por favor, insira um número entre 1 e 100.\n");
            continue;
        }

        if (tentativa < numero_secreto) {
            printf("O número correto é maior.\n");
        } else if (tentativa > numero_secreto) {
            printf("O número correto é menor.\n");
        } else {
            printf("Parabéns! Você adivinhou o número corretamente!\n");
            break;
        }

        tentativas_restantes--;

        if (tentativas_restantes == 0) {
            printf("Você não conseguiu adivinhar o número. O número correto era %d.\n", numero_secreto);
        } else {
            printf("Tentativas restantes: %d\n", tentativas_restantes);
        }
    }

    return 0;
}
