#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const int mxn = 1e4+10;
int dp[mxn] = {};
int n,m;
int main(){
	cin>>n>>m;
	dp[n] = 1;
	queue<int> q;
	q.push(n);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(now*2<mxn&&dp[now*2] == 0){
			dp[now*2] = dp[now]+1;
			q.push(now*2);
		}
		if(now-1>=0&&dp[now-1] == 0){
			dp[now-1] = dp[now]+1;
			q.push(now-1);
		}
	}
	cout<<dp[m]-1<<"\n";
	return 0;
}

