#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e6+10;
int segtree[mxn*4];
int arr[mxn];
int ppp = 1;
int n;
ll ans = 0;
queue<pii> q;

void build(int now,int l,int r){
	if(l == r){
		segtree[now] = l;
		return;
	}
	int mid = (l+r)>>1;
	build(now*2+1,l,mid);
	build(now*2+2,mid+1,r);
	if(arr[segtree[now*2+1]]>arr[segtree[now*2+2]])segtree[now] = segtree[now*2+1];
	else segtree[now] = segtree[now*2+2];
}

int getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r){
		return segtree[now];
	}
	int mid = (l+r)>>1;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else{
		int a = getval(now*2+1,l,mid,s,e);
		int b = getval(now*2+2,mid+1,r,s,e);
		if(arr[a]>arr[b])return a;
		else return b;
	}
}

void maketree(int l,int r){
	if(l == r)return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	build(0,0,n-1);
	q.push({0,n-1});
	while(!q.empty()){
		int l = q.front().fs,r = q.front().sc;
		q.pop();
		int p = getval(0,0,n-1,l,r);
		if(p != l){
			ans+=arr[p];
			q.push({l,p-1});
		}
		if(p != r){
			ans += arr[p];
			q.push({p+1,r});
		}
	}
	cout<<ans;
}
