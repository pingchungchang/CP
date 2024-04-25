#include <bits/stdc++.h>
using namespace std;



vector<vector<int>> v;
void getval(int i,int j){
	if(v[i][j] == 1){
		cout<<"X";
		return;
	}
	int cnt = 0;
	for(int a = -1;a<=1;a++){
		for(int b = -1;b<=1;b++){
			if(v[i+a][j+b] == 1)cnt++;
		}
	}
	cout<<cnt;
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	while(cin>>n>>m){
		v = vector<vector<int>>(n+2,vector<int>(m+2,0));
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=m;j++){
				cin>>v[i][j];
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=m;j++){
				getval(i,j);
				if(j != m)cout<<' ';
			}
			cout<<'\n';
		}
	}
}
