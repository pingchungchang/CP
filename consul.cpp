#include "grader.h"
#include <bits/stdc++.h>
using namespace std;
/*
/// insert your code
/// for example
if(cnt(kth(1)) > n / 3) say_answer(kth(1));
	else say_answer(-1);

*/

map<int,int> kmp,cmp;

int get_idx(int p){
	if(kmp.find(p) != kmp.end())return kmp[p];
	else return kmp[p] = kth(p);
}
int get_cnt(int k){
	if(cmp.find(k) != cmp.end())return cmp[k];
	else return cmp[k] = cnt(k);
}

void solve(int N){
	kmp.clear();cmp.clear();
	vector<int> v;
	for(int i = 1;i<=N;i++)v.push_back(i);
	srand(time(NULL));
	random_shuffle(v.begin(),v.end());
	for(int i = 0;i<25;i++){
		int now = v[i];
		if(get_cnt(get_idx(now))>N/3){
			say_answer(get_idx(now));
			return;
		}
	}
	say_answer(-1);
	return;
}
