#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 1e5+10;
const ll mod = 1e9+7;
int n,m;
set<int> unvis;
vector<int> paths[mxn];
int group[mxn];

void BFS(int s){
	queue<int> q;
	q.push(s);
	group[s] = s;
	unvis.erase(s);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		vector<int> vv;
		for(auto &i:unvis){
			if(*lower_bound(paths[now].begin(),paths[now].end(),i) == i)continue;
			group[i] = s;
			vv.push_back(i);
			q.push(i);
		}
		for(auto &i:vv)unvis.erase(i);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if(a>b)swap(a,b);
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		paths[i].push_back(mxn);
		sort(paths[i].begin(),paths[i].end());
	}
	for(int i = 1;i<=n;i++)unvis.insert(i);
	int ans = 0;
	for(int i = 1;i<=n;i++){
		if(!group[i]){
			BFS(i);ans++;
		}
	}
	cout<<ans;
}
