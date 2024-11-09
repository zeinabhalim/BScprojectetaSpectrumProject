#include"iostream"
#include"stdio.h"
#include"stdlib.h"
#include"cstdio"
#include"TGraph.h"
#include"TGraphErrors.h"

int betaspec() {
         FILE *fb=fopen("data_input.txt","r");
         char line[80];
        Int_t ix[60] ,k;
        Double_t x[60] , y[60], ey[60], ex[60] ;  
        k=0;
        fgets(line, 79,fb);
        while (fgets(line,79,fb)){
        sscanf(&line[0],"%d %lg %lg %lg",&ix[k], &x[k],&y[k],&ey[k]);
        ex[k]=0.0 ;
        k=k+1;
        
        }
TCanvas* c=new TCanvas();
c->SetGrid();
// cout << "x[]= " <<x[k-1]<< x[k-1] <<", y[]= " <<y[k-1] <<", ey[k-1] << endl;
TGraphErrors *betagr=new TGraphErrors(28, x, y,ex,ey);
betagr ->SetTitle("Beta spectrum of {}^{90}Sr_{38} ;I(mA); count rate (Counts/30sec) ");
betagr ->SetMarkerStyle(4);
betagr ->SetMarkerSize(0.5);
betagr ->Draw("AP");

TF1 *F1=new TF1("F1","33",0,700);
F1->SetNpx(5000);
F1->Draw("Same");

TLatex lat;
lat.SetTextAlign(12);
lat.SetTextSize(0.04);
lat.DrawLatex(400,25,"The background");

TText *tx1=new TText(400 ,40, "The background");

//c->Print(" ");
}

