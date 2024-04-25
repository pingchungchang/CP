#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> v;
	for(int i = 1;i<=n*2;i++){
		if(i<=n)v.push_back(i);
		else v.push_back(i-n);
	}
	vector<vector<int>> result(n+1,vector<int>(n+1,-1));
	if(n&1){
		for(int i = 0;i<n;i++){
			for(int j = 1;j<=n/2;j++){
				// cout<<v[i]<<":"<<v[j+i]<<endl;
				result[v[i]][v[i+j]] = 1;
			}
		}
	}
	else{
		for(int i = 0;i<n;i++){
			for(int j = 1;j<n/2;j++)result[v[i]][v[i+j]] = 1;
			result[v[i]][v[i+n/2]] = 0;
			for(int j = n/2+1;j<n;j++)result[v[i]][v[i+j]] = -1;
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++)cout<<result[i][j]<<' ';
	}
	cout<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
}