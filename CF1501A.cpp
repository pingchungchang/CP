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

void solve(){
	ll n;
	cin>>n;
	vector<pll> v(n+1,make_pair(0,0));
	for(int i = 1;i<=n;i++)cin>>v[i].fs>>v[i].sc;
	vector<ll> tmp(n+1,0);
	for(int i = 1;i<=n;i++)cin>>tmp[i];
	ll now = 0;
	for(int i = 1;i<=n;i++){
		now += v[i].fs-v[i-1].sc+tmp[i];
		if(i != n)now += (v[i].sc-v[i].fs+1)/2;
		if(i != n&&now<v[i].sc)now = v[i].sc;
//		cout<<now<<endl;
	}
	cout<<now<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

