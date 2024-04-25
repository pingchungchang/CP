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
	int n;
	cin>>n;
	int ans = -1;
	map<int,int> mp;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		if(mp[k] == 0){
			mp[k] = i;
			continue;
		}
		ans = max(ans,mp[k]+(n-i));
		mp[k] = i;
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

