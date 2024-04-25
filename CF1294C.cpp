#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n;
	cin>>n;
	for(ll i = 2;i*(i+1)*(i+2)<=n;i++){
		for(ll j = i+1;i*j*(j+1)<=n;j++){
			ll tmp = i*j;
			if(n%tmp == 0){
				ll k = n/tmp;
				if(k != i&&k != j){
					cout<<"YES\n"<<i<<' '<<j<<' '<<k<<'\n';
					return;
				}
			}
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
