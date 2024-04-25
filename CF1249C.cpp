#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


vector<ll> v;
vector<ll> all;

void solve(){
	ll n;
	cin>>n;
	int p;
	for(p = 0;v[p]<n;p++);
	ll ans = v[p];
	ll tans = 0;
	for(int i = 0;i<v.size();i++)tans += v[i];
	ll d = tans-n;
	for(int i = v.size()-1;i>=0;i--){
		if(d>=v[i])d -= v[i],tans -= v[i];
		//cout<<i<<":"<<v[i]<<' '<<d<<endl;
	}
	cout<<min(tans,ans)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	v = {1};
	while(v.back()<1e18){
		v.push_back(v.back()*3);
	}
	int t;
	cin>>t;
	while(t--)solve();
}
