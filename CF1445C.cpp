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
	ll p,q;
	cin>>p>>q;
	if(p%q != 0){
		cout<<p<<'\n';
		return;
	}
	ll ans = 0;
	for(ll i = 1;i*i<=q;i++){
		if(q%i == 0){
			ll tmp = p;
			ll k = q/i;
			while(tmp%k == 0&&tmp%q == 0)tmp /=k;
			if(tmp%q != 0)ans = max(ans,tmp);
			if(i != 1){
				k = i;
				tmp = p;
				while(tmp%k == 0&&tmp%q == 0)tmp /=k;
				if(tmp%q != 0)ans = max(ans,tmp);
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

