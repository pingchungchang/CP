#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define ls segtree[now].pl
#define rs segtree[now].pr

const int inf = 1e9+10;
const int mxn = 2e5+10;
int n,arr[mxn],ldp[mxn],rdp[mxn];

struct node{
	int pl,pr,val;
	node(){
		pl = pr = val = 0;
	}
};

node segtree[mxn*32];
int ppp;

int newnode(){
	ppp++;
	segtree[ppp].pl = segtree[ppp].pr = segtree[ppp].val = 0;
	return ppp;
}

int setval(int now,int l,int r,int p,int v){
	if(!now)now = newnode();
	if(l == r){
		segtree[now].val = max(segtree[now].val,v);
		return now;
	}
	int mid = l+(r-l)/2;
	if(mid>=p)segtree[now].pl = setval(ls,l,mid,p,v);
	else segtree[now].pr = setval(rs,mid+1,r,p,v);
	segtree[now].val = max(segtree[ls].val,segtree[rs].val);
	return now;
}

int getval(int now,int l,int r,int s,int e){
	if(!now)return 0;
	if(l>=s&&e>=r)return segtree[now].val;
	int mid = l+(r-l)/2;
	if(mid>=e)return getval(ls,l,mid,s,e);
	else if(mid<s)return getval(rs,mid+1,r,s,e);
	else return max(getval(ls,l,mid,s,e),getval(rs,mid+1,r,s,e));
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	vector<pii> v;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		arr[i] -= i;
	}
	ppp = 0;
	int rt = newnode();
	for(int i = 1;i<=n;i++){
		ldp[i] = getval(rt,-inf,inf,-inf,arr[i])+1;
		rt = setval(rt,-inf,inf,arr[i],ldp[i]);
	}
	ppp = 0;
	rt = newnode();
	for(int i = n;i>=1;i--){
		rdp[i] = getval(rt,-inf,inf,arr[i],inf)+1;
		rt = setval(rt,-inf,inf,arr[i],rdp[i]);
	}

	/*
	for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';cout<<endl;
	for(int i = 1;i<=n;i++)cout<<ldp[i]<<' ';cout<<endl;
	for(int i = 1;i<=n;i++)cout<<rdp[i]<<' ';cout<<endl;
   */

	ppp = 0;
	rt = newnode();
	for(int i = 1;i<=n;i++){
		rdp[i] += getval(rt,-inf,inf,-inf,arr[i]+1);
		rt = setval(rt,-inf,inf,arr[i-1],ldp[i-1]);
	}
	cout<<max(0,n-*max_element(rdp+1,rdp+n+1)-1);
}
