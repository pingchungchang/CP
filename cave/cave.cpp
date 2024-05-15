#include "cave.h"
#include <bits/stdc++.h>
using namespace std;


const int mxn = 5050;

namespace {
	int state[mxn],perm[mxn],pstate[mxn];
	int buf[mxn];
	int N;
	bool done[mxn];
}

int ask(int arr[]){
	int re = tryCombination(arr);
	if(re == -1)re = N+1;
	return re;
}

void solve(int id){
	memset(buf,0,sizeof(buf));
	for(int i = 0;i<id;i++){
		buf[perm[i]] = state[i];
	}
	if(ask(buf)>id)state[id] = 0;
	else state[id] = 1;
	vector<int> v;
	for(int i = 0;i<N;i++){
		if(done[i])continue;
		v.push_back(i);
	}
	int l = 0,r = v.size()-1;
	while(l != r){
		int mid = (l+r)>>1;
		for(auto &i:v)buf[i] = state[id]^1;
		for(int i = l;i<=mid;i++)buf[v[i]] = state[id];
		if(ask(buf)>id)r = mid;
		else l = mid+1;
	}
	perm[id] = v[l];
	done[v[l]] = true;
	return;
}

void exploreCave(int NN) {
	N = NN;
	for(int i = 0;i<N;i++){
		solve(i);
	}
	for(int i = 0;i<N;i++){
		pstate[perm[i]] = state[i];
	}
	for(int i = 0;i<N;i++){
		state[perm[i]] = i;
	}
	answer(pstate,state);
	return;
}
