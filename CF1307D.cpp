#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> paths[mxn];
int n,m,k;
vector<int> sp;
int dist1[mxn],dist2[mxn];
vector<pii> v;

void BFS(int start,int dist[]){
	fill(dist,dist+mxn,-1);
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(dist[nxt] == -1){
				dist[nxt] = dist[now]+1;
				q.push(nxt);
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 0;i<k;i++){
		int tmp;
		cin>>tmp;
		sp.push_back(tmp);
	}
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	BFS(1,dist1);
	BFS(n,dist2);
	assert(dist1[n] == dist2[1]);
	int D = dist1[n];
	for(auto &i:sp){
		v.push_back({dist1[i]-dist2[i],i});
	}
	sort(v.begin(),v.end());
	int mt = dist1[v[0].sc];
	int ans = 0;
	//for(int i = 0;i<v.size();i++)cout<<v[i].fs<<":"<<v[i].sc<<endl;
	for(int i = 1;i<v.size();i++){
		ans = max({ans,min(D,dist2[v[i].sc]+mt+1)});
		mt = max(mt,dist1[v[i].sc]);
	}
	cout<<ans;
}
