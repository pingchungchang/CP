#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> v;

bool check(int r,int c){
	if(r<=n-6){
		int total = 0;
		for(int i = 0;i<6;i++)total += v[r+i][c];
		if(total>=4)return true;
	}
	if(c<=n-6){
		int total = 0;
		for(int i = 0;i<6;i++)total += v[r][c+i];
		if(total>=4)return true;
	}
	if(r<=n-6&&c<=n-6){
		int total = 0;
		for(int i = 0;i<6;i++)total += v[r+i][c+i];
		if(total >=4)return true;
	}
	if(c<=n-6&&r>=5){
		int total = 0;
		for(int i = 0;i<6;i++)total += v[r-i][c+i];
		if(total>=4)return true;
	}
	return false;
}
int main(){
	cin>>n;
	v = vector<vector<int>>(n,vector<int>(n,0));
	for(int i = 0;i<n;i++){
		for(int j= 0;j<n;j++){
			char c;
			cin>>c;
			if(c == '#')v[i][j] = 1;
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(check(i,j)){
				cout<<"Yes";
				return 0;
			}
		}
	}
	cout<<"No";
	return 0;
}
