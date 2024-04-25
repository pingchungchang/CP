#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
//	io
	ll n,m;
	cin>>n>>m;
	ll arr[n+1];
	m--;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	map<ll,ll> mp;
	vector<ll> cycle;
	ll now = 1;
	ll id = 0;
	while(m>0&&mp.find(now) == mp.end()){
		mp[now] = id++;
		cycle.push_back(now);
		now = arr[now];
	}
	if(m == 0){
		cout<<now;
		return 0;
	}
//	cout<<mp[now]<<' ';for(auto &i:cycle)cout<<i<<',';cout<<endl;
//	return 0;
	ll sz = cycle.size()-mp[now];
//	cout<<sz;
	now = cycle[mp[now]+m%sz];
	cout<<now;
}

