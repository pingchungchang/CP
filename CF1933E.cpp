#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 2e5+10;

ll n,q;
ll arr[mxn],pref[mxn];

inline ll calc(ll s,ll e,ll u){
	ll len = pref[e]-pref[s-1];
	return (u*2+1-len)*len/2;
}

void solve(){
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i],pref[i] = pref[i-1]+arr[i];
	cin>>q;
	while(q--){
		ll s,u;
		cin>>s>>u;
		ll l = s,r = n;
		while(l+1<r){
			ll mid = (l+r)>>1;
			if(calc(s,mid,u)>=calc(s,mid+1,u))r = mid;
			else l = mid+1;
		}
		cout<<(calc(s,l,u)>=calc(s,r,u)?l:r)<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
