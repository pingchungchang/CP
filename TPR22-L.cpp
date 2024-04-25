#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct node{
	int par;
	ll val;
	ll tag;
	vector<ll> ws;
	vector<pair<ll,ll>> childs;
	node(){
		val = INT_MAX;
		par = -1;
		tag = 0;
	}
};
ll n,x;
vector<node> tree;
void dfs(int now,ll t,ll w){
	while(tree[now].tag--){
		tree[t].ws.push_back(w);
	}
	if(now == x){
		for(auto nxt:tree[now].childs){
			tree[nxt.fs].par = x;
			dfs(nxt.fs,nxt.fs,0LL);
		}
		return;
	}
	for(auto nxt:tree[now].childs){
		if(nxt.fs == tree[now].par)continue;
		tree[nxt.fs].par = now;
		dfs(nxt.fs,now,nxt.sc+w);
	}
	return;
}
bool f(ll d){
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	priority_queue<ll,vector<ll>,less<ll>> pq2;
	for(auto tmp:tree[x].childs){
		ll now = tmp.fs;
		ll pos = upper_bound(tree[now].ws.begin(),tree[now].ws.end(),d)-tree[now].ws.begin();
		if(pos == 0){
			pq2.push(tmp.sc);
		}
		for(ll i = 0;i<pos-1;i++)pq.push(tree[now].ws[i]+tmp.sc);
	}
	for(auto i:tree[x].ws)pq.push(i);
	while(!pq2.empty()&&!pq.empty()&&pq.top()+pq2.top()<=d){
		pq.pop();
		pq2.pop();
	}
	if(pq2.empty())return true;
	else return false;
	
}
int main(){
	cin>>n>>x;
	tree = vector<node>(n+1,node());
	for(int i = 0;i<n-1;i++){
		ll a,b,w;
		cin>>a>>b>>w;
		tree[a].childs.push_back(make_pair(b,w));
		tree[b].childs.push_back(make_pair(a,w));
	}
	ll m;
	cin>>m;
	for(ll i = 0;i<m;i++){
		ll k;
		cin>>k;
		tree[k].tag += 1;
	}
	dfs(x,0,0);
	for(auto i:tree){
		sort(i.ws.begin(),i.ws.end());
	}
	ll l = 0, r = 1LL*INT_MAX*4;
	while(l != r){
		ll mid = (l+r)/2;
		if(f(mid))r = mid;
		else l = mid+1;
	}
	cout<<l;
}

