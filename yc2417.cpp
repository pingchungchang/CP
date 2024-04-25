#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,k;
	cin>>n>>k;
	n -= k;
	int ans = 0;
	for(ll i = 1;i*i<=n;i++){
		if(n%i == 0){
			ll tmp = i;
			if(tmp>k)ans++;
			tmp = n/i;
			if(i*i == n||tmp<=k)continue;
			ans++;
		}
	}
	cout<<ans;
}
