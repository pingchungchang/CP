#include "interactive.h"
#include <bits/stdc++.h>
using namespace std;


const int mxn = 110;
const int B = 7;
multiset<int> S1[B],S2[B];
vector<int> v[B];
vector<int> ans;
map<int,int> mp;

multiset<int> parse(vector<int> v){
	multiset<int> re;
	for(auto &i:v)re.insert(i);
	return re;
}

void kotori(multiset<int> &a,multiset<int> &b){
	for(auto &i:a)b.erase(b.find(i));
	if(!b.empty())b.erase(b.find(0));
	return;
}

vector<int> guess(int n) {
	ans = vector<int>(n);
	ans[0] = ask(1);
	for(int i = 0;i<B;i++){
		for(int j = 2;j<=n;j++){
			if(j&(1<<i))v[i].push_back(j);
		}
	}
	for(int i = 0;i<B;i++){
		if(v[i].empty())continue;
		S1[i] = parse(get_pairwise_xor(v[i]));
		v[i].push_back(1);
		S2[i] = parse(get_pairwise_xor(v[i]));
		v[i].pop_back();
	}
	for(int i = 0;i<B;i++){
		kotori(S1[i],S2[i]);
	}
	for(int i = 0;i<B;i++){
		for(auto &j:S2[i]){
			mp[j^ans[0]] |= 1<<i;
		}
	}
	for(auto &i:mp)ans[i.second-1] = i.first;
	return ans;
}
