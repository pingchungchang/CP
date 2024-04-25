#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
pii segtree[mxn*4];
int n;

int ask(int l,int r){
	cout<<"? "<<l<<' '<<r<<endl;
	int re;
	cin>>re;
	if(re == -1)exit(0);
	return r-l+1-re;
}

int getval(int now,int l,int r,int tar){
	//cout<<l<<' '<<r<<":"<<tar<<endl;
	if(l == r){
		segtree[now].fs = segtree[now].sc = 1;
		return l;
	}
	int mid = (l+r)>>1;
	int re;
	if(!segtree[now*2+1].fs)segtree[now*2+1].sc = ask(l,mid),segtree[now*2+1].fs = 1;
	if(segtree[now*2+1].sc>=tar)re =  getval(now*2+1,l,mid,tar);
	else re =  getval(now*2+2,mid+1,r,tar-segtree[now*2+1].sc);
	if(segtree[now].fs&&segtree[now*2+1].fs)
		segtree[now*2+2].fs = 1,segtree[now*2+2].sc = segtree[now].sc-segtree[now*2+1].sc;
	if(segtree[now*2+1].fs&&segtree[now*2+2].fs)
		segtree[now].fs = 1,segtree[now].sc = segtree[now*2+1].sc+segtree[now*2+2].sc;
	return re;
}

void modify(int now,int l,int r,int tar){
	if(segtree[now].fs){
		segtree[now].sc--;
	}
	if(l==r){
		segtree[now].sc = 0;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=tar)modify(now*2+1,l,mid,tar);
	else modify(now*2+2,mid+1,r,tar);
	return;
}

void solve(){
	int k;
	cin>>k;
	int tmp = getval(0,1,n,k);
	cout<<"! "<<tmp<<endl;
	modify(0,1,n,tmp);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	int t;cin>>t;
	while(t--)solve();
}
