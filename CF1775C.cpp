#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll n,tar;
	cin>>n>>tar;
	ll ans = n;
	for(int i = 60;i>=0;i--){
		if(tar&(1ll<<i))continue;
		if(!(n&(1ll<<i)))continue;
		ans = max(ans,((n>>i)+1)<<i);
	}
	bool flag = true;
	for(int i = 60;i>=0;i--){
		if(tar&(1ll<<i)){
			if(!(n&(1ll<<i)))flag = false;
			if((n>>i) != (ans>>i))flag = false;
		}
		else{
			if(!(n&(1ll<<i)));
			else if((n>>i) == (ans>>i))flag = false;
		}
	}
	if(flag)cout<<ans<<'\n';
	else cout<<"-1\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
