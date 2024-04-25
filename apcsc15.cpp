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

const int mxn = 1e5+10;
ll bit[mxn+1];
void modify(ll p,ll val){
	for(;p<=mxn;p += p&-p)bit[p]+= val;
	return;
}
ll getval(ll p){
	ll re = 0;
	for(;p>0;p -= p&-p)re += bit[p];
	return re;
}
int main(){
	io
	ll n;
	cin>>n;
	vector<ll> v(n);
	vector<ll> all;
	for(auto &i:v){
		cin>>i;
		all.push_back(i);
	}
	sort(_all(all));
	all.erase(unique(_all(all)),all.end());
	for(auto &i:v){
		i = lower_bound(_all(all),i)-all.begin();
		i++;
	}
	ll ans = 0;
	for(int i = 0;i<n;i++){
		ans += getval(mxn-1)-getval(v[i]);
		modify(v[i],1);
	}
	cout<<ans;
}

