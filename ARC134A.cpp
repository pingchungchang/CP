#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n,L,w;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>L>>w;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	ll now = 0;
	ll ans= 0;
	for(auto &i:arr){
		if(now<i){
			ans += (i-now+w-1)/w;
		}
		now = i+w;
	}
	// cout<<now<<endl;
	if(now<=L)ans += (L-now+w-1)/w;
	cout<<ans;
}