#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

ll sum = 0;
map<ll,ll> pre,suf;

ll add(ll k){
	sum -= pre[k]*suf[k];
	suf[k]--;
	pre[k]++;
	sum += pre[k]*suf[k];
	return 0;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll arr[n];
	for(auto &i:arr){
		cin>>i;
		suf[i]++;
	}
	ll ans = 0;
	for(auto &i:arr){
		add(i);
		ans += sum-(pre[i]*suf[i]);
	}
	cout<<ans;
}
