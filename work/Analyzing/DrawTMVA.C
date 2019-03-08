//Declare histograms we will use:
TH1D *h_BDT;
TH1D *my_BDT_S;
TH1D *my_BDT_B;

void DrawTMVA(){

  //Read in the file:
  TFile *_f_tmva = TFile::Open("hist-data-15.root");
  (TNtuple*)_f_tmva->cd();


  //Create an ntuple and fill it with the TestTree from the file
  TNtuple* Tree_test;
  Tree_test = (TNtuple*)_f_tmva->Get("Eventloop_RunTime");

  //Draw the variable "BDT" from the tree.  Save it into a new histogram you can manipulate:
  h_BDT = new TH1D("h_BDT","h_BDT",100,-1.,1.);
  Tree_test->Draw("BDT>>h_BDT");


  //Print out info about the histogram
  cout<<"Number of bins in the histogram: "<<  h_BDT->GetNbinsX()<<endl;
  double nbins;
  nbins = h_BDT->GetNbinsX();

  for(int i=1; i<nbins+1; i++){
    cout<<"Content of Bin number "<<i<<" "<<h_BDT->GetBinContent(i)<<endl;
  }

  //Look in the other directory in the file, called Method_BDT (and then subdirectory BDT) and plot histograms from there

  _f_tmva->cd("Method_BDT/BDT");

  my_BDT_S = (TH1D*)gDirectory->Get("MVA_BDT_S");
  my_BDT_B = (TH1D*)gDirectory->Get("MVA_BDT_B");


  my_BDT_S->Draw();
  my_BDT_S->SetName("my_BDT_S");


  my_BDT_B->SetName("my_BDT_B");
  my_BDT_B->SetLineColor(2);
  my_BDT_B->Draw("same");




}
