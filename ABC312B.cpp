#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

string tar[9];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(auto &i:tar)i = string(9,'?');
	for(int i = 0;i<3;i++)for(int j = 0;j<3;j++)tar[i][j] = '#';
	for(int i = 6;i<9;i++)for(int j = 6;j<9;j++)tar[i][j] = '#';
	for(int i = 0;i<4;i++)tar[3][i] = tar[i][3] = tar[8-i][5] = tar[5][8-i] = '.';
	int n,m;
	cin>>n>>m;
	string arr[n];
	for(auto &i:arr)cin>>i;
	vector<pii> ans;
	for(int i = 0;i<=n-9;i++){
		for(int j = 0;j<=m-9;j++){
			bool flag = true;
			for(int k = 0;k<9;k++)for(int kk = 0;kk<9;kk++){
				if(tar[k][kk] == '?')continue;
				if(tar[k][kk] != arr[i+k][j+kk])flag = false;
			}
			if(flag)ans.push_back({i+1,j+1});
		}
	}
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return 0;
}
