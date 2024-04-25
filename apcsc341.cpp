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
	ll l,r,val;
	node(){}
};
const int mxn = 5e5+10;
ll bit[mxn];
void modify(ll p,ll v){
	for(;p<mxn;p += p&-p)bit[p] = max(bit[p],v);
	return;
}
ll getval(ll p){
	ll re = 0;
	for(;p>0;p -= p&-p)re = max(re,bit[p]);
	return re;
}
int main(){
	io
	ll ans = 0;
	ll n;
	cin>>n;
	node arr[n];
	vector<int> all = {0,(ll)1e9+10};
	for(int i= 0;i<n;i++){
		cin>>arr[i].l>>arr[i].r>>arr[i].val;
		all.push_back(arr[i].l);
		all.push_back(arr[i].r);
	}
	sort(_all(all));
	all.erase(unique(_all(all)),all.end());
	for(auto &i:arr){
		i.l = lower_bound(_all(all),i.l)-all.begin();
		i.r = lower_bound(_all(all),i.r)-all.begin();
	}
	ll dp[all.size()];
	memset(dp,0LL,sizeof(dp));
	for(auto &i:arr){
		ll big = getval(i.l-1);
		modify(i.r,big+i.val);
	}
	cout<<getval(all.size()-1);
	
}

