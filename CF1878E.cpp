#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define mid ((int)(l+r)>>1)

const int mxn = 2e5+10;
int segtree[mxn*4];
int arr[mxn];

void build(int now,int l,int r){
	if(l == r){
		segtree[now] = arr[l];
		return;
	}
	build(now*2+1,l,mid);
	build(now*2+2,mid+1,r);
	segtree[now] = segtree[now*2+1]&segtree[now*2+2];
	return;
}

int getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r){
		return segtree[now];
	}
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return getval(now*2+1,l,mid,s,e)&getval(now*2+2,mid+1,r,s,e);
}

void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	build(0,1,n);
	int q;
	cin>>q;
	while(q--){
		int l,k;
		cin>>l>>k;
		if(arr[l]<k){
			cout<<"-1 ";
		}
		else{
			int s = l,e = n;
			while(s != e){
				int m = (s+e+1)>>1;
				if(getval(0,1,n,l,m)>=k)s = m;
				else e = m-1;
			}
			cout<<s<<' ';
		}
	}
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
