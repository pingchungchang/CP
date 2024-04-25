#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	ll n,k;
	cin>>n>>k;
	pll now;
	vector<vector<ll>> req(2,vector<ll>(n));
	for(int i = 0;i<2;i++){
		for(ll j= 0;j<n;j++)cin>>req[i][j];
	}
	now = make_pair(req[0][0],req[1][0]);
	for(ll i= 1;i<n;i++){
		vector<ll> v;
		ll a = req[0][i],b = req[1][i];
		if(abs(a-now.fs)<=k||abs(a-now.sc)<=k)v.push_back(a);
		if(abs(b-now.fs)<=k||abs(b-now.sc)<=k)v.push_back(b);
		if(v.size() == 0){
			cout<<"No";
			return 0;
		}
		while(v.size()<2)v.push_back(1LL*INT_MAX*2);
		now.fs = v[0];
		now.sc = v[1];
	}
	cout<<"Yes";
	return 0;
}

