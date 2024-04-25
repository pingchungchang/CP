#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const ll mxn = 1e5+10;
ll n,m,l;
set<pii> st;
pll brr[mxn];
ll arr[mxn];

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>l;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=m;i++){
		cin>>brr[i].fs;
		brr[i].sc = i;
	}
	sort(brr+1,brr+m+1,greater<pll>());
	while(l--){
		int a,b;
		cin>>a>>b;
		st.insert(make_pair(a,b));
	}
	ll ans = -1;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(st.find(make_pair(i,brr[j].sc)) != st.end())continue;
			else{
				ans = max(ans,brr[j].fs+arr[i]);
				break;
			}
		}
	}
	assert(ans>=0);
	cout<<ans;
}
