#include <iostream>
#include <string>
using namespace std;

void test(){
		
	TFile *_file1 = TFile::Open("hist-DAOD_TRUTH1.test_ttbb_lh_300.root");
	(TNtuple*)_file1->cd();

	TNtuple* Tree_test;
	Tree_test = (TNtuple*)_file1->Get("data_2tag2pjet_0ptv_SR_SelFJpPt");
	
	Tree_test->Draw("BDT>>h_BDT");

}
