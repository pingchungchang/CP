#include "minerals.h"
#include <bits/stdc++.h>
using namespace std;

/*
int v = Query(1);
Answer(i, 2 * N + 1 - i);
*/

#define pii pair<int,int>
#define fs first
#define sc second
const int B = 15;
const int mxn = 86011;
int pl,pr;
vector<pii> ans;
int before[mxn];
int res;
int pt;

void dc(int l,int r,vector<int> v){
}

void Solve(int N) {
	vector<int> v[2];
	vector<int> vv;
	for(int i = 1;i<=N*2;i++)vv.push_back(i);
	mt19937 seed(time(NULL));
	shuffle(vv.begin(),vv.end(),seed);
	for(auto &i:vv){
		auto tmp = Query(i);
		if(tmp != res){
			res = tmp;
			v[0].push_back(i);
		}
		else{
			v[1].push_back(i);
		}
		before[i] = tmp;
	}
	vv.clear();
	pt = N-1;
	dc(0,N-1,v[1]);
}
