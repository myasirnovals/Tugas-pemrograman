#include <iostream>

using namespace std;
int persegi(){
	int a, b;
	cout<<"Masukkan jml baris \t: ";
	cin>>a;
	cout<<"Masukkan jml kolom \t: ";
	cin>>b;
	
	for(int c = 1; c <= a; c++){
		for(int d = 1; d < b; d++){
			cout<<"* ";
		}
		cout<<"*"<<endl;
	}
}
