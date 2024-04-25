#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

struct line{
	ll m,b;
	ll t;
	line(ll a,ll bb,ll tt){
		m = a,b = bb;
		t = tt;
	}
	ll operator()(ll k){
		return m*k+b;
	}
};
ld intersect(line a,line b){
	return (a.b-b.b)/(b.m-a.m);
}
const ll mxn = 5e5+10;
const ll inf = 1e18;
ll n,k;
ll arr[mxn],pref[mxn],dp[mxn];
bool check(line small,line med,line add){
	auto inter1 = min((ld)small.t+k,intersect(small,med));
	ld inter2 = intersect(med,add);
	if(inter1>=inter2)return true;
	else return false;
}
int main(){
	cin>>n>>k;
	deque<line> dq;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	reverse(arr+1,arr+n+1);
	for(int i = 1;i<=n;i++)pref[i] = pref[i-1]+arr[i];
	dq.push_back(line(0,0,0));
	for(ll i = 1;i<=n;i++){
		while(dq.front().t<i-k)dq.pop_front();
		while(dq.size()>=2&&dq[0](i)<=dq[1](i)){
			dq.pop_front();
		}
		dp[i] = - i*i +dq[0](i);
		line tmp(2*i,dp[i]+pref[i]-i*i,i);
		while(dq.size()>=2&&check(dq[dq.size()-2],dq[dq.size()-1],tmp))dq.pop_back();
		dq.push_back(tmp);
		// cout<<i<<":";for(auto &j:dq)cout<<j.m<<' '<<j.b<<' '<<j.t<<',';cout<<endl;
	}
	// for(int i = 0;i<=n;i++)cout<<dp[i]<<' ';cout<<endl;
	cout<<dp[n];
}

/*
dp[i] = dp[j] + pref[i] -(i-j)*(i-j) 
dp[i] = pref[i] - i*i + 2*i*j -j*j +dp[j]
i-j<=k
*/
