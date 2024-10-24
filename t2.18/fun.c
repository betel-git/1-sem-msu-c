#include "fun.h"
/* Итак, алгоритм:
1. Создать n-мерный массив
2. задать базу в виде случаев n = 1, n = 2
3. Отрабатываем крайние случаи с единичкой
4. Новый второй элемент = старый первый + второй старый
5. Новый третий элемент = второй старый + третий старый
6. Новый четвёртый элемент = третий старый + четвертый старый
 */

void Pascal(int *arr, int n) {
    int i = 1, old = 1, megaold = 1, j = 3;
    // в качестве базовых случаев рассмотрим n = 1 и n = 2
    if (n == 1) {
        arr[0] = 1;
    }
    if (n == 2) {
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 1;
    }
    // основной случай n > 2
    if (n != 1 && n != 2) {
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 1;
        // зададим нулевое значение для всех элементов массива
        for (int i = 3; i <= n; i++) {
            arr[i] = 0;
        }
        // каждую итерацию мы рассматриваем биномиальные коэффициенты для некоторого m, чтобы потом прийти к n 
        while (j <= n) {
            i = 1;
            // шаг от m к m + 1
            while (arr[i] > 0) {
                megaold = old;
                old = arr[i];
                arr[i] = megaold + arr[i];
                i++;
            }
            arr[i] = 1;
            j++;
        }
    }
}