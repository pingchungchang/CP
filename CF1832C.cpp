#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	vector<ll> v;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		if(!v.empty()&&v.back() == k)continue;
		while(v.size()>=2&&(v[v.size()-2]-v.back())*(v.back()-k)>=0)v.pop_back();
		v.push_back(k);
	}
	cout<<v.size()<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
