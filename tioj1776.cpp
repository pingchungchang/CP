#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

vector<int> v;
const int mxn = 17;
bool no[mxn][mxn][3][3];
int n,m;

void dfs(){
	if(v.size() == n){
		cout<<"yes\n";
		for(auto &i:v)cout<<i+1<<'\n';
		exit(0);
		return;
	}
	for(int i = 0;i<3;i++){
		bool flag = true;
		for(int j = 0;j<v.size();j++){
			if(no[v.size()][j][i][v[j]])flag = false;
		}
		if(flag){
			v.push_back(i);
			dfs();
			v.pop_back();
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a--,b--,c--,d--;
		no[a][c][b][d] = no[c][a][d][b] = 1;
	}
	dfs();
	cout<<"no";
}
