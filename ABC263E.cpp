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
const ll mod = 998244353;

ll pw(ll a,ll b){
	ll re = 1;
	while(b != 0){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
ll inverse(ll k){
	return pw(k,mod-2);
}
int main(){
	io
	ll n;
	cin>>n;
	ll arr[n];
	ll suff[n+1];
	for(int i= 0;i<n-1;i++)cin>>arr[i];
	arr[n-1] = 0;
	suff[n] = suff[n-1] = 0LL;
	ll sum = 0;
	for(int i = n-2;i>=0;i--){
		arr[i] = (suff[i+1]-suff[i+arr[i]+1]+mod+arr[i]+1)*inverse(arr[i])%mod ;
		if(arr[i]>=mod)arr[i]-= mod;
		suff[i] = suff[i+1]+arr[i];
		if(suff[i]>=mod)suff[i]-= mod;
	}
//	for(int i = 0;i<n;i++)cout<<arr[i]<<' ';cout<<'\n';
//	for(int i = 0;i<n;i++)cout<<suff[i]<<' ';cout<<'\n';
	cout<<arr[0];
}

