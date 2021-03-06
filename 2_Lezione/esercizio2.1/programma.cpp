#include <iostream>
#include "programma.h"
using namespace std;

//variabile globale:ogni funzione può mofificare il suo valore.
int scambi=0;
	
void byValue(double a, double b){
	double appo;
	static int conta=0; //variabile statica
	appo=a;
	a=b;
	b=appo;
	conta++;
	scambi++;
	cout << "Scambi eseguiti byValue: " << conta << endl;  
}

	
void byReference(double& a, double& b){
	double appo;
	static int conta=0;
	appo=a;
	a=b;
	b=appo;
	conta++;
	scambi++;
	cout << "Scambi eseguiti byReference: " << conta << endl; 
}

void byPointer(double* a, double* b){
	double appo;
	static int conta=0;
	appo=*a;
	*a=*b;
	*b=appo;
	conta++;
	scambi++;
	cout << "Scambi eseguiti byPointer: " << conta << endl; 
}

//è necessaria questa funzione per sapere il valore di una variabile globale: non posso accedere al suo valore direttamente dal main.
int quantiScambi(){
	return scambi;
}
