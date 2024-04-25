#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	while(k&&*min_element(arr,arr+n) != 0){
		ll d = *max_element(arr,arr+n);
		k--;
		for(auto &i:arr)i = d-i;
		if(*min_element(arr,arr+n)<=0&&*max_element(arr,arr+n)>=0)break;
	}
	if(k<=0){
		for(auto &i:arr)cout<<i<<' ';
		cout<<'\n';
		return;
	}
	ll p = *max_element(arr,arr+n),neg = *min_element(arr,arr+n);
	if(k&1){
		for(auto &i:arr)i = p-i;
	}
	for(auto &i:arr)cout<<i<<' ';cout<<'\n';
	return;
	/*
	   p,0 -> 0,p -> p,0 -> 0,p
	   i ->p-i -> i
   */
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
