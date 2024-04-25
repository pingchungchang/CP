#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> v(n+1,vector<int>(n+1,0));
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			char c;
			cin>>c;
			v[i][j] = v[i-1][j]+v[i][j-1]-v[i-1][j-1];
			if(c == '*'){
				v[i][j]++;
			}
		}
	}
	for(int i = 0;i<m;i++){
		int x1,x2,y2,y1;
		cin>>y1>>x1>>y2>>x2;
		cout<<v[y2][x2]+v[y1-1][x1-1]-v[y2][x1-1]-v[y1-1][x2]<<'\n';
	}
}
