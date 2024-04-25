#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

struct node{
	int t;
	int tar;
	node(){
		t = tar = 0;
	}
};

inline bool in(int l,int r,int t){
	return l<=t&&r>=t;
}

void solve(){
	int n;
	cin>>n;
	node arr[n+1];
	for(int i = 0;i<n;i++)cin>>arr[i].t>>arr[i].tar;
	arr[n].t = 4e9;arr[n].tar = 2e9;
	pii now = {0LL,arr[0].tar};
	int ans = 0;
	for(int i = 1;i<=n;i++){
		//cout<<i<<":"<<now.fs<<' '<<now.sc<<'\n';
		pii range;
		range.fs = now.fs;
		if(now.fs>now.sc) range.sc = max(now.sc,now.fs-(arr[i].t-arr[i-1].t));
		else range.sc = min(now.sc,now.fs+(arr[i].t-arr[i-1].t));
		if(in(min(range.fs,range.sc),max(range.fs,range.sc),arr[i-1].tar))ans++;
		now.fs = range.sc;
		if(range.sc == now.sc)now.sc = arr[i].tar;
	}
	cout<<ans<<'\n';
	return;
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
