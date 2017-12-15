/*
 * Крестики-нолики v0.005
 * матрица N x N
 * |N| <= 200
 * собрать цепочку из трех X или O
 * выиграл тот, кто собрал цепочку первым
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 200
#define DEFLTSIZE 3

char w = ' '; /* глобальная для выигрыша */

/* n size array(матрица[n][n], размер матрицы) */
void n_size_a(int *p, int size) {
   int i, j, c = 1;
   for (i = 0; i < size; i++) {
      for (j = 0; j < size; j++) {
         *(p + i * size + j) = c++; /* 'с' от 1 до размера матрицы в квадрате */
         c < 11    ? printf("[  %d  ] ", *(p + i * size + j)) :\
			c < 101   ? printf("[ %d  ] ",  *(p + i * size + j)) :\
         c < 1001  ? printf("[ %d ] ",   *(p + i * size + j)) :\
         c < 10001 ? printf("[%d ] ",    *(p + i * size + j)) :\
					      printf("[%d] ",     *(p + i * size + j));
      }
      puts("");
   }
}
/*random choose() - предназначен для случайного выбора Х/О*/
char rnd_chs() {
   srand((unsigned int) time(NULL));
   return (rand() % 2 ? 'X' : 'O');
}
/* проверка цепочки(матрица, размер её, текущая строка, текущий столбец, победитель) */
char check_trio(int *q, int size, int i, int j, char win) {
   if((i+1) < size && (j+1) < size && *(q + (i+1) * size + (j+1)) == win && (i-1) >= 0 && (j-1) >= 0   && *(q + (i-1) * size + (j-1)) == win || /* \ */
      (i-1) >= 0   && *(q + (i-1) * size + (j)) == win && (i+1) < size && *(q + (i+1) * size + (j))   == win || /* ↕ */
      (j-1) >= 0   && *(q + (i) * size + (j-1)) == win && (j+1) < size && *(q + (i)   * size + (j+1)) == win || /* ↔ */
      (i+1) < size && (j-1) >= 0 && *(q + (i+1)   * size + (j-1)) == win && (i+1) >= 0 && (j+1) < size && *(q + (i-1) * size + (j+1)) == win || /* / */

      (i-1) >= 0   && *(q + (i-1) * size + (j))   == win && (i-2)  >= 0   && *(q + (i-2) * size + (j))   == win || /* ↑ */
      (i+1) < size && *(q + (i+1) * size + (j))   == win && (i+2)  < size && *(q + (i+2) * size + (j))   == win || /* ↓ */
      (j+1) < size && *(q + (i)   * size + (j+1)) == win && (j+2)  < size && *(q + (i)   * size + (j+2)) == win || /* → */
      (j-1) >= 0   && *(q + (i)   * size + (j-1)) == win && (j-2)  >= 0   && *(q + (i)   * size + (j-2)) == win || /* ← */
      (i-2) >= 0   && (j-2) >= 0   && *(q + (i-2) * size +  (j-2)) == win && (i-1) >= 0   && (j-1) >= 0 && *(q + (i-1) * size + (j-1))   == win || /* °\ */
      (i+1) < size && (j+1) < size && *(q + (i+1) * size +  (j+1)) == win && (i+2) < size && (j+2) < size && *(q + (i+2) * size + (j+2)) == win || /* \. */
      (i-2) >= 0   && (j+2) < size && *(q + (i-2) * size +  (j+2)) == win && (i-1) >= 0   && (j+1) < size && *(q + (i-1) * size + (j+1)) == win || /* /° */
      (i+1) < size && (j-1) >= 0   && *(q + (i+1) * size +  (j-1)) == win && (i+2) < size && (j-2) >= 0 && *(q + (i+2) * size + (j-2))   == win)   /* ./ */ {
      return win;
   }
   return 0;
}

/* input value(матрица, размер её, номер ячейки, переключатель, X/O, O/X) */
char inp_val(int *p, int size, int x, int *trg, char you, char he) {
   int i, j;
   for (i = 0; i < size; i++) {
      for (j = 0; j < size; j++) {
         if (*(p + i * size + j) == x) { /* *(p + i * size + j) == p[i][j] */
            if ( !(*trg) ) { /* если trg == 1, то ставиться you, you зависит от rnd_chs() */
               *(p + i * size + j) = you;
               if(check_trio(p, size, i, j, you)) {
                  w = you;
               }
               *trg = !(*trg); /* меняем значение trg, дабы чередовать X/O */
            } else {
               *(p + i * size + j) = he;
               if(check_trio(p, size, i, j, he)) {
                  w = he;
               }
               *trg = !(*trg);
            }
            printf("[ %c ] ", *(p + i * size + j)); /* выводим char элемент массива в int массиве */
            continue; /* прерывания второго вывода. Без неё, например, если ввести х=5 в 3х3, то будет так: [4] [X] [88] [6] */
         } /* проверка, если p[i][j] == X || O, то печатаем char %c, если значение < 10 или < 100, то форматируем вывод: [ 5 ] или [55 ] */
         (*(p + i * size + j) == 'X' || *(p + i * size + j) == 'O') ? printf("[ %c ] ", *(p + i * size + j)) :
          *(p + i * size + j)  <  10  ? printf("[ %d ] ", *(p + i * size + j)) :
          *(p + i * size + j)  <  100 ? printf("[%d ] ",  *(p + i * size + j)) :
                                 printf("[%d] ",   *(p + i * size + j));
      } puts("");
   }
   return w;
}

/* Проверка: пустые ли ячейки для ничьи */
int check_empty(int *p, int size, int *n) {
   int i, j;
   for (i = 0; i < size; i++) {
      for (j = 0; j < size; j++) {
         if(*(p + i * size + j) == 'X' || *(p + i * size + j) == 'O') {
            (*n)++;
         } else {
            *n = 0;
         }
      }
   }
   return *n;
}

int main() { /*a draw - ничья*/
   int size_grid = 0, input_number_grid = 0, adraw = 0, trg_value = 0, grid[MAXSIZE][MAXSIZE];
    /*memset(grid, 0,  sizeof(grid)); */
   char you = rnd_chs(), he = (you == 'X' ? 'O' : 'X');
   /* Проверка ввода размера матрицы, размер < 100 и > 2 */
   do {
      printf("enter size (2 < size(grid) <= %d)): ", sizeof(grid) / sizeof(grid[0]));
      fflush(stdin); /*вызывает очистку буферов после каждой операции записи*/
   } while(scanf("%d", &size_grid) != 1 && printf("you need to enter number from 3 to %d\n", sizeof(grid) / sizeof(grid[0]))
         || size_grid < DEFLTSIZE     && printf("you need to enter > 2\n")
         || size_grid > (sizeof(grid) / sizeof(grid[0])) && printf("you need to enter <= %d and > 0\n", sizeof(grid) / sizeof grid[0]));
   n_size_a((int *) grid, size_grid);
   printf("First play [ %c ], ", you);
   while(w == ' ') {
      do { /* Проверка ввода числа ячейки, чтобы было число в заданном диапозоне, не было символов */
         printf("enter item of grid: ");
         fflush(stdin); /* вызывает очистку буферов после каждой операции записи */
      } while(scanf("%d", &input_number_grid) != 1 && printf("you need to enter number from 3 to %d\n", size_grid*size_grid)
            || input_number_grid < 1             && printf("you need to enter > 0\n")
            || input_number_grid > (size_grid*size_grid) && printf("you need to enter <= %d\n", size_grid*size_grid));
      inp_val((int *) grid, size_grid, input_number_grid, &trg_value, you, he);

        if(w == 'X' || w == 'O') {
            continue;
        }
        else if(check_empty((int *) grid, size_grid, &adraw) != size_grid*size_grid) {
         printf("next playing [ %c ]\n", trg_value ? he : you);
         adraw=0;
      } else {
         puts("No one won! Draw");
         return 0;
      }
   }
   printf("\nWon %c!!!", w);
    /*system("pause");*/
   return 0;
}
