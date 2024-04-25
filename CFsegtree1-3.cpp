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
	ll l,r,val,tag;
	node(){
		pl = pr = 0;
		val = tag = 0;
	}
	node(ll s,ll e){
		pl = pr = 0;
		val = INT_MAX;
		tag = 0;
		l = s,r = e;
	}
};
void modify(node* now,ll p,ll v){
	if(now->l == now->r){
		now->val = v;
		now->tag = 1;
		return;
	}
	ll mid = (now->l+now->r)/2;
	if(now->pl == 0){
		now->pl = new node(now->l,mid);
		now->pr = new node(mid+1,now->r);
	}
	if(mid>=p){
		modify(now->pl,p,v);
	}
	else modify(now->pr,p,v);
	if(now->pl->val != now->pr->val){
		if(now->pl->val>now->pr->val){
			now->val = now->pr->val;
			now->tag = now->pr->tag;
		}
		else{
			now->val = now->pl->val;
			now->tag = now->pl->tag;
		}
	}
	else{
		now->val = now->pl->val;
		now->tag = now->pl->tag+now->pr->tag;
	}
	return;
}
pll getval(node* now,ll s,ll e){
	if(now->l>=s&&now->r<=e){
		return make_pair(now->val,now->tag);
	}
	ll mid = (now->l+now->r)/2;
	if(mid>=e)return getval(now->pl,s,e);
	else if(mid<s)return getval(now->pr,s,e);
	else{
		auto p1 = getval(now->pl,s,e);
		auto p2 = getval(now->pr,s,e);
		if(p1.fs==p2.fs){
			p1.sc += p2.sc;
			return p1;
		}
		else return min(p1,p2);
	}
}
int main(){
	io
	int n,m;
	cin>>n>>m;
	node* segtree = new node(0,n-1);
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		modify(segtree,i,k);
	}
	while(m--){
		int t;
		cin>>t;
		if(t == 1){
			ll p,v;
			cin>>p>>v;
			modify(segtree,p,v);
		}
		else{
			ll s,e;
			cin>>s>>e;
			auto re = getval(segtree,s,e-1);
			cout<<re.fs<<' '<<re.sc<<'\n';
		}
	}
}

