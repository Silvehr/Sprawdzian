#include<cmath>

// Do czego służy:
// - a: początek dziedziny w której wiadomo, że znajduje się miejsce 0
// - b: koniec dziedziny w której wiadomo, że znajduje się miejsce 0
// - delta: precyzja oznaczająca jak dokładne musi być x0
// - epsilon: precyzja oznaczająca jak dokładne musi być f(x0) (jak bliskie ono musi być 0)

// Jak to działa?
// Funkcja do szukania miejsca zerowego działa na zasadzie wyszukiwania binarnego
// Zmniejszamy o połowę przedział w którym miejsce zerowe może się znajdować z każdym obrotem
double find0(double a, double b, double delta, double epsilon)
{
    
    double rangeLen = b-a;
    double x0;

    while(true)
    {
        rangeLen = (b-a) / 2;
        x0 = a + rangeLen;

        // w *f* wstaw swoją funkcje
        // I USUŃ TEN KOMENTARZ
        if(std::abs(rangeLen) < delta || abs(f(x0)) < epsilon)
            return x0;

        // Co to robi?
        // Decyduje, którą połowę bierzemy, górną czy dolną
        // Dlaczego tak? 
        // Musimy pamiętać, że x0 ZAWSZE jest większe od a
        // x0 to jest średnia z b oraz a i wyznacza 2 połowy, górną i dolną.
        // Jeżeli f(a) * f(x0) jest ujemne, to znaczy, że f(x0) jest dodatnie, z czego wynika, że miejsce x0 jest ujęte między nim a zmienną a
        // W przeciwnym wypadku miejsce zerowe musi być zawarte w górnej połowie
        if((f(x0) * f(a)) < 0)
            b = x0;
        else
            a = x0;
    }
}