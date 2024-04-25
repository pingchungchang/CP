#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &v){
	auto tmp = v;
	for(int i = 0;i<v.size();i++){
		for(int j = 0;j<v[0].size();j++){
			v[i][j] = tmp[v.size()-j-1][i];
		}
	}
	return;
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> v(n,vector<int>(n));
	auto tar = v;
	for(auto &i:v)for(auto &j:i)cin>>j;
	for(auto &i:tar)for(auto &j:i)cin>>j;
	for(int i = 0;i<4;i++){
		/*
		for(auto &j:v){
			for(auto &k:j)cout<<k<<' ';cout<<endl;
		}
		cout<<endl;
		*/
		bool flag =true;
		for(int j = 0;j<n;j++){
			for(int k = 0;k<n;k++){
				if(v[j][k]&&!tar[j][k]){
					flag = false;
				}
			}
		}
		if(flag){
			cout<<"Yes";
			return 0;
		}
		rotate(v);
	}
	cout<<"No";
}
