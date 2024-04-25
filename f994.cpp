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
#define int ll
#pragma GCC optimize("O3")
const ll inf = 5e18;
const ll inf2 = 5e9+10;
const ll mxn = 1e6+10;
struct line{
	ll m,b;
	line(){
		m = 0,b = -inf;
	}
	line(ll mm,ll bb){
		m = mm,b = bb;
	}
	ll operator()(ll k){
		return k*m+b;
	}
};

struct node{
	ll l,r;
	node *pr,*pl;
	line val;
	node(){
		pl = pr = 0;
		val = line(0,-inf);
	}
	node(ll lll,ll rrr){
		l = lll,r = rrr;
		val = line(0,-inf);
		pl = pr = 0;
	}
};
void push(node* now){
	ll mid = now->l+(now->r-now->l)/2;
	now->pl = new node(now->l,mid);
	now->pr = new node(mid+1,now->r);
	return;
}
void addline(node* now,line x){
	if(now->l == now->r){
		if(now->val(now->l)>x(now->l)){
			now->val = x;
		}
		return;
	}
	ll mid = now->l+(now->r-now->l)/2;
	if(now->val(mid)<x(mid)){
		swap(now->val,x);
	}
	if(now->val.m == x.m)return;
	if(!now->pl)push(now);
	if(now->val.m > x.m){
		addline(now->pl,x);
	}
	else addline(now->pr,x);
	return;
}
ll getval(node* now,ll p){
	if(!now->pl)return now->val(p);
	ll mid = now->l+(now->r-now->l)/2;
	if(mid>=p)return max(now->val(p),getval(now->pl,p));
	else return max(now->val(p),getval(now->pr,p));
}
node* segtree = new node(-inf2,inf2);
ll pre1[mxn],pre2[mxn],a[mxn],b[mxn],dp[mxn];

main(){
	io
	ll n;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>a[i];
	for(int i = 1;i<=n;i++)cin>>b[i];
	for(ll i = 1;i<=n;i++){
		pre2[i] = pre2[i-1]+a[i];
		pre1[i] = i*a[i]+pre1[i-1];
	}
	addline(segtree,line(0,0));
	for(int i = 1;i<=n;i++){
		dp[i] = pre1[i]+getval(segtree,pre2[i]);
		line now(b[i]-i,-pre1[i]+dp[i]-b[i]*pre2[i]+i*pre2[i]);
		addline(segtree,now);
	}
	cout<<dp[n];
}
//a1x1 + b1 = a2x2+b2
//(b1-b2)/(a2-a1) = x
/*
5
a:-1 -2 -3 -4 -5
b: 1  2  3  4  5
*/
//dp[i] = max(pre1[i]-pre1[j]-j*(pre2[i]-pre2[j])+b[j]*(pre2[i]-pre2[j])+dp[j])
//dp[i] = max(pre1[i]-pre1[j]-j*pre2[i]+j*pre2[j]+b[j]*pre2[i]-b[j]*pre2[j]+dp[j]
//dp[i] = pre1[i] + max(-pre1[j]+j*pre2[j]-b[j]*pre2[j]+dp[j] + (b[j]-j)*pre2[i])

//l + (r-l)/2;
