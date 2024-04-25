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
	vector<ll> ans(n,-1);
	ll now = n-1;
	ll lim = n;
	bool flag = true;
	while(flag){
		flag = false;
		for(ll i = 0;i<lim;i++){
			ll tmp = sqrt(now+i);
			if(tmp*tmp == now+i){
				ans[i] = now;
				now = i-1;
				lim = i;
				flag = true;
				break;
			}
		}
	}
	for(ll i = 1;i<n;i++){
		if(ans[i] == -1)ans[i] = ans[i-1]-1;
	}
	for(auto &i:ans){
		if(i == -1){
			cout<<"-1\n";
			return;
		}
	}
	for(auto i:ans)cout<<i<<' ';
	cout<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

