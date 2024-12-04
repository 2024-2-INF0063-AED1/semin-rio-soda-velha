#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define prints(x)                       \
    for (int i = 0; i < strlen(x); i++) \
    printf("%c", x[i])
#define print(x) printf("%d", x)
#define printb(x) printf("%s", x ? "true" : "false")
#define HERE printf("HERE\n")

// Vetor utilizado para andar no tabuleiro
int movs[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

// Tamanho do tabuleiro
int n = 0;
// Array que representa o tabuleiro
char *tabuleiro;
// Array que armazena a string de vitoria (xxx... ou ooo...)
char *vitoria;

// Array que armazena as posições mais antigas atuais do X e do O
char **posicaoArr;

// Função que verifica se a posicao após o movimento é válida
bool isNotValid(int x, int y)
{
    return !(x >= 0 && x < n && y >= 0 && y < n);
}

// Função que verifica se o jogador venceu usando Grid Search
bool verificaVitoria(int x, int y, int jogador)
{
    // Para cada par de movimentos em movs
    for (int k = 0; k < sizeof(movs) / sizeof(*movs); k++)
    {
        int i = x, j = y;
        bool final = true;

        // Para cada posição no array de vitoria
        for (int l = 0; l < n; l++)
        {
            // Se a posição não é válida ou o simbolo na posição do tabuleiro atual é diferente do simbolo
            // na posição l do array de vitoria (varia de acordo com o jogador atual)
            if (isNotValid(i, j) || tabuleiro[n * i + j] != vitoria[n * jogador + l])
            {
                final = false;
                break;
            }
            i += movs[k][0];
            j += movs[k][1];
        }
        if (final)
        {
            return true;
        }
    }

    return false;
}

// Função chamada quando é necessario preparar o jogo (tamanho do tabuleiro e array de vitoria dependem da opção escolhida)
int preparaJogo(int i)
{
    // Se a opção escolhida for 2 ou 3, o jogador escolhe o tamanho do tabuleiro
    if (i != 1)
    {
        while (n < 3)
        {
            printf("Digite o tamanho do tabuleiro maior ou igual a 3 (0 finaliza o programa): ");
            if (!scanf("%d", &n))
            {
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                {
                } // Discard that line up to the newline
                printf("Entrada invalida!\n");
                n = -1;
            }

            if (n == 0)
            {
                return 0;
            }
        }
    } // Se a opção escolhida for 1, o tamanho do tabuleiro é 3
    else
    {
        n = 3;
    }

    // Libera a memória alocada anteriormente para o tabuleiro, o array de vitoria e o array das posições para evitar memory leaks
    free(tabuleiro);
    free(vitoria);
    // Aloca a memória para o tabuleiro e o array de vitoria
    tabuleiro = (char *)malloc(n * n * sizeof(char));
    vitoria = (char *)malloc(n * 2 * sizeof(char));
    if (i == 3)
    {
        free(posicaoArr);
        posicaoArr = (char **)malloc(n * 2 * sizeof(char *));
    }

    // Inicializa o tabuleiro com espaços vazios
    for (int i = 0; i < n * n; i++)
    {
        tabuleiro[i] = ' ';
    }

    // Inicializa o array de vitoria com os simbolos de vitoria
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vitoria[n * i + j] = i ? 'O' : 'X';
        }
    }
    return 1;
}

// Função que printa o tabuleiro atual
void mostraTabuleiro()
{
    // Printa o tabuleiro atual para o jogador
    printf("Tabuleiro:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tabuleiro[n * i + j] == ' ')
            {
                printf("  %d  ", n * i + j + 1);
            }
            else
            {
                printf("  %c  ", tabuleiro[n * i + j]);
            }
        }
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            printf("------");
        }
        printf("\n");
    }
}

int main()
{
    // Loop principal do programa que lê o tamanho do tabuleiro e executa o jogo ate que o valor inserido seja 0
    do
    {
        // Variavel que armazena a opção escolhida pelo jogador
        int p;
        // Loop que garante que o jogador escolha uma opção válida
        do
        {
            printf("Digite 1 para jogar o jogo base, 2 para o jogo de tamanho customizavel e 3 para o modo dinamico (0 para finalizar o programa): ");
            if (!scanf("%d", &p))
            {
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                {
                } // Discard that line up to the newline
                printf("Entrada invalida!\n");
            }
            if (p == 0)
            {
                return 0;
            }
        } while (p != 0 && p != 1 && p != 2 && p != 3);

        // Chama a variavel para preparar o jogo
        if (!preparaJogo(p))
        {
            return 0;
        }

        // Variavel que armazena o jogador atual (0 ou 1), é utilizado na função que verifica a vitoria para
        // indexar a string de vitoria correta
        int jogador = 0;

        // Posição escolihada pelo jogador para realizar o movimento
        int posicao;

        // Variavel que armazena o turno atual
        int turno = 0;

        // Variavel que armazena as variaveis para indexar as posições mais antigas atuais do X e do O
        int indexX = 0, indexO = n;

        // Variavel que armazena se o jogo acabou
        int final = false;

        // Loop do jogo
        do
        {
            // Mostra o tabuleiro
            mostraTabuleiro();

            // Le a posição escolhida pelo jogador
            printf("Jogador %d, digite a posicao: ", jogador + 1);
            while (!scanf("%d", &posicao))
            {
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                {
                } // Discard that line up to the newline
                printf("Entrada invalida!\n");
            }

            // Se a posição escolhida é válida, realiza o movimento e verifica se o jogador venceu caso não então
            // o jogo continua com o proximo jogador (jogador+1)
            if ((tabuleiro[posicao - 1] != 'X' && tabuleiro[posicao - 1] != 'O') && posicao >= 0 && posicao <= n * n)
            {
                tabuleiro[posicao - 1] = jogador == 0 ? 'X' : 'O';

                if (p == 3 && jogador == 0)
                {
                    if (turno >= n * 2)
                    {
                        *posicaoArr[jogador * n + indexX] = ' ';
                    }
                    posicaoArr[jogador * n + indexX] = &tabuleiro[posicao - 1];
                    indexX++;
                    if (indexX >= n)
                    {
                        indexX = 0;
                    }
                }
                else if (p == 3 && jogador)
                {
                    if (turno >= n * 2)
                    {
                        *posicaoArr[jogador * n + indexO] = ' ';
                    }
                    posicaoArr[jogador * n + indexO] = &tabuleiro[posicao - 1];
                    indexO++;
                    if (indexO >= 2 * n)
                    {
                        indexO = n;
                    }
                }

                // Verifica se o jogador venceu
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (verificaVitoria(i, j, jogador))
                        {
                            final = true;
                            break;
                        }
                    }
                    if (final)
                    {
                        break;
                    }
                }

                // Limpa o console antes de imprimir
                system("cls");
                if (final)
                {
                    printf("Jogador %d venceu!\n", jogador + 1);
                    mostraTabuleiro();
                    printf("Digite qualquer numero para continuar jogando: ");
                    int x;
                    while (!scanf("%d", &x))
                    {
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF)
                        {
                        } // Discard that line up to the newline
                        printf("Entrada invalida!\n");
                    }
                    if (!x)
                    {
                        return 0;
                    }
                    n = 0;
                    p = -1;
                }
                else if (turno + 1 >= n * n && p != 3)
                {
                    printf("Empate!\n");
                    mostraTabuleiro();
                    printf("Digite qualquer numero para continuar jogando: ");
                    int x;
                    while (!scanf("%d", &x))
                    {
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF)
                        {
                        } // Discard that line up to the newline
                        printf("Entrada invalida!\n");
                    }
                    if (!x)
                    {
                        return 0;
                    }
                    n = 0;
                    p = -1;
                }
                jogador = (jogador + 1) % 2;
                turno++;
            }
            // Se a posição escolhida é inválida, printa uma mensagem de erro
            else
            {
                // Limpa o console antes de imprimir
                system("cls");
                printf("Posicao invalida!\n");
            }
        } while (!final);
    } while (true);
}