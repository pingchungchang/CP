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
	node* pl,*pr;
	int l,r;
	int val;
	node(){
		pl = pr = 0;
		l = r = val = 0;
	}
	node(int s,int e){
		l = s,r = e;
		val = 0;
		pl = pr = 0;
	}
};

void modify(node* now,int p,int v){
	if(now->l == now->r){
		now->val = v;
		return;
	}
	int mid = (now->l+now->r)/2;
	if(now->pl == 0){
		now->pl = new node(now->l,mid);
		now->pr = new node(mid+1,now->r);
	}
	if(mid>=p)modify(now->pl,p,v);
	else modify(now->pr,p,v);
	now->val = max(now->pl->val,now->pr->val);
}

int getval(node* now,int s,int v){
	if(now == 0)return -1;
	if(now->val<v||now->r<s)return -1;
	if(now->l == now->r)return now->l;
	int mid = (now->l+now->r)/2;
	if(now->l>=s){
		if(now->pl->val>=v)return getval(now->pl,s,v);
		else return getval(now->pr,s,v);
	}
	if(mid<s)return getval(now->pr,s,v);
	else if(mid>=s){
		if(getval(now->pl,s,v) != -1)return getval(now->pl,s,v);
		else return getval(now->pr,s,v);
	}
}
int main(){
	io
	int n,q;
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
			int p,v;
			cin>>p>>v;
			arr[p] = v;
			modify(segtree,p,v);
		}
		else{
			int v;
			cin>>v;
			cout<<getval(segtree,0,v)<<'\n';
		}
	}
}

