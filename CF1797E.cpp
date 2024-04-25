#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
const int Mxn = 5e6+10;
const int mxn = 1e5+10;

int lpf[Mxn],phi[Mxn],dep[Mxn];

struct node{
	int anc,big,total;
	node(){}
};
node segtree[mxn*4];
int cnt = 0;
int arr[mxn];

int lca(int a,int b){
	if(a == 0)return b;
	if(b == 0)return a;
	while(a != b){
		if(dep[a]<dep[b])swap(a,b);
		a = phi[a];
	}
	return a;
}

void init(int now,int l,int r){
	if(l == r){
		segtree[now].anc = arr[l];
		segtree[now].big = dep[arr[l]];
		segtree[now].total = dep[arr[l]];
		return;
	}
	int mid = (l+r)>>1;
	init(now*2+1,l,mid);
	init(now*2+2,mid+1,r);
	segtree[now].big = max(segtree[now*2+1].big,segtree[now*2+2].big);
	segtree[now].anc = lca(segtree[now*2+1].anc,segtree[now*2+2].anc);
	segtree[now].total = segtree[now*2+1].total+segtree[now*2+2].total;
	return;
}

void modify(int now,int l,int r,int s,int e){
	if(l == r){
		segtree[now].anc = phi[segtree[now].anc];
		segtree[now].big = dep[segtree[now].anc];
		segtree[now].total = dep[segtree[now].anc];
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=s&&segtree[now*2+1].big > 1)modify(now*2+1,l,mid,s,e);
	if(mid<e&&segtree[now*2+2].big > 1)modify(now*2+2,mid+1,r,s,e);
	segtree[now].big = max(segtree[now*2+1].big,segtree[now*2+2].big);
	segtree[now].anc = lca(segtree[now*2+1].anc,segtree[now*2+2].anc);
	segtree[now].total = segtree[now*2+1].total+segtree[now*2+2].total;
	return;
}

pii getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return {segtree[now].anc,segtree[now].total};
	int mid = (l+r)>>1;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else{
		auto ta = getval(now*2+1,l,mid,s,e),tb = getval(now*2+2,mid+1,r,s,e);
		return {lca(ta.fs,tb.fs),ta.sc+tb.sc};
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 2;i<Mxn;i++){
		if(!lpf[i]){
			for(int j = i;j<Mxn;j+=i)lpf[j] = i;
		}
	}
	phi[1] = 1;
	dep[1] = 1;
	for(int i = 2;i<Mxn;i++){
		int pre = i/lpf[i];
		if(pre%lpf[i] == 0)phi[i] = phi[pre]*lpf[i];
		else phi[i] = phi[pre]*(lpf[i]-1);
	}
	for(int i = 2;i<Mxn;i++)dep[i] = dep[phi[i]]+1;
	for(int i = 2;i<Mxn;i++)assert(dep[i] != 1);

	int n,q;
	cin>>n>>q;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	init(0,0,n-1);
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int l,r;
			cin>>l>>r;
			l--,r--;
			modify(0,0,n-1,l,r);
		}
		else{
			int l,r;
			cin>>l>>r;
			l--,r--;
			auto tar = getval(0,0,n-1,l,r);
			cout<<tar.sc-dep[tar.fs]*(r-l+1)<<'\n';
		}
	}
	return 0;
}
