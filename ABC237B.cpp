#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll n,m;
	cin>>n>>m;
	vector<vector<ll>> v(n,vector<ll>(m));
	for(ll i = 0;i<n;i++)for(ll j = 0;j<m;j++)cin>>v[i][j];
	for(ll i = 0;i<m;i++){
		for(ll j= 0;j<n;j++)cout<<v[j][i]<<' ';
		cout<<'\n';
	}
}
