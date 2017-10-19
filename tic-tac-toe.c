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

/*------------== 1? ==------------ Почему ошибка?
int rnd_chs() {
    char x;
    srand(time(NULL));
    rand()%2 ? x = 'X' : x = 'O';
    return x;
}
...
printf("... [%c]", rnd_chs());
--> Ошибка во втором присваивании: error: lvalue required as left operand of assignment
      rand()%2 ? x = 'X' : x = 'O';
                             ^
*/

/*-----------== 2? ==------------
Как сделать функцию, чтобы можно было вводить N-размерность сетки?
    int grid(int array[N][N]) { //Ругаетсяяяя
        memset(array, 0, sizeof(array));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                array[i][j] = n++;
                printf("[ %d ]", array[i][j]);
            }
            printf("\n");
        }
    }
*/

/*-----------== 3? ==------------

void
selectCell(int arrayI[3][3], char arrayC[3][3]) {
    int x = getchar() - '0';
    memset(arrayC, '-', sizeof arrayC);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if( x == arrayI[i][j]) {
                arrayC[i][j] = 'X';
            }
            printf("[ %c ]", arrayC[i][j]);
        }
        printf("\n");
    }
}

Вводим 5 и на 5, т.е. 4 элементе 88, как сделать 'W'?
[ 0 ][ 0 ][ 0 ]
[ 0 ][ 88 ][ 0 ]
[ 0 ][ 0 ][ -115 ]
Почему 8 элемент равен чему-то? Как это исправить?
*/

/*-----------== 4? ==------------
    int trg(int k) {
            return k *= (-1);
        }
    Как сделать функцию, чтобы она меняла Х на О в функции selectCell()
    void selectCell(int arrayI[3][3], char arrayC[3][3]) {
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

*/