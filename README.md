# Dokumentacja programu – Drzewo Binarne (BST)

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
`20, 10, 30, 5, 15, 25, 35`

powstaje drzewo:
```text
Korzen -> 20
 Prawy: 30
    P: 35
    L: 25
 Lewy:  10
    P: 15
    L: 5
```

---

## 2. Wykorzystane biblioteki

### `#include <iostream>`
Biblioteka umożliwiająca obsługę wejścia i wyjścia. Wykorzystywana przede wszystkim do:
- `cout` – wyświetlania informacji na ekranie,
- `endl` – przechodzenia do nowej linii.

### `#include <queue>`
Biblioteka zawierająca kolekcję (`queue`). W obecnej wersji programu nie jest bezpośrednio wykorzystywana.

### `#include <string>`
Biblioteka umożliwiająca korzystanie z typu `string`. Jest używana w funkcji `wypiszWizualniePomocniczo()` do przechowywania wcięć oraz oznaczeń gałęzi drzewa.

### `using namespace std;`
Pozwala korzystać z elementów przestrzeni nazw `std` bez konieczności pisania `std::` przed każdym wywołaniem (np. `cout`, `string`).

---

## 3. Struktura `drzewo` oraz Klasa `DrzewoBinarne`

Poniżej znajduje się kompletny kod źródłowy programu zawarty w jednym pliku:

```cpp
#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Struktura reprezentująca pojedynczy węzeł drzewa
struct drzewo
{
    int a;
    struct drzewo *lewy;    // mniejsze liczby (<)
    struct drzewo *prawy;   // większe lub równe (>=)
};

// Klasa zarządzająca drzewem binarnym
class DrzewoBinarne
{
private:
    drzewo *korzen;

    // Funkcja pomocnicza do usuwania węzłów z pamięci przez destruktor
    void usunDrzewo(drzewo *wezel)
    {
        if (wezel == nullptr)
            return;

        usunDrzewo(wezel->lewy);
        usunDrzewo(wezel->prawy);

        delete wezel;
    }

    // Rekurencyjna funkcja wyświetlająca drzewo w formie gałęzi
    void wypiszWizualniePomocniczo(drzewo *wezel, string wciecie, string galaz)
    {
        if (wezel == nullptr) return;

        cout << wciecie << galaz << wezel->a << endl;

        // Rekurencyjnie wypisujemy prawe i lewe poddrzewo
        if (wezel->lewy != nullptr || wezel->prawy != nullptr)
        {
            wypiszWizualniePomocniczo(wezel->prawy, wciecie + "    ", "P: ");
            wypiszWizualniePomocniczo(wezel->lewy, wciecie + "    ", "L: ");
        }
    }

    // Rekurencyjne wypisywanie posortowane (In-order)
    void wypiszPosortowanePomocniczo(drzewo *wezel)
    {
        if (wezel == nullptr) return;
        wypiszPosortowanePomocniczo(wezel->lewy);
        cout << wezel->a << " ";
        wypiszPosortowanePomocniczo(wezel->prawy);
    }

public:
    // Konstruktor - inicjalizuje puste drzewo
    DrzewoBinarne()
    {
        korzen = nullptr;
    }

    // Destruktor - zwalnia całą pamięć za pomocą delete
    ~DrzewoBinarne()
    {
        usunDrzewo(korzen);
    }

    // Funkcja dodająca liczbę int do drzewa BST
    void dodajLiczbe(int wartosc)
    {
        drzewo *nowyWagonik = new drzewo;
        nowyWagonik->a = wartosc;
        nowyWagonik->lewy = nullptr;
        nowyWagonik->prawy = nullptr;

        // Jeśli drzewo jest puste, nowy element staje się korzeniem
        if (korzen == nullptr)
        {
            korzen = nowyWagonik;
            return;
        }

        // Zaczynamy wędrówkę od korzenia w dół drzewa
        drzewo *aktualny = korzen;
        while (true)
        {
            if (wartosc < aktualny->a)
            {
                // Idziemy w lewo (liczba mniejsza)
                if (aktualny->lewy == nullptr)
                {
                    aktualny->lewy = nowyWagonik;
                    break;
                }
                aktualny = aktualny->lewy;
            }
            else
            {
                // Idziemy w prawo (liczba większa lub równa)
                if (aktualny->prawy == nullptr)
                {
                    aktualny->prawy = nowyWagonik;
                    break;
                }
                aktualny = aktualny->prawy;
            }
        }
    }

    // Funkcja sortująca i wypisująca posortowane elementy
    void sortujIWypisz()
    {
        cout << "Posortowane elementy drzewa: ";
        wypiszPosortowanePomocniczo(korzen);
        cout << endl;
    }

    // Funkcja wyświetlająca drzewo ze strukturalnymi gałęziami
    void wypiszJakoDrzewo()
    {
        if (korzen == nullptr)
        {
            cout << "Drzewo jest puste." << endl;
            return;
        }
        cout << "Korzen -> " << korzen->a << endl;
        if (korzen->prawy) wypiszWizualniePomocniczo(korzen->prawy, "", " Prawy: ");
        if (korzen->lewy)  wypiszWizualniePomocniczo(korzen->lewy, "",  " Lewy:  ");
    }
};

int main()
{
    DrzewoBinarne mojeDrzewo;

    mojeDrzewo.dodajLiczbe(20);
    mojeDrzewo.dodajLiczbe(10);
    mojeDrzewo.dodajLiczbe(30);
    mojeDrzewo.dodajLiczbe(5);
    mojeDrzewo.dodajLiczbe(15);
    mojeDrzewo.dodajLiczbe(25);
    mojeDrzewo.dodajLiczbe(35);

    // Wywołanie sortowania
    mojeDrzewo.sortujIWypisz();

    cout << endl;

    // Wywołanie wizualizacji drzewa z gałęziami
    mojeDrzewo.wypiszJakoDrzewo();

    return 0;
}
```

---

## 4. Podsumowanie

Program w czytelny sposób demonstruje mechanizm zarządzania pamięcią dynamiczną (`new`/`delete`), rekurencję oraz strukturę danych jaką jest drzewo binarne wyszukiwania.
