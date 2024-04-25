#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	int n,m;
	cin>>n>>m;
	ll arr[n+1];
	arr[0] = 0LL;
	for(ll i= 1;i<=n;i++){
		cin>>arr[i];
	}
	vector<ll> dam(n+1,0LL);
	vector<ll> rdam(n+2,0LL);
	for(ll i = 1;i<=n;i++){
		dam[i] = dam[i-1];
		dam[i] += (arr[i]<arr[i-1]?arr[i-1]-arr[i]:0LL);
	}
	for(int i = n;i>=0;i--){
		rdam[i] = rdam[i+1];
		rdam[i] += (arr[i]<arr[i+1]?arr[i+1]-arr[i]:0LL);
	}
//	for(int i = 1;i<=n;i++)cout<<dam[i]<<" ";cout<<endl;
//	for(int i = 1;i<=n;i++)cout<<rdam[i]<<' ';cout<<endl;
	while(m--){
		ll a,b;
		cin>>a>>b;
		if(a<b)cout<<dam[b]-dam[a]<<'\n';
		else cout<<rdam[b]-rdam[a]<<'\n';
	}
}
int main(){
	io
	int t = 1;
	while(t--)solve();
}

