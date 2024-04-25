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
	ll pos;
	bool operator<(node b)const{
		if(abs(pos) != abs(b.pos))return abs(pos)<abs(b.pos);
		else return pos<b.pos;
	}
	node(ll k){
		pos = k;
	}
	node(){}
};
void solve(){
	ll n;
	cin>>n;
	set<node> st;
	for(int i = 1;i<=n;i++){
		st.insert(node(i));
		st.insert(node(-i));
	}
	vector<pll> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i].fs;
		v[i].sc = i;
	}
	sort(_all(v));
	reverse(_all(v));
	vector<ll> ans(n);
	ll total = 0;
	for(auto &i:v){
		ans[i.sc] = st.begin()->pos;
		st.erase(st.find(*st.begin()));
		total += abs(ans[i.sc])*i.fs*2;
	}
	cout<<total<<'\n';
	cout<<"0 ";
	for(auto i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
}

