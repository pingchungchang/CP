#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("popcnt,avx2,sse4")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define al3 array<int,3>

const int mxm = 5e5+10;
const int mxn = 1101;
int N,M;
int dist[mxn];
bitset<mxn> inq;
queue<int> q;
int cnt[mxn];
vector<pii> paths[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	for(int i = 1;i<=M;i++){
		int a,b,c;
		cin>>a>>b>>c;
		paths[b].push_back(pii(a,-c));
	}
	for(int i = 1;i<=N;i++)q.push(i);
	inq.set();
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		inq[now] = false;
		cnt[now]++;
		if(cnt[now]>N+1){
			cout<<"-1\n";
			return 0;
		}
		for(auto [nxt,w]:paths[now]){
			if(dist[nxt]<=dist[now]+w)continue;
			dist[nxt] = dist[now]+w;
			if(!inq[nxt])q.push(nxt);
			inq[nxt] = true;
		}
	}
	int sh = *min_element(dist+1,dist+N+1);
	sh += 1e6;
	for(int i = 1;i<=N;i++)dist[i] = dist[i]-sh;
	for(int i = 1;i<=N;i++)cout<<dist[i]<<'\n';
	return 0;
}
