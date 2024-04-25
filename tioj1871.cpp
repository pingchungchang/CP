#include <bits/stdc++.h>
using namespace std;
#include "lib1871.h"
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const int mxn = 1e6+10;
int sparse[mxn][21];
const int inf = INT_MAX;
int getval(int a,int b){
	int d = b-a+1;
	int cnt = 0;
	while(d){
		cnt++;
		d>>=1;
	}
	cnt--;
	return min(sparse[a][cnt],sparse[b-(1<<cnt)+1][cnt]);
}
int main(){
	for(auto &i:sparse)for(auto &j:i)j = inf;
	int n = futa::init();
	auto arr = futa::momo_gives_you_list_of_futa();
	for(int i = 0;i<n;i++)sparse[i][0] = arr[i];
	for(int i = 1;i<=20;i++){
		for(int j = 0;j<n-(1<<(i-1));j++){
			sparse[j][i] = min(sparse[j][i-1],sparse[j+(1<<(i-1))][i-1]);
		}
	}
	int q = futa::momo_tells_you_q();
	while(q--){
		auto req = futa::momo_asks();
		futa::you_tell_momo(getval(req.fs,req.sc));
	}
	return 0;
}

