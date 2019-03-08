#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//TH1F *h_data_binsD;
//TH1F *h_data_binsF;

void DrawHistogram();
char cwd[PATH_MAX];
TString y[20];
int Num1=0;

void Combine() {
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("Current working dir: %s\n", cwd);
    const char *dirname= cwd;
    const char *ext=".root";
    TSystemDirectory dir(dirname, dirname);
    TList *files = dir.GetListOfFiles();
    TString fname;
    if (files) { TSystemFile *file;
      TIter next(files);
      while ((file=(TSystemFile*)next())) { fname = file->GetName();
	if (!file->IsDirectory() && fname.EndsWith(ext)){
	  //  	  cout<<fname.Data() << endl;
	  y[Num1] = fname.Data();
	  Num1++;
	}
      }
    }
    DrawHistogram();
  }else {
    perror("getcwd() error");
    return 1;
    }
}

void DrawHistogram()
{
  TString Ned("/");
  ofstream myfile;
  myfile.open("Bins_info_for_data_and_fakes");
  //  TPRegexp r1("\\bhist-RSG_C10_(\\w+).root\\b");
  for(int i=0;i<Num1;i++){
    TString fileN = cwd +Ned+ y[i];
    // cout << fileN << endl;
    // r1.Substitute(y[i],"$1");
    //cout << y[i] << endl;
    TFile *_f_combinedData = TFile::Open(fileN);
    TString FullND = "data_0ptag0pjet_0ptv_SR_cutflow_sumofweights";
    TString FullNF = "fakes_0ptag0pjet_0ptv_SR_cutflow_sumofweights";
    TH1F *h_data_binsD = (TH1F *)gDirectory->Get(FullND);
    TH1F *h_data_binsF = (TH1F *)gDirectory->Get(FullNF);
    //Getting entries for DATA SUM OF WEIGHTS
    myfile << "\nEntries in each bin for "<<_f_combinedData->GetName() << "\n";
    myfile << "data" << endl;
    if (h_data_binsD==nullptr){
      myfile << "empty\n"<<endl;
    }
    else{
      double nbinsD = h_data_binsD->GetNbinsX();
	 for (int w = 1; w < (nbinsD + 1); w++)
      {
	myfile << "Bin " << w << " number of entries: " << h_data_binsD->GetBinContent(w) << "\n";
      }
    }
    myfile<< "\nfakes" << endl;
        if (h_data_binsF==nullptr){
      myfile << "empty\n"<<endl;
    }
    else{
      double nbinsF = h_data_binsF->GetNbinsX();
	 for (int w = 1; w < (nbinsF + 1); w++)
      {
	myfile << "Bin " << w << " number of entries: " << h_data_binsF->GetBinContent(w) << "\n";
      }
    }
  }
}
