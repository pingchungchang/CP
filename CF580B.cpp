#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct node{
	node* pl;
	node* pr;
	ll val;
	ll l;
	ll r;
	node(){
		pl = nullptr;
		pr = nullptr;
		val = 0;
	}
	node(ll a,ll b){
		l = a;
		r = b;
		pl = nullptr;
		pr = nullptr;
		val = 0;
	}
};

void maketree(node* now,ll pos,ll val){
	if(now->l == now->r){
		now->val += val;
		return;
	}
	ll mid = (now->l+now->r)/2;
	if(now->pl == nullptr)now->pl = new node(now->l,mid);
	if(now->pr == nullptr)now->pr = new node(mid+1,now->r);
	if(mid>=pos){
		maketree(now->pl,pos,val);
	}
	else{
		maketree(now->pr,pos,val);
	}
	now->val = now->pr->val+now->pl->val;
	return;
}
ll getval(node* now,ll s,ll e){
//	cout<<now->l<<' '<<now->r<<' '<<s<<' '<<e<<endl;
	if(now->val == 0)return 0;
	if(s == now->l&&e == now->r)return now->val;
	ll mid = (now->l+now->r)/2;
	if(mid>=e)return getval(now->pl,s,e);
	else if(mid+1<=s)return getval(now->pr,s,e);
	else{
		return getval(now->pl,s,mid)+getval(now->pr,mid+1,e);
	}
}
int main(){
	node* segtree = new node(0LL,(ll)2*1e9+2);
	ll n,d;
	cin>>n>>d;
	pll v[n];
	for(ll i = 0;i<n;i++){
		cin>>v[i].fs>>v[i].sc;
		maketree(segtree,v[i].fs,v[i].sc);
	}
	ll ans = 0;
//	cout<<getval(segtree,0,0);
	for(auto i:v){
		ans = max(ans,getval(segtree,i.fs,i.fs+d-1));
//		cout<<getval(segtree,i.fs,i.fs+d-1)<<endl;
	}
	cout<<ans;
}

