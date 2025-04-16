double find0(double a, double b, double delta, double epsilon)
{
    double rangeLen = b-a;
    double x0;

    while(true)
    {
        rangeLen = (b-a) / 2;
        x0 = a + rangeLen;

        // w *function* wstaw swoją funkcje
        if(abs(rangeLen) < delta || abs(f(x0)) < epsilon)
            return x0;

        if((f(x0) * f(a)) < 0)
            b = x0;
        else
            a = x0;
    }
}

double CalkaProstokat(double a, double b, int p)
{
    if(a == b)
        return 0;

    double h = (b - a) / precision;
    double pole = 0;

    for(double current = a + step; current <= b; current+=h)
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