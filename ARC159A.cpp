#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll inf = 1e18;
const ll mxn = 202;
ll dist[mxn][mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,k;
	cin>>n>>k;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin>>dist[i][j];
			if(dist[i][j] == 0)dist[i][j] = inf;
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			dist[i+n][j] = dist[i][j+n] = dist[i+n][j+n] = dist[i][j];
		}
	}
	for(int i = 0;i<n*2;i++){
		for(int j = 0;j<n*2;j++){
			for(int k = 0;k<n*2;k++){
				dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
			}
		}
	}
	for(int i = 0;i<n*2;i++)for(int j = 0;j<n*2;j++)if(dist[i][j]>=inf)dist[i][j] = -1;
	ll q;
	cin>>q;
	while(q--){
		ll s,e;
		cin>>s>>e;
		s--,e--;
		if(s/n == e/n){
			s %= n,e %= n;
			cout<<dist[s][e]<<'\n';
		}
		else{
			s %= n,e %= n;
			e += n;
			cout<<dist[s][e]<<'\n';
		}
	}
	return 0;
}
