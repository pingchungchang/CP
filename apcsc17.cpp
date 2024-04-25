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

const int mxn = 3e5+10;
ll bit1[mxn+1],bit2[mxn+1];
void modify(ll* bit,ll p,ll val){
	for(;p<=mxn;p += p&-p){
		bit[p] += val;
	}
	return;
}

ll getval(ll* bit,ll p){
	ll re = 0;
	for(;p>0;p -= p&-p)re += bit[p];
	return re;
}
int main(){
	ll n;
	cin>>n;
	ll arr[n];
	vector<ll> all;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		all.push_back(arr[i]);
	}
	sort(_all(all));
	all.erase(unique(_all(all)),all.end());
	for(auto &i:arr){
		i = lower_bound(_all(all),i)-all.begin();
		i++;
	}
	ll ans = 0;
	for(int i = 0;i<n;i++){
		ans += getval((ll*)bit2,mxn)-getval((ll*)bit2,arr[i]);
		ans += arr[i]*(getval((ll*)bit1,mxn)-getval((ll*)bit1,arr[i]));
		modify((ll*)bit2,arr[i],arr[i]);
		modify((ll*)bit1,arr[i],1);
	}
	cout<<ans;
}

