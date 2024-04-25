#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> ans(m);
	for(int i = 0;i<m;i++)cin>>ans[i];
	for(int asd = 0;asd<n;asd++){
		vector<int> v(m+1);
		for(int i =0;i<m+1;i++)cin>>v[i];
		vector<int> vv(m);
		if(v[m]>=v[m-1])vv[m-1] = 1;
		else vv[m-1] = 0;
		for(int i = m-2;i>=0;i--){
			int dif = abs(v[i+1]-v[i+2]);
			if(dif>=v[i])vv[i]=1;
			else vv[i] =0;
		}
		for(int i = 0;i<m;i++){
			if(vv[i] != ans[i])break;
			if(i == m-1){
				for(int j = 0;j<m+1;j++)cout<<v[j]<<' ';
				return 0;
			}
		}
	}
}
