#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll n,m,k;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	vector<vector<pair<ll,ll>>> paths(n);
	vector<int> goneto(n,0);
	for(ll i =0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		paths[a].push_back(make_pair(b,c));
	}
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
	pq.push(make_pair(0,0));
	vector<ll> ans;
	ll x = k;
	while(!pq.empty()&&x>0){
		ll now = pq.top().second;
		ll val = pq.top().first;
		pq.pop();
		if(goneto[now]>k)continue;
		goneto[now]++;
		if(now == n-1){
			cout<<val<<'\n';
			x--;
		}
		for(ll i =0;i<paths[now].size();i++){
			ll nxt = paths[now][i].first;
			if(goneto[nxt]>k)continue;
			pq.push(make_pair(paths[now][i].second+val,nxt));
		}
	}
}
