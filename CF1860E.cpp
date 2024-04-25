#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
const int sh = 5e4+10;
const int mxc = 27;
string s;
int n;
vector<pii> paths[mxn];
int dist[mxc*mxc][mxn];

void BFS(int s,int d[]){
	for(int i = 0;i<mxn;i++)d[i] = 1e9;
	deque<pii> dq;
	d[s] = 0;
	dq.push_back(make_pair(s,0));
	while(!dq.empty()){
		auto now = dq.front();
		dq.pop_front();
		if(now.sc != d[now.fs])continue;
		for(auto nxt:paths[now.fs]){
			if(d[nxt.fs]>d[now.fs]+nxt.sc){
				d[nxt.fs] = d[now.fs]+nxt.sc;
				if(!nxt.sc)dq.push_front(make_pair(nxt.fs,d[nxt.fs]));
				else dq.push_back(make_pair(nxt.fs,d[nxt.fs]));
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	n = s.size();
	for(int i = 1;i<n;i++){
		int ta = s[i-1]-'a',tb = s[i]-'a';
		paths[sh+ta*mxc+tb].push_back({i,1});
		paths[i].push_back({sh+ta*mxc+tb,0});
	}
	for(int i = 2;i<n;i++){
		paths[i].push_back({i-1,1});
		paths[i-1].push_back({i,1});
	}
	for(int i = 0;i<26;i++){
		for(int j = 0;j<26;j++){
			BFS(sh+i*mxc+j,dist[i*mxc+j]);
		}
	}
	/*
	for(int i = 0;i<4;i++){
		for(int j = 0;j<4;j++){
			cout<<(char)('a'+i)<<(char)('a'+j)<<":";for(int l = 1;l<n;l++)cout<<dist[i*mxc+j][l]<<' ';cout<<endl;
		}
	}

   */
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		int tans = abs(a-b);
		for(int i = 0;i<26;i++){
			for(int j = 0;j<26;j++){
				tans = min(tans,dist[i*mxc+j][a]+dist[i*mxc+j][b]-1);
			}
		}
		cout<<tans<<'\n';
	}
	return 0;
}
