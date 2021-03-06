#include <iostream>
#include "integrale.h"
#include "funzioneBase.h"
#include "seno.h"
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc,char**argv){		

	if(argc!=2){
		cerr << "Errore.Inserire <./eseguibile.x> <prec>" << endl;
		return -1;	
	}
		
	double prec=atof(argv[1]);
	double b=3.1415;
	double a=0.;
	
	funzioneBase *s=new seno();
	integrale integral(a,b,s,prec);

	cout <<"Integrale: " << integral.trapezoidiPrec() << endl;
	
return 0;
}
