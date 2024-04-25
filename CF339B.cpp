#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	ll n,m;
	cin>>n>>m;
	ll ans = 0;
	ll now = 1;
	for(ll i = 0;i<m;i++){
		ll k;
		cin>>k;
		if(k>=now){
			ans += k-now;
			now = k;
		}
		else{
			ans += n-now+k;
			now = k;
		}
	}
	cout<<ans;
}

