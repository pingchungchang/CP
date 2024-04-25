#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int parse(string s){
	int re = 0;
	for(int i = 0;i<s.size();i++){
		if(s[i] == '1')re ^= 1<<i;
	}
	return re;
}

const int mxn = 2048;
int dist[mxn];

void solve(){
	int n,m;
	cin>>n>>m;
	fill(dist,dist+mxn,mxn*mxn);
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	string in;
	cin>>in;
	pq.push({0,parse(in)});
	dist[parse(in)] = 0;
	pair<pii,int> paths[m];
	for(auto &i:paths){
		cin>>i.sc;
		cin>>in;
		i.fs.fs = parse(in);
		cin>>in;
		i.fs.sc = parse(in);
	}
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(dist[now.sc] != now.fs)continue;
		for(auto &i:paths){
			int to = now.sc^(now.sc&i.fs.fs)|i.fs.sc;
			if(dist[to]>now.fs+i.sc){
				dist[to] = now.fs+i.sc;
				pq.push({dist[to],to});
			}
		}
	}
	if(dist[0]>=mxn*mxn)cout<<"-1\n";
	else cout<<dist[0]<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
