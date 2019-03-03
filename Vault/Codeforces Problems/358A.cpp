#include<bits/stdc++.h>
using namespace std;

int n;
int li[1005];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&li[i]);
	}
	bool val = 1;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(i==j) continue;
			if((li[j]<max(li[i],li[i+1]) && li[j]>min(li[i],li[i+1]) && (li[j+1]>max(li[i],li[i+1]) || li[j+1]<min(li[i],li[i+1]))))
			{
				val = 0;
//				printf(">> %d %d\n",i,j);
			}
			if((li[j+1]<max(li[i],li[i+1]) && li[j+1]>min(li[i],li[i+1]) && (li[j]>max(li[i],li[i+1]) || li[j]<min(li[i],li[i+1]))))
			{
//				printf(">>>> %d %d\n",i,j);
				val = 0;
			}
		}
	}
	if(val) printf("no\n");
	else printf("yes\n");
	return 0;
}