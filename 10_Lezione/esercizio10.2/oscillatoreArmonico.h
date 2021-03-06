#ifndef _OSCILLATOREARMONICO_
#define _OSCILLATOREARMONICO_

#include "funzioneVettorialeBase.h"
#include "vettoreLineare.h"

class oscillatoreArmonico: public funzioneVettorialeBase{
	public:
		oscillatoreArmonico(double omega){_omega=omega;}
		vettoreLineare eval(const vettoreLineare &,double t) const;
		

	private:
		double _omega;

};



#endif
