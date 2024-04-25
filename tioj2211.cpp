#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
#include "lib2211.h"

int finding(vector<int> &v,int k){
	for(int i = 0;i<v.size();i++){
		if(v[i] == k)return i+1;
	}
	return 0;
}
int main(){
	int n = Init();
	int sq = sqrt(n)+1;
	vector<int> v = {1};
	for(int i = 1;i<=sq;i++){
		int tmp = Query(v.back(),1);
		if(tmp == 1){
			Report(v.back());
			return 0;
		}
		v.push_back(tmp);
	}
	int pre = v.back();
	auto now = Query(v.back(),sq);
	while(!finding(v,now)){
		pre = now;
		now = Query(now,sq);
	}
	int pos = finding(v,now);
	int k;
	if(sq-pos != 0)k = Query(pre,sq-pos);
	else k = pre;
	Report(k);
	return 0;
}

