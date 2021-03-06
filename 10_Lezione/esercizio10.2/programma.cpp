#include <iostream>
#include "rungeKutta.h"
#include "eulero.h"
#include "oscillatoreArmonico.h"
#include "vettoreLineare.h"
#include <cstdlib>
#include "TApplication.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h"
#include <cmath>

using namespace std;

int main(int argc, char ** argv) {
	if(argc!=2){
		cerr << "Errore. Scrivere: <./eseguibile.x> <passoIntegrazione> " << endl;
		return -1;
	}
	
	TApplication app("app", 0, 0);
	TCanvas tela("tela","Oscillatore armonico");
	TGraph * posizioni=new TGraph();
	TGraph * errori=new TGraph();
	
	tela.Divide(2,2);
	
	
	rungeKutta rk;
	oscillatoreArmonico * osc=new oscillatoreArmonico(1.);
	double h=atof(argv[1]);
	double tmax=70;
	int nstep=int(tmax/h+0.5);
	double t=0;
	vettoreLineare x(2);
	x.setComponente(0,0);
	x.setComponente(1,1.);
	for(int i=0; i<nstep; i++){
		posizioni->SetPoint(i,t,x.getComponente(0));
		errori->SetPoint(i,t,fabs(x.getComponente(0)-sin(t)));
		x=rk.passo(t,x,h,osc);
		t=t+h;
	}
	

	
	eulero eul;
	t=0;
	TGraph *posizioni1=new TGraph();
	x.setComponente(0,0);
	x.setComponente(1,1.);
	for(int i=0; i<nstep; i++){
		posizioni1->SetPoint(i,t,x.getComponente(0));
		x=eul.passo(t,x,h,osc);
		t=t+h;
	}
	
	
	
	unsigned int counter =0;
	double errore;
	TGraph discrepanze;
	//Studio come varie l'errore modificando il passo di integrazione.
	
	for(float h=0.0001; h<0.1; h+=0.0001){
		t=0;
		x.setComponente(0,0.);
		x.setComponente(1,1.);
		nstep=int(tmax/h+0.5);
		for(int i=0; i<nstep; i++){
			errore=fabs(x.getComponente(0)-sin(t));
			x=rk.passo(t,x,h,osc);
			t=t+h;
		}
		
		discrepanze.SetPoint(counter,h,errore);
		
		counter++;
	}
	
	
	tela.cd();
	tela.cd(1);
	posizioni->SetTitle("Posizioni:RungeKutta");
	posizioni->GetXaxis()->SetTitle("t (s)");
	posizioni->GetYaxis() ->SetTitle("x (m)");
	posizioni->Draw("AL");
	tela.cd(2);
	posizioni1->SetTitle("Posizioni:Eulero");
	posizioni1->GetXaxis()->SetTitle("t (s)");
	posizioni1->GetYaxis() ->SetTitle("x (m)");
	posizioni1->Draw("AL");
	tela.cd(3);
	errori->SetTitle("Errori");
	errori->GetXaxis()->SetTitle("t (s)");
	errori->GetYaxis()->SetTitle("err (m)");
	errori->Draw("AL");
	
	discrepanze.SetTitle("Discrepanze a 70 s");
	discrepanze.GetXaxis()->SetTitle("Passo (s)");
	discrepanze.GetYaxis()->SetTitle("Errore (m)");
	tela.cd(4)->SetLogx();
	tela.cd(4)->SetLogy();
	discrepanze.Draw("AL");
		
	app.Run();
	return 0;
}
