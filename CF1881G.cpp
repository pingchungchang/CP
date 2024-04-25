#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const int mxn = 2e5+10;
ll bit[mxn];
int n,q;
set<int> two,three;
string s;

void modify(int p,int v){
	for(;p<=n;p+=p&-p)bit[p] += v;
	return;
}
ll getval(int p){
	ll re = 0;
	for(;p>0;p-= p&-p)re += bit[p];
	return re;
}

ll get(int p){
	return (getval(p)+s[p]-'a')%26;
}

void add(set<int>& st,int p){
	st.insert(p);
	return;
}

void del(int p){
	if(two.find(p) != two.end())two.erase(p);
	if(three.find(p) != three.end())three.erase(p);
	return;
}

void check(int p){
	if(p<=0||p>n)return;
	if(p+1<=n&&get(p) == get(p+1))add(two,p);
	if(p+2<=n&&get(p) == get(p+2))add(three,p);
	return;
}

void solve(){
	for(int i = 1;i<=n;i++)modify(i,-getval(i));
	two.clear();three.clear();
	cin>>n>>q>>s;
	s = "#"+s;
	for(int i = 1;i+1<=n;i++){
		if(get(i) == get(i+1))add(two,i);
		if(i+2<=n&&get(i) == get(i+2))add(three,i);
	}
	while(q--){
		int t;
		cin>>t;
		if(t == 2){
			int l,r;
			cin>>l>>r;
			auto it1 = two.lower_bound(l);
			auto it2 = three.lower_bound(l);
			bool flag = true;
			if(it1 != two.end()&&*it1+1<=r)flag = false;
			if(it2 != three.end()&&*it2+2<=r)flag = false;
			cout<<(flag?"YES\n":"NO\n");
		}
		else{
			ll l,r,v;
			cin>>l>>r>>v;
			modify(l,v);
			modify(r+1,-v);
			for(int i = -3;i<=3;i++){
				del(i+l);
				del(i+r);
				check(i+l);
				check(i+r);
			}
		}
	}
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
