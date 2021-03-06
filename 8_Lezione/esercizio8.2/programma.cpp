#include "random.h"
#include <iostream>
#include "funzioneBase.h"
#include "gaussiana.h"
#include <cmath>
#include <fstream>
#include "TApplication.h"
#include "TH1F.h"
#include "TCanvas.h"

using namespace std;

int main(){	

	TApplication app("app",0,0);
	TH1F isto("istogramma","Metodo Accept-Reject",100,-4,4);
	TH1F isto1("istogramma","Metodo Accept-Reject",100,-6,6);
	funzioneBase *f=new gaussiana(1.,1.);
	funzioneBase *f1=new gaussiana(0.,2.);
	random rand(3);


	for(int i=0; i<100000; i++){
		isto.Fill(rand.acceptReject(f,-10,10,1./(sqrt(2*3.1415))));
		isto1.Fill(rand.acceptReject(f1,-10,10,1./(sqrt(2*3.1415))));
	}

	TCanvas *tela=new TCanvas("tela","tela");
	TCanvas *tela1=new TCanvas("tela1","tela1");
	tela->cd();
	isto.Draw();
	tela1->cd();
	isto1.Draw();

	app.Run();
	
return 0;
}







