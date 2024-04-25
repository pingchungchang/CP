#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,t;
	cin>>n>>t;
	vector<vector<int> > dir = {{0,-1},{-1,0},{0,1},{1,0}};
	vector<vector<int>> v(n,vector<int>(n));
	for(int i = 0;i<n;i++)for(int j = 0;j<n;j++)cin>>v[i][j];
	vector<int> now = {n/2,n/2};
	for(int i = 1;i<n;i++){
		for(int j = 0;j<2;j++){
			for(int k = 0;k<i;k++){
				cout<<v[now[0]][now[1]];
				now[0]+= dir[t][0];
				now[1]+= dir[t][1];
			}
			t = (t+1)%4;
		}
	}
	for(int i = 0;i<n;i++){
		cout<<v[now[0]][now[1]];
		now[0]+= dir[t][0];
		now[1]+= dir[t][1];
	}
}
