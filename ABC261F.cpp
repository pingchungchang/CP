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

const ll mxn = 3e5+10;
ll bit[mxn];
vector<ll> cols[mxn];
void modify(ll p,ll v){
	for(;p<mxn;p += p&-p)bit[p] +=v;
}
ll getval(ll p){
	ll re = 0;
	for(;p>0;p -= p&-p)re += bit[p];
	return re;
}
int main(){
//	io
	ll n;
	cin>>n;
	pll arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i].sc;
	}
	for(auto &i:arr)cin>>i.fs;
	ll ans = 0;
	for(int i = n-1;i>=0;i--){
		ans += getval(arr[i].fs-1);
		modify(arr[i].fs,1);
	}
	for(auto &i:bit)i = 0;
	for(auto &i:arr){
		cols[i.sc].push_back(i.fs);
	}
	for(auto &c:cols){
		if(c.empty())continue;
		vector<ll> all;
		for(auto &i:c)all.push_back(i);
		sort(_all(all));
		all.erase(unique(_all(all)),all.end());
		for(auto &i:c)i = lower_bound(_all(all),i)-all.begin()+1;
		fill(bit,bit+all.size()+1,0);
		for(int i = (int)c.size()-1;i>=0;i--){
			ans -= getval(c[i]-1);
			modify(c[i],1);
		}
	}
	cout<<ans;
}

