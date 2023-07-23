#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
const ll mxx=1e3+5;
vector< vector<ll> >dp(mxx,vector<ll>(mxx,0));
//vector<ll>dp(mxx,-1);

ll LIS(ll prev,ll cur,vector<ll>&v)
{ 

	if(cur == v.size())
		return 0;
	
    ll a=0,b=0;
    a=LIS(prev,cur+1,v);

    //include only if the following condition satiesfied

    if(v[cur]>v[prev] or prev == -1)
     b=1+LIS(cur,cur+1,v);

   return dp[cur][prev+1]=max(a,b);

}
int main()
{
   ll n,i,j,ans=0,cur,prev;
   cin>>n;
   vector<ll>v(n,0);
   for(i=0;i<n;i++)
   	cin>>v[i];
   //cout<<LIS(-1,0,v);
   vector<ll>sigdp(n+1,1);

   // for(cur=0;cur<n;cur++)
   // {
   // 	 for(prev=cur-1;prev>=0;prev--)
   // 	 {
   // 	 	if(v[cur]>v[prev])
   // 	 	 sigdp[cur]=max(sigdp[cur],1+sigdp[prev]);
   // 	 	ans=max(sigdp[cur],ans);
   // 	 }
   // }

   // for(cur=0;cur<n;cur++)
   // {
	  //  	for(prev=0;prev<cur;prev++)
	  //  	{
	  //  		if(v[cur]>v[prev])
	  //  		{
	  //  			sigdp[cur]=max(sigdp[cur],1+sigdp[prev]);
	  //  		}
	  //  		ans=max(ans,sigdp[cur]);
	  //  	}
   // }

   // cout<<ans<<"\n";

   // print the LIS

   // vector<ll>ansLIS;
   // ll req=ans;
   // prev=INT_MAX;
   // for(i=n-1;i>=0;i--)
   // {
   // 	  if(sigdp[i]==req and v[i]<prev)
   // 	  {
   // 	  	prev=v[i];
   // 	  	req--;
   // 	  	ansLIS.push_back(prev);
   // 	  }
   // }

   // reverse(all(ansLIS));
   // for(auto ele:ansLIS)
   // 	cout<<ele<<" ";
   // cout<<"\n";

   // O(nlogn)

   vector<ll>tmp;
   tmp.push_back(v[0]);

   for(i=1;i<n;i++)
   {
      if(v[i]>tmp.back())
      	tmp.push_back(v[i]);
      else
      {
      	ll ind=lower_bound(all(tmp),v[i])-tmp.begin();
      	tmp[ind]=v[i];
      }
   }

   cout<<tmp.size()<<"\n";
}