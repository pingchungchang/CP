#include "citymapping.h"
#include <bits/stdc++.h>

using namespace std;

#define pll pair<ll,ll>
#define fs first
#define sc second
#define ll long long
#define pii pair<int,int>
const int mxn = 1010;
vector<pair<ll,pii>> edges;
ll dist[mxn][mxn];
queue<vector<int>> q;

ll f(int a,int b){
	return dist[a][b]?dist[a][b]:dist[a][b] = dist[b][a] = get_distance(a,b);
}

inline void calc(vector<int> v){
	//for(auto &i:v)cout<<i<<',';cout<<endl;
	if(v.size()<2)return;
	if(v.size()==2){
		edges.push_back(make_pair(f(v[0],v[1]),make_pair(v[0],v[1])));
		return;
	}
	random_shuffle(v.begin(),v.end());
	int a = v[0];pll sm = make_pair(f(a,v[1]),1ll*v[1]);
	for(int i = 1;i<v.size();i++)sm = min(sm,make_pair(f(a,v[i]),1ll*v[i]));
	int b = sm.sc;
	edges.push_back(make_pair(sm.fs,make_pair(a,b)));
	vector<int> lv,rv;
	for(auto &i:v){
		if(i == a||i == b)continue;
		if(f(a,i)<f(b,i))lv.push_back(i);
		else rv.push_back(i);
	}
	lv.push_back(a);
	rv.push_back(b);
	q.push(lv);
	q.push(rv);
	return;
}

void find_roads(int N, int Q, int A[], int B[], int W[]) {
	srand(7122);
	q.push({});
	for(int i = 1;i<=N;i++)q.front().push_back(i);
	while(!q.empty()){
		auto v = q.front();
		q.pop();
		calc(v);
	}
	assert(edges.size() == N-1);
	for(int i = 0;i<edges.size();i++){
		W[i] = edges[i].fs;
		A[i] = edges[i].sc.fs;
		B[i] = edges[i].sc.sc;
	}
	return;
}
