#include <iostream>
#include <fstream>
#include "programma.h"
using namespace std;

int main() {
	ifstream filein;
	int N;
	char nomefile[100];

	//riempio il vettore con i dati del file
	filein.open("dati.dat");
	//controllo se il file è stato aperto correttamente
	if(filein.fail()){
		cerr << "Errore apertura file" << endl;
		cout << "Inserire nome file:" << endl;
		cin >> nomefile;
		filein.open(nomefile);
	}

	filein >> N;
	double* vett=new double[N]; //un vettore deve sempre essere dichiarato dopo che la sua dimensione è resa nota a runtime
	for(int i=0; i<N; i++)
		filein >> vett[i];
	filein.close();	

	//scambio gli elementi di posto pari con quelli dispari
	//inserisco il nuovo vettore in un file
	ofstream fileout;
	fileout.open("VettoreElemScambiati.dat");
	if((N%2)==0){
	//tutti gli elementi vengono scambiati
		for(int j=0; j<N-1; j=j+2)
			byPointer(&vett[j],&vett[j+1]);
	} else { //numero dispari di elementi
		for(int j=0; j<N-2; j++)
			byPointer(&vett[j],&vett[j+1]);
	}
		
	for(int k=0; k<N; k++)
		fileout << vett[k] << endl;

	fileout.close();
	delete [] vett;
	vett=NULL;


return 0;
}
