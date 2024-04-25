#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
ll n,x;
ll arr[mxn];

ll f(ll tar){
	ll re = 0;
	for(int i = 1;i<=n;i++)re += max(0LL,tar-arr[i]);
	return re;
}


void solve(){
	cin>>n>>x;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	ll l = 1,r = 2e9;
	while(l != r){
		ll mid = (l+r+1)>>1;
		if(f(mid)<=x)l = mid;
		else r = mid-1;
	}
	cout<<l<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
