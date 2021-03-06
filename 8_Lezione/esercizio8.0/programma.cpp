#include "random.h"
#include <iostream>
#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"


using namespace std;

int main(){
	//prima parte
	TApplication app("app",0,0);

	random rand(3);

	TH1F isto("istogramma", "numeri random", 100,0,10);

	for(int i=0; i<500000; i++){
		double n=rand.uniforme();
		isto.Fill(n);
	}

	TCanvas *tela =new TCanvas("tela","tela");
	tela->cd();
	isto.Draw();

	app.Run();

	//seconda parte
	random rand1(4,2,9,3);
	double n=rand1.uniforme();
	unsigned int i=0;
	double a;
	do{
		i++;
		a=rand1.uniforme();
		cout << a << endl;
	}while(n!=a);

	cout << "Periodo: " << i << endl;

return 0;
}
