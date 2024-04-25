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
const ll mod = 1e9+7;
const ll mxn = 2e5+10;
ll bit[2][3][mxn+10];
void modify(ll tmp[],ll p,ll v){
	ll kk = p;
	for(;p<=mxn;p += p&-p){
		tmp[p] += v;
		if(tmp[p]>=mod)tmp[p] -= mod;
	}
	return;
}
ll getval(ll tmp[],ll s,ll e){
	ll re = 0;
	for(;e>0;e -= e&-e){
		re += tmp[e];
		if(re>=mod)re -= mod;
	}
	s--;
	for(;s>0;s -= s&-s){
		re -= tmp[s];
		if(re<0)re += mod;
	}
	return re;
}
//nowlow:0 2 4,nowhigh:1 3 5
int main(){
	ll n;
	cin>>n;
	ll arr[n];
	vector<ll> all;
	for(auto &i:arr){
		cin>>i;
		all.push_back(i);
	}
	sort(_all(all));
	all.erase(unique(_all(all)),all.end());
	for(auto &i:arr)i = lower_bound(_all(all),i)-all.begin()+1;
	ll ans = 0;
//	modify(bit[0],1,1);
//	cout<<getval(bit[0],1,1)<<endl;return 0;
	for(auto &i:arr){
		ll ta = getval(bit[1][2],i+1,mxn);
		ll tb = getval(bit[0][2],0,i-1);
		modify(bit[0][2],i,getval(bit[1][1],i+1,mxn));
		modify(bit[1][2],i,getval(bit[0][1],0,i-1));
		modify(bit[0][1],i,getval(bit[1][0],i+1,mxn));
		modify(bit[1][1],i,getval(bit[0][0],0,i-1));
		modify(bit[0][0],i,1);
		modify(bit[1][0],i,1);
		modify(bit[0][2],i,ta);
		modify(bit[1][2],i,tb);
//		cout<<i<<endl;
//		for(int ii = 0;ii<6;ii++){
//			for(int j= 0;j<10;j++)cout<<getval(bit[ii],j,j)<<" ";
//			cout<<endl;
//		}
//		cout<<endl;
	}
	ans = getval(bit[0][2],0,mxn)+getval(bit[1][2],0,mxn);
	if(ans>=mod)ans -= mod;
	cout<<ans;	
}

