#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;

ll st[200004];
ll stair(ll now){
	return st[now];
}
ll c(ll a,ll b){
	if(a<=b)return 1;
	if(b == 0)return 1;
	return (c(a-1,b)+c(a-1,b-1))%mod;
}
void solve(){
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i = 0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	ll biggest = 0;
	ll sb = 0;
	for(ll i =n-1;i>=0;i--){
		if(arr[i] == arr[n-1])biggest++;
		else if(arr[i] == arr[n-1]-1)sb++;
	}
	if(biggest >1){
		cout<<stair(n)<<'\n';
	}
	else if(sb == 0){
		cout<<0<<'\n';
	}
	else{
		ll ans = stair(n);
		for(ll i = 0;i<=n-sb-biggest;i++){
			if(i == 0)ans = (ans+mod-stair(n-1))%mod;
			else ans = (ans+mod-stair(n-1-i)*(n-sb-biggest)%mod)%mod;
		}
		cout<<ans<<'\n';
	}
}
int main(){
	st[0] = 1;
	st[1] = 1;
	for(ll i = 2;i<= 2*1e5;i++){
		st[i] = st[i-1]*i%mod;
	}
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
