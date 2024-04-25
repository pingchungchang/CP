#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll basis[61];
	memset(basis,0LL,sizeof(basis));
	ll l,r;
	cin>>l>>r;
	for(int i = 0;i<n;i++){
		ll tmp;
		cin>>tmp;
		for(int j = 60;j>=0;j--){
			if(tmp&(1LL<<j)){
				if(!basis[j]){
					basis[j] = tmp;
					break;
				}
				else tmp ^= basis[j];
			}
		}
	}
	vector<ll> v;
	for(int i = 0;i<=60;i++)if(basis[i])v.push_back(basis[i]);
	l--,r--;
	for(ll i = l;i<=r;i++){
		ll now = i;
		ll ans = 0;
		for(int j = v.size()-1;j>=0;j--){
			if(now&(1<<j))ans = max(ans,ans^v[j]);
			else ans = min(ans,ans^v[j]);
		}
		cout<<ans<<' ';
	}
	return 0;
}
