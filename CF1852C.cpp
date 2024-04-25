#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll n,k;
	cin>>n>>k;
	ll arr[n+1];
	arr[0] = 0;
	for(int i= 1;i<=n;i++)cin>>arr[i],arr[i]%=k;
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		ll d = arr[i]-arr[i-1];
		if(d>=0){
			pq.push(d);
			ans += pq.top();
			pq.pop();
		}
		else{
			pq.push(d+k);
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
