#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	int n;
	cin>>n;
	vector<int> all(2*n);
	vector<vector<int> > req(n,vector<int>(3,0));
	for(int i = 0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		all[2*i] = a;
		all[2*i+1] = 1+b;
		req[i][1] = a;
		req[i][0] = b+1;
		req[i][2] = c;
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
//	for(int i = 0;i<all.size();i++)cout<<all[i]<<' ';
//	cout<<endl;
	for(int i = 0;i<n;i++){
		req[i][0] = (lower_bound(all.begin(),all.end(),req[i][0])-all.begin());
		req[i][1] = (lower_bound(all.begin(),all.end(),req[i][1])-all.begin());
	}
//	for(int i = 0;i<req.size();i++)cout<<req[i][0]<<' '<<req[i][1]<<' '<<req[i][2]<<',';
//	cout<<endl;
	vector<ll> dp(all.size(),0);
	sort(req.begin(),req.end());
	int now = 0;
	for(int i = 1;i<all.size();i++){
		dp[i] = dp[i-1];
//		cout<<req[now][0]<<' '<<i<<endl<<endl;
		while(now<n&&req[now][0]<=i){
			dp[i] = max(dp[i],dp[req[now][1]]+req[now][2]);
			now++;
		}
	}
//	for(int i = 0;i<all.size();i++)cout<<dp[i]<<' ';
//	cout<<"ans:\n";
	cout<<dp[dp.size()-1];
} 

/*
10
86 94 24
88 94 35
50 86 23
15 29 53
66 72 82
61 84 93
16 40 22
92 99 70
41 93 24
78 86 19
*/
