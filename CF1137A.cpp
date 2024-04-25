#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> v(n,vector<int>(m));
	vector<int> all;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>v[i][j];
		}
	}
	vector<int> row(n);
	vector<int> col(m);
	for(int i = 0;i<n;i++){
		vector<int> vv;
		for(int j = 0;j<m;j++)vv.push_back(v[i][j]);
		sort(vv.begin(),vv.end());
		vv.erase(unique(vv.begin(),vv.end()),vv.end());
		row[i] = vv.size();
	}
	for(int i = 0;i<m;i++){
		vector<int> vv;
		for(int j = 0;j<n;j++)vv.push_back(v[j][i]);
		sort(vv.begin(),vv.end());
		vv.erase(unique(vv.begin(),vv.end()),vv.end());
		col[i] = vv.size();
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cout<<max(row[i],col[j])<<' ';
		}
		cout<<'\n';
	}
}
