#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2020;
const ll inf = 1e18;
int arr[mxn],brr[mxn];
ll dist[mxn][mxn];
pll pos[mxn];
bitset<mxn> vis;
pll len[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>pos[i].fs>>pos[i].sc;
	for(int i = 1;i<=n;i++)cin>>arr[i],dist[0][i] = dist[i][0] = arr[i];
	for(int i = 1;i<=n;i++)cin>>brr[i];
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			dist[i][j] = (brr[i]+brr[j])*(abs(pos[i].fs-pos[j].fs)+abs(pos[i].sc-pos[j].sc));
		}
	}
	for(auto &i:len)i = {inf,inf};
	len[0] = {0,0};
	ll ans = 0;
	/*
	for(int i = 0;i<=n;i++){
		for(int j = 0;j<=n;j++)cout<<dist[i][j]<<' ';cout<<endl;
	}

   */
	for(int i = 0;i<=n;i++){
		pll small = {inf,inf};
		for(int j = 0;j<=n;j++)if(!vis[j])small = min(small,{len[j].fs,j});
		vis[small.sc] = true;
		ans += small.fs;
		int now = small.sc;
		//cout<<small.fs<<':'<<small.sc<<":"<<len[now].sc<<endl;
		for(int j = 0;j<=n;j++){
			if(!vis[j]&&len[j].fs>dist[now][j]){
				len[j] = {dist[now][j],now};
			}
		}
	}
	vector<int> station;
	vector<pii> edges;
	for(int i = 1;i<=n;i++){
		if(len[i].sc == 0)station.push_back(i);
		else edges.push_back({len[i].sc,i});
	}
	cout<<ans<<'\n';
	cout<<station.size()<<'\n';for(auto &i:station)cout<<i<<' ';cout<<'\n';
	cout<<edges.size()<<'\n';for(auto &i:edges)cout<<i.fs<<' '<<i.sc<<'\n';
	return 0;
}
