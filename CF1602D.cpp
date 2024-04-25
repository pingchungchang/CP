#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	io
	ll n;
	cin>>n;
	ll a[n+1],b[n+1];
	a[0] = 0,b[0] = 0;
	for(int i = 1;i<=n;i++)cin>>a[i];
	for(int i = 1;i<=n;i++)cin>>b[i];
	ll dp[2][n+1];
	memset(dp,-1,sizeof(dp));
	queue<pll>q;
	q.push({1,n});
	set<ll> st1,st2;
	for(int i = 1;i<n;i++)st.insert(i);
	while(!q.empty()){
		
	}
}

