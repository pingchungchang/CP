#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,k,r,c;
	cin>>n>>k>>r>>c;
	r--,c--;
	vector<vector<int>> v(n*3,vector<int>(n*3,0));
	for(int i = 0;i<n*3;i+=k){
		for(int j = 0;j<n*3;j++){
			int x = i+j,y = j;
			if(x>=n*3||x<0||y>=n*3||y<0)break;
			v[x][y] = 1;
		}
		for(int j = 0;j<n*3;j++){
			int x = j,y = i+j;
			if(x>=n*3||x<0||y>=n*3||y<0)break;
			v[x][y] = 1;
		}
	}
	bool flag = false;
	for(int i = n;i<n*2;i++){
		if(flag)break;
		for(int j = n;j<n*2;j++){
			if(v[i][j]){
				r = i-r;
				c = j-c;
				flag = true;
				break;
			}
		}
	}
	//cout<<r<<' '<<c<<'\n';
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(v[i+r][j+c])cout<<"X";
			else cout<<".";
		}
		cout<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
