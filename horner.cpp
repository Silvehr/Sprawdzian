// Jak to gówno działa?
//
// To coś pozwala na wyciąganie x przed nawias
// Weźmy taki wielomian:
//      3x³ + 4x² - x + 5
// Horner rozkłada stopniowo w ten sposób:
//      x * (3x² + 4x - 1) + 5
//      x * (x * (3x + 4) - 1) + 5 <- tu jest dodawany współczynnik
//      x * (x * (x * (3) + 4) - 1) + 5
//                     ^ to jest liczone na samym początku

int horner_rec(int wsp[],int st, int x)
{
	if(st==0)
		return wsp[0];
	
	return x*horner_rec(wsp,st-1,x)+wsp[st];
}

int horner_iter(int wsp[],int st, int x)
{
	int wynik = wsp[0]; // To jest ostatni (najgłębszy) współczynnik, w tym wypadku 3

	for(int i=1;i<=st;i++)
		wynik = wynik*x + wsp[i]; // <- współczynnik wyciągnięty przed nawias
	
	return wynik;
}