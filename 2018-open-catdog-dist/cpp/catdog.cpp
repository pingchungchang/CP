#include "catdog.h"
#include <bits/stdc++.h>
using namespace std;

const int mxn = 101000;
int x;
vector<int> tree[mxn];
int dp[mxn][2];
int N;
int arr[mxn];

void initialize(int NN, std::vector<int> A, std::vector<int> B) {
	memset(arr,0,sizeof(arr));
	N = NN;
	for(int i = 0;i<N-1;i++){
		int a= A[i],b = B[i];
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	return;
}


void dfs(int now,int par){
	memset(dp[now],0,sizeof(dp[now]));
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
		if(arr[now] != 1)dp[now][1] += min({dp[nxt][1],dp[nxt][0]+1});
		if(arr[now] != 2)dp[now][0] += min({dp[nxt][1]+1,dp[nxt][0]});
	}
	if(arr[now]){
		for(int i = 0;i<2;i++){
			if(arr[now]-1 != i)dp[now][i] = mxn;
		}
	}
	return;
}

int answer(){
	dfs(1,1);
	for(int i = 1;i<=N;i++)cout<<dp[i][0]<<' ';cout<<endl;
	for(int i = 1;i<=N;i++)cout<<dp[i][1]<<' ';cout<<endl;
	cout<<endl;
	return *min_element(dp[1],dp[1]+2);
}

int cat(int v) {
	arr[v] = 1;
	return answer();
}

int dog(int v) {
	arr[v] = 2;
	return answer();
}

int neighbor(int v) {
	arr[v] = 0;
	return answer();
}
