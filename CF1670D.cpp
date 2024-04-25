#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const ll mxn = 1e5+10;
vector<ll> dp;
void solve(){
	ll n;
	cin>>n;
	ll pos = lower_bound(dp.begin(),dp.end(),n)-dp.begin();
	cout<<pos+1<<'\n';
	return;
}
int main(){
	io
	int t;
	dp.push_back(0LL);
	for(ll i = 2;i<mxn;i++){
		ll a = i/3+(i%3 >= 1?1LL:0);
		ll b = i/3+(i%3 >= 2?1LL:0);
		ll c = i/3;
//		if(i<=10)cout<<i<<":"<<a<<' '<<b<<' '<<c<<'\n';
		dp.push_back(0);
		dp.back() = a*b+b*c+a*c;
		dp.back()*=2;
		if(dp.back()>=INT_MAX){
//			cout<<dp.size()<<' '<<dp.back()<<'\n';
			break;
		}
	}
//	for(int i = 1;i<=10;i++)cout<<dp[i]<<',';
	cin>>t;
	while(t--)solve();
}

