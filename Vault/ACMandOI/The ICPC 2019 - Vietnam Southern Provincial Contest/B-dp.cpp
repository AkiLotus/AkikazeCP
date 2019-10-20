#include<bits/stdc++.h>
using namespace std;
#define i64 long long


clock_t t1,t2;
int multi_test;

i64 n;
int Maxsum=0;
vector<int> Map;
vector<int> Pos;
bool Cans[50000001]={false};
void input()
{
    //cerr<<"he\n";
    cin>>n; 
    Map.resize(n);
    for(auto &z:Map)cin>>z,Maxsum+=z;
}

void solve()
{
    for(int i=0;i<n;i++)
    {
        if(Map[i]%2==0)
        {
            Map[i]/=2;
            Map.push_back(Map[i]);
        }
    }
    n=Map.size();
    Cans[0]=true;
    Pos.push_back(0);
    int sum=Maxsum;
    Maxsum/=2;
    for(int i=0;i<n;i++)
    {
        vector<int> cur;
        for(auto z:Pos)
        {
            if(z+Map[i]<=Maxsum&&Cans[z+Map[i]]==false)
            {
                Cans[z+Map[i]]=true;
                cur.push_back(z+Map[i]);
            }
        }
        for(auto z:cur)Pos.push_back(z);
    }
    int sum1=*max_element(Pos.begin(),Pos.end());
    cout<<max(sum1,sum-sum1);

}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   // t1=clock();

    //cin>>multi_test;
    multi_test=1;
    while(multi_test--)
    {
        input();
        solve();
    }


    //t2=clock();
    //float diff ((float)t2-(float)t1);
   // float seconds = diff / CLOCKS_PER_SEC;
    //cerr << "\nRunning in " << seconds << " seconds\n" ;
}