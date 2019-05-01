#include<iostream>
using namespace std;
main(){
	int n;
	cin>>n;
	cin.ignore();
	string kq;
	long long dem=-1,tong=0;
	for (int i=1;i<=n;i++){
		string ten;
		cin>>ten;
		int k,m,dem1=0;
		cin>>k>>m;
		cin.ignore();
		while (k<=m){
			dem1++;
			m=m-k+2;
		}
		tong+=dem1;
		if (dem1>dem){
			kq=ten;
			dem=dem1;
		}
	}
	cout<<tong<<endl<<kq;
}
