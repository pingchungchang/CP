#include <bits/stdc++.h>
using namespace std;
// c array is faster that vector
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	int v[n][31] = {};
//	vector<vector<int>> v(n,vector<int>(31));
	for(int i =0;i<n;i++){
		int a;
		cin>>a;
		a--;
		v[i][0] = a;
	}
	for(int i =1;i<31;i++){
		for(int j =0;j<n;j++){
			v[j][i] = v[v[j][i-1]][i-1];
		}
	}
	for(int i =0;i<q;i++){
		int a,b;
		cin>>a>>b;
		a--;
		int k = 1;
		for(int j =0;j<31;j++){
			if((k&b) != 0){
				a = v[a][j];
			}
			k<<=1;
		}
		cout<<a+1<<'\n';
	}
}
