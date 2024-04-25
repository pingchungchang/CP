#include <bits/stdc++.h>
using namespace std;

vector<int> dsjset;
int main(){
	int n,m;
	cin>>n>>m;
	dsjset = vector<int>(n);
	for(int i = 0;i<n;i++)dsjset[i] = i;
	vector<vector<int>> req(m);
	for(int i = 0;i<m;i++){
		int k,a,b;
		cin>>k>>a>>b;
		a--,b--;
	}
}
