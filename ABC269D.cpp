#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const int mxn = 2010;
bitset<mxn> col[mxn];

void dfs(int r,int c){
	if(!col[r][c])return;
	col[r][c] = false;
	dfs(r+1,c+1);
	dfs(r,c+1);
	dfs(r,c-1);
	dfs(r-1,c-1);
	dfs(r+1,c);
	dfs(r-1,c);
}
int main(){
	io
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int a,b;
		cin>>a>>b;
		col[a+1005][b+1005] = true;
	}
	int ans =0;
//	cout<<endl;
//	return 0;
	for(int i = 1;i<mxn;i++){
		for(int j= 1;j<mxn;j++){
			if(col[i][j]){
//				cout<<i<<' '<<j<<endl;
				ans++;
				dfs(i,j);
			}
		}
	}
	cout<<ans;
}

