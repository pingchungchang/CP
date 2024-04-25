#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e6+10;
int n;
pii segtree[mxn*5/2];
int arr[mxn];
int fa[mxn];

void make(int now,int l,int r){
	if(l == r){
		segtree[now] = {arr[l],l};
		return;
	}
	int mid = (l+r)>>1;
	make(now*2+1,l,mid);
	make(now*2+2,mid+1,r);
	segtree[now] = min(segtree[now*2+1],segtree[now*2+2]);
}

pii get(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r){
		return segtree[now];
	}
	int mid = (l+r)>>1;
	if(mid>=e)return get(now*2+1,l,mid,s,e);
	else if(mid<s)return get(now*2+2,mid+1,r,s,e);
	else return min(get(now*2+1,l,mid,s,e),get(now*2+2,mid+1,r,s,e));
}

void build(int l,int r,int par){
	auto re = get(0,1,n,l,r);
	fa[re.sc] = par;
	if(re.sc != l)build(l,re.sc-1,re.sc);
	if(re.sc != r)build(re.sc+1,r,re.sc);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		arr[k] = i;
	}
	make(0,1,n);
	build(1,n,0);
	for(int i = 1;i<=n;i++)cout<<fa[i]<<'\n';
}
