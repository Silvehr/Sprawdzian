#include <cstdlib>

double calc_pi(long precision)
{
    long liczba_trafien = 0;

    for(long i = 0; i < precision; i++)
    {
        double x = ((double)rand() / RAND_MAX);
        double y = ((double)rand() / RAND_MAX);
        if(x * x + y * y <= 1)
            liczba_trafien++;
    }

    return 4 * (double)liczba_trafien / precision;
}