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
	ll t;
	ll id;
	ll s,e;
	ll val;
	node(){
		t = id = s = e = val = 0LL;
	}
	node(ll a,ll b,ll c,ll d,ll ed){
		t = a,s = b,e = c,val = d,id = ed;
	}
};
bool cmp(node a,node b){
	if(a.val != b.val){
		return a.val<b.val;
	}
	else{
		return a.t<b.t;
	}
}
const ll mxn = 2e5+10;
ll bit[mxn];
void modify(ll p,ll val){
	for(;p<mxn;p+= p&-p){
		bit[p]+= val;
	}
}
ll getval(ll s,ll e){
	ll re = 0;
	for(;e>0;e -= e&-e){
		re += bit[e];
	}
	s--;
	for(;s>0;s -= s&-s)re -= bit[s];
	return re;
}
int main(){
	io
	ll n,q;
	cin>>n>>q;
	vector<ll> ans(q,-1);
	vector<node> req;
	for(ll i = 1;i<=n;i++){
		ll k;
		cin>>k;
		req.push_back(node(0,i,i,k,i));
	}
	for(ll i = 0;i<q;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		req.push_back(node(1,a,b,c,i));
	}
//	for(auto &i:req)cout<<i.s<<' '<<i.e<<' '<<i.val<<' '<<i.id<<endl;
	sort(req.begin(),req.end(),cmp);
	for(auto &i:req){
//		cout<<i.t<<' '<<i.s<<' '<<i.e<<' '<<i.val<<endl;
		if(i.t == 0){
			modify(i.s,1);
		}
		else{
			ans[i.id] = getval(i.s,i.e);
		}
	}
	for(auto &i:ans)cout<<i<<'\n';
}

