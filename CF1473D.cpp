#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

vector<pll> segtree;
vector<ll> pref;
void maketree(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now] = {v,v};
		return;
	}
	int mid = (l+r)/2;
	if(mid>=p)maketree(now*2+1,l,mid,p,v);
	else maketree(now*2+2,mid+1,r,p,v);
	segtree[now].fs = max(segtree[now*2+1].fs,segtree[now*2+2].fs);
	segtree[now].sc = min(segtree[now*2+1].sc,segtree[now*2+2].sc);
}
pll getval(int now,int l,int r,int s,int e){
//	cout<<l<<' '<<r<<' '<<s<<' '<<e<<endl;
	if(l>=s&&e>=r)return segtree[now];
	int mid = (l+r)/2;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	pll a = getval(now*2+1,l,mid,s,e),b = getval(now*2+2,mid+1,r,s,e);
	return {max(a.fs,b.fs),min(a.sc,b.sc)};
}
void solve(){
	ll n,q;
	cin>>n>>q;
	pref = vector<ll>(n+1,0);
	segtree = vector<pll>((n+2)*4,make_pair(0,0));
	string s;
	cin>>s;
	for(int i = 1;i<=n;i++){
		if(s[i-1] == '+'){
			pref[i] = 1;
		}
		else pref[i] = -1;
		pref[i] += pref[i-1];
		maketree(0,0,n+1,i,pref[i]);
	}
//	cout<<getval(0,0,n+1,0,1).fs<<' '<<getval(0,0,n+1,n+1,n+1).sc<<'\n';
	maketree(0,0,n+1,n+1,pref.back());
	maketree(0,0,n+1,0,0);
	while(q--){
		int s,e;
		cin>>s>>e;
		pll lef = getval(0,0,n+1,0,s-1),rig = getval(0,0,n+1,e+1,n+1);
//		cout<<s<<e<<endl;
		ll shift = pref[e]-pref[s-1];
		ll sm =min(lef.sc,rig.sc-shift),big = max(lef.fs,rig.fs-shift);
//		cout<<sm<<' '<<big<<' '<<shift<<' '<<;
		cout<<big-sm+1<<'\n';
	}
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

