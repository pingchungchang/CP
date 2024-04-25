#include <vector>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,sse4")

#define ll long long
#define pii pair<int,int>
#define fs first
#define sc second

namespace {
	const int B = 60;
	const int BK = 64;
	const int mxn = 256;

	struct mat{
		bitset<mxn> val[mxn];
		mat(){}
		mat operator*(mat b)const{
			for(int i = 0;i<mxn;i++){
				for(int j = 0;j<i;j++){
					bool ta = b.val[i][j],tb = b.val[j][i];
					b.val[i][j] = tb,b.val[j][i] = ta;
				}
			}
			mat re;
			for(int i = 0;i<mxn;i++){
				for(int j = 0;j<mxn;j++){
					re.val[i][j] = (val[i]&b.val[j]).any();
				}
			}
			return re;
		}
	};
	mat dp[B][BK];
	int N;
}

void initialize(int n, std::vector<std::pair<int, int>> segments) {
	int N = n;
    // 這邊填入程式碼，下面這個是範例。
	for(auto &i:segments){
		i.fs--,i.sc--;
		dp[0][1].val[i.sc][i.fs] = 1;
	}
	for(int i = 2;i<BK;i++){
		dp[0][i] = dp[0][i-1]*dp[0][0];
	}
	N = n;
	for(int i = 0;i<B;i++){
		if(i)dp[i][1] = dp[i-1][BK-1]*dp[i-1][1];
		for(int j = 2;j<BK;j++)dp[i][j] = dp[i][j-1]*dp[i][1];
	}

	/*
	for(int i = 0;i<4;i++){
		cerr<<i<<":";
		for(int j = 0;j<BK;j++){
			cerr<<j<<":"<<endl;
			for(int ii = 0;ii<N;ii++){
				for(int jj = 0;jj<N;jj++){
					cerr<<dp[i][j].val[ii][jj];
				}
				cerr<<endl;
			}
		}
	}
	*/
	return;
}

bool has_route(int s, int t, long long k) {
	s--,t--;
	bitset<mxn> now;
	now.reset();
	now[s] = true;
	int id = 0;
	while(k){
		if(k%BK != 0){
			bitset<mxn> tmp;
			int t = k%BK;
			for(int j = 0;j<mxn;j++){
				tmp[j] = (dp[id][t].val[j]&(now)).any();
			}
			now = tmp;
		}
		id++;
		k/=BK;
	}
	return now[t];
}
