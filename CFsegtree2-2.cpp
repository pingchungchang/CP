#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double


struct node{
	node *pl,*pr;
	ll l,r,val;
	node(){
		pl = pr = 0;
		l = r = val = 0;
	}
	node(ll s,ll e){
		l = s,r = e;
		val = 0;
		pl = pr = 0;
	}
};

void modify(node* now,ll p,ll v){
	if(now->l == now->r){
		now->val = v;
		return;
	}
	ll mid = (now->l+now->r)/2;
	if(now->pl == 0){
		now->pl = new node(now->l,mid);
		now->pr = new node(mid+1,now->r);
	}
	if(mid>=p)modify(now->pl,p,v);
	else modify(now->pr,p,v);
	now->val = now->pl->val+now->pr->val;
	return;
}
ll getval(node* now,ll k){
	if(now == 0)return -1;
	if(now->l == now->r)return now->l;
	if(now->pl->val>=k)return getval(now->pl,k);
	else return getval(now->pr,k-now->pl->val);
}
int main(){
	io
	ll n,q;
	cin>>n>>q;
	int arr[n];
	node* segtree = new node(0,n-1);
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		arr[i] = k;
		modify(segtree,i,k);
	}
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			ll p;
			cin>>p;
			modify(segtree,p,1-arr[p]);
			arr[p] = 1-arr[p];
		}
		else{
			ll k;
			cin>>k;
			cout<<getval(segtree,k+1)<<'\n';
		}
	}
}

