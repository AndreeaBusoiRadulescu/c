//#include "assignment.h";
#include <iostream>;

/*
	Sa se implementeze functia withdraw ce accepta doi parametri:
	- balance - reprezinta balanta contului curent
	- amount - reprezinta suma pe care dorim sa o extragem din cont
	Functia trebuie sa respecte urmatoarele cerinte:
	- La apelul functiei withdraw se va extrage din balanta suma dorita
	(Exemplu: In urma apelului withdraw(2000, 1000), balanta va avea valoarea 1000)
	- Daca balanta este negativa si se incearca efectuarea unei tranzactii
	se va aplica o penalizare de 10% asupra balantei, fara a efectua tranzactia
	(Exemplu: pentru o balanta de -1000, la incercarea efectuarii unei tranzactii
	balanta va avea valoarea de -1100).
	- Daca suma pe care dorim sa o extragem este negativa, se va efectua operatia de
	depunere. (pentru o balanta de 1000, la apelul functiei cu un amount de -200, vom
	obtine balanta cu valoarae 1200)
	- Daca suma dorita este mai mare decat valoarea balantei, nu se va efectua nicio operatie
	- Daca se va efectua operatia de withdraw cu amount 0, se va aplica o penalizare de 5% asupra balantei

*/

using namespace std;

void withdraw(double *balance, double amount)
{
	if (*balance < 0)
		*balance +=  *balance * 0.1; //penalizare de 10%
	else
		if (amount < 0)
			*balance = (*balance - amount); //operatie de depunere
		else
			if (amount == 0)
				*balance = *balance * 0.95; //penalizare de 5%
			else
				if (*balance > amount)
					*balance = (*balance - amount); //extragere
				else
				cout << "\n Nu s-a efectuat nicio operatie \n"; 
}
 

int main()
{
	double balantaContCurent;
	double sumaDeExtrasDinCont;

	balantaContCurent = -5;
	sumaDeExtrasDinCont = 2000;
	cout << " Balanta cont curent inainte de operatie: " << balantaContCurent;
	cout << "\n Suma ce o doream extrasa din cont: " << sumaDeExtrasDinCont;
	withdraw(&balantaContCurent, sumaDeExtrasDinCont);
	cout << "\n Balanta cont curent dupa operatie: " << balantaContCurent;
	cout << "\n Rezultat corect pentru balanta cont curent dupa operatie: -5.5";
	
	balantaContCurent = 10;
	sumaDeExtrasDinCont = -10;
	cout << "\n\n Balanta cont curent inainte de operatie: " << balantaContCurent;
	cout << "\n Suma ce o doream extrasa din cont: " << sumaDeExtrasDinCont;
	withdraw(&balantaContCurent, sumaDeExtrasDinCont);
	cout << "\n Balanta cont curent dupa operatie: " << balantaContCurent;
	cout << "\n Rezultat corect pentru balanta cont curent dupa operatie: 20";

	balantaContCurent = 1000;
	sumaDeExtrasDinCont = 1100;
	cout << "\n\n Balanta cont curent inainte de operatie: " << balantaContCurent;
	cout << "\n Suma ce o doream extrasa din cont: " << sumaDeExtrasDinCont;
	withdraw(&balantaContCurent, sumaDeExtrasDinCont);
	cout << " Balanta cont curent dupa operatie: " << balantaContCurent;
	cout << "\n Rezultat corect pentru balanta cont curent dupa operatie: 1000";

	balantaContCurent = 5000;
	sumaDeExtrasDinCont = 0;
	cout << "\n\n Balanta cont curent inainte de operatie: " << balantaContCurent;
	cout << "\n Suma ce o doream extrasa din cont: " << sumaDeExtrasDinCont;
	withdraw(&balantaContCurent, sumaDeExtrasDinCont);
	cout << "\n Balanta cont curent dupa operatie: " << balantaContCurent;
	cout << "\n Rezultat corect pentru balanta cont curent dupa operatie: 4750";

	balantaContCurent = 2000;
	sumaDeExtrasDinCont = 1000;
	cout << "\n\n Balanta cont curent inainte de operatie: " << balantaContCurent;
	cout << "\n Suma ce o doream extrasa din cont: " << sumaDeExtrasDinCont;
	withdraw(&balantaContCurent, sumaDeExtrasDinCont);
	cout << "\n Balanta cont curent dupa operatie: " << balantaContCurent;
	cout << "\n Rezultat corect pentru balanta cont curent dupa operatie: 1000";

	cout << endl;
	return 0;
}
