#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 110;
const ll inf = 1e18;
ll dist[mxn][mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(auto &i:dist)for(auto &j:i)j = inf;
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		dist[a][b] = dist[b][a] = -c;
	}
	for(int i =1;i<=n;i++)dist[i][i] = 0;
	int d;
	cin>>d;
	while(d--){
		int a,b;
		cin>>a>>b;
		dist[a][b] = dist[b][a] = abs(dist[a][b]);
	}
	for(int i = 1;i<=n;i++)for(int j= 1;j<=n;j++)dist[i][j] = max(dist[i][j],0ll);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			for(int k = 1;k<=n;k++){
				dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
			}
		}
	}
	int q;
	int s,e;
	cin>>s>>e;
	cout<<dist[s][e]<<'\n';
	return 0;
}
