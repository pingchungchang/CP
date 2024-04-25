#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
pll arr[mxn];
ll n;

inline bool f(ll k){
	pll now = make_pair(0,0);
	for(int i = 1;i<=n;i++){
		pll range = make_pair(now.fs-k,now.sc+k);
		range.fs = max(range.fs,arr[i].fs);
		range.sc = min(range.sc,arr[i].sc);
		now = range;
		if(now.sc<arr[i].fs||now.fs>arr[i].sc)return false;
	}
	return true;
}

void solve(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i].fs>>arr[i].sc;
	}
	ll l = 0,r = 1e9;
	while(l != r){
		ll mid = (l+r)>>1;
		if(f(mid))r = mid;
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
