#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll n;
	cin>>n;
	if(n<7){
		cout<<-1<<'\n';
		return;
	}
	if(__builtin_popcountll(n)>=3){
		ll ans = 0;
		int c = 0;
		for(int i = 62;i>=0;i--){
			if(c==3)break;
			if((1LL<<i)&n)ans |= 1ll<<i,c++;
		}
		cout<<ans<<'\n';
		return;
	}
	else{
		int high = 0;
		int low = 62;
		for(int i = 0;i<=62;i++){
			if((1ll<<i)&n)high = i,low = min(low,i);
		}
		ll tans = (1ll<<(high-3))+(1ll<<(high-1))+(1ll<<(high-2));
		if(high != low&&low>=2){
			tans = n^(1ll<<low)^(1ll<<(low-1))^(1ll<<(low-2));
		}
		cout<<tans<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
