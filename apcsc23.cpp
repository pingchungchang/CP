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
struct node{
	node *pl,*pr;
	ll l,r;
	ll val;
	node(){}
	node(ll lll,ll rrr){
		pl = pr = 0;
		l = lll,r = rrr;
		val = 0;
	}
};
ll getval(node* now,ll s,ll e){
	if(!now)return 0LL;
	if(now->l>=s&&now->r<=e)return now->val;
	ll mid = (now->l+now->r)/2;
	if(e<=mid)return getval(now->pl,s,e);
	else if(mid<s)return getval(now->pr,s,e);
	else return getval(now->pl,s,e)+getval(now->pr,s,e);
}
void addval(node* now,ll p,ll v){
	if(now->l == now->r){
		now->val += v;
		return;
	}
	ll mid = (now->l+now->r)/2;
	if(!now->pl){
		now->pl = new node(now->l,mid);
		now->pr = new node(mid+1,now->r);
	}
	if(mid>=p)addval(now->pl,p,v);
	else addval(now->pr,p,v);
	now->val = now->pl->val+now->pr->val;
	return;
}
int main(){
	ll n,x;
	cin>>n>>x;
	ll arr[n+1];
	arr[0] = 0;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++)arr[i] += arr[i-1];
//	for(auto i:arr)cout<<i<<' ';cout<<endl;
	ll mxn = *max_element(arr,arr+n+1);
	mxn += 10;
	node* segtree = new node(0,mxn*2);
	ll ans = 0;
	for(int i = 0;i<=n;i++){
		ans += getval(segtree,arr[i]-x+mxn+1,mxn*2);
		addval(segtree,arr[i]+mxn,1LL);
//		cout<<ans<<endl;
	}
//	cout<<getval(segtree,mxn,mxn*2)<<endl<<endl;
	cout<<ans;
}

