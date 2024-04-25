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
	int l,r,val;
	node(){
		l = r = val = 0;
		pl = pr = 0;
	}
	node(int s,int e){
		pl = pr = 0;
		l = s,r = e,val = 0;
	}
};

void addval(node* now,int p,int v){
	if(now->l == now->r){
		now->val += v;
		return;
	}
	int mid = (now->l+now->r)/2;
	if(now->pl == 0){
		now->pl = new node(now->l,mid);
		now->pr = new node(mid+1,now->r);
	}
	if(mid>=p)addval(now->pl,p,v);
	else addval(now->pr,p,v);
	now->val = now->pl->val+now->pr->val;
	return;
}
int getval(node* now,int v){
	if(!now)return -1;
	if(now->l == now->r)return now->l;
	if(now->pl->val>=v)return getval(now->pl,v);
	else return getval(now->pr,v-now->pl->val);
}
int main(){
	int n;
	cin>>n;
	node* segtree = new node(1,n);
	for(int i = 1;i<=n;i++)addval(segtree,i,1);
	vector<int> v(n+1,0);
	for(int i = 1;i<=n;i++){
		cin>>v[i];
	}
	for(int i = n;i>0;i--){
		v[i] = getval(segtree,i-v[i]);
		addval(segtree,v[i],-1);
	}
	for(int i = 1;i<=n;i++)cout<<v[i]<<' ';
}

