#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2048;
int N,M,Q;
vector<int> paths[mxn];
int dist[mxn][mxn];

queue<int> q;
void bfs(int s,int d[]){
	fill(d,d+mxn,-1);
	d[s] = 0;
	q.push(s);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(d[nxt] == -1){
				q.push(nxt);
				d[nxt] = d[now]+1;
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M>>Q;
	for(int i = 0;i<M;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		paths[a].push_back(b+N);
		paths[a+N].push_back(b);
		paths[b+N].push_back(a);
		paths[b].push_back(a+N);
	}
	for(int i = 0;i<N;i++){
		bfs(i,dist[i]);
	}
	while(Q--){
		int s,t;
		ll a,b;
		cin>>s>>t>>a>>b;
		s--,t--;
		a--;
		ll ev = dist[s][t];
		ll od = dist[s][t+N];
		if(od<0)od = 1e18,od++;
		if(ev<0)ev = 1e18,ev++;
		ll ans = 0;
		if(b>=ev)ans += (b-ev)/2+1;
		if(a>=ev)ans -= (a-ev)/2+1;
		if(b>=od)ans += (b-od)/2+1;
		if(a>=od)ans -= (a-od)/2+1;
		cout<<ans<<'\n';
	}
	return 0;
}
