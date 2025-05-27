#include<cmath>

// Jak to gówno działa?
//
// Do liczenia tego pierwiastka wykorzystywany jest prostokąt i kwadrat
// Weźmy prostokąt o boku 1 x P. Jego pole to będzie P
// Celem jest uzyskiwanie pola poprzez zbliżanie do siebie boków a i b tak, aby dawały to samo pole (P)

double pierwiastek(double P, double eps)
{
    double a = 1.0, b = P;
    
    while(abs(a-b)>=eps) 
    {
        a = (a+b)/2.0;  // Naturalnie bierzemy średnią
        b = P/a;        // Potrzebujemy drugiego boku naszej figury
    }

    return (a+b)/2.0; 
}