#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define mid ((l+r)>>1)
#define ls now*2+1
#define rs now*2+2


const int sh = 2e5+10;
const int mxn = sh*2;
vector<pair<int,pii>> op,rop;
pii arr[mxn];
int n;
int L,W;

pii segtree[mxn*4];

void modify(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		segtree[now].sc += v;
		return;
	}
	if(mid>=s)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
	segtree[now].fs = max(segtree[ls].fs+segtree[ls].sc,segtree[rs].fs+segtree[rs].sc);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>L>>W;
	for(int i = 0;i<n;i++){
		cin>>arr[i].fs>>arr[i].sc;
		arr[i].fs += sh;arr[i].sc += sh;
		op.push_back(make_pair(arr[i].fs-L+1,make_pair(arr[i].sc-W+1,arr[i].sc)));
		rop.push_back(make_pair(arr[i].fs+1,make_pair(arr[i].sc-W+1,arr[i].sc)));
	}
	sort(op.rbegin(),op.rend());
	sort(rop.rbegin(),rop.rend());
	int ans = 0;
	for(int i = 0;i<mxn;i++){
		while(!op.empty()&&op.back().fs == i){
			auto tmp = op.back().sc;
			op.pop_back();
			modify(0,0,mxn,tmp.fs,tmp.sc,1);
		}
		while(!rop.empty()&&rop.back().fs == i){
			auto tmp = rop.back().sc;
			rop.pop_back();
			modify(0,0,mxn,tmp.fs,tmp.sc,-1);
		}
		if(segtree[0].fs+segtree[0].sc)ans = max(ans,segtree[0].fs+segtree[0].sc);
		//cout<<i<<":"<<segtree[0].fs+segtree[0].sc<<endl;
	}
	cout<<ans;
}
