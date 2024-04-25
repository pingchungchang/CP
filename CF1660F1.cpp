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
	ll l,r;
	ll val;
	node(){
		pl = pr = 0;
		l = r = 0;
		val = 0;
	}
	node(ll s,ll e){
		l = s;
		r = e;
		val = 0;
		pl = pr = 0;
	}
};
void del(node* now){
	if(now == 0)return;
	del(now->pl);
	del(now->pr);
	free(now);
	return;
}
const ll mxn = 3e5;
void addval(node* now,ll p,ll v){
//	cout<<now->l<<' '<<now->r<<' '<<p<<endl;
	if(now->l == now->r){
		now->val += v;
		return;
	}
	ll mid = (now->l+now->r)/2;
	if(now->pl == 0){
		now->pl = new node(now->l,mid);
		now->pr = new node(mid+1,now->r);
	}
	if(mid>=p)addval(now->pl,p,v);
	else addval(now->pr,p,v);
	now->val = now->pl->val+now->pr->val;
}
ll getval(node* now,ll s,ll e){
	if(now == nullptr)return 0;
//	cout<<now->l<<' '<<now->r<<' '<<s<<' '<<e<<'\n';
	if(s<=now->l&&e>=now->r)return now->val;
	ll mid = (now->l+now->r)/2;
	if(mid>=e)return getval(now->pl,s,e);
	else if(mid<s)return getval(now->pr,s,e);
	else return getval(now->pl,s,e)+getval(now->pr,s,e);
}
node* segtree;
void solve(){
	del(segtree);
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<vector<ll>> mods(3);
	ll total = 0;
	mods[0].push_back(0);
	for(ll i = 0;i<n;i++){
		if(s[i] == '-')total --;
		else total++;
//		cout<<total<<' ';
		mods[(total+(ll)3e5)%3].push_back(total);
	}
//	cout<<'\n';
	segtree = new node(0,mxn*2);
	ll ans = 0;
	for(auto &i:mods){
//		cout<<endl;
//		cout<<i[0]<<"\n";
		for(auto &j:i){
			ans += getval(segtree,j+mxn,mxn*2);
			addval(segtree,j+mxn,1LL);
//			cout<<j<<',';
		}
		del(segtree);
		segtree = new node(0,mxn*2);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

