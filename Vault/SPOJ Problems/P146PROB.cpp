#include<bits/stdc++.h>
using namespace std;
 
struct canh
{
	int dau,cuoi;
	int trongso;
};
long long ntest,m,i,u,c,v;
long long d[101],dem=0,dad[101];
canh CA[10001];
long long chiphi=0;
 
int FindDad(int u)
{
	if(dad[u]==-1)
		{
			dad[u]=u;return u;
		}
	else return dad[u];
}
 
void Add(int u,int v)
{
	if(u>v)	
		for(int i=1;i<=m;i++)
			{
				if(dad[i]==u)
					dad[i]=v;
			}
	else if(v>u) 
		for(int i=1;i<=m;i++)
				{
					if(dad[i]==v)
						dad[i]=u;
				}		
}
void QUICK_SORT(canh CA[],int left,int right)
{
	if(left==right)
		return;
	 if(left<right)
		{
			int k=(left+right)/2;
			int i=left,j=right;
		while(i<=j)
			{
				while(CA[i].trongso<CA[k].trongso) i++;
				while(CA[j].trongso>CA[k].trongso) j--;
				if(i<=j)
					{
						canh g=CA[i];
						CA[i]=CA[j];
						CA[j]=g;
						i++,j--;
					}
			}
		QUICK_SORT(CA,left,j);
		QUICK_SORT(CA,i,right);	
		}
}
 
 
void quickSort(canh CA[], int l, int r)
{
	if(l<r){
 
    int key = CA[(l+r)/2].trongso;
    int i = l, j = r;
    while(i <= j)
    {
        while(CA[i].trongso < key) i++;       
        while(CA[j].trongso > key) j--;       
        if(i <= j)
        {
            if (i < j)
            	{
            		canh g=CA[i];
					CA[i]=CA[j];
					CA[j]=g;
				}
            i++;
            j--;
        }
    }
    quickSort(CA, l, j);   
    quickSort(CA, i, r); 
	}
}
 
void Selec(canh CA[],int n)
{
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
			if(CA[i].trongso>CA[j].trongso)
				{
					canh g=CA[i];
					CA[i]=CA[j];
					CA[j]=g;
				}
}
void process()
{
	//QUICK_SORT(CA,1,dem);
	//Selec(CA,dem);
	quickSort(CA,1,dem);
	int demcanh=0,demdinh=0;
	int i1=dem,x,y;
	while(demcanh<m-1&&demdinh<m)
	{
		x=FindDad(CA[i1].dau);
		if(x==-1) demdinh++;
		y=FindDad(CA[i1].cuoi);
		if(y==-1) demdinh++;
		if(x!=y)
			{
				Add(x,y);demcanh++;
				chiphi-=CA[i1].trongso;
			}
		//cout <<CA[i1].dau<<" "<<CA[i1].cuoi<<" "<<CA[i1].trongso<<endl;
		i1--;
	}
}
int main()
{
	//freopen("input.txt.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin>>ntest;
	for(int j=1;j<=ntest;j++)
		{
			cin >>m;chiphi=0,dem=0;
			for(int jj=1;jj<=m;jj++)
				{
					cin >>i>>u>>c; 
					d[i]=u,dad[i]=-1;
					for(int j1=1;j1<=c;j1++)
						{
							cin >>v;
							if(i>v)	
								{
									CA[++dem].dau=i; CA[dem].cuoi=v;
									CA[dem].trongso=d[i]+d[v];
									chiphi+=CA[dem].trongso;
								}
						}
				}
				process();
				//for(int i=1;i<=dem;i++)
				//	cout <<CA[i].dau<<"  "<<CA[i].cuoi<<"  "<<CA[i].trongso<<endl;
				cout <<chiphi<<endl;
 
		}
}