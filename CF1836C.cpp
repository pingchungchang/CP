#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int A,B,C;
ll k;


void solve(){
	cin>>A>>B>>C>>k;
	if(max(A,B) != C&&max(A,B) != C-1){
		cout<<"-1\n";
		return;
	}
	ll ra = 1;
	for(int i = 1;i<A;i++)ra *= 10;
	ll rb = 1;
	for(int i = 1;i<B;i++)rb *= 10;
	ll rc = 1;
	for(int i = 1;i<C;i++)rc *= 10;
	for(ll i = ra;i<ra*10;i++){
		ll l = rb,r = rb*10-1;
		while(l != r){
			ll mid = (l+r)>>1;
			if(mid+i<rc)l = mid+1;
			else r = mid;
		}
		ll s = l;
		l = s,r = rb*10-1;
		while(l != r){
			ll mid = (l+r+1)>>1;
			if(mid+i>=rc*10)r = mid-1;
			else l = mid;
		}
		ll e = r;
		if(s+i<rc||s+i>=rc*10)continue;
		if(e-s+1>=k){
			cout<<i<<" + "<<s+k-1<<" = "<<i+s+k-1<<'\n';
			return;
		}
		k -= e-s+1;
	}
	cout<<"-1\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
