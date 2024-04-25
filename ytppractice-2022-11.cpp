#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const ll inf = 1e12;
struct node{
	ll l,r,c;
	node(){}
};
int main(){
	io
	int n;
	cin>>n;
	pll arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i].fs;
	for(int i = 0;i<n;i++)cin>>arr[i].sc;
	ll dp[n];
	vector<node> v(n,node());
	for(auto &i:v)cin>>i.l>>i.r>>i.c;
	fill(dp,dp+n,inf);
	dp[0] = arr[0].sc;
	if(arr[0].fs<v[0].l||arr[0].fs>v[0].r)dp[0]+= v[0].c;
	else{
		arr[0].fs = v[0].l+v[0].r-arr[0].fs;
	}
	if(n>3000){
		map<ll,ll> mp;
		ll total = 0;
		for(auto &i:v){
			mp[i.l]+=i.c;
			total += i.c;
		}
		ll ans = total-mp[arr[0].fs]+arr[0].sc;
		if(arr[0].fs != v[0].l)dp[0] = v[0].c;
		else dp[0] = min(arr[0].sc,v[0].c);
		for(int i = 1;i<n;i++){
			ans = min(ans,total-mp[arr[i].fs]+arr[i].sc);
			if(arr[i].fs != v[i].l)dp[i] = dp[i-1]+v[i].c;
			else dp[i] = min(v[i].c,arr[i].sc)+dp[i-1];
			mp[v[i].l]-=v[i].c;
			total -= v[i].c;
		}
		cout<<ans;
		return 0;
	}
	for(int i = 1;i<n;i++){
		dp[i] = dp[i-1];
		if(arr[0].fs<v[i].l||arr[0].fs>v[i].r)dp[i] += v[i].c;
		else{
			arr[0].fs = v[i].l+v[i].r-arr[0].fs;
		}
	}
	for(int i = 1;i<n;i++){
		ll k = dp[i-1]+arr[i].sc;
		if(arr[i].fs<v[i].l||arr[i].fs>v[i].r)k += v[i].c;
		else arr[i].fs = v[i].r+v[i].l-arr[i].fs;
		dp[i] = min(dp[i],k);
		ll now = k;
		for(int j = i+1;j<n;j++){
			if(arr[i].fs<v[j].l||arr[i].fs>v[j].r)now += v[j].c;
			else arr[i].fs = v[j].r+v[j].l-arr[i].fs;
			dp[j] = min(dp[j],now);
		}
	}
	cout<<dp[n-1];
}

