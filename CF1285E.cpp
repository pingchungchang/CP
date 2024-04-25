#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2e5+10;
//const int inf = 10;
const int inf = 1e9+10;

struct node{
	int pl,pr,tag,val;
	int cl,cr,tl,tr;
	node(){
		tl = tr = 0;
		cl = cr = 0;
		pl = pr = 0;
		tag = val = 0;
	}
};
node segtree[mxn*100];
int ppp = 0;
int newnode(){
	ppp++;
	segtree[ppp].pl = segtree[ppp].pr = segtree[ppp].tag = segtree[ppp].val = 0;
	segtree[ppp].cl = segtree[ppp].cr = 0;
	segtree[ppp].tl = segtree[ppp].tr = 0;
	return ppp;
}

void modify(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		segtree[now].tag += v;
		if(l != s)segtree[now].tl+=v;
		if(r != e)segtree[now].tr+=v;
		assert(segtree[now].tag>=0);
		return;
	}
	int mid = l+(r-l)/2;
	if(mid>=s){
		if(!segtree[now].pl)segtree[now].pl = newnode();
		modify(segtree[now].pl,l,mid,s,e,v);
	}
	if(mid<e){
		if(!segtree[now].pr)segtree[now].pr = newnode();
		modify(segtree[now].pr,mid+1,r,s,e,v);
	}
	segtree[now].val = 0;
	int ls = segtree[now].pl,rs = segtree[now].pr;
	if(segtree[ls].tag)segtree[now].val ++;
	else segtree[now].val += segtree[ls].val;
	if(segtree[rs].tag)segtree[now].val ++;
	else segtree[now].val += segtree[rs].val;
	segtree[now].cl = segtree[now].cr = false;
	segtree[now].cl = segtree[ls].cl+segtree[ls].tl;
	segtree[now].cr = segtree[rs].cr+segtree[rs].tr;
	if((segtree[ls].cr+segtree[ls].tr)&&(segtree[rs].cl+segtree[rs].tl))segtree[now].val--;
	return;
}
void pv(int now,int l = -inf,int r = inf){
	if(!now)return;
	cout<<l<<' '<<r<<":"<<segtree[now].tag<<' '<<segtree[now].val<<' '<<segtree[now].cl<<' '<<segtree[now].cr<<endl;
	int mid = l+(r-l)/2;
	pv(segtree[now].pl,l,mid);
	pv(segtree[now].pr,mid+1,r);
}

void solve(){
	ppp = 0;
	int root = newnode();
	int n;
	cin>>n;
	pll arr[n];
	for(auto &i:arr){
		cin>>i.fs>>i.sc;
		modify(root,-inf,inf,i.fs,i.sc,1);
	}
	int ans = 0;
	//cout<<segtree[root].val<<'\n';return;
	for(auto &i:arr){
		modify(root,-inf,inf,i.fs,i.sc,-1);
		//pv(root);
		//cout<<endl;
		ans = max(ans,segtree[root].val);
		modify(root,-inf,inf,i.fs,i.sc,1);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
