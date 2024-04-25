#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll n,k;
	cin>>n>>k;
	ll a[n],b[n];
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	for(ll i = 0;i<n;i++){cin>>a[i];pq.push({a[i],i});}
	for(auto &i:b)cin>>i;
	sort(b,b+n);
	for(auto &i:b){
		a[pq.top().sc] = i;
		pq.pop();
	}
	for(auto &i:a)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
