#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define mid ((l+r)>>1)


struct node{
	int sum = 0;
	int pl,pr;
	node(){}
};

const int mxn = 3e5+10;
int n,q;
int ppp = 0;
int roots[mxn];
node segtree[mxn*30];
int newnode(){
	ppp++;
	return ppp;
}

int modify(int now,int l,int r,int p,int v){
	int tmp = newnode();
	segtree[tmp] = segtree[now];
	if(l == r){
		segtree[tmp].sum+=v;
		return tmp;
	}
	if(mid>=p)segtree[tmp].pl = modify(segtree[tmp].pl,l,mid,p,v);
	else segtree[tmp].pr = modify(segtree[tmp].pr,mid+1,r,p,v);
	segtree[tmp].sum = segtree[segtree[tmp].pl].sum+segtree[segtree[tmp].pr].sum;
	return tmp;
}

int getval(int lp,int rp,int l,int r,int tar){
	//cout<<l<<' '<<r<<' '<<tar<<":"<<segtree[rp].sum-segtree[lp].sum<<'\n';
	if(segtree[rp].sum-segtree[lp].sum<tar)return -1;
	if(l == r)return (segtree[rp].sum-segtree[lp].sum>=tar?l:-1);
	int re = -1;
	if(segtree[segtree[rp].pl].sum-segtree[segtree[lp].pl].sum>=tar)
		re = getval(segtree[lp].pl,segtree[rp].pl,l,mid,tar);
	if(re != -1)return re;
	if(segtree[segtree[rp].pr].sum-segtree[segtree[lp].pr].sum>=tar)
		re = getval(segtree[lp].pr,segtree[rp].pr,mid+1,r,tar);
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	roots[0] = newnode();
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		roots[i] = modify(roots[i-1],0,mxn,k,1);
		//cout<<segtree[roots[i]].sum<<' ';
	}
	//cout<<endl;
	while(q--){
		int l,r,k;
		cin>>l>>r>>k;
		cout<<getval(roots[l-1],roots[r],0,mxn,(r-l+1)/k+1)<<'\n';
	}
	return 0;
}
