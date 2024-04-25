#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Functions provided to the solution.
std::vector<int> activate_sonar_system(int k, const std::vector<int>& p);

/*
  // 這邊填入程式碼，下面這個是範例。不保證任何得分。

  // 在題本中 n=2, m=2, L=1, R=8。
  std::vector<int> r1 = activate_sonar_system(4, {1, 5});
  // 回傳 [1, 0]
  std::vector<int> r2 = activate_sonar_system(2, {1, 3});
  // 回傳 [0, 1]
  return {3, 4};
*/

#define pii pair<int,int>
#define fs first
#define sc second
const int B = 16;
int M;
int CCC = 0;

vector<int> ask(int k,vector<int> v){
	CCC++;
	assert(v.size() == M);
	assert(CCC<=8888);
	for(int i = 1;i<v.size();i++){
		if(v[i-1]+k-1>=v[i])assert(false);
	}
	return activate_sonar_system(k,v);
}

std::vector<int> detect_debris(int N, int m, int L, int R) {
	M = m;
	vector<int> ans;
	vector<int> v;
	for(int i = 0;i<M;i++){
		v.push_back(1+i*1e7);
	}
	auto re = ask((int)1e7,v);
	v.clear();
	vector<pii> range;
	for(int i = 0;i<M;i++){
		if(re[i]){
			v.clear();
			for(int j = 0;j<M;j++){
				v.push_back(i*1e7+j*1e5+1);
			}
			auto tmp = ask((int)1e5,v);
			for(int j = 0;j<M;j++){
				if(tmp[j])range.push_back(pii(i*1e7+j*1e5+1,i*1e7+(j+1)*1e5));
			}
		}
	}
	vector<pii> inq;
	for(auto &i:range)cerr<<i.fs<<' '<<i.sc<<endl;
	while(!range.empty()||!inq.empty()){
		while(inq.size() != M&&!range.empty()){
			inq.push_back(range.back());
			range.pop_back();
		}
		int C = -1e9;
		while(inq.size() != M){
			inq.push_back(pii(C,C+1e5-1));
			C += 1e5;
		}
		//for(auto &i:inq)cerr<<i.fs<<' '<<i.sc<<',';cerr<<endl;
		for(int i = B;i>=0;i--){
			v.clear();
			int CC = C;
			for(auto &[l,r]:inq){
				if(r-l+1<(1<<i)){
					v.push_back(CC);
					CC += 1e5;
				}
				else v.push_back(l);
			}
			auto re = ask(1<<i,v);
			for(int j = 0;j<inq.size();j++){
				auto &[l,r] = inq[j];
				if(r-l+1<(1<<i))continue;
				if(!re[j])l += 1<<i;
			}
		}
		vector<pii> nxt;
		for(int i = 0;i<inq.size();i++){
			auto [l,r] = inq[i];
			if(l<=r){
				ans.push_back(l);
				if(l<r)nxt.push_back({l+1,r});
			}
		}
		inq = nxt;
	}
	assert(ans.size() == N);
	return ans;
}
