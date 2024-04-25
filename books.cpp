#include <bits/stdc++.h>

#include "books.h"
#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

using namespace std;
/*
//
// --- Sample implementation for the task books ---
//
// To compile this program with the sample grader, place:
//     books.h books_sample.cpp sample_grader.cpp
// in a single folder and run:
//     g++ books_sample.cpp sample_grader.cpp
// in this folder.
//

if (skim(2) == 42) {
	impossible();
} else {
	answer({1, 3});
}
*/

map<ll,ll> mp;
ll ask(ll p){
	if(mp.find(p) != mp.end())return mp[p];
	else return mp[p] = skim(p);
}

void solve(int N, int K, long long A, int S) {
	mp.clear();
	vector<pll> v;
	ll sum = 0;
	for(int i = 1;i<=K;i++){
		v.push_back(pll(i,ask(i)));
	}
	ll l = 1,r = N+1;
	while(l+1<r){
		ll mid = (l+r)>>1;
		if(ask(mid)>=A)r = mid;
		else l = mid;
	}
	if(r != N+1){
		ll sum = ask(r);
		int cnt = 1;
		vector<int> ans = {r};
		for(int i = 1;i<=K;i++){
			if(ans.size()>=K)break;
			if(i == ans[0])continue;
			ans.push_back(i);
			sum += ask(i);
		}
		if(sum>=A&&sum<=A*2){
			answer(ans);
			return;
		}
	}
	for(int i = 1;i<=K;i++){
		if(r-i>0)v.push_back(pll(r-i,ask(r-i)));
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i = 0;i<(1<<v.size());i++){
		if(__builtin_popcount(i) != K)continue;
		ll sum = 0;
		for(int j = 0;j<v.size();j++){
			if(i&(1<<j))sum += v[j].sc;
		}
		if(sum>=A&&sum<=A*2){
			vector<int> ans;
			for(int j = 0;j<v.size();j++){
				if(i&(1<<j))ans.push_back(v[j].fs);
			}
			answer(ans);
			return;
		}
	}
	impossible();
	return;
}
