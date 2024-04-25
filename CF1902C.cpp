#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 2e5+10;
ll arr[mxn];
ll n;
set<int> st;

void solve(){
	st.clear();
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	ll G = 0;
	sort(arr,arr+n);
	st.insert(arr[0]);
	for(int i = 1;i<n;i++){
		G = __gcd(G,arr[i]-arr[i-1]);
	}
	for(int i = 0;i<n;i++)st.insert(arr[i]);
	G = max(G,1ll);
	arr[n] = arr[n-1]+G;
	ll ans = 0;
	ll big = *max_element(arr,arr+n+1);
	for(int i = 0;i<=n;i++)ans += (big-arr[i])/G;
	for(arr[n] = arr[n-1];st.find(arr[n]) != st.end();arr[n] -= G);
	ll tans = 0;
	big = *max_element(arr,arr+n+1);
	for(int i = 0;i<=n;i++)tans += (big-arr[i])/G;
	cout<<min(ans,tans)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
