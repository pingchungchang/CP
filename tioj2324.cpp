#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 2e5+10;
vector<pll> tree[mxn];
vector<tlll> edges;
int dsu[mxn],sz[mxn];
ll n;
ll arr[mxn];
ll dist[mxn];

inline void subtask2(){
	cin>>n;
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i = 2;i<=n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		pq.push(arr[b]+c);
	}
	ll small = arr[1];
	ll ans = 0;
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		ans += now+small;
		small = min(small,now);
	}
	cout<<ans<<'\n';
	return;
}

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
inline void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	sz[a] += sz[b];
	dsu[b] = a;
	return;
}

void dfs(int now,int fa){
	for(auto nxt:tree[now]){
		if(nxt.fs == fa)continue;
		dist[nxt.fs] = dist[now]+nxt.sc;
		dfs(nxt.fs,now);
	}
	return;
}

inline void subtask1(){
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i],dsu[i] = i,sz[i] = 1;
	for(int i = 1;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		tree[a].push_back({b,c});
		tree[b].push_back({a,c});
	}
	for(int i = 1;i<=n;i++){
		dist[i] = 0;
		dfs(i,i);
		for(int j = i+1;j<=n;j++){
			edges.push_back(make_tuple(dist[j]+arr[j]+arr[i],i,j));
		}
		//cout<<i<<":";for(int j = 1;j<=n;j++)cout<<dist[j]<<' ';cout<<endl;
	}
	sort(edges.begin(),edges.end());
	ll ans = 0;
	for(auto &i:edges){
		if(root(get<1>(i)) == root(get<2>(i)))continue;
		ans += get<0>(i);
		onion(get<1>(i),get<2>(i));
		
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	subtask1();exit(0);
	subtask2();exit(0);
}
