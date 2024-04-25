#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	map<int,int> mp;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		mp[k]++;
	}
	int cnt[n+1] = {};
	for(auto &i:mp){
		for(int j = i.fs;j<=n;j+=i.fs)cnt[j] += i.sc;
	}
	cout<<*max_element(cnt,cnt+n+1)<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
