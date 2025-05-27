#include<cmath>

double CalkaProstokat(double a, double b, int p)
{
    if(a == b)
        return 0;

    double h = (b - a) / p;
    double pole = 0;

    for(double current = a + h; current <= b; current+=h)
    {
        // zamiast *func* wstaw nazwę funkcji
        pole += abs(func(current)) * h;
    }

    return pole;
} 

double CalkaTrapez(double a, double b, int p)
{
    if(a == b)
        return 0;

    double h = (a - b) / p;
    double prev = a;
    double pole = 0;

    for(double current =a + h; current <= b; current+=h)
    {
        // func => twoja funkcja
        pole += (abs(func(current) + func(prev))) * h / 2;
        prev = current;
    }

    return pole;
}

double CalkaDwochFunkcji(double a, double b, int p)
{
    if(a == b)
        return 0;
    
    double krok = (a - b) / p;
    double prev = a;
    double pole = 0;

    for(double current =a + krok; current <= b; current+=krok)
    {
        double h1 = abs(f1(current) - f2(current));
        double h2 = abs(f1(prev) - f2(prev));

        pole += (abs(h1 + h2)) * krok / 2;
        prev = current;
    }

    return pole;
}