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
#define vi vector<ll>
#define vvi vector<vi>

int main(){
	map<ll,ll> mp;
	ll n,m;
	cin>>n>>m;
	mp[1] = mp[n+1] = 0;
	for(int i = 0;i<m;i++){
		ll a,b;
		cin>>a>>b;
		mp[a]++;
		mp[b+1]--;
	}
	int pre = 1;
	int total = 0;
	ll ans = 0;
	for(auto &i:mp){
		if((total&1) == 0)ans += i.fs-pre;
		pre = i.fs;
		total += i.sc;
	}
	cout<<ans;
}

