#include "peru.h"
#include <bits/stdc++.h>
using namespace std;

const int mxn = 25e5+10;
const ll mod = 1e9+7;
const ll p = 23;
ll ans = 0;

ll arr[mxn];
ll N,K;
multiset<ll> st;
ll dp[mxn];
deque<pll> dq;

void add(ll k){
	st.insert(k);
	return;
}

void del(ll k){
	st.erase(st.find(k));
	return;
}

int solve(int n, int k, int* v){
	N = n,K = k;
	for(int i = 0;i<n;i++)arr[i+1] = v[i];
	dq.push_back(pll(0,dp[0]+arr[1]));
	add(dp[0]+arr[1]);
	for(int i = 1;i<=N;i++){
		while(i-dq.front().fs>K){
			del(dq.front().sc);
			dq.pop_front();
		}
		while(!dq.empty()&&arr[dq.back()]<=arr[i]){
			del(dq.back().sc);
			dq.pop_back();
		}
		if(dq.empty()){
			ll val = dp[max(0ll,i-K)]+arr[i];
			add(dp[max(0ll,i-K)]+arr[i]);
		}
	}
}
