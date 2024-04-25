#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
int sparse[mxn][21];
const int inf = 2e9;

int getval(int s,int e){
	int d= e-s+1;
	int cnt = 0;
	while(d){
		d>>=1;
		cnt++;
	}
	cnt--;
//	cout<<cnt<<',';
	return min(sparse[s][cnt],sparse[e-(1<<cnt)+1][cnt]);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(auto &i:sparse)for(auto &j:i)j = inf;
	int n,q;
	cin>>n>>q;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		sparse[i][0] = k;
	}
	for(int i = 1;i<=20;i++){
		for(int j = 0;j<n-(1<<(i-1));j++){
			sparse[j][i] = min(sparse[j][i-1],sparse[j+(1<<(i-1))][i-1]);
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		s--,e--;
		cout<<getval(s,e)<<'\n';
	}
//	for(int i = 0;i<10;i++){
//		for(int j = 0;j<n;j++)cout<<sparse[j][i]<<' ';cout<<'\n';
//	}
	return 0;
}
