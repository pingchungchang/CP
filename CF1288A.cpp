#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	ll n,d;
	cin>>n>>d;
	ll ans = d;
	for(ll i = 2;i<=d;i = d/(d/i)+1){
		ll tmp = i;
		ans = min(ans,tmp-1+(d+tmp-1)/tmp);
		tmp = i-1;
		ans = min(ans,tmp-1+(d+tmp-1)/tmp);
	}
	if(ans>n)cout<<"No\n";
	else cout<<"Yes\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
