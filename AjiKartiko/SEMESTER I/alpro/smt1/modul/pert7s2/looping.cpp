#include <iostream>

using namespace std;
int main() {
	int a, b;
	cout<<"masukkan jumlah baris \t: ";
	cin>>a;
	cout<<"masukkan jumlah kolom \t: ";
	cin>>b;
	
	for(int c = 1; c<= a; c++){
		for(int d = 1; d < b; d++){
			cout<<"* ";
		}
		cout<<"*"<<endl;
	}
}
