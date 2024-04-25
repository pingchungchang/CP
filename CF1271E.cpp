#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

ll n,k;

inline ll calc(ll k){
	if(k>n)return 0LL;
	ll re = 0;
	if(!(k&1))k>>=1,re = -1;
	for(ll i = 0;(k<<i)<=n;i++){
		ll tmp = k<<i;
		ll l = 0,r = (1LL<<i)-1;
		while(l != r){
			ll mid = (l+r+1)>>1;
			assert((tmp|mid) == (tmp^mid));
			if((tmp|mid)<=n)l = mid;
			else r = mid-1;
		}
		//cout<<i<<":"<<tmp<<','<<l<<endl;
		re += l+1;
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	if(n == k){
		cout<<1;
		return 0;
	}
	ll l = 1,r = (n+1)/2;
	while(l != r){
		ll mid = (l+r+1)>>1;
		if(calc(mid*2-1)>=k)l = mid;
		else r = mid-1;
	}
	ll ans = l*2-1;
	l = 1, r = n/2;
	while(l != r){
		ll mid = (l+r+1)>>1;
		if(calc(mid*2)>=k)l = mid;
		else r = mid-1;
	}
	ans = max(ans,l*2);
	cout<<ans;
}
