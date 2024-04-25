#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

map<int,int> mp;

 main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		if(mp.find(k) != mp.end()){
			ans = max(ans,n-i+mp[k]);
		}
		mp[k] = i;
	}
	cout<<ans;
}
