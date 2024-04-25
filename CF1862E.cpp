#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,m,d;
	cin>>n>>m>>d;
	ll arr[n+1];
	for(int i = 1;i<=n;i++)cin>>arr[i];
	ll sum = 0;
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		if(arr[i]>0){
			pq.push(arr[i]);
			sum += arr[i];
		}
		while(pq.size()>m){
			sum -= pq.top();
			pq.pop();
		}
		ans = max(ans,sum-d*i);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
