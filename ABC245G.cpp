#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct node{
	ll col;
	ll c1;
	ll ans;
	vector<pair<ll,ll>> paths;
	int cnt;
	node(){
		c1 = -1;
		cnt = 0;
		ans = LONG_LONG_MAX;
	}
};
int main(){
	io
	ll n,m,k,l;
	cin>>n>>m>>k>>l;
	vector<node> v(n,node());
	for(ll i = 0;i<n;i++){
		cin>>v[i].col;
	}
	priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> pq;
	for(ll i = 0;i<l;i++){
		ll a;
		cin>>a;
		a--;
		pq.push(make_tuple(0,a,v[a].col));
	}
	for(ll i = 0;i<m;i++){
		ll a,b;
		ll c;
		cin>>a>>b>>c;
		a--,b--;
		v[a].paths.push_back(make_pair(b,c));
		v[b].paths.push_back(make_pair(a,c));
	}
//	cout<<'\n';
	while(!pq.empty()){
		ll vv = get<0>(pq.top());
		ll now = get<1>(pq.top());
		ll cc = get<2>(pq.top());
		pq.pop();
//		cout<<vv<<' '<<now<<' '<<cc<<'\n';
		if(v[now].cnt == 2||v[now].c1 == cc)continue;
		v[now].cnt++;
		if(cc != v[now].col) v[now].ans = min(v[now].ans,vv);
		v[now].c1 = cc;
		for(auto nxt:v[now].paths){
			if(v[nxt.fs].cnt == 2||v[nxt.fs].c1 == cc)continue;
			pq.push(make_tuple(vv+nxt.sc,nxt.fs,cc));
		}
	}
	
	for(int i = 0;i<n;i++)cout<<(v[i].ans == LONG_LONG_MAX?-1:v[i].ans)<<' ';
}

