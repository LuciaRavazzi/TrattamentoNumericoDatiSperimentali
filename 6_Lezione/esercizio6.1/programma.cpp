#include <iostream>
#include <fstream>
#include "vettore.h"
#include "vettoreDati.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"

using namespace std;


int main(int argc,char** argv){
	if(argc!=3){
		cerr << "Errore. Inserire nuovamente <./eseguibile.x> <nomefile> <QuantiElemOrdinare>" << endl;
		return 0;
	}

	
	TApplication app("app",0,0);
	TCanvas *tela=new TCanvas("tela","tela");
	TGraph graph;

	double k=0;
	clock_t t;


	for(int i=0; i<atoi(argv[2]); i=i+1000){
		vettoreDati vett(argv[1],i); //riempio il vettore da file con i valori
		
		t=clock();
		vett.quickSort();
		t=clock()-t;

		k++;
		
		graph.SetPoint(k,i,(double) t/CLOCKS_PER_SEC);
	}

	graph.SetTitle("Tempo di ordinamento:Quicksort");
	graph.GetXaxis()->SetTitle("[N]");
	graph.GetYaxis()->SetTitle("[t]");

	tela->cd();
	graph.Draw("AL*");
	app.Run();

return 0;
}



	
	
