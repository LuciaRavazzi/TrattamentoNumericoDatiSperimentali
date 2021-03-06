#include <iostream>
#include "rungeKutta.h"
#include "Pendolo.h"
#include "vettoreLineare.h"
#include <cstdlib>
#include "TApplication.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h"
#include <cmath>
#include "PendoloApp.h"

using namespace std;

int main(int argc, char ** argv) {
	if(argc!=2){
		cerr << "Errore. Scrivere: <./eseguibile.x> <passo> " << endl;
		return -1;
	}
	
	TApplication app("app", 0, 0);
	TCanvas tela("tela","Pendolo");
	TGraph posizioni;
	tela.Divide(2,1,0.01,0.01);
	
	//oscillazioni piccole: approssimazione.
	vettoreLineare x(2);
	x.setComponente(0,1.);
	x.setComponente(1,0.);
	
	rungeKutta rk;
	pendolo * pend=new pendolo(9.81,1.);
	
	double tmax=10.;
	double t=0;
	double h=atof(argv[1]);
	unsigned int nsteps=(tmax/h);
	for(int i=0; i<=nsteps; i++){
		posizioni.SetPoint(i,t,x.getComponente(0));
		x=rk.passo(t,x,h,pend);
		t=t+h;
	}
	posizioni.SetTitle("Pendolo: grafico spazio-tempo");
	posizioni.GetXaxis()->SetTitle("t [s]");
	posizioni.GetYaxis()->SetTitle("x [rad]");
	
	
	cout << "********" << endl;
	
	// Ora individuiamo l'ampiezza dell'oscillazione.
	// Comincia a risolvere. Quando passa da una inversione di velocita' registra. Poi registra quando ci ripassa.

		TGraph graph;
		int k=0; //contatore per graph
		double j=0.02;
		do{
		x.setComponente(0,j);
		x.setComponente(1,0.);

		int i=0;
		double omegaprec=0;
		double tinit=0;
		double tfin=0;
		double ampiezza=0;
		
		
		while(1>0){
			
			x=rk.passo(i*h,x,h,pend);
			// Controlla se il prodotto delle velocita' angolari e' cambiato di segno.
			if(x.getComponente(1)*omegaprec<0){
				tinit=h*i;
				break;
			}
			i++;		
			omegaprec=x.getComponente(1);
		}

		i++;
		omegaprec=x.getComponente(1);
		 
		while(1>0){
			
			x=rk.passo(i*h,x,h,pend);
		
			// Controlla se il prodotto delle velocita' angolari e' cambiato di segno.
			if(x.getComponente(1)*omegaprec<0){
				tfin=h*i;
				ampiezza=x.getComponente(0);
				break;
			}
		
			i++;
			omegaprec=x.getComponente(1);
		}
		
		
		j=j+0.1;
		graph.SetPoint(k,fabs(ampiezza),2*(tfin-tinit));
			k++;
		cout << "Periodo: " << 2*(tfin-tinit) << "  Ampiezza: " << 2*fabs(ampiezza) << endl;


	} while(j<3);


	graph.GetXaxis()->SetTitle("Ampiezza [rad]");
	graph.GetYaxis()->SetTitle("Periodo [s]");
	tela.cd(1);
	posizioni.Draw("AL");
	tela.cd(2);
	graph.Draw("AL*");

	
	app.Run();
	return 0;
}
