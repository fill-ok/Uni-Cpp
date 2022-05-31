#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// --------------------exception classes ------------------------------------
class DimensionException: public std::exception{
   private:
      const char* message;
   public:
      DimensionException(const char* m): message(m) {}

      virtual const char* what() const throw() override{
         return message;
      }
};

class DivisonException: public std::exception{
   private:
      const char* message;
   public:
      DivisonException(const char* m): message(m) {}

      virtual const char* what() const throw() override{
         return message;
      }
};

// ----------------------real classes .--------------------------------------
class Vektor{
	private:
		double* d;
		int n;

	public:
		Vektor(int i) : n(i) {
			d = new double[i];
			for(int i=0 ; i<n ; i++)
				d[i] = rand() % 100 / 10.0;
		}

		~Vektor() {
			delete[] d;
		}

		//Vektoren elementweise addieren
		Vektor& operator+=(const Vektor& v) {
			try{
				if(v.n != n) {
					throw DimensionException("Dimensionsfehler... / YOU ARE SH#T");
				}
			} catch (DimensionException& dim_error){
				cout << dim_error.what() << endl;
				exit(1);
			}
			
			for(int i=0 ; i<n ; i++)
				d[i] += v.d[i];

			return *this;
		}

		//Jedes Element des Vektors durch z teilen
	    Vektor& operator/=(double z) {
			try{
				if(z == 0) {
					throw DivisonException("Divisonsfehler... / YOU ARE SH#T");
				}
			} catch (DivisonException& dim_error){
				cout << dim_error.what() << endl;
				exit(1);
			}
			
			for(int i=0 ; i<n ; i++)
				d[i] /= z;

			return *this;
		}


	friend ostream& operator<<(ostream& os, const Vektor& v) {
		os << setprecision(1) << fixed;
		os << "(";
		for(int i=0; i<v.n; ++i) {
			os << v.d[i];
			if(i<v.n-1)
				os << ",  ";
		}
		os << ")";
		return os;
	}
};

int main() {
    // std::cin.exceptions(std::ios_base::failbit);

	srand(time(nullptr));
	Vektor v1(5);
	Vektor v2(5);
	Vektor v3(6);
	cout << "       v1: " << v1 << endl;
	cout << "       v2: " << v2 << endl;
	cout << "       v3: " << v3 << endl;

	v1 += v2;
	cout << " v1 += v2: " << v1 << endl;
	v3 /= 2.5;
	cout << "v3 /= 2.5: " << v3 << endl;
	v1 += v3;
	cout << " v1 += v3: " << v1 << endl;
	v3 /= 0.0;
	cout << "v3 /= 0.0: " << v3 << endl;

	return 0;
}
