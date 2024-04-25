#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	map<ll,ll> used;
	ll n;
	cin>>n;
	vector<ll> v(n);
	for(ll i =0;i<n;i++)cin>>v[i];
	ll s =0;
	ll ans =0;
	for(ll i =0;i<n;i++){
		if(used.count(v[i]) ==0){
			used[v[i]] = i;
		}
		else{
			if(used[v[i]] <s){
				used[v[i]] = i;
			}
			else{
				ans = max(ans,i-s);
				s = used[v[i]]+1;
				used[v[i]] = i;
			}
		}
	}
	ans = max(ans,n-s);
	cout<<ans;
}
