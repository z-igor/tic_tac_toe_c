#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int
rnd_chs() {
    char x;
    srand(time(NULL));
    if(rand()%2) {
        return x = 'X';
    } else {
        return x = 'O';
    }
}

int
trg(int k) {
    return k *= (-1);
}

void
grid(int arrayI[3][3]) { /*Сетка 3х3*/
    int n = 1;
    // memset(arrayI, 0, sizeof(arrayI));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arrayI[i][j] = n++;
            printf("[ %d ]", arrayI[i][j]);
        }
        printf("\n");
    }
}

void
selectCell(int arrayI[3][3], char arrayC[3][3]) {
    printf("Введите номер ячейки: ");
    int x = getchar() - '0', rnd = 0, k = 1;
    printf("\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if( x == arrayI[i][j]) {
                k = k * (-1);
                if(k == -1 && rnd_chs() == 'O') {
                    arrayC[i][j] = 'O';
                } else {
                    arrayC[i][j] = 'X';
                }

            }
            printf("[ %c ]", arrayC[i][j]);
        }
        printf("\n");
    }
}

int main (void) {
    // system("chcp 1251");
    // system("cls");
    int matrI[3][3], flag = 1;
    char matrC[3][3], you, he;
    memset(matrI, 0, sizeof(matrI));
    memset(matrC, '-', sizeof matrC);
    you = rnd_chs();
    if(you == 'X') {
        he = 'O';
    } else {
        he = 'X';
    }
    printf("Выберите ячейку в сетке, куда хотите поставить крестик/нолик\nВы ходите [%c]\nСоперник ходит [%c]\n", you, he);
    grid(matrI);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            while(matrC[i][j] != 'X' && matrC[i][j] != 'O') {
                selectCell(matrI, matrC);
            }
        }
    }
    printf("Сетка заполнена!");
    return 0;
}
