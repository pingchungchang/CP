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
	int pl,pr;
	ll cnt,sum;
	node(){}
};
int ppp = 0;
const int mxn = 2e5+10;
const ll inf = 1e9+10;
node segtree[mxn*20];
pll arr[mxn];

int newnode(){
	ppp++;
	segtree[ppp].cnt = segtree[ppp].sum = segtree[ppp].pl = segtree[ppp].pr = 0;
	return ppp;
}

void modify(int now,int l,int r,int p,int c){
	if(l == r){
		segtree[now].cnt += c;
		segtree[now].sum += 1ll*l*c;
		return;
	}
	if(mid>=p){
		if(!segtree[now].pl)segtree[now].pl = newnode();
		modify(segtree[now].pl,l,mid,p,c);
	}
	else{
		if(!segtree[now].pr)segtree[now].pr = newnode();
		modify(segtree[now].pr,mid+1,r,p,c);
	}
	int ls = segtree[now].pl,rs = segtree[now].pr;
	segtree[now].sum = segtree[now].cnt = 0;
	if(ls)segtree[now].cnt += segtree[ls].cnt,segtree[now].sum += segtree[ls].sum;
	if(rs)segtree[now].cnt += segtree[rs].cnt,segtree[now].sum += segtree[rs].sum;
	return;
}

ll getval(int now,int l,int r,int tar){
	if(l == r){
		return 1ll*l*tar;
	}
	int ls = segtree[now].pl,rs = segtree[now].pr;
	if(rs&&segtree[rs].cnt>=tar)return getval(rs,mid+1,r,tar);
	else return getval(ls,l,mid,tar-segtree[rs].cnt)+segtree[rs].sum;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int r = newnode();
	for(int i = 1;i<=n;i++){
		cin>>arr[i].fs>>arr[i].sc;
		modify(r,0,inf,arr[i].fs,arr[i].sc);
	}
	int q;
	cin>>q;
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int p,v;
			cin>>p>>v;
			modify(r,0,inf,arr[p].fs,-arr[p].sc);
			arr[p].fs = v;
			modify(r,0,inf,arr[p].fs,arr[p].sc);
		}
		else if(t == 2){
			int p,v;
			cin>>p>>v;
			modify(r,0,inf,arr[p].fs,-arr[p].sc);
			arr[p].sc = v;
			modify(r,0,inf,arr[p].fs,arr[p].sc);
		}
		else{
			int c;
			cin>>c;
			if(segtree[r].cnt<c)cout<<"-1\n";
			else cout<<getval(r,0,inf,c)<<'\n';
		}
	}
	return 0;
}
