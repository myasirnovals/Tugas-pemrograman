#include <iostream>

using namespace std;
int segitiga(){
	int jml;
	cout<<"Masukkan jumlah bintang: ";
	cin>>jml;

	for(int a = 0; a < jml; a++){
		for(int b = 0; b < a; b++){
			cout<<"* ";
		}
		cout<<"*"<<endl;
	}
}
