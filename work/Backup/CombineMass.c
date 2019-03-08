#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
TH1F *h_data_bins;

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
  TPRegexp r1("\\bhist-RSG_C10_(\\w+).root\\b");
  for(int i=0;i<Num1;i++){
    TString fileN = cwd +Ned+ y[i];
    cout << fileN << endl;
    r1.Substitute(y[i],"$1");
    cout << y[i] << endl;
    TFile *_f_combinedData = TFile::Open(fileN);
    TString FullN = "RS_G_hh_bbtt_hh_c10_"+ y[i]+"_0ptag0pjet_0ptv_SR_cutflow_sumofweights";
    h_data_bins = (TH1F *)gDirectory->Get(FullN);
    //Getting entries for DATA SUM OF WEIGHTS
    cout << "Entries in each bin for "<<_f_combinedData->GetName() << endl;
    double nbins = h_data_bins->GetNbinsX();
    for (int i = 1; i < (nbins + 1); i++)
      {
	cout << "Bin " << i << " number of entries: " << h_data_bins->GetBinContent(i) << endl;
      }
    cout << endl;
  }
}
