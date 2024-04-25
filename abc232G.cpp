#include <bits/stdc++.h>
using namespace std;

#define ll long long
constexpr ll mx = 1e5*2+5;
ll a[mx];
ll b[mx];
ll goneto[mx];
bool vis[mx] = {};
int main(){
	ll n,m;
	cin>>n>>m;
	for(ll i = 0;i<n;i++){
		goneto[i] = 1e15;
	}
	for(ll i = 0;i<n;i++)cin>>a[i];
	for(ll j = 0;j<n;j++)cin>>b[j];
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
	pq.push(make_pair(0,0));
	goneto[0] = 0;
	while(!pq.empty()&&vis[n-1] == false){
		ll now = pq.top().second;
		ll val = pq.top().first;
//		cout<<now<<' ';
		pq.pop();
		if(vis[now] == true||goneto[now]<val)continue;
		vis[now] = true;
		for(ll i =0;i<n;i++){
			if(vis[i] == true)continue;
			ll w = (a[now]+b[i])%m;
			if(goneto[i]>w+val){
				goneto[i] = w+val;
				pq.push(make_pair(w+val,i));
			}
		}
	}
	cout<<goneto[n-1];
}
