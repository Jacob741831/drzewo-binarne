Drzewo Binarne w C++ (Binary Search Tree)

Ten projekt przedstawia prostą, ale w pełni funkcjonalną implementację Binarnego Drzewa Poszukiwań (BST) w języku C++. Kod demonstruje zarządzanie pamięcią, strukturę węzłów, operacje wstawiania oraz dwa sposoby prezentacji danych: sortowanie rosnące oraz wizualizację struktury gałęziowej.

🚀 Funkcjonalności

Struktura Węzła (drzewo): Reprezentuje pojedynczy węzeł zawierający wartość całkowitą (int a) oraz wskaźniki na lewe i prawe poddrzewo.

Klasa Zarządzająca (DrzewoBinarne):

dodajLiczbe(int wartosc): Wstawia nową wartość do drzewa zgodnie z zasadą BST (mniejsze elementy trafiają do lewego poddrzewa, większe lub równe do prawego).

sortujIWypisz(): Wykorzystuje algorytm In-order do wypisania elementów drzewa w porządku rosnącym.

wypiszJakoDrzewo(): Generuje czytelną, tekstową wizualizację hierarchii drzewa na konsoli.

Bezpieczne Zarządzanie Pamięcią: Automatyczne czyszczenie pamięci za pomocą destruktora i rekurencyjnej funkcji usuwającej węzły (delete).

🛠️ Zasada Działania (Reguła Wstawiania)

Wstawianie nowych elementów odbywa się iteracyjnie od korzenia:

Jeśli drzewo jest puste, nowy element staje się korzeniem.

Jeśli wartość jest mniejsza od aktualnego węzła, przechodzimy do lewego poddrzewa.

Jeśli wartość jest większa lub równa, przechodzimy do prawego poddrzewa.

Proces powtarza się do momentu natrafienia na wolne miejsce.

💻 Przykładowy Kod Główny (main)

Program testowy wstawia następujące liczby: 20, 10, 30, 5, 15, 25, 35.

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

    // Wyświetlenie posortowanych elementów (In-order)
    mojeDrzewo.sortujIWypisz();

    cout << endl;

    // Wyświetlenie struktury drzewa
    mojeDrzewo.wypiszJakoDrzewo();

    return 0;
}
