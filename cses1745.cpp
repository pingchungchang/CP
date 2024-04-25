#include <bits/stdc++.h>
using namespace std;

int dp[100001] = {};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	set<int> ans;
	int n;
	cin>>n;
	dp[0] = 1;
	for(int asd =0;asd<n;asd++){
		int k;
		cin>>k;
		for(int i =100000;i>=k;i--){
			if(dp[i-k] !=0&&dp[i] == 0){
				dp[i] = 1;
				ans.insert(i);	
			}		}
	}
	cout<<ans.size()<<'\n';
	for(auto it = ans.begin();it != ans.end();it++){
		cout<<*it<<' ';
	}
}
//4
//4 2 5 2
