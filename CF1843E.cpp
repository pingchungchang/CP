#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 1e5+10;
int arr[mxn];
int n,m,q;
pll req[mxn];
int change[mxn];

bool check(int k){
	fill(arr,arr+n+1,0);
	for(int i = 1;i<=k;i++)arr[change[i]] = 1;
	for(int i = 1;i<=n;i++)arr[i] += arr[i-1];
	for(int i = 1;i<=m;i++){
		int tmp = arr[req[i].sc]-arr[req[i].fs-1];
		if(tmp>req[i].sc-req[i].fs+1-tmp){
			return true;
		}
	}
	return false;
}

void solve(){
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		cin>>req[i].fs>>req[i].sc;
	}
	cin>>q;
	for(int i = 1;i<=q;i++){
		cin>>change[i];
	}
	int l = 1,r = q+1;
	while(l != r){
		int mid = (l+r)>>1;
		if(check(mid))r = mid;
		else l = mid+1;
	}
	if(r == q+1)cout<<"-1\n";
	else cout<<l<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
