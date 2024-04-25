#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> v(n,vector<int>(m));
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>v[i][j];
		}
	}
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
	for(int i = 1;i<n;i++){
		pq.push(make_pair(v[i][0],make_pair(i,0)));
		pq.push(make_pair(v[i][m-1],make_pair(i,m-1)));
	}
	for(int j = 1;j<n;j++){
		pq.push(make_pair(v[0][j],make_pair(0,j)));
		pq.push(make_pair(v[n-1][j],make_pair(n-1,j)));
	}
	while(!pq.empty()){
		pair<int,int> now = pq.top().second;
		int val = pq.top().first;
		pq.pop();
	}
}
