#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define all(T) T.begin(),T.end()
int main(){
	io
	ll n,q;
	cin>>n>>q;
	vector<vector<ll>> v(n+1);
	for(ll i = 1;i<=n;i++)v[i] = {i};
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			ll a,b;
			cin>>a>>b;
			if(v[a].size()<v[b].size())v[a].swap(v[b]);
			for(auto i:v[b])v[a].push_back(i);
			v[b].clear();
		}
		else{
			ll k;
			cin>>k;
			if(v[k].empty())cout<<"-1\n";
			else{
				cout<<v[k].size()<<'\n';
			}
		}
	}
	for(int i = 1;i<=n;i++){
		if(v[i].empty())continue;
		sort(all(v[i]));
		cout<<i<<": ";
		for(auto j:v[i])cout<<j<<' ';
		cout<<'\n';
	}
}

