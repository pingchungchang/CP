#include "Boblib.h"
#include <cassert>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second

/*
InitMap( 3, 2 );
MakeMap( 1, 2 );
*/

namespace BOB{
	const int H = 10;
	const int mxn = 1020;
	set<int> g[mxn];
	int N,n;
	bitset<mxn> bit;
	int dp[mxn];
	int N10,N11;
	void get_ind(){
		for(int i = 0;i<N;i++){
			if(g[i].size() == N-2){
				N11 = i;
				//cerr<<"N11:"<<i<<endl;
				for(int j = 0;j<N;j++){
					if(i==j||g[i].find(j) != g[i].end())continue;
					N10 = j;
					//cerr<<"N10:"<<j<<endl;
					return;
				}
			}
		}
		assert(false);
		return;
	}
	vector<int> bg[mxn];
	vector<int> get_num(){
		vector<int> vv;
		for(auto &i:g[N10]){
			bit[i] = true;
			vv.push_back(i);
		}
		for(auto &i:vv){
			for(auto &j:g[i]){
				if(bit[j]){
					bg[i].push_back(j);
				}
			}
		}
		vector<int> one;
		for(auto &i:vv){
			//cerr<<i<<":";for(auto &j:bg[i])cerr<<j<<' ';cerr<<endl;
			if(bg[i].size() == 1)one.push_back(i);
		}
		assert(one.size()==2);
		//cerr<<"ONE:"<<one[0]<<' '<<one[1]<<endl;
		int pre = -1,now = (g[one[0]].size()>g[one[1]].size()?one[0]:one[1]);
		vector<int> re;
		bool flag = true;
		while(flag){
			re.push_back(now);
			flag = false;
			for(auto nxt:bg[now]){
				if(!bit[nxt]||nxt == pre)continue;
				pre = now;
				now = nxt;
				flag = true;
				break;
			}
		}
		return re;
	}
	vector<pii> ans;

	void answer(){
		//cerr<<N<<":"<<ans.size()<<endl;
		for(auto &i:ans){
			//cerr<<i.fs<<' '<<i.sc<<endl;
		}
		InitMap(N-H-2,ans.size());
		for(auto &i:ans){
			//cerr<<i.fs<<' '<<i.sc<<endl;
			MakeMap(i.fs,i.sc);
		}
		return;
	}

	void GO(int NN,int M,int A[],int B[]){
		N = NN;
		n = N-12;
		for(int i = 0;i<M;i++){
			g[A[i]].insert(B[i]);
			g[B[i]].insert(A[i]);
		}
		//cerr<<"BOB"<<endl;
		for(int i = 0;i<M;i++){
			//cerr<<A[i]<<' '<<B[i]<<endl;
		}
		//cerr<<endl;
		get_ind();
		auto v = get_num();
		assert(v.size() == H);
		for(auto &i:v)bit[i] = true;
		bit[N10] = bit[N11] = true;
		for(int i = 0;i<H;i++){
			for(auto nxt:g[v[i]]){
				dp[nxt] |= 1<<i;
			}
		}
		for(int i = 0;i<N;i++){
			if(bit[i])continue;
			for(auto nxt:g[i]){
				if(nxt<i||bit[nxt])continue;
				ans.push_back({dp[i],dp[nxt]});
			}
		}
		answer();
	}
}

void Bob( int V, int U, int C[], int D[] ){
	BOB::GO(V,U,C,D);
}

