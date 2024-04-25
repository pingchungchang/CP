#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
#pragma GCC optimize("O2")
const ll mxn = 2e4+10;
const ll inf = 2e8;
ll n,k;
ll arr[mxn];
ll segtree[mxn*4+4];
vector<int> all;
void modify(int now,int l,int r,int p){
	if(l == r){
		segtree[now]++;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=p)modify(now*2+1,l,mid,p);
	else modify(now*2+2,mid+1,r,p);
	segtree[now] = segtree[now*2+1]+segtree[now*2+2];
	return;
}
int getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return segtree[now];
	int mid = (l+r)>>1;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return getval(now*2+1,l,mid,s,e)+getval(now*2+2,mid+1,r,s,e);
}
int f(int x){
	memset(segtree,0,sizeof(segtree));
	modify(0,0,mxn,lower_bound(_all(all),0)-all.begin());
	int re = 0;
	for(int i = 1;i<=n;i++){
		int p = upper_bound(_all(all),arr[i]-x)-all.begin();
		if(p>0){
			re += getval(0,0,mxn,0,p-1);
		}
		modify(0,0,mxn,lower_bound(_all(all),arr[i])-all.begin());
	}
	return re;
}
void solve(){
	all.clear();
	arr[0] = 0;
	all.push_back(0);
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		arr[i]+=arr[i-1];
		all.push_back(arr[i]);
	}
	sort(_all(all));
	all.erase(unique(_all(all)),all.end());
	ll l = -inf,r = inf;
	while(l != r){
		ll mid = l+(r-l+1)/2;
		ll re = f(mid);
//		cout<<l<<' '<<r<<' '<<re<<'\n';
		if(re>=k)l = mid;
		else r = mid-1;
	}
	cout<<l<<'\n';
	return;
}
int main(){
	io
	while(cin>>n>>k){
		if(n == 0&&k == 0)return 0;
		solve();
	}
}

