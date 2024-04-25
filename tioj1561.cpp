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

const int mxn = 110;
const int inf = 1e9;
int paths[mxn][mxn];
pii dist[mxn];
int goneto[mxn];
int n,m;
void solve(){
	for(auto &i:goneto)i = 0;
	for(auto &i:paths)for(auto &j:i)j = inf;
	for(auto &i:dist)i = {inf,inf};
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		paths[a][b] = paths[b][a] = c;
	}
	int s,e;
	cin>>s>>e;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,s});
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(goneto[now.sc] == 2)continue;
//		cout<<now.fs<<' '<<now.sc<<endl;
		goneto[now.sc]++;
		for(int i = 0;i<n;i++){
			if(paths[now.sc][i] == inf||goneto[i] == 2)continue;
			if(paths[now.sc][i]+now.fs<dist[i].fs){
				swap(dist[i].fs,dist[i].sc);
				dist[i].fs = paths[now.sc][i]+now.fs;
				pq.push({paths[now.sc][i]+now.fs,i});
			}
			else if(paths[now.sc][i]+now.fs<dist[i].sc){
				dist[i].sc = paths[now.sc][i]+now.fs;
				pq.push({paths[now.sc][i]+now.fs,i});
			}
		}
	}
	if(dist[e].sc != inf)cout<<dist[e].sc<<'\n';
	else cout<<-1<<'\n';
}
int main(){
//	io
	while(cin>>n>>m)solve();
	
}
