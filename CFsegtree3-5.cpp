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
	ll val,tag,l,r;
	node *pl,*pr;
	node(ll s,ll e){
		l = s,r = e;
		pl = pr = 0;
		val = tag = 0;
	}
};

void addval(node* now,ll s,ll e,ll v){
	if(now->l>=s&&now->r<=e){
		now->tag += v;
		return;
	}
	ll mid = (now->l+now->r)/2;
	if(now->pl == 0){
		now->pl = new node(now->l,mid);
		now->pr = new node(mid+1,now->r);
	}
	if(mid>=e)addval(now->pl,s,e,v);
	else if(mid<s)addval(now->pr,s,e,v);
	else{
		addval(now->pl,s,e,v);
		addval(now->pr,s,e,v);
	}
	now->val = now->pl->tag*(now->pl->r-now->pl->l+1)+now->pl->val+now->pr->tag*(now->pr->r-now->pr->l+1)+now->pr->val;
	return;
}
void push(node* now){
	now->pl->tag +=now->tag;
	now->pr->tag += now->tag;
	now->tag = 0;
	now->val = now->pl->tag*(now->pl->r-now->pl->l+1)+now->pl->val+now->pr->tag*(now->pr->r-now->pr->l+1)+now->pr->val;	
}
ll getval(node* now,ll p){
	if(!now)return 0;
	if(now->l == now->r){
		return now->val+now->tag;
	}
	ll mid = (now->l+now->r)/2;
	push(now);
	if(mid>=p)return getval(now->pl,p);
	else return getval(now->pr,p);
	
}
int main(){
	io
	int n,q;
	cin>>n>>q;
	node* segtree = new node(0,n-1);
	for(int i = 0;i<n;i++){
		addval(segtree,i,i,0);
	}
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			ll s,e,v;
			cin>>s>>e>>v;
			addval(segtree,s,e-1,v);
		}
		else{
			ll p;
			cin>>p;
			cout<<getval(segtree,p)<<'\n';
		}
	}
}

