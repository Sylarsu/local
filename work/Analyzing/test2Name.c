#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void test2Name() {
	TFile *file = new TFile("hist-data-15.root");
	TKey *key1;
	TKey *key2;
	TIter next1( file->GetListOfKeys());
	TIter next2( file->GetListOfKeys());
	int j=0;
	while ((key1 = (TKey *) next1())) {
		j++;
   }
   cout << j << endl;
   	string y[j];
	int i=0;
	while ((key2 = (TKey *) next2())) {
		y[i] = key2->GetName();
		i++;
	}
		
	ofstream myfile;
	
	myfile.open("ListofN.txt");
	
	for (int z=0; z<j ; z++){
	
	myfile << y[z] << "  ";
	
	}
}