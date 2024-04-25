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

struct node{
	mutable ld w;
	ll l;
	mutable ll r;
	node(){
		l = w = 0;
	}
	node(ll lll,ll rr,ld b){
		l = lll,r = rr,w = b;
	}
	node(ll k){
		l = k,r = k,w = -1;
	}
	bool operator<(const node &b)const{
		return l<b.l;
	}
};
set<node> st;
const ll mxn = 1e5+10;
ll pref[mxn];
int main(){
	io
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		cin>>pref[i];
		pref[i] += pref[i-1];
	}
	for(int i = 1;i<=n;i++){
		ll t;
		cin>>t;
		st.insert(node(i,i,t));
	}
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			ll p;
			cin>>p;
			p++;
			auto it = st.lower_bound(node(p));
			if(it != st.end()&&it->l == p){
				auto it2 = --it;
				it++;
				it2->w += it->w;
				it2->r = it->r;
				st.erase(it);
			}
			else{
				it--;
				ll l = it->l,r = it->r;
				ld w = it->w;
				st.erase(it);
				st.insert(node(l,p-1,w*(pref[p-1]-pref[l-1])/(pref[r]-pref[l-1])));
				st.insert(node(p,r,w*(pref[r]-pref[p-1])/(pref[r]-pref[l-1])));
			}
		}
		else if(t == 2){
			ll p,val;
			cin>>p>>val;
			auto it = st.lower_bound(node(p));
          	if(it == st.end()||it->l != p)it--;
			it->w+=val;
		}
		else{
			ll p;
			cin>>p;
			auto it = st.lower_bound(node(p));
          	if(it == st.end()||it->l != p)it--;
			cout<<fixed<<setprecision(15)<<it->w/(pref[it->r]-pref[it->l-1])<<'\n';
		}
//		for(auto it = st.begin();it != st.end();it++){
//			cout<<it->l<<' '<<it->r<<':'<<it->w<<' '<<pref[it->r]-pref[it->l-1]<<'\n';
//		}
	}
	return 0;	
}
