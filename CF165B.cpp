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
ll n,k;
bool f(ll now){
	ll re = 0;
	ll kk = 1;
	while(now/kk>0){
		re += now/kk;
		kk *= k;
	}
	return re>=n;
}
int main(){
	io
	cin>>n>>k;
	ll l = 1,r = 1e9;
	while(l != r){
		ll mid = (l+r)>>1;
		if(f(mid))r = mid;
		else l = mid+1;
	}
	cout<<l;
}

