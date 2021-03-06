#include <iostream>
#include "parabola.h"
#include "funzioneBase.h"
#include <cstdlib>
#include <iomanip>
#include "solutore.h"
#include "bisezione.h"
#include <cmath>

using namespace std;

int main(int argc,char** argv) {
	if(argc!=5){
		cerr << "Errore. Inserire <./eseguibile.x> <xmin> <xmax> <prec> <Nmax>" << endl;
		return -1;
	}

	int cifre_significative=-log(atof(argv[3]));

	funzioneBase *f=new parabola(3,5,-2);
	solutore *s=new bisezione(atof(argv[1]),atof(argv[2]),atof(argv[3]),atof(argv[4]),f);

	cout << "Zero della funzione:" <<setprecision(cifre_significative-1) << s->cercaZeri() << endl;
	return 0;
}
		
