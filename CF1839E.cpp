#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pii pair<int,int>
const int mxn = 303;
bitset<mxn*mxn/2> dp[mxn];
pii pre[mxn][mxn*mxn/2];
int arr[mxn];
set<int> v[2];
int n;

int get(){
	int re;
	cin>>re;
	return re;
}

void FIRST(){
	cout<<"First"<<endl<<1<<endl;
	int a = 1,b;
	while(b = get()){
		int mn = min(arr[a],arr[b]);
		arr[a] -= mn,arr[b] -= mn;
		for(int i = 1;i<=n;i++)if(arr[i])a = i;
		//for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';cout<<endl;
		cout<<a<<endl;
	}
	return;
}

void SECOND(){
	cout<<"Second"<<endl;
	int a = 0,b = 0;
	while(a = get()){
		int r = 0;
		if(v[1].find(a) != v[1].end())r = 1;
		b = *v[r^1].begin();
		cout<<b<<endl;
		int mn = min(arr[a],arr[b]);
		arr[a] -= mn;if(!arr[a])v[r].erase(a);
		arr[b] -= mn;if(!arr[b])v[r^1].erase(b);
	}
	return;
}

int main(){
	cin>>n;
	int total = 0;
	for(int i = 1;i<=n;i++)cin>>arr[i],total += arr[i];
	dp[0][0] = true;
	int tar = total>>1;
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=tar;j++){
			if(j>=arr[i]&&dp[i-1][j-arr[i]]){
				pre[i][j] = {i-1,j-arr[i]};
				dp[i][j] = dp[i][j]|dp[i-1][j-arr[i]];
			}
			if(dp[i-1][j])pre[i][j] = {i-1,j};
			dp[i][j] = dp[i-1][j]|dp[i][j];
		}
		//for(int j = 1;j<=tar;j++)cout<<dp[i][j];cout<<endl;
	}
	if((total&1)||!dp[n][tar])FIRST();
	else{
		pii now = {n,tar};
		while(now.fs != 0){
			if(pre[now.fs][now.sc].sc != now.sc)v[0].insert(now.fs);
			now = pre[now.fs][now.sc];
		}
		for(int i = 1;i<=n;i++){
			if(v[0].find(i) == v[0].end())v[1].insert(i);
		}
		/*
		for(auto &i:v[0])cout<<i<<' ';cout<<endl;
		for(auto &i:v[1])cout<<i<<' ';cout<<endl;

	   */
		SECOND();
	}
}
