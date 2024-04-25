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
	ll n,x;
	cin>>n>>x;
	vector<pii> v(n);
	for(auto &i:v){
		cin>>i.fs;
		i.sc = 1;
	}
	int p = 0;
	while(p<v.size()){
		if(v[p].fs%x == 0){
			v.push_back({v[p].fs/x,v[p].sc*x});
			p++;
		}
		else break;
	}
	ll ans = 0;
	for(auto &i:v)ans += i.fs*i.sc;
//	for(auto &i:v)cout<<i.fs<<' '<<i.sc<<',';
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

