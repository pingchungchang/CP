#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	ll n,k;
	cin>>n>>k;
	vector<ll> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	vector<vector<ll>> ans;
	for(ll i = 0;i<(1<<n);i++){
		vector<ll> tmp;
		for(int j =0;j<n;j++){
			if(i&(1<<j)){
				tmp.push_back(v[j]);
			}
		}
		if(tmp.size() == k)ans.push_back(tmp);
	}
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	for(auto i:ans){
		for(auto j:i)cout<<j<<' ';
		cout<<'\n';
	}
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

