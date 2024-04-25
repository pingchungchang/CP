#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m,n;
	cin>>m>>n;
	vector<vector<int>> v(m,vector<int>(n,0));
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			cin>>v[i][j];
			if(i != 0&&v[i][j] != 0)v[i][j]+= v[i-1][j];
		}
	}
	int ans = 0;
	for(int i = 0;i<m;i++){
		for(int j = n-1;j>=0;j--){
			int smallest = v[i][j];
			for(int k = j;k>=0;k--){
				smallest = min(smallest,v[i][k]);
				int nowans = smallest*(j-k+1);
				ans = max(ans,nowans);
			}
		}
	}
	cout<<ans;	
}

