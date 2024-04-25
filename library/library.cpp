#include <cstdio>
#include <vector>
#include "library.h"
#include <bits/stdc++.h>
using namespace std;

/*
vector<int> M(N);
int A = Query(M);
vector<int> res(N);
Answer(res);
*/

#define pii pair<int,int>
#define fs first
#define sc second
const int mxn = 1010;
vector<int> v;
vector<pii> edges;
vector<int> perm;
bitset<mxn> ch;
int N;

int ask(bitset<mxn> b){
	if(b.count() == 0)return 0;
	vector<int> re(N);
	for(int i = 0;i<N;i++){
		if(b[i])re[i] = 1;
		else re[i] = 0;
	}
	return Query(re);
}

bool check(int s,int now){
	ch.reset();
	int exp = v.size()-s+1;
	for(int i = s;i<v.size();i++){
		ch[v[i]] = true;
	}
	ch[now] = true;
	//cerr<<s<<":"<<now<<"::";
	//for(int i = 0;i<N;i++)//cerr<<(ch[i]?1:0);cerr<<":";
	int re = ask(ch);
	for(auto &i:edges){
		if(ch[i.fs]&&ch[i.sc])exp--;
	}
	//cerr<<re<<','<<exp<<endl;
	if(exp != re)return false;
	else return true;
}

int get_edge(int s,int now){
	int l = s,r = v.size()-1;
	while(l != r){
		int mid = (l+r+1)>>1;
		if(check(mid,now))r = mid-1;
		else l = mid;
	}
	return l;
}

void calc(int now){
	while(!check(0,now)){
		int s = get_edge(0,now);
		edges.push_back({v[s],now});
		//cerr<<v[s]<<":"<<now<<endl;
	}
	return;
}

vector<int> g[mxn];
vector<int> ans;

void dfs(int now){
	ch[now] = true;
	ans.push_back(now+1);
	for(auto nxt:g[now]){
		if(ch[nxt])continue;
		dfs(nxt);
	}
	return;
}

void Solve(int NN){
	//cerr<<"HI"<<endl;
	if(NN == 1){
		Answer(vector<int>(1,1));
		return;
	}
	N = NN;
	srand(time(NULL));
	for(int i = 0;i<N;i++)perm.push_back(i);
	//random_shuffle(perm.begin(),perm.end());
	for(auto &i:perm){
		if(!v.empty())calc(i);
		v.push_back(i);
	}
	for(auto &i:edges){
		g[i.fs].push_back(i.sc);
		g[i.sc].push_back(i.fs);
	}
	for(auto &i:edges){
		//cerr<<i.fs<<' '<<i.sc<<endl;
	}
	int st = 0;
	for(int i = 0;i<N;i++){
		if(g[i].size()==1)st = i;
	}
	ch.reset();
	dfs(st);
	//for(auto &i:ans)//cerr<<i<<' ';cerr<<endl;
	Answer(ans);
	return;
}
