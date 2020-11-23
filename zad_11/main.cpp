#include <iostream>
#include <omp.h>

int main()
{
    std::cout << "Bez dodatkowych dyrektyw:\n";
    #pragma omp parallel
    std::cout << "Witaj z watku nr " << omp_get_thread_num() << " sposrod " << omp_get_num_threads() << "\n";

    std::cout << "\nDyrektywa omp single\n";
    #pragma omp parallel
    #pragma omp single
    std::cout << "Witaj z watku nr " << omp_get_thread_num() << " sposrod " << omp_get_num_threads() << "\n";

    std::cout << "\nDyrektywa omp master\n";
    #pragma omp parallel
    #pragma omp master
    std::cout << "Witaj z watku nr " << omp_get_thread_num() << " sposrod " << omp_get_num_threads() << "\n";

    std::cout << "\nDyrektywa omp critical\n";
    #pragma omp parallel
    #pragma omp critical
    std::cout << "Witaj z watku nr " << omp_get_thread_num() << " sposrod " << omp_get_num_threads() << "\n";
}

/*
1.
a)
    Za każdym razem wynik działania programu jest taki sam z tą różnicą, że jest wykonywany przez inny wątek.
    Jest to skutek tego, że w danej chwili wątki mogą być ,,zajętę,, innym zadaniem o większym priorytecie lub
    za bardzo obciążone i zgłasza się ten, który jest najbardziej w danej chwili dostępny.
b)
    Komunikaty wchodzą sobie w drogę. Jest to skutek braku synchronizacji. Ma miejsce wtedy wyścig danych(date race).
    Dwa wątki mają dostęp do tej samej pamięci. Powoduje to różne wyniki programu.

2.
a)
    #pragma omp single -> kod jest wykonywany przez jeden wątek(niekocznie master thread)
    Zalety:
    - ten sam wynik działania części programu,
    - możliwość wykonania kodu, który nie wymaga działania na wielu wątkach,
    - ma domyślną bariere po ukończeniiu bloku, gdzie wątki czekają na synchronizację,
    Wady:
    - dyrektywa nie określa, który wątek wwykona blok instrukcji,
    - pozostałe wątki czekają, dopóki ten jeden nie zakończy zadania

b)
    #pragma omp master -> określa, że tylko wątek główny ma wykonać sekcję programu
    Zalety:
    - cały program jest obsługiwany przez jeden wątek,
    Wady:
    - nie ma bariery domyślnej jak dyrektywa single,
    - pozostałe wątki nie wykonują bloku,
c) #pragma omp critical -> tworzy region("sekcje krytyczna"), który może być wykonywany przez co najwyżej jeden wątek naraz
    Zalety:
    - służy do unikania pościgu(race condition) przy dostępie do zmiennych,
    - wykonanie szczególnego kawałka kodu(np. inkremetacja ),
    Wady:
    - kod zawarty w sekcji krytycznej jest kodem szeregowym,
    - niepoprawne użycie, sekcja powinna zawierać kod, który wykonuje się szybko, by nie blokować pracy innych wątków,
 */