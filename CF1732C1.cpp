#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const ll mxn = 1e5+10;
pll arr[mxn];
int n,q;

inline tlll calc(ll len){
	tlll ans = make_tuple(arr[len].fs-arr[0].fs-arr[len].sc,1,len);
	for(int i = len;i<=n;i++){
		ll tval = arr[i].fs-arr[i-len].fs-(arr[i].sc^arr[i-len].sc);
		ans = max(ans,make_tuple(tval,i-len+1,i));
	}
	return ans;
}

void solve(){
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>arr[i].fs,arr[i].sc = arr[i].fs^arr[i-1].sc,arr[i].fs += arr[i-1].fs;
	cin>>q>>q;
	ll ans = 0;
	for(int i = 0;i<=n;i++){
		ans = max(ans,arr[n].fs-arr[i].fs-(arr[n].sc^arr[i].sc));
	}
	ll l = 1,r = n;
	while(l != r){
		ll mid = (l+r)>>1;
		auto re = calc(mid);
		if(get<0>(re) == ans)r = mid;
		else l = mid+1;
	}
	auto re = calc(l);
	cout<<get<1>(re)<<' '<<get<2>(re)<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
