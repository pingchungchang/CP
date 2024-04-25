#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

inline ll calc(ll k){
	ll re = 0;
	while(k){
		re += k%3;
		k/=3;
	}
	return re;
}

void solve(){
	ll n,k;
	cin>>n>>k;
	ll cnt = calc(n);
	if(k<=n&&k>=cnt&&(k-cnt)%2 == 0)cout<<"Yes\n";
	else cout<<"No\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
