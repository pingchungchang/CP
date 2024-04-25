#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	map<int,ll> mp;
	int n,q;
	cin>>n;
	ll ans[n+1] = {};
	ll arr[n+1];
	memset(ans,0,sizeof(ans));
	for(int i = 1;i<=n;i++)cin>>arr[i];
	cin>>q;
	tlll req[q+1];
	int sm = 0;
	for(int i = 1;i<=q;i++){
		cin>>get<0>(req[i])>>get<1>(req[i])>>get<2>(req[i]);
		mp[get<0>(req[i])] += get<2>(req[i]);
		mp[get<1>(req[i])+1] -= get<2>(req[i]);
		while(!mp.empty()&&mp.begin()->sc==0)mp.erase(mp.begin());
		if(!mp.empty()&&mp.begin()->sc<0){
			sm = i;
			mp.clear();
		}
	}
	for(int i = 1;i<=sm;i++){
		ans[get<0>(req[i])] += get<2>(req[i]);
		ans[get<1>(req[i])+1] -= get<2>(req[i]);
	}
	for(int i = 1;i<=n;i++)ans[i] += ans[i-1];
	for(int i = 1;i<=n;i++)cout<<arr[i]+ans[i]<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
