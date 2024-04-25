#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const ll mod = 1e9+7;
void solve(){
	ll cnt[33];
	memset(cnt,0LL,sizeof(cnt));
	int n;
	cin>>n;
	ll arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	ll tmp = arr[0];
	for(int i = 0;i<n;i++)tmp &= arr[i];
	for(int i = 0;i<n;i++)arr[i]^=tmp;
	ll z = 0;
	for(auto i:arr)if(i == 0)z++;
	ll ans = z*(z-1)%mod;
	z -= 2;
	for(ll i = n-2;i>0;i--){
		ans = ans*i%mod;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

