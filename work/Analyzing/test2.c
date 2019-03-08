#include <iostream>
#include <string>
using namespace std;

TH1F* data15;

void test2(){
	ifstream input;
	
	input.open("ListofN.txt");
	
	string ListofName[10];
	
	for (int j=0; j<10 ; j++){
		
	input >> ListofName[j];
	
	cout << ListofName[j] <<endl;
	
	}
	
	string mystr;
	
	for (int z=2; z<28 ; z++){
		
	mystr = ListofName[z];
	cout << mystr << endl;
	
	TFile *_file1 = TFile::Open("hist-data-15.root");
	
	Int_t ci;      // for color index setting
	
	TColor *color; // for color definition with alpha
	
	TString newstring = mystr;
	
	data15 = (TH1F*)_file1->Get(newstring);
	
	TCanvas *c4 = new TCanvas("c4");
	
	c4->cd();
	data15->GetYaxis()->SetRangeUser(0,700);
	
	data15->Draw();
	
	
	TLegend *leg = new TLegend(0.6504298,0.1518987,0.8667622,0.2658228,NULL,"brNDC");
	TLegendEntry *entry=leg->AddEntry("data15"+newstring,"l");
	entry->SetLineColor(1);
	
	c4->Print(newstring+".pdf");
	
	}
}
