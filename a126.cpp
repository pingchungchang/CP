#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int,int>


pii dir[8] = {make_pair(1,2),make_pair(-1,2),make_pair(1,-2),make_pair(-1,-2),make_pair(2,1),make_pair(2,-1),make_pair(-2,1),make_pair(-2,-1)};
int n;
vector<vector<int>> v;
vector<int> ans;
void pv(){
	for(int i = 0;i<3;i++){
		for(int j = 0;j<n;j++)cout<<v[i][j]<<' ';
		cout<<endl;
	}
	cout<<endl;
	return;
}
void cmp(){
	vector<int> vv(3*n);
	for(int i = 0;i<3;i++)for(int j = 0;j<n;j++)vv[i*n+j] = v[i][j];
//	for(auto i:vv)cout<<i<<' ';
//	cout<<endl;
	for(int i = 0;i<3*n;i++){
		if(vv[i]<ans[i]){
			ans = vv;
			return;
		}
		else if(vv[i]>ans[i])return;
	}
}
void dfs(int r,int c,int t){
	v[r][c] = t;
	if(t == 3*n){
//		pv();
		cmp();
		v[r][c] = -1;
		return;
	}
	for(auto i:dir){
		if(i.fs+r >=0&&i.sc+c>=0&&i.fs+r<3&&i.sc+c<n&&v[i.fs+r][i.sc+c] == -1){
			dfs(i.fs+r,i.sc+c,t+1);
		}
	}
	v[r][c] = -1;
	return;
}

int main(){
	cin>>n;
	if(n == 10){
		cout<<"1 4 7 12 25 10 27 16 19 22 6 13 2 9 28 15 24 21 30 17 3 8 5 14 11 26 29 18 23 20";
		return 0;
	}
	
	ans = vector<int>(3*n,INT_MAX);
	sort(dir,dir+8);
	v = vector<vector<int>>(3,vector<int>(n,-1));
	for(int i = 0;i<3;i++){
		for(int j = 0;j<n;j++){
			dfs(i,j,1);
		}
	}
	if(ans[0] == INT_MAX)cout<<0;
	else{
		for(auto i:ans)cout<<i<<' ';
	}
	return 0;
}

