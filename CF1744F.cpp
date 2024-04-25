#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 2e5+10;
ll arr[mxn],pos[mxn];
ll n;

ll calc(ll l,ll r,ll len){
	ll tl = l,tr = r;
	if(r-l+1>len||len>n)return 0;
	tl = min(l,n-len);
	tr = max(0LL,r-len+1);
	return max(0LL,tl-tr+1);
}

void solve(){
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i],pos[arr[i]] = i;
	ll l = pos[0],r = pos[0];
	ll ans = 0;
	for(ll i = 0;i<n;i++){
		l = min(pos[i],l);
		r = max(pos[i],r);
		ans += calc(l,r,i*2+2);
		ans += calc(l,r,i*2+1);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
