#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll arr[3];
	for(auto &i:arr)cin>>i;
	int dir[] = {-1,0,1};
	ll ans = abs(arr[0]-arr[1])+abs(arr[1]-arr[2])+abs(arr[2]-arr[0]);
	for(auto dx:dir){
		for(auto dy:dir){
			for(auto dz:dir){
				ll tmp[] = {arr[0]+dx,arr[1]+dy,arr[2]+dz};
				ans = min(ans,abs(tmp[0]-tmp[1])+abs(tmp[1]-tmp[2])+abs(tmp[2]-tmp[0]));
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
