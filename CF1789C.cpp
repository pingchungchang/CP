#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n,m;
	cin>>n>>m;
	int arr[n];
	int cnt[n+m+10] = {},pre[n+m+10];
	memset(pre,-1,sizeof(pre));
	for(auto &i:arr)cin>>i,pre[i] = 0;
	long long ans = 0;
	int sum = 0;
	for(int i = 1;i<=m;i++){
		int p,v;
		cin>>p>>v;
		p--;
		if(arr[p] != v){
			assert(pre[arr[p]] != -1);
			cnt[arr[p]] += i-pre[arr[p]];
			pre[v] = i;
			pre[arr[p]] = -1;
			sum = sum-cnt[v]+cnt[arr[p]];
		}
		assert(sum>=0);
		arr[p] = v;
		ans += 1LL*n*i+sum;
	}
	cout<<ans<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
