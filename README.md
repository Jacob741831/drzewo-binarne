# Dokumentacja programu – Drzewo Binarne

## 1. Opis programu

Program przedstawia implementację drzewa binarnego wyszukiwania (BST – Binary Search Tree) w języku C++.

Program umożliwia:
- tworzenie pustego drzewa binarnego,
- dodawanie liczb całkowitych do drzewa,
- automatyczne rozmieszczanie elementów zgodnie z zasadami drzewa BST,
- wyświetlanie elementów drzewa w kolejności rosnącej,
- wyświetlanie struktury drzewa w formie gałęzi,
- automatyczne zwalnianie pamięci po zakończeniu działania programu.

Każdy element drzewa jest reprezentowany przez strukturę `drzewo`. Zawiera ona przechowywaną liczbę oraz dwa wskaźniki prowadzące do lewego i prawego dziecka.

Zasada działania drzewa jest następująca:
- liczby mniejsze od wartości aktualnego węzła trafiają do lewego poddrzewa,
- liczby większe lub równe wartości aktualnego węzła trafiają do prawego poddrzewa.

Przykładowo, dla kolejno dodanych wartości:

20, 10, 30, 5, 15, 25, 35

powstaje drzewo:

        20
       /  \
     10    30
    /  \   /  \
   5   15 25  35

Program następnie wypisuje elementy w kolejności rosnącej oraz przedstawia strukturę drzewa.

---

## 2. Wykorzystane biblioteki

### `#include <iostream>`

Biblioteka umożliwiająca obsługę wejścia i wyjścia.

W programie wykorzystywana jest przede wszystkim do:
- `cout` – wyświetlania informacji na ekranie,
- `endl` – przechodzenia do nowej linii.

### `#include <queue>`

Biblioteka zawierająca kolejkę (`queue`).

W obecnej wersji programu nie jest ona wykorzystywana. Można ją usunąć bez wpływu na działanie programu.

### `#include <string>`

Biblioteka umożliwiająca korzystanie z typu `string`.

Jest używana w funkcji `wypiszWizualniePomocniczo()` do przechowywania wcięć oraz oznaczeń gałęzi drzewa.

### `using namespace std;`

Pozwala korzystać z elementów przestrzeni nazw `std` bez konieczności pisania `std::`.

Przykładowo zamiast:

std::cout
std::string

można używać:

cout
string

---

# 3. Struktura `drzewo`

```cpp
struct drzewo
{
    int a;
    struct drzewo *lewy;
    struct drzewo *prawy;
};
