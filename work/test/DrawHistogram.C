//Declare histograms we will use. We will copy histograms from the data file into these
TH1F *h_data_bins;

void DrawHistogram()
{

  TFile *_f_combinedData = TFile::Open("/home/adduser/work/test/hist-RSG_C10_M1300.root");
  h_data_bins = (TH1F *)gDirectory->Get("RS_G_hh_bbtt_hh_c10_M1300_0ptag0pjet_0ptv_SR_cutflow_sumofweights");

  //Getting entries for DATA SUM OF WEIGHTS
  cout << "Entries in each bin for "<<_f_combinedData->GetName() << endl;
  double nbins = h_data_bins->GetNbinsX();
  for (int i = 1; i < (nbins + 1); i++)
  {
    cout << "Bin " << i << " number of entries: " << h_data_bins->GetBinContent(i) << endl;
  }
  cout << endl;
}
