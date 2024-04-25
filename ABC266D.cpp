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
const int mxn = 1e5+10;
pll pos[mxn];
const ll inf = 1e18;
int main(){
	io
	ll n;
	cin>>n;
	for(int i = 0;i<n;i++){
		ll t,x,v;
		cin>>t>>x>>v;
		pos[t] = {x,v};
	}
//	for(int i = 0;i<10;i++)cout<<i<<' '<<pos[i].fs<<' '<<pos[i].sc<<endl;
	ll dp[5] = {0,-inf,-inf,-inf,-inf};
	for(int i = 1;i<mxn;i++){
		ll tmp[5];
		for(int j = 0;j<5;j++){
			tmp[j] = dp[j];
			if(j != 0)tmp[j] = max(tmp[j],dp[j-1]);
			if(j != 4)tmp[j] = max(tmp[j],dp[j+1]);
		}
		tmp[pos[i].fs]+= pos[i].sc;
		for(int j = 0;j<5;j++)dp[j] = tmp[j];
	}
//	for(auto &j:dp)cout<<j<<' ';cout<<endl;
	cout<<*max_element(dp,dp+5);
}

