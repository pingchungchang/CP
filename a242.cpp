#include <iostream>
using namespace std;
int v[101][101] = {};
int v2[101][101] = {};
int main(){
	int r,c;
	cin>>r>>c;
//	vector<vector<int>> v(r,vector<int>(c,0));
	for(int i =0;i<r;i++){
		for(int j =0;j<c;j++){
			cin>>v[i][j];
		}
	}
//	vector<vector<int>> v2(c,vector<int>(r,0));
	for(int i =0;i<r;i++){
		for(int j =0;j<c;j++){
			v2[j][i] = v[i][j];
		}
	}
	for(int i =0;i<c;i++){
		for(int j =0;j<r;j++){
			cout<<v2[i][j];
//			if(j !=r-1)cout<<' ';
			cout<<' ';
		}
		if(i != c-1)cout<<'\n';
	}
}
