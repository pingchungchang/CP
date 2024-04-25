#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


ll n,c;
const ll mxn = 2e5+10;
ll arr[mxn];
const ll inf = 2e18;

ll f(ll k){
	ll total = 0;
	for(int i = 0;i<n;i++){
		total += (k*2+arr[i])*(k*2+arr[i]);
		if(total>1e18)return inf;
	}
	return total;
}

void solve(){
	cin>>n>>c;
	ll l = 0,r = 5e8;
	for(int i =0;i<n;i++)cin>>arr[i];
	while(l != r){
		ll mid = (l+r)>>1;
		if(f(mid)>=c)r = mid;
		else l = mid+1;
	}
	cout<<l<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
