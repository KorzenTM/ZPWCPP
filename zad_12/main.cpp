#include <stdio.h>
#include <time.h>
#include <omp.h>

int main()
{
    const int N = 1000000000;
    int i = 0;
    double sum = 0;
    clock_t t0 = clock();
    #pragma omp parallel for private(i) reduction(+:sum)
    for (i = N - 1; i >= 0; --i)
    {
        sum += 1.0 / (i + 1.0);
    }
    clock_t t1 = clock();
    printf("s = %g\n", sum);
    printf("t = %g\n", ((double)t1 - t0)/CLOCKS_PER_SEC);
}

/*
 * Zadanie 1
 *a) Wyniki w obydwu wersjach są inne.
 * Wersja równoległa -> 19.0267
 * Wersja szeregowa -> 18.8079
 *b) Wyniki wersji rownoleglej w zależności od liczby wątków:
    *   Liczba Wynik     Czas
    *   1      18.8079   0:06.43
    *   2      18.8704   0:03.07
    *   4      19.0267   0:01.74
*c)Utrata dokładności typu float. Jeśli użyjemy mniejsze N to wtedy wyniki będą takie same. Należy użyć typ double.
*d)Nie jest to czas rzeczywisty. clock() zwraca czas CPU yżywany przez proces.
*e) Funkcja nie nadaje się do oceny przyspieszenia wersji równoległych programów, ponieważ czas procesora może zawierać
* czas bezczynności(np. wątki czekające przy barierach bądź poza obszarami równoległymi)
*f)Rzeczywisty czas wykonuwania programu -> elapsed lub real
 * Liczba użytych wątków -> CPU
*/