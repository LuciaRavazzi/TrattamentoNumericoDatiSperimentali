#ifndef _FUNZIONE_
#define _FUNZIONE_

#include "funzioneBase.h"
#include <cmath>

class funzione:public funzioneBase{
	public: 	
	funzione() {}
	double eval(double x) const { return sin(x)-x*cos(x);}
};

#endif
