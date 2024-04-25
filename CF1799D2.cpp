#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define mid ((l+r)>>1)

const ll mxn = 3e5+10;
constexpr ll inf = 1e18;
ll hot[mxn],cold[mxn],arr[mxn];
pll segtree[mxn*4];

void init(int now,int l,int r){
	if(l == r)segtree[now].fs = inf,segtree[now].sc = 0;
	else{
		init(now*2+1,l,mid);
		init(now*2+2,mid+1,r);
		segtree[now].fs = inf,segtree[now].sc = 0;
	}
	return;
}

void push(int now){
	segtree[now*2+1].sc += segtree[now].sc;
	segtree[now*2+2].sc += segtree[now].sc;
	segtree[now].sc = 0;
	segtree[now].fs = min(segtree[now*2+1].fs+segtree[now*2+1].sc,segtree[now*2+2].fs+segtree[now*2+2].sc);
	return;
}

void modify(int now,int l,int r,int p,ll v){
	if(l == r){
		segtree[now].fs = min(segtree[now].fs+segtree[now].sc,v);
		segtree[now].sc = 0;
		return;
	}
	push(now);
	if(mid>=p)modify(now*2+1,l,mid,p,v);
	else modify(now*2+2,mid+1,r,p,v);
	segtree[now].fs = min(segtree[now*2+1].fs+segtree[now*2+1].sc,segtree[now*2+2].fs+segtree[now*2+2].sc);
	return;
}
ll getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return segtree[now].fs+segtree[now].sc;
	push(now);
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return min(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
}

void solve(){
	ll n,k;
	cin>>n>>k;
	init(0,0,k);
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=k;i++)cin>>cold[i];
	for(int i = 1;i<=k;i++)cin>>hot[i];
	modify(0,0,k,0,cold[arr[1]]);
	for(int i = 2;i<=n;i++){
		ll small = getval(0,0,k,0,k);
		ll sp = getval(0,0,k,arr[i],arr[i]);
		if(arr[i] == arr[i-1])segtree[0].sc += hot[arr[i]];
		else segtree[0].sc += cold[arr[i]];
		modify(0,0,k,arr[i-1],small+cold[arr[i]]);
		modify(0,0,k,arr[i-1],sp+hot[arr[i]]);
	}
	cout<<getval(0,0,k,0,k)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
