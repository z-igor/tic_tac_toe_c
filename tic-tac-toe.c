#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int
rnd_chs() {
    char x;
    srand(time(NULL));
    return x = (rand() % 2 ? 'X' : 'O');
}

void
grid(int arrayI[3][3]) { /*Сетка 3х3*/
    int n = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arrayI[i][j] = n++;
            printf("[ %d ]", arrayI[i][j]);
        }
        printf("\n");
    }
}

char
check_win(char aC[3][3], char you) { // по горизонтале проверяет тройку
    int bl = 1;
    printf("You=%c, He=%c\n", you, he);
    for (int i = 0; i < 3; i++) {
        for (int j=0; j < 3;j++) {
            while(bl && j < 3) {
                if(aC[i][j] == you) { // c YОU работает, с HЕ не работает еще
                    printf("You(%c) [%d][%d]=[%c]\n", you, i, j, aC[i][j]);
                    bl = 1;
                    if(j == 2) {
                        printf("You(%c) [%d][%d]=[%c]\n", you, i, j, aC[i][j]);
                        return aC[i][j];
                    }
                    j++;
                } /*else if(aC[i][j] == he) {
                    printf("He(%c) [%d][%d]=[%c]\n", he, i, j, aC[i][j]);
                    bl = 1;
                    j++;
                    if(j == 2) {
                        printf("You(%c) [%d][%d]=[%c]\n", you, i, j, aC[i][j]);
                        return aC[i][j];
                    }
                }*/
                else {
                    // printf("a[%d][%d]=[%c]\n",i,j, aC[i][j]);
                    i++;
                    j = 0;
                }
            }
        }
    }
}

int
selectCell(int arrayI[3][3], char arrayC[3][3], char you, char he, int *trg) {
    printf("Введите номер ячейки:");
    int x = 0;
    do {
        x = getchar();
    } while (x == '\n');
    x = x - '0';
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (x == arrayI[i][j]) {
                if ( !(*trg) ) {
                    arrayC[i][j] = you;
                    *trg = !(*trg);
                } else {
                    arrayC[i][j] = he;
                    *trg = !(*trg);
                }
            }
            printf("[ %c ]", arrayC[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    // system("chcp 1251");
    // system("clean");
    int matrI[3][3], trg = 0;
    char matrC[3][3], you, he, win;
    memset(matrI, 0, sizeof(matrI));
    memset(matrC, ' ', sizeof(matrC));
    you = rnd_chs();
    he = (you == 'X' ? 'O' : 'X');
    printf("Выберите ячейку в сетке, куда хотите поставить крестик/нолик\nВы ходите [%c]\nСоперник ходит [%c]\n", you, he);
    grid(matrI);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            while (matrC[i][j] == ' ' /*|| (win != you || win != he) */) {
                selectCell(matrI, matrC, you, he, &trg);
                // win = check_win(matrC, you);
            }
        }
    }
    printf("Выиграл = %c", check_win(matrC, you));
    // system("pause");
    return 0;
}

// char check(void) {
//  int t;
//  char *p;
//  for(t=0; t<3; t++) { //строки
//  p = &matrix[t] [0];
//  if (*p==* (p+1) && * (p+1)==*(p+2))
//    return *p;
//  }
//  for(t=0; t<3; t++) { // столбцы
//  p = &matrix[0][t];
//  if(*p==*(p+3) && *(p+3)==*(p+6))
//    return *p;
//  }
//   диагонали
//  if(matrix[0] [0]==matrix [1] [1] && matrix[1] [1]==matrix [2] [2] )
//  return matrix[0][0];
//  if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2] [0])
//  return matrix[0][2];
//  return SPACE;
// }

// bool Win()
// {
//     int i = 0, j(0);
//     if (((matrix[i][j] == 'X') && (matrix[i][j + 1] == 'X') && (matrix[i][j + 2] == 'X')) || ((matrix[i][j] == 'X') && (matrix[i + 1][j] == 'X') && (matrix[i + 2][j] == 'X')) || ((matrix[i][j] == 'X') && (matrix[i + 1][j + 1] == 'X') && (matrix[i + 2][j + 2] == 'X')) || ((matrix[i + 2][j] == 'X') && (matrix[i + 1][j + 1] == 'X') && (matrix[i][j + 2] == 'X')) || ((matrix[i + 1][j] == 'X') && (matrix[i + 1][j + 1] == 'X') && (matrix[i + 1][j + 2] == 'X')) || ((matrix[i + 2][j] == 'X') && (matrix[i + 2][j + 1] == 'X') && (matrix[i + 2][j + 2] == 'X')) || ((matrix[i][j + 1] == 'X') && (matrix[i + 1][j + 1] == 'X') && (matrix[i + 2][j + 1] == 'X')) || ((matrix[i][j + 2] == 'X') && (matrix[i + 1][j + 2] == 'X') && (matrix[i + 2][j + 2] == 'X')))
//     {
//     cout << "Вы победили!\n";
//     return 0;
//     }
//     else if (((matrix[i][j] == 'O') && (matrix[i][j + 1] == 'O') && (matrix[i][j + 2] == 'O')) || ((matrix[i][j] == 'O') && (matrix[i + 1][j] == 'O') && (matrix[i + 2][j] == 'O')) || ((matrix[i][j] == 'O') && (matrix[i + 1][j + 1] == 'O') && (matrix[i + 2][j + 2] == 'O')) || ((matrix[i + 2][j] == 'O') && (matrix[i + 1][j + 1] == 'O') && (matrix[i][j + 2] == 'O')) || ((matrix[i + 1][j] == 'O') && (matrix[i + 1][j + 1] == 'O') && (matrix[i + 1][j + 2] == 'O')) || ((matrix[i + 2][j] == 'O') && (matrix[i + 2][j + 1] == 'O') && (matrix[i + 2][j + 2] == 'O')) || ((matrix[i][j + 1] == 'O') && (matrix[i + 1][j + 1] == 'O') && (matrix[i + 2][j + 1] == 'O')) || ((matrix[i][j + 2] == 'O') && (matrix[i + 1][j + 2] == 'O') && (matrix[i + 2][j + 2] == 'O')))
//     {
//         cout << "Победил компьютер!\n";
//         return 0;
//     }
//     else return 1;
// }
