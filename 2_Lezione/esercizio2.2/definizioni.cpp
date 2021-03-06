#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>

#include "dichiarazioni.h"
#include "selectionSort.h"

using namespace std;

void stampa(const vettore v){
	int width=int (log10(v.quanti)+1);
	cout<<endl<<"Stampo vettore."<<endl;
	for(int i=0; i<v.quanti; i++){
		cout<< setw(width) << i << ") " <<v.vett[i]<<endl;
	}
	cout<<endl;
	
	
}

void stampa(const vettore v, const char* nome){
	int width=int (log10(v.quanti)+1);
	cout<<"Eseguo stampa su file: "<<nome<<endl;
	ofstream out;
	out.open(nome);
	if(out.fail()){
		cerr<<"Errore nella scrittura su file."<<endl;
	}
	for(int i=0; i<v.quanti; i++){
		out<< setw(width) << i << ") " <<v.vett[i]<<endl;
	}
	out.close();
}

vettore carica(int n, const char* nome){
	vettore v;
	v.quanti=n;
	v.vett=new double [v.quanti];
	
	// Carico il vettore da file.
	ifstream in;
	in.open(nome);
	if(in.fail()){
		cerr<<"Errore nella lettura da file"<<endl;
	}
	for(int i=0; i<v.quanti; i++){
		in>>v.vett[i];
	}
	
	
	in.close();
	return v;
}

void ordina(vettore v){
	ordinaArrayCrescente(v.vett,v.quanti);
}
