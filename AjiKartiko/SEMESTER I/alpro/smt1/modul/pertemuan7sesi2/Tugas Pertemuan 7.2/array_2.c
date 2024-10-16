#include <iostream>

using namespace std;
int array_2(){
	int jml_arr;
	cout<<"Jumlah Index : ";
	cin>>jml_arr;
	
	int angka [jml_arr];
	
	for(int a = 0; a < jml_arr; a++){
		cout<<"Masukkan Nilai Index Ke-"<<a<<" : ";
		cin>>angka[a];
	}
	cout<<"==================================="<<endl;
	cout<<"Nilai Yang Tersimpan"<<endl;
	cout<<"==================================="<<endl;
	for(int b = 0; b< jml_arr; b++){
		cout<<"Index Ke-"<<b<<" : "<<angka[b]<<endl;
	}
}
