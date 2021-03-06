#include "rungeKutta.h"
#include "equazioneDifferenzialeBase.h"
#include "funzioneVettorialeBase.h"
#include "vettoreLineare.h"



vettoreLineare rungeKutta::passo(double t, const vettoreLineare& inizio,double h, funzioneVettorialeBase *f) const{
	vettoreLineare k1(inizio.getN());
	vettoreLineare k2(inizio.getN());
	vettoreLineare k3(inizio.getN());
	vettoreLineare k4(inizio.getN());
	
	k1=f->eval(inizio,t);
	k2=f->eval(inizio+k1*(h/2),t+h/2);
	k3=f->eval(inizio+k2*(h/2),t+(h/2));
	k4=f->eval(inizio+k3*h,t+h);
	
	return inizio+(k1+k2*2+k3*2+k4)*(h/6);
}


