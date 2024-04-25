#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define int ll
#define tlll tuple<ll,ll,ll>

const ll mxn = 3e5+10;
ll n,m,q;
ll bit[mxn];
pll arr[mxn];
set<pll> st;

void modify(int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] += v;
	return;
}
ll getval(int p){
	ll re = 0;
	for(;p>0;p-= p&-p)re += bit[p];
	return re;
}

void add(ll p,ll v){
	auto rit = st.lower_bound(make_pair(p,0));
	auto lit = prev(rit);
	ll len = rit->fs-lit->fs-1;
	modify(lit->fs,-lit->sc*len*(len+1)/2);
	len = rit->fs-p-1;
	modify(p,v*len*(len+1)/2);
	len = p-lit->fs-1;
	modify(lit->fs,lit->sc*len*(len+1)/2);
	st.insert(make_pair(p,v));
	return;
}

inline ll getans(ll p){
	if(!p)return 0ll;
	auto it = st.lower_bound(make_pair(p+1,0ll));
	it--;
	ll re = getval(it->fs-1);
	ll len = next(it)->fs-it->fs-1;
	re += it->sc*len*(len+1)/2;
	len = next(it)->fs-p-1;
	re -= it->sc*len*(len+1)/2;
	//cout<<p<<":"<<it->fs<<','<<re<<'\n';
	//for(int i = 1;i<=n;i++)cout<<getval(i)<<' ';cout<<'\n';
	return re;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>q;
	for(int i = 1;i<=m;i++)cin>>arr[i].fs;
	for(int i = 1;i<=m;i++)cin>>arr[i].sc;
	sort(arr+1,arr+m+1);
	st.insert(make_pair(arr[1].fs,arr[1].sc));
	st.insert(make_pair(arr[m].fs,arr[m].sc));
	modify(arr[1].fs,arr[1].sc*(n-2)*(n-1)/2);
	for(int i = 2;i<m;i++)add(arr[i].fs,arr[i].sc);
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int p,v;
			cin>>p>>v;
			add(p,v);
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<getans(r)-getans(l-1)<<'\n';
		}
	}
	return 0;
}
