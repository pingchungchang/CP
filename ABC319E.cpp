#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 1e5+10;
map<ll,ll> mp;
ll n,x,y;
pll arr[mxn];

inline ll solve(ll s){
	ll now = s+x;
	for(int i = 1;i<n;i++){
		now = (now+arr[i].fs-1)/arr[i].fs*arr[i].fs;
		now += arr[i].sc;
	}
	return now+y;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>x>>y;
	for(int i = 1;i<n;i++)cin>>arr[i].fs>>arr[i].sc;
	for(int i = 0;i<5*7*8*9;i++)mp[i] = solve(i);
	ll C = 5*7*8*9;
	int q;
	cin>>q;
	while(q--){
		ll k;
		cin>>k;
		cout<<mp[k%C]+(k-k%C)<<'\n';
	}
}
