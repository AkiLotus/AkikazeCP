#include<iostream>
using namespace std;
char a[1000][1000];
int h1[1000],c1[1000],h2[1000],c2[1000];
main(){
	int m,n,k;
	cin>>k;
	for (int t=0;t<k;t++){
		cin>>m>>n;
		long long kq=0;
		for (int i=0;i<m;i++){
			h1[i]=0;
			h2[i]=0;
		}
		for (int i=0;i<n;i++){
			c1[i]=0;
			c2[i]=0;
		}
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				cin>>a[i][j];
				if (a[i][j]=='1'){
					h1[i]++;
					c1[j]++;
				}
				if (a[i][j]=='2'){
					h2[i]++;
					c2[j]++;
				}
			}
		}
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				if (a[i][j]=='1'){
					kq=kq+h2[i]*c2[j];
				}
				if (a[i][j]=='2'){
					kq=kq+h1[i]*c1[j];
				}
			}
		}
		cout<<kq<<endl;
	}
}
