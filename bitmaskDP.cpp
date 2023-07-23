#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
const ll mxx=1e3+5;
vector< vector<ll> >dp(16,vector<ll>(1LL<<16,-1));


ll maskedDP(vector< vector<ll> >&cost,ll ava_per_mask,ll jn,ll n)
{
      if(jn==n)
      	return 0;

      if(dp[jn][ava_per_mask]!=-1)
      	return dp[jn][ava_per_mask];

      ll ans=INT_MAX;
      
      for(ll i=0;i<n;i++)
      {
      	  if((ava_per_mask&(1LL<<i)))
      	  {
      	  	   ans=min(ans,cost[i][jn]+maskedDP(cost,ava_per_mask^(1LL<<i),jn+1,n));
      	  }
      }

      return dp[jn][ava_per_mask]=ans;
}



int main()
{
	ll n,i,j;
	cin>>n;
	vector< vector<ll> >cost(n,vector<ll>(n,0));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		 cin>>cost[i][j];
	}
 
     cout<<maskedDP(cost,(1LL<<15)-1,0,n)<<"\n";
}