#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define fs first
#define sc second

const int inf = 1e9+10;
const int mxn = 505;
int dist[mxn][mxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	int s,e;
	cin>>s>>e;
	for(auto &i:dist)for(auto &j:i)j = inf;
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		dist[a][b] = min(dist[a][b],c);
	}
	for(int i = 0;i<n;i++)for(int j = 0;j<n;j++)for(int k = 0;k<n;k++)
		dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
	ll total = dist[s][e]+dist[e][s];
	if(total>60*60*5)cout<<"So many sleepless nights where you were waiting up on me.";
	else{
		total /= 60;
		ll m = total%60;
		total /=60;
		ll h = total;
		string th = to_string(h);
		string tm = to_string(m);
		if(tm.size() != 2)tm = "0"+tm;
		if(th.size() != 2)th = "0"+th;
		cout<<th<<":"<<tm;
	}
}
