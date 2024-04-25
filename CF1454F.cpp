#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
int arr[mxn],suf[mxn];
int segtree[mxn*4];
int n;

void build(int now,int l,int r){
	if(l == r){
		segtree[now] = arr[l];
		return;
	}
	int mid = (l+r)>>1;
	build(now*2+1,l,mid);
	build(now*2+2,mid+1,r);
	segtree[now] = min(segtree[now*2+1],segtree[now*2+2]);
	return;
}
int getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r){
		return segtree[now];
	}
	int mid = (l+r)>>1;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return min(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
}


void solve(){
	for(int i = 0;i<=n;i++)arr[i] = suf[i] = 0;
	cin>>n;
	vector<int> all;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	int pref = 0;
	for(int i = n;i>=1;i--)suf[i] = max(suf[i+1],arr[i]);
	build(0,1,n);
	for(int i = 1;i<n-1;i++){
		pref = max(pref,arr[i]);
		int l = i+2,r = n;
		while(l != r){
			int mid = (l+r+1)>>1;
			if(suf[mid]>=pref)l = mid;
			else r = mid-1;
		}
		int t1 = l;
		r = l-1;l = i+1;
		while(l != r){
			int mid = (l+r+1)>>1;
			if(getval(0,1,n,i+1,mid) >= pref)l = mid;
			else r = mid-1;
		}
		//cout<<i<<":"<<l<<' '<<suf[l+1]<<' '<<getval(0,1,n,i+1,l)<<endl;
		if(pref != suf[l+1])continue;
		if(pref == suf[l+1] &&getval(0,1,n,i+1,l) == pref){
			cout<<"YES\n"<<i<<' '<<l-i<<' '<<n-l<<'\n';
			return;
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
