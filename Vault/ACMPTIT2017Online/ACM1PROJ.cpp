#include<iostream>
#include<queue>
#define base 1000000007
using namespace std;
main(){
	//int t;
	//cin>>t;
	//for (int i=1;i<=t;i++){
		long long n;
		cin>>n;
		priority_queue <long long,vector<long long>,greater<long long> > kq;
		for (long long j=1;j<=n;j++){
			long long c;
			cin>>c;
			kq.push(c);
		}
		if (n==2){
			long long kq1=kq.top();
			kq.pop();
			kq1=kq1+kq.top();
			cout<<kq1%base<<endl;
		}
		else {
			if (n==1) cout<<kq.top()<<endl;
			else {
				long long kq2=0;
				while (kq.size()!=1){
					long long kq1=kq.top();
					kq.pop();
					kq1=(kq1+kq.top())%base;
					kq.pop();
					kq.push(kq1);
					kq2=(kq2+kq1)%base;
				}
				cout<<kq2<<endl;
			}
		}
	//}
}