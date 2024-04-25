#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

struct Edge{
	ll id,to,val,from;
	Edge(){id = to = from = val = 0;}
};

const int inf = 1e18;
const int mxn = 2022;
int n,m,k;
vector<pll> rural[mxn*4];
vector<Edge> edges;
ll dist[mxn];
int pre[mxn];
bitset<mxn> vis;
ll urban[mxn];
deque<pll> all;
int relax[mxn];

inline void getans(vector<pii>& v){
	for(auto &i:v){
		all.push_back(make_pair(i.fs,urban[i.fs]));
		reverse(rural[i.sc].begin(),rural[i.sc].end());
		for(auto &j:rural[i.sc])all.push_back(make_pair(j.sc,j.fs));
	}
	reverse(all.begin(),all.end());
	int head = -1;

	cout<<all.size()+1<<'\n';
	ll S = 0;
	for(auto &i:all)S += i.sc;
	assert(S>=0);
	int sz = all.size();
	for(int i = 0;i<sz;i++)all.push_back(all[i]);
	for(int i = 1;i<all.size();i++)all[i].sc += all[i-1].sc;
	deque<int> dq;
	for(int i = 0;i<sz;i++){
		while(!dq.empty()&&all[dq.back()].sc>=all[i].sc)dq.pop_back();
		dq.push_back(i);
	}
	ll ans[2] = {0ll,0ll};
	for(int i = 0;i<sz;i++){
		while(!dq.empty()&&dq.front()<=i)dq.pop_front();
		while(!dq.empty()&&all[dq.back()].sc>=all[i+sz].sc)dq.pop_back();
		dq.push_back(i+sz);
		if(all[dq.front()].sc>=all[i].sc){
			ans[all[i+1].fs>n]++;
			head = all[i+1].fs;
		}
	}
	while(all.back().fs != all[0].fs)all.pop_back();
	all.pop_back();
	while(all.front().fs != head){
		all.push_back(all.front());
		all.pop_front();
	}
	for(auto &i:all){
		cout<<i.fs<<' ';
	}
	cout<<all[0].fs;
	cout<<'\n';
	cout<<ans[0]<<' '<<ans[1];
}


inline bool BELLMAN_FORD(){
	for(auto &i:dist)i = -inf;
	dist[1] = 0;
	int change = 0;
	bool cyc = false;
	for(int i = 0;i<=m+n+1;i++){
		change = 0;
		for(auto &j:edges){
			if(!j.from)continue;
			if(dist[j.to]<=dist[j.from]+urban[j.to]+j.val){
				dist[j.to] = dist[j.from]+urban[j.to]+j.val;
				pre[j.to] = j.id;
				change = j.to;
				relax[j.to] = relax[j.from]+1;
				if(relax[j.to]>=n){
					cyc = true;
					break;
				}
			}
		}
		if(cyc)break;
	}
	if(!cyc)return false;

	int now = change;
	vector<pii> v;
	while(!vis[now]){
		assert(now);
		vis[now] = true;
		now = edges[pre[now]].from;
	}
	do{
		v.push_back(make_pair(now,edges[pre[now]].id));
		now = edges[pre[now]].from;
	}while(v[0].fs != now);
	getans(v);
	return true;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++)cin>>urban[i],urban[i] = urban[i];
	edges.push_back(Edge());
	for(int i = 1;i<=m;i++){
		Edge ta;
		cin>>ta.from>>ta.to;
		ta.val = 0;
		ta.id = i;
		for(int j = 1;j<=k;j++){
			pll tmp;
			tmp.sc = n+(i-1)*k+j;
			cin>>tmp.fs;
			ta.val += tmp.fs;
			rural[i].push_back(tmp);
		}
		edges.push_back(ta);
	}
	if(BELLMAN_FORD())return 0;
	else cout<<0;
}
