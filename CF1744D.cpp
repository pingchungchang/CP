#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
void solve(){
	ll n;
	cin>>n;
	ll cnt = n;
	ll arr[32];
	fill(arr,arr+32,0LL);
	for(ll i = 1;i<=n;i++){
		ll k;
		cin>>k;
		while(!(k&1)){
			cnt--;
			k>>=1;
		}
		ll tmp = i;
		int c = 0;
		while(!(tmp&1)){
			c++;
			tmp>>=1;
		}
		arr[c]++;
	}
	ll ans = 0;
	for(int i = 31;i>=1;i--){
		if(cnt>=i){
			ans += min(arr[i],cnt/i);
			cnt -= i*min(arr[i],cnt/i);
		}
	}
	if(cnt<=0)cout<<ans<<'\n';
	else cout<<"-1\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

