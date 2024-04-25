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
	ll ans= INT_MAX;
	vector<ll> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	for(int i = 0;i<n-1;i++){
		auto tmp = v;
		tmp[i]^= tmp[i+1];
		ll tt = 0;
		if(tmp[i+1] != 0)tt = 1;
		tmp[i+1] = 0;
		for(int j = i-1;j>=0;j--){
			if(tmp[j+1] != 0){
				tt++;
				if(tmp[j] != 0)tmp[j]^= tmp[j+1];
			}
		}
		if(tmp[0] != 0)tt++;
		for(int j = i+2;j<n;j++){
			if(tmp[j-1] != 0){
				tt++;
				if(tmp[j] != 0)tmp[j]^= tmp[j-1];
			}
		}
		if(tmp[n-1] != 0)tt++;
		ll tt1 = tt;
		ans = min(ans,tt);
		
		
		tmp = v;
		tmp[i+1]^= tmp[i];
		tt = 0;
		if(tmp[i] != 0)tt= 1;
		tmp[i] = 0;
		for(int j = i-1;j>=0;j--){
			if(tmp[j+1] != 0){
				tt++;
				if(tmp[j] != 0)tmp[j]^= tmp[j+1];
			}
		}
		if(tmp[0] != 0)tt++;
		for(int j = i+2;j<n;j++){
			if(tmp[j-1] != 0){
				tt++;
				if(tmp[j] != 0)tmp[j]^= tmp[j-1];
			}
		}
		if(tmp[n-1] != 0)tt++;
		cout<<i<<' '<<tt1<<' '<<tt<<'\n';
		ans = min(ans,tt);
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

