#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int n,m;
const int mxn = 1010;
int dist[mxn];
int paths[mxn][mxn];
bitset<mxn> done;

void solve(){
	int s,e;
	cin>>s>>e;
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		paths[a][b] = min(paths[a][b],c);
		paths[b][a] = min(paths[b][a],c);
	}
	for(int i = 1;i<=n;i++){
		dist[i] = mxn*mxn*mxn;
		done[i] = 0;
	}
	dist[s] = 0;
	for(int i = 0;i<n;i++){
		int small = -1;
		for(int j = 1;j<=n;j++){
			if(!done[j]&&(small == -1||dist[small]>dist[j]))small = j;
		}
		if(small == -1)break;
		//cout<<small<<":"<<dist[small]<<endl;
		done[small] = true;
		for(int j = 1;j<=n;j++){
			dist[j] = min(dist[j],dist[small]+paths[small][j]);
		}
		//for(int j = 1;j<=n;j++)cout<<dist[j]<<' ';cout<<endl;
	}
	cout<<(dist[e]>=mxn*mxn*mxn?"He is very hot":to_string(dist[e]))<<'\n';

	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++)paths[i][j] = mxn*mxn*mxn;
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 0;i<mxn;i++){
		for(int j = 0;j<mxn;j++)paths[i][j] = mxn*mxn*mxn;
	}
	while(cin>>n>>m)solve();
}
