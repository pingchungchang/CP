#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


inline ll f(ll a,ll b,ll r){
	if(a==b)return 0;
	ll re = 0;
	bool flag = false;
	for(int i = 60;i>=0;i--){
		if(((a>>i)&1) == ((b>>i)&1))continue;
		ll tar = ((a>>i)&1);
		if(!flag){
			if((re|((tar^1)<<i))<=r){
				re |= (tar^1)<<i;
				flag = true;
			}
		}
		else{
			if((re|(tar<<i))<=r){
				re |= tar<<i;
			}
		}
	}
	return abs((re^a)-(re^b));
}

void solve(){
	ll a,b,r;
	cin>>a>>b>>r;
	ll ans = min(f(a,b,r),f(b,a,r));
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
