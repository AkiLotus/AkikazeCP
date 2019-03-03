#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
 
// Limit and square root of limit
#define L 120000
#define LSQ 347
typedef long long int int64;
 
int64 gcd(int64 a, int64 b)
{
  int64 c = a % b;
  while(c != 0)
  {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}
 
int main()
{
  // Store pairs in here
  vector< pair<int64,int64> > pairs;
 
  // Use the parameterization
  for(int64 u=1; u<LSQ; u++){
    for(int64 v=1; v<u; v++){
      if(gcd(u,v) != 1) continue;
      if((u-v) % 3 == 0) continue;
      int64 a = 2*u*v + v*v;
      int64 b = u*u - v*v;
      if(a+b > L) break;
      // From coprime pairs make composite pairs
      for(int k=1; k*(a+b)<L; k++){
        pairs.push_back(make_pair(k*a,k*b));
        pairs.push_back(make_pair(k*b,k*a));
      }
    }
  }
 
  // Sort pairs list
  sort(pairs.begin(),pairs.end());
 
  // Create index
  int index[L];
  for(int i=0; i<L; i++) index[i] = -1;
  for(int i=0; i<pairs.size(); i++){
    if(index[pairs[i].first] == -1)
      index[pairs[i].first] = i;
  }
 
  // Which sums have been reached?
  bool sums[L];
  for(int i=0; i<L; i++) sums[i] = false;
 
  // Iterate through all pairs
  for(int i=0; i<pairs.size(); i++){
    int64 a = pairs[i].first;
    int64 b = pairs[i].second;
 
    // Construct vectors for indices
    vector<int64> va;
    vector<int64> vb;
 
    // Fetch indices
    int ia = index[a];
    int ib = index[b];
 
    while(ia<pairs.size()){
      pair<int64,int64> next = pairs[ia];
      if(next.first != a) break;
      va.push_back(next.second);
      ia++;
    }
 
    while(ib<pairs.size()){
      pair<int64,int64> next = pairs[ib];
      if(next.first != b) break;
      vb.push_back(next.second);
      ib++;
    }
 
    // Find common objects between va and vb
    for(int ja=0; ja<va.size(); ja++){
      for(int jb=0; jb<vb.size(); jb++){
        if(va[ja]==vb[jb]){
          // Potential c found
          int64 c = va[ja];
          if(a+b+c<L) sums[a+b+c] = true;
        }
      }
    }
  }
 
  // Tally up sums
  int64 s = 0;
  for(int i=0; i<L; i++)
    if(sums[i]) s+=i;
 
  printf("%lld\n",s);
  return 0;
}
