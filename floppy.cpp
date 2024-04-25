#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>

#include "floppy.h"
#define pii pair<int,int>
#define fs first
#define sc second
using namespace std;

void read_array(int subtask_id, const std::vector<int> &v) {
	vector<int> st;
	string s;
	for(int i = 0;i<v.size();i++){
		while(!st.empty()&&v[st.back()]<v[i]){
			s += '0';
			st.pop_back();
		}
		s += '1';
		st.push_back(i);
	}
	save_to_floppy(s);
	return;
}

const int mxn = 4e4+10;
pii segtree[mxn*4];
vector<int> dag[mxn];
int deg[mxn];
int arr[mxn];
int C = 0;
vector<int> ans;

void TOPO(int N){
	queue<int> q;
	for(int i = 0;i<N;i++){
		if(!deg[i])q.push(i);
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		arr[now] = --C;
		for(auto nxt:dag[now]){
			deg[nxt]--;
			if(!deg[nxt])q.push(nxt);
		}
	}
	return;
}

void build(int now,int l,int r){
	if(l == r){
		segtree[now] = {arr[l],l};
		return;
	}
	int mid = (l+r)>>1;
	build(now*2+1,l,mid);
	build(now*2+2,mid+1,r);
	segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
}

pii getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return segtree[now];
	int mid = (l+r)>>1;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return max(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
}

std::vector<int> solve_queries(int subtask_id, int N,
        const std::string &bits,
        const std::vector<int> &a, const std::vector<int> &b) {
	vector<int> st;
	int p = 0;
	for(auto &i:bits){
		if(i == '1'){
			if(!st.empty()){
				deg[p]++;
				dag[st.back()].push_back(p);
			}
			st.push_back(p);
			p++;
		}
		else{
			deg[st.back()]++;
			dag[p].push_back(st.back());
			st.pop_back();
		}
	}
	TOPO(N);
	build(0,0,N-1);
	for(int i = 0;i<a.size();i++){
		ans.push_back(getval(0,0,N-1,a[i],b[i]).sc);
	}
	return ans;
}
