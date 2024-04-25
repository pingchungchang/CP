#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const int mxn = 1e6+10;
int main(){
	io
	ll n,m;
	cin>>n>>m;
	vector<ll> v(n);
	for(auto &i:v)cin>>i;
	ll ans = 0;
	ll r = 0;
	vector<int> cnt(mxn,0);
	for(ll i = 0;i<n;i++){
		while(r < n&&cnt[v[r]] == 0){
			cnt[v[r]]++;
			r++;
		}
		if(r-i>=m)ans++;
		cnt[v[i]]--;
	}
	cout<<ans;
}

