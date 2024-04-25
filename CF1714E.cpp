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
	ll tar = 0;
	ll tmp;
	cin>>tmp;
	bool flag = true;
	while(tmp%10 != 2&&tmp%10 != 0)tmp += tmp%10;
	tar = tmp;
	for(ll i = 1;i<n;i++){
		ll k;
		cin>>k;
		while(k%10 != 2&&k%10 != 0)k += k%10;
		if(abs(tar-k)%10 != 0){
			flag = false;
		}
		else if(tar%10 == 0&&tar != k){
			flag = false;
		}
		else{
			if(abs(tar-k)/10%2 != 0){
				flag = false;
			}
		}
	}
	
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

