#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tiii tuple<int,int,int>

const int mxn = 8e5+10;
pii segtree[mxn*4];
pii arr[mxn];
int n;

void modify(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		segtree[now].sc+=v;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=s)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
	segtree[now].fs = max(segtree[now*2+1].fs+segtree[now*2+1].sc,segtree[now*2+2].fs+segtree[now*2+2].sc);
	return;
}

int getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r){
		return segtree[now].fs+segtree[now].sc;
	}
	int mid = (l+r)>>1;
	if(mid>=e)return getval(now*2+1,l,mid,s,e)+segtree[now].sc;
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e)+segtree[now].sc;
	else return max(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e))+segtree[now].sc;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i].fs>>arr[i].sc;
		arr[i].fs++,arr[i].sc++;
		modify(0,0,n,arr[i].fs,arr[i].sc,1);
		int t1 = getval(0,0,n,arr[i].fs,arr[i].fs),t2 = getval(0,0,n,0,arr[i].fs-1);
		if(t2+1>t1){
			modify(0,0,n,arr[i].fs,arr[i].fs,t2+1-t1);
		}
	}
	cout<<getval(0,0,n,0,n);
}
