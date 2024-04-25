#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 1e7+10;
int lpf[mxn];

void solve(){
	int n;
	cin>>n;
	map<int,int> mp;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		while(lpf[k] != 1){
			mp[lpf[k]]++;
			k /= lpf[k];
		}
	}
	int ans = 0;
	for(auto &i:mp){
		ans += i.sc/2;
		i.sc &= 1;
	}
	ll cnt = 0;
	for(auto &i:mp)cnt += i.sc;
	cout<<ans+cnt/3<<'\n';
}
int main(){
	for(int i = 2;i<mxn;i++){
		if(!lpf[i]){
			for(int j = i;j<mxn;j+=i){
				lpf[j] = i;
			}
		}
	}
	lpf[1] = 1;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
