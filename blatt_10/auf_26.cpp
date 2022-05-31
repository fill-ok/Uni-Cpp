#include <iostream>
#include <iomanip>
#include "warenkorb.hpp"


using namespace std;

int main()
{
	Apfel a(12345, "Granny Smith", 1.99, 0.65);
	Apfel b(12543, "Golden Delicious", 1.79, 1.2);
	Ananas c(21313, "Brasilien", 1.25, 3);
	Ananas d(21766, "Thailand", 1.55, 1);

	Warenkorb w("warenkorb nummer 1");
	w.get_info_warenkorb();

	cout << "\nFuelle Warenkorb ..." << endl;
	w.add(a);
	w.add(b);
	w.add(c);
	w.add(d);
	w.get_info_warenkorb();

	cout << "\nGesamtpreis: " << setprecision(3) << w.get_Preis_warenkorb() << " Euro" << endl;

	return 0;
}
