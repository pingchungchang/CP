#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

map<vector<string>,string> mp;

vector<string> v(3,"...");

bool check(char turn){
	for(int i = 0;i<3;i++){
		if(v[i][0] == v[i][1]&&v[i][1] == v[i][2] &&v[i][0] == turn)return true;
		if(v[0][i] == v[1][i]&&v[1][i] == v[2][i] &&v[0][i] == turn)return true;
	}
	if(v[0][0] == v[1][1]&&v[1][1] == v[2][2] &&v[0][0] == turn)return true;
	if(v[0][2] == v[1][1]&&v[1][1] == v[2][0]&&v[1][1] == turn)return true;
	return false;
}

void dfs(char turn){
	mp[v] = (turn == 'X'?"first":"second");
	bool flag = false;
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			if(v[i][j] != '.')continue;
			flag = true;
			v[i][j] = turn;
			if(check(turn)){
				mp[v] = string()+"the "+(turn == 'X'?"first":"second")+" player won";
			}
			else dfs(turn == 'X'?'0':'X');
			v[i][j] = '.';
		}
	}
	if(!flag)mp[v] = "draw";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	dfs('X');
	vector<string> vv(3);
	for(auto &i:vv)cin>>i;
	if(mp.find(vv) ==mp.end())cout<<"illegal";
	else cout<<mp[vv];
}
