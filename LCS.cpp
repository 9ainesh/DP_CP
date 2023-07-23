#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
const ll mx=1e3+4;
vector< vector<ll> >dp(mx+1,vector<ll>(mx+1,-1));


ll LCS(ll m,ll n,string&a,string&b)
{
  if(m==0 or n==0)
  	return 0;

  if(dp[m][n]!=-1)
  	return dp[m][n];

  if(a[m-1]==b[n-1])
  {
     return dp[m][n]=1+LCS(m-1,n-1,a,b);
  }
  else
  {
  	ll aa=LCS(m-1,n,a,b);
  	ll bb=LCS(m,n-1,a,b);
  	return dp[m][n]=max(aa,bb);
  }
 
}

int main()
{
   ll i,j,m,n;
   string b="nainesh";
   string a="ninih";
   m=a.size(),n=b.size();
   cout<<LCS(m,n,a,b)<<"\n";

eo b 
   // Lets find the lcs string 

   string ans="";
   for(i=m,j=n ; i>0 and j>0 ; )
   {
   	  if(a[i-1]==b[j-1])
   	  {
   	  	ans.push_back(a[i-1]);
   	  	i--,j--;
   	  }
   	  else
   	  {
   	  	 if(dp[i][j-1]>dp[i-1][j])
   	  	 {
   	  	 	j--;
   	  	 }
   	  	 else
   	  	 {
   	  	 	i--;
   	  	 }
   	  }
   }

   reverse(all(ans));
   cout<<ans<<"\n";

   // For shortest common super sequence
   string scss="";
   for(i=m,j=n; i>0 and j>0; )
   {
   	  if(a[i-1]==b[j-1])
   	  {
   	  	scss.push_back(a[i-1]);
   	  	i--,j--;
   	  }
   	  else if(dp[i-1][j]>dp[i][j-1])
   	  {
         scss.push_back(a[i-1]);
         i--;
   	  }
   	  else
   	  {
   	  	scss.push_back(b[j-1]);
   	  	j--;
   	  }
   }

   reverse(all(scss));
   cout<<scss<<"\n";

}