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
#pragma GCC optimize("O3")
int main(){
	io
	ll n,m,p,q;
	cin>>n>>m>>p>>q;
	bool one = false;
	if(p == 1){
		one = true;
		p = 2;
	}
	ll row[m],col[m];
	ll total = 0;
	for(int i = 0;i<m;i++)cin>>col[i];
	for(int i = 1;i<m;i++)cin>>row[i];
	row[0] = col[0];
	int dp[2][m];
	int now = 0,pre = 1;
//	for(int i = 0;i<m;i++)cout<<col[i]<<' ';cout<<endl;
	for(int i = 0;i<m;i++)dp[now][i] = col[i];
	for(int i = 1;i<m;i++){
		swap(now,pre);
		dp[now][0] = row[i];
		for(int j = 1;j<m;j++)dp[now][j] = dp[now][j-1]^dp[pre][j-1]^dp[pre][j];
		ll len = 1;
		for(int j = 1;j<m;j++){
			if(dp[now][j]>=dp[now][j-1]){
				len++;
			}
			else len = 1;
			if(len>=p)total += min(q,len)-p+1;
//			cout<<len<<',';
		}
		
//		for(int j = 0;j<m;j++)cout<<dp[now][j]<<' ';
//		cout<<total<<endl;
	}
	for(int i = 0;i<m;i++)dp[now][i] = row[i];
	for(int i = 1;i<m;i++){
		swap(now,pre);
		dp[now][0] = col[i];
		for(int j = 1;j<m;j++)dp[now][j] = dp[now][j-1]^dp[pre][j-1]^dp[pre][j];
		ll len = 1;
		for(int j = 1;j<m;j++){
			if(dp[now][j]>=dp[now][j-1]){
				len++;
			}
			else len = 1;
			if(len>=p)total += min(len,q)-p+1;
		}
	}
	ll len = 1;
	for(int i = 1;i<m;i++){
		if(row[i]>=row[i-1])len++;
		else len = 1;
		if(len>=p)total += min(len,q)-p+1;
	}
	len = 1;
	for(int i = 1;i<m;i++){
		if(col[i]>=col[i-1])len++;
		else len = 1;
		if(len>=p)total += min(len,q)-p+1;
	}
//	cout<<total<<endl;
	if(one)total += m*m;
	else total += (m-1)*(m-1);
	cout<<total%n<<'\n';
	return 0;
}

