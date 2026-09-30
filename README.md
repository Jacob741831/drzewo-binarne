🌳 Drzewo binarne wyszukiwania w C++

Program przedstawia implementację binarnego drzewa wyszukiwania (BST — Binary Search Tree) w języku C++.

Program umożliwia:

dodawanie liczb całkowitych do drzewa,

automatyczne umieszczanie elementów w odpowiednich gałęziach,

wypisywanie elementów drzewa w kolejności rosnącej,

wizualne przedstawienie struktury drzewa,

automatyczne zwalnianie pamięci po zakończeniu programu.

📌 Zasada działania

Każdy element drzewa jest reprezentowany przez strukturę drzewo, która zawiera:

a — wartość przechowywaną w węźle,

lewy — wskaźnik na lewe poddrzewo,

prawy — wskaźnik na prawe poddrzewo.

Dla każdego węzła obowiązuje zasada:

lewe poddrzewo  <  węzeł  <=  prawe poddrzewo


Oznacza to, że:

liczby mniejsze od wartości węzła trafiają w lewo,

liczby większe lub równe trafiają w prawo.

Przykład

Dla kolejno dodanych wartości:

20 10 30 5 15 25 35


otrzymujemy:

        20
       /  \
     10    30
    /  \   / \
   5   15 25 35

🛠️ Główne elementy programu
struct drzewo

Struktura reprezentująca pojedynczy węzeł:

struct drzewo
{
    int a;
    struct drzewo *lewy;
    struct drzewo *prawy;
};


Każdy węzeł przechowuje swoją wartość oraz adresy swoich dzieci.

Klasa DrzewoBinarne

Klasa zarządza całym drzewem. Posiada prywatny wskaźnik:

drzewo *korzen;


który wskazuje na korzeń drzewa.

➕ Dodawanie elementów

Za dodawanie liczb odpowiada funkcja:

void dodajLiczbe(int wartosc)


Nowy element jest tworzony dynamicznie za pomocą new.

Następnie program rozpoczyna wyszukiwanie miejsca od korzenia:

Jeżeli drzewo jest puste, element zostaje korzeniem.

Jeżeli nowa wartość jest mniejsza od aktualnego węzła — przechodzimy w lewo.

Jeżeli jest większa lub równa — przechodzimy w prawo.

Proces trwa do momentu znalezienia pustego miejsca.

🔢 Sortowanie elementów

Za wypisanie elementów w kolejności rosnącej odpowiada:

void sortujIWypisz()


Wykorzystuje ona przejście in-order, czyli:

lewe poddrzewo
        ↓
     węzeł
        ↓
prawe poddrzewo


Dzięki właściwościom drzewa BST wartości są wypisywane automatycznie od najmniejszej do największej.

Dla przykładowych danych wynik będzie:

Posortowane elementy drzewa: 5 10 15 20 25 30 35

🌲 Wyświetlanie drzewa

Funkcja:

void wypiszJakoDrzewo()


prezentuje strukturę drzewa w formie tekstowej.

Przykładowy wynik:

Korzen -> 20
 Prawy: 30
     P: 35
     L: 25
 Lewy:  10
     P: 15
     L: 5


Oznaczenia:

Korzen — korzeń drzewa,

P — prawe poddrzewo,

L — lewe poddrzewo.

🧹 Zarządzanie pamięcią

Ponieważ węzły są tworzone dynamicznie przy pomocy:

new drzewo;


należy je później usunąć.

Odpowiada za to destruktor:

~DrzewoBinarne()
{
    usunDrzewo(korzen);
}


Funkcja usunDrzewo() rekurencyjnie przechodzi po całym drzewie i usuwa każdy węzeł za pomocą:

delete wezel;


Dzięki temu pamięć zaalokowana przez program jest prawidłowo zwalniana.

▶️ Przykładowe dane

W funkcji main() do drzewa dodawane są:

20
10
30
5
15
25
35


Struktura drzewa:

        20
       /  \
     10    30
    /  \   / \
   5   15 25 35

💻 Kompilacja i uruchomienie

Program wymaga kompilatora obsługującego język C++.

Przykładowo przy użyciu g++:

g++ main.cpp -o drzewo


Następnie:

Linux / macOS
./drzewo

Windows
drzewo.exe

📦 Wykorzystane biblioteki

Program korzysta z:

#include <iostream>
#include <queue>
#include <string>


W praktyce w obecnej wersji programu potrzebne są:

<iostream> — obsługa cout,

<string> — obsługa typu string.

Biblioteka <queue> jest dołączona, ale w aktualnej wersji programu nie jest wykorzystywana.

⏱️ Złożoność

Dla drzewa o wysokości h dodanie elementu wymaga przejścia maksymalnie przez h poziomów:

O(h)


Dla dobrze zbalansowanego drzewa:

O(log n)


W najgorszym przypadku, gdy drzewo staje się podobne do listy:

O(n)


Przejście in-order odwiedzające wszystkie elementy ma złożoność:

O(n)

📚 Cel projektu

Projekt służy do demonstracji podstawowych zagadnień związanych z:

drzewami binarnymi,

binarnymi drzewami wyszukiwania,

wskaźnikami,

dynamiczną alokacją pamięci,

rekurencją,

przechodzeniem po strukturach danych,

zarządzaniem pamięcią w C++.

👨‍💻 Podsumowanie

Program tworzy binarne drzewo wyszukiwania, dodaje do niego liczby całkowite, następnie:

wypisuje elementy w kolejności rosnącej,

przedstawia strukturę drzewa w formie tekstowej,

usuwa wszystkie dynamicznie utworzone węzły przy zakończeniu działania programu.
