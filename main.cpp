#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Struktura reprezentuj¹ca pojedynczy wêze³ (wagonik) drzewa
struct drzewo
{
    int a;
    struct drzewo *lewy;   // mniejsze liczby (<)
    struct drzewo *prawy;  // wiêksze lub równe (>=)
};

// Klasa zarz¹dzaj¹ca drzewem binarnym
class DrzewoBinarne
{
private:
    drzewo *korzen;

    // Funkcja pomocnicza do usuwania wêz³ów z pamiêci przez destruktor
    void usunDrzewo(drzewo *wezel)
    {
        if (wezel == nullptr)
            return;

        usunDrzewo(wezel->lewy);
        usunDrzewo(wezel->prawy);

        delete wezel;
    }

    // Rekurencyjna funkcja wyœwietlaj¹ca drzewo w formie ga³êzi
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

    // Destruktor - zwalnia ca³¹ pamiêæ za pomoc¹ delete
    ~DrzewoBinarne()
    {
        usunDrzewo(korzen);
    }

    // Funkcja dodaj¹ca liczbê int (tworzy nowy wagonik i wstawia go, badaj¹c œcie¿kê od korzenia)
    void dodajLiczbe(int wartosc)
    {
        drzewo *nowyWagonik = new drzewo;
        nowyWagonik->a = wartosc;
        nowyWagonik->lewy = nullptr;
        nowyWagonik->prawy = nullptr;

        // Jeœli drzewo jest puste, nowy wagonik staje siê korzeniem
        if (korzen == nullptr)
        {
            korzen = nowyWagonik;
            return;
        }

        // Zaczynamy wêdrówkê od samego korzenia w dó³ drzewa
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
                // Idziemy w prawo (liczba wiêksza lub równa)
                if (aktualny->prawy == nullptr)
                {
                    aktualny->prawy = nowyWagonik;
                    break;
                }
                aktualny = aktualny->prawy;
            }
        }
    }

    // Funkcja sortuj¹ca i wypisuj¹ca posortowane elementy
    void sortujIWypisz()
    {
        cout << "Posortowane elementy drzewa: ";
        wypiszPosortowanePomocniczo(korzen);
        cout << endl;
    }

    // Funkcja wyœwietlaj¹ca drzewo ze strukturalnymi ga³êziami
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

    /*
      Zasada wstawiania (od góry od korzenia):
      - Korzen to 20.
      - Wchodzi 10 -> mniejsze od 20, leci w lewo.
      - Wchodzi 30 -> wiêksze od 20, leci w prawo.
      - Wchodzi 5  -> mniejsze od 20, potem mniejsze od 10 -> leci na skrajne lewe poddrzewo.
      - Kolejne liczby trafiaj¹ do drzewa w ten sam sposób, szukaj¹c swojego miejsca od góry do do³u.
    */
    mojeDrzewo.dodajLiczbe(20);
    mojeDrzewo.dodajLiczbe(10);
    mojeDrzewo.dodajLiczbe(30);
    mojeDrzewo.dodajLiczbe(5);
    mojeDrzewo.dodajLiczbe(15);
    mojeDrzewo.dodajLiczbe(25);
    mojeDrzewo.dodajLiczbe(35);

    // Wywo³anie sortowania
    mojeDrzewo.sortujIWypisz();

    cout << endl;

    // Wywo³anie wizualizacji drzewa z ga³êziami
    mojeDrzewo.wypiszJakoDrzewo();

    return 0;
}
