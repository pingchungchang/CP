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
	ll n,m;
	cin>>n>>m;
	vector<ll> v(n,0);
	for(int i = 0;i<n;i++){
		for(int j  = 0;j<m;j++){
			ll k;
			cin>>k;
			v[i] = max(v[i],k);
		}
	}
	ll total = 0;
	for(int i= 0;i<n;i++)total += v[i];
	cout<<total<<'\n';
	vector<ll> ans = {};
	for(int i = 0;i<n;i++){
		if(total%v[i] == 0)ans.push_back(v[i]);
	}
	if(ans.empty())cout<<-1;
	else for(auto i:ans)cout<<i<<' ';
}

