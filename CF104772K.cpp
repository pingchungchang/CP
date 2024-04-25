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
	ll ans = 0;
	while(n){
		ans++;
		ll tmp = 0;
		for(int i = 0;i<64;i++){
			if(tmp+(1ll<<i)<=n)tmp += 1ll<<i;
			else break;
		}
		n -= tmp;
	}
	cout<<ans-1<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
