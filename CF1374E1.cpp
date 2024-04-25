#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,k;
	cin>>n>>k;
	vector<ll> both;
	priority_queue<ll,vector<ll>,less<ll>> pq[2];
	ll total = 0;
	for(int i = 0;i<n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		if(b == 1&&c==1){
			both.push_back(a);
			continue;
		}
		total += a;
		if(b == 1){
			pq[0].push(a);
		}
		else if(c == 1)pq[1].push(a);
		else total -= a;
	}
	while(pq[0].size()>k){
		total -= pq[0].top();
		pq[0].pop();
	}
	while(pq[1].size()>k){
		total -= pq[1].top();
		pq[1].pop();
	}
	sort(both.begin(),both.end());
	if(min(pq[0].size(),pq[1].size())+both.size()<k){
		cout<<"-1\n";
		return;
	}
	ll ans = 1e18;
	if(min(pq[0].size(),pq[1].size())==k)ans = total;
	for(int i = 0;i<both.size();i++){
		if(i>=k)break;
		total += both[i];
		while(pq[0].size()>=k-i){
			total -= pq[0].top();
			pq[0].pop();
		}
		while(pq[1].size()>=k-i){
			total -= pq[1].top();
			pq[1].pop();
		}
		if(min(pq[0].size(),pq[1].size())+i+1==k)ans = min(ans,total);
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
