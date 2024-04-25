#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
ll n,m;
vector<ll> v;

vector<ll> segtree;
void addval(ll now,ll l,ll r,ll p,ll val){
	if(l == r){
		segtree[now] = val;
		return;
	}
	ll mid = (l+r)/2;
	if(mid>=p)addval(now*2+1,l,mid,p,val);
	else addval(now*2+2,mid+1,r,p,val);
	segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
}

ll getval(ll now,ll l,ll r,ll s,ll e){
	if(l>=s&&e>=r)return segtree[now];
	ll mid = (l+r)/2;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return max(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
}
void solve(){
	ll sx,sy,ex,ey,k;
	cin>>sx>>sy>>ex>>ey>>k;
	if(abs(ey-sy)%k != 0||abs(ex-sx)%k != 0){
		cout<<"NO\n";
		return;
	}
	sx += (n-sx)/k*k;
	if(sy>ey)swap(sy,ey);
	if(getval(0,0,m+1,sy,ey)>=sx||sx<ex){
		cout<<"NO\n";
		return;
	}
	else{
		cout<<"YES\n";
		return;
	}
}
int main(){
	io
	cin>>n>>m;
	segtree = vector<ll>((m+2)*4,0LL);
	v = vector<ll>(m+2,n);
	for(ll i = 1;i<=m;i++)cin>>v[i];
	for(ll i = 0;i<=m+1;i++){
		addval(0,0,m+1,i,v[i]);
	}
	int q;
	cin>>q;
	while(q--)solve();	
}

