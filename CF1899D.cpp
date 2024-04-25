#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


//a_i*(2^a_j) = a_j*(2^a_j)
//a_i/a_j = 2^(a_j-a_i)

void solve(){
	map<ll,ll> mp;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int tmp;
		cin>>tmp;
		mp[tmp]++;
	}
	ll ans = 0;
	for(auto &i:mp){
		ans += (i.sc-1)*i.sc/2;
		for(ll j = 1;j<32;j++){
			if(mp.find(i.fs+j) != mp.end()&&(i.fs+j)==i.fs*(1ll<<j))ans += i.sc*mp[i.fs+j];
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
