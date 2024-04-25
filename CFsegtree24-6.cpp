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
	ll sum,tag,mx,l,r;
	node(ll a,ll b){
		l = a,r = b;
		pl = pr = 0;
		sum = mx = 0;
		tag = INT_MAX;
	}
};

void push(node* now){
	ll mid = (now->l+now->r)/2;
	if(!now->pl){
		now->pl = new node(now->l,mid);
		now->pr = new node(mid+1,now->r);
	}
	if(now->tag == INT_MAX)return;
	now->pl->tag = now->pr->tag = now->tag;
	now->tag = INT_MAX;
	now->pl->sum = (now->pl->r-now->pl->l+1)*now->pl->tag;
	now->pr->sum = (now->pr->r-now->pr->l+1)*now->pr->tag;
	now->pl->mx = max(0LL,now->pl->sum);
	now->pr->mx = max(0LL,now->pr->sum);
	now->sum = now->pl->sum+now->pr->sum;
	now->mx = max(now->pl->mx,now->pr->mx+now->pl->sum);
}
void modify(node* now,ll s,ll e,ll val){
//	cout<<now->l<<' '<<now->r<<endl;
	if(now->l>=s&&now->r<=e){
		now->tag = val;
		now->sum = val*(now->r-now->l+1);
		now->mx = max(0LL,val*(now->r-now->l+1));
		return;
	}
	ll mid = (now->l+now->r)/2;
	if(!now->pl){
		now->pl = new node(now->l,mid);
		now->pr = new node(mid+1,now->r);
	}
	push(now);
	if(s<=mid)modify(now->pl,s,e,val);
	if(mid<e)modify(now->pr,s,e,val);
	now->sum = now->pl->sum+now->pr->sum;
	now->mx = max(now->pl->mx,now->pr->mx+now->pl->sum);
	return;
}
ll getval(node* now,ll val){
//	cout<<now->l<<' '<<now->r<<' '<<val<<endl;
	if(now->l== now->r){
		return (now->mx>val?now->l-1:now->l);
	}
	push(now);
	if(now->pl->mx>val)return getval(now->pl,val);
	else return getval(now->pr,val-now->pl->sum);
}
int main(){
	io
	ll n;
	cin>>n;
	node* segtree = new node(1,n);
	char t;
	while(cin>>t){
//		cout<<t<<endl;
		if(t == 'E')return 0;
		else if(t == 'Q'){
			ll v;
			cin>>v;
			cout<<getval(segtree,v)<<'\n';
		}
		else{
			ll s,e,d;
			cin>>s>>e>>d;
			modify(segtree,s,e,d);
		}
	}
}

