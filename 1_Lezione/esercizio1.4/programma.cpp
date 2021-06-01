#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double modulo(double);
double modulo(double,double);
double modulo(int,double*);

int main() {
	//overloading di funzioni per la funzione modulo
	double a;
	cout << "Inserire un numero" << endl;
	cin >> a;
	cout << "Modulo di un numero: " << setprecision(3) <<  modulo(a) << endl;
	
	double b,c;
	cout << "Inserire le coordinate di un punto nel piano cartesiano" << endl;
	cin >> c;
	cin >> b;
	cout << "Modulo di (" << c << ";" << b << ") :" << setprecision(3) << modulo(c,b) << endl;

	int N;
	cout << "Inserire la dimensione di uno spazio R-dimensionale" << endl;
 	cin >> N;
	double *vett=new double[N];
	cout << "Inserire le coordinate di un punto che vive in uno spazio" << N << "-dimensionale" << endl;
	for(int i=0; i<N; i++)
		cin >> vett[i];

	cout <<"Modulo:" << setprecision(3) << modulo(N,vett) << endl;
		
return 0;
}



double modulo(double a){
	return fabs(a);
}

double modulo(double a, double b){
	return sqrt(a*a+b*b);
}

double modulo(int N, double *vett){
	double appo=0;
	for(int i=0; i<N; i++)
		appo=appo+vett[i]*vett[i];
return sqrt(appo);
}
