#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mod = 998244353;

const ll mxn = 1e5+10;
int dsu[mxn],sz[mxn],cnt[mxn],dp[mxn];

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	dsu[b] = a;
	sz[a] += sz[b];
	cnt[a] += cnt[b];
	dp[a] += dp[b];
	return;
}

void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)dsu[i] = i,sz[i] = 1,dp[i] = 0,cnt[i] = 0;
	pll arr[n];
	for(auto &i:arr)cin>>i.fs;
	for(auto &i:arr)cin>>i.sc;
	ll ans = 1;
	set<ll> st;
	for(auto &i:arr){
		st.insert(i.fs);
		st.insert(i.sc);
		onion(i.fs,i.sc);
		cnt[root(i.fs)]++;
		if(i.fs == i.sc)dp[root(i.fs)] = true;
	}
	if(st.size() != n){
		cout<<"0\n";
		return;
	}
	for(int i = 1;i<=n;i++){
		if(dsu[i] == i){
			if(cnt[i] != sz[i]){
				cout<<"0\n";
				return;
			}
			if(dp[i])ans = ans*n%mod;
			else ans = ans*2%mod;
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
/*
1 2
1 2
1 2
3 4
5 1


1 1
1 2
1 3
1 4
*/
