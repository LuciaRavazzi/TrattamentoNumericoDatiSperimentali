#include "monteCarlo.h"
#include "random.h"
#include "funzioneBase.h"
#include "seno.h"
#include <iostream>
#include <cstdlib>
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include <cmath>


double devStd(double[]);
double media(double[]);

using namespace std;

int const N=1000;
int main(){

	double a=0.;
	double b=3.1315;
	funzioneBase *s=new seno();
	monteCarlo monte(a,b,s);
	double vett[N]; 
	double vett1[N];
	double k=0;

	TApplication app("app",0,0);
	TGraph graph1;
	TGraph graph2;

	//primo punto
	for(int i=100; i<10000; i=i+100){//punti per il calcolo di un integrale
		for(int j=0; j<N; j++){//itero il calcolo dell'integrale con N fissato
			vett[j]=monte.MetodoMedia(i);
			vett1[j]=monte.HitOrMiss(1.,i);
		}	
		k++;
		graph1.SetPoint(k,i,devStd(vett));	
		graph2.SetPoint(k,i,devStd(vett1));			
	}



	
	TCanvas *tela=new TCanvas("tela","tela");
	TCanvas *tela1=new TCanvas("tela1","tela1");
	tela->cd();

	graph1.SetTitle("Studio della devStd dell'integrale di sin(x) tra 0 e PI con il metodo della media ");
	graph1.GetXaxis()->SetTitle("Numero punti per ogni valutazione");
	graph1.GetYaxis()->SetTitle("devStd");
	graph1.Draw("AL");	

	tela1->cd();
	graph2.SetTitle("Studio della devStd dell'integrale di sin(x) tra 0 e PI con il metodo Hit or Miss" );
	graph2.GetXaxis()->SetTitle("Numero punti per ogni valutazione dell'integrale");
	graph2.GetYaxis()->SetTitle("devStd");
	graph2.Draw("AL");	

	
	//secondo punto:Verificare che l'errore ha un andamento di K*N^a dove a=0.5.
	double h,i,l,p;
	int N1=5000;
	int N2=15000;
	
		for(int j=0; j<N; j++){
			vett[j]=monte.MetodoMedia(N1);
			vett1[j]=monte.HitOrMiss(1.,N1);
		}
		h=devStd(vett);
		i=devStd(vett1);
		
		for(int j=0; j<N; j++){
			vett[j]=monte.MetodoMedia(N2);
			vett1[j]=monte.HitOrMiss(1.,N2);
		}
		l=devStd(vett);
		p=devStd(vett1);
	
	double c=log(l/h)/log((double)N2/N1);
	double d=log(p/i)/log((double)N2/N1);
	cout << "Andamento dell'errore:K*N^a: a vale per il metodo della Media: " << c << endl;
	cout << "Andamento dell'errore:K*N^a: a vale per il metodo Hit or Miss: " << d << endl;


	//terzo punto:conoscendo l'andamento dell'errore,calcolare quanti punti sono necessari per avere una precisione di 0.001.
	double coeff;
	coeff=h*sqrt(N1);
	cout << "Coefficiente: " << coeff  << endl;
		cout << "Per avere una precisione del 0.001, servono "  << pow(coeff/0.001,2) << "punti" << endl;
	
	
	app.Run();

return 0;
}  


double media(double* vett){
	double accu=0;

	for(int i=0; i<N; i++)
		accu=accu+vett[i];
return (double) accu/N;
}


double devStd(double* vett){
	double accu=0;
	double m=media(vett);

	for(int i=0; i<N; i++)
		accu=accu+(vett[i]-m)*(vett[i]-m);

return sqrt((double) accu/N);
}
	
	















	

	
	
