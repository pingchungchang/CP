#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

ll dp[10],dp2[10];
ll pw(ll a,ll b){
	ll re = 1;
	while(b--)re *= a;
	return re;
}
ll calc(ll tar){
	if(tar == 0)return 0LL;
	ll s;
	for(s = 0;pw(10,s)<=tar;s++);
	s--;
	ll cnt = tar-pw(10,s)+1;
	//cout<<s<<' '<<cnt<<endl;
	return dp[s]+dp2[s]*cnt+(s+1)*cnt*(cnt+1)/2;
	//return (s>0?dp[s-1]+dp2[s-1]*cnt:0LL)+(s+1)*cnt*(cnt+1)/2;
}

void solve(){
	ll k;
	cin>>k;
	ll l = 0,r = 1e9;
	while(l != r){
		ll mid = (l+r+1)>>1;
		//cout<<l<<' '<<mid<<' '<<r<<' '<<calc(mid)<<endl;
		if(calc(mid)<k)l = mid;
		else r = mid-1;
	}
	//cout<<k<<":"<<l<<' '<<calc(l)<<":";
	k -= calc(l);
	for(ll i = 0;i<10;i++){
		if(k<=dp2[i]){
			k -= dp2[i-1];
			assert(i != 0);
			ll t = (k-1)/i,r = k%i;
			r = (r+i-1)%i;
			//cout<<k<<":"<<i<<' '<<t+pw(10,i-1)<<' '<<r<<'\n';
			cout<<to_string(t+pw(10,i-1))[r]<<'\n';
			return;
		}
	}
	assert(false);
}
int main(){
	for(ll i = 1;i<10;i++){
		ll cnt = pw(10,i)-pw(10,i-1);
		dp2[i] = dp2[i-1]+i*cnt;
		dp[i] = dp[i-1]+dp2[i-1]*cnt+i*cnt*(cnt+1)/2;
	}
	/*
	for(auto &i:dp2)cout<<i<<' ';cout<<'\n';
	for(auto &i:dp)cout<<i<<' ';cout<<'\n';
	cout<<calc(101);return 0;

   */
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
