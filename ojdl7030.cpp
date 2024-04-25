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

const int mxn = 5e5+10;
pll segtree[mxn*4];

void pull(int now){
	segtree[now].fs = max(segtree[ls].fs+segtree[ls].sc,segtree[rs].fs+segtree[rs].sc);
	return;
}
void modify(int now,int l,int r,int s,int e,ll v){
	if(l>=s&&e>=r){
		segtree[now].sc+=v;
		return;
	}
	if(mid>=s)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
	pull(now);
	return;
}

struct Q{
	ll t,tp,s,e,v;
	Q(){}
	bool operator<(Q b)const{
		return t ==b.t?tp<b.tp:t<b.t;
	}
};

vector<Q> req;
int n,q;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
}
