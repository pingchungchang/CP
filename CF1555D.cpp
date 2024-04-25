#include <bits/stdc++.h>
using namespace std;


vector<string> cycles = {"abc","acb","bac","bca","cab","cba"};
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	vector<vector<int>> ans(6,vector<int>(n+1,0));
	
	for(int i = 0;i<n;i++){
		for(int j = 0;j<6;j++){
			ans[j][i+1] = ans[j][i];
			if(cycles[j][i%3] != s[i])ans[j][i+1]++;
		}
	}
	for(int i = 0;i<m;i++){
		int l,r;
		cin>>l>>r;
		int tmp = INT_MAX;
		for(int i = 0;i<6;i++){
			tmp = min(tmp,ans[i][r]-ans[i][l-1]);
		}
		cout<<tmp<<'\n';
	}
}
