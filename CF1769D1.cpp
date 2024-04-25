#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define endl '\n'

const int mxn = 9;
const int MX = 50;
int dp[2][MX][MX][MX][MX];
map<char,int> mp;
int player[4][mxn];

int dfs(int turn,int w,int x,int y,int z){
	if(dp[turn][w][x][y][z] != -1)return dp[turn][w][x][y][z];
	int sw = w/mxn,ew = w%mxn,sx = x/mxn,ex = x%mxn,sy = y/mxn,ey = y%mxn,sz = z/mxn,ez = z%mxn;

	bool win = true;
	for(int i = 0;i<mxn;i++){
		if(player[0][i] == turn&&(sw>i||ew<i))win = false;
		if(player[0][i] == turn&&w == 40)win = false;
	}
	for(int i = 0;i<mxn;i++){
		if(player[1][i] == turn&&(sx>i||ex<i))win = false;
		if(player[1][i] == turn&&x == 40)win = false;
	}
	for(int i = 0;i<mxn;i++){
		if(player[2][i] == turn&&(sy>i||ey<i))win = false;
		if(player[2][i] == turn&&y == 40)win = false;
	}
	for(int i = 0;i<mxn;i++){
		if(player[3][i] == turn&&(sz>i||ez<i))win = false;
		if(player[3][i] == turn&&z == 40)win = false;
	}
	if(win){
		//cout<<turn<<' '<<w<<' '<<x<<' '<<y<<' '<<z<<' '<<turn<<endl;
		return dp[turn][w][x][y][z] = turn;
	}

	dp[turn][w][x][y][z] = turn^1;
	bool flag = false;
	if(w != 40){
		if(sw>0&&player[0][sw-1] == turn){
			flag = true;
			int tmp = dfs(turn^1,w-mxn,x,y,z);
			if(tmp == turn)dp[turn][w][x][y][z] = turn;
		}
		if(ew < mxn-1&&player[0][ew+1] == turn){
			flag = true;
			int tmp = dfs(turn^1,w+1,x,y,z);
			if(tmp == turn)dp[turn][w][x][y][z] = turn;
		}

	}
	else if(player[0][3] == turn){
		flag = true;
		int tmp = dfs(turn^1,30,x,y,z);
		if(tmp == turn)dp[turn][w][x][y][z] = turn;
	}

	if(x != 40){
		if(sx>0&&player[1][sx-1] == turn){
			flag = true;
			int tmp = dfs(turn^1,w,x-mxn,y,z);
			if(tmp == turn)dp[turn][w][x][y][z] = turn;
		}
		if(ex !=mxn-1&&player[1][ex+1] == turn){
			flag = true;
			int tmp = dfs(turn^1,w,x+1,y,z);
			if(tmp == turn)dp[turn][w][x][y][z] = turn;
		}
	}
	else if(player[1][3] == turn){
		flag = true;
		int tmp = dfs(turn^1,w,30,y,z);
		if(tmp == turn)dp[turn][w][x][y][z] = turn;
	}

	if(y != 40){
		if(sy != 0&&player[2][sy-1] == turn){
			flag = true;
			int tmp = dfs(turn^1,w,x,y-mxn,z);
			if(tmp == turn)dp[turn][w][x][y][z] = turn;
		}
		if(ey !=mxn-1&&player[2][ey+1] == turn){
			flag = true;
			int tmp = dfs(turn^1,w,x,y+1,z);
			if(tmp == turn)dp[turn][w][x][y][z] = turn;
		}
	}
	else if(player[2][3] == turn){
		flag = true;
		int tmp = dfs(turn^1,w,x,30,z);
		if(tmp == turn)dp[turn][w][x][y][z] = turn;
	}

	if(z != 40){
		if(sz > 0&&player[3][sz-1] == turn){
			flag = true;
			int tmp = dfs(turn^1,w,x,y,z-mxn);
			if(tmp == turn)dp[turn][w][x][y][z] = turn;
		}
		if(ez !=mxn-1&&player[3][ez+1] == turn){
			flag = true;
			int tmp = dfs(turn^1,w,x,y,z+1);
			if(tmp == turn)dp[turn][w][x][y][z] = turn;
		}
	}
	else if(player[3][3] == turn){
		flag = true;
		int tmp = dfs(turn^1,w,x,y,30);
		if(tmp == turn)dp[turn][w][x][y][z] = turn;
	}

	if(flag){

		/*
		cout<<turn<<' '<<w<<' '<<x<<' '<<y<<' '<<z<<":";
		cout<<dp[turn][w][x][y][z]<<endl;
	   */
		return dp[turn][w][x][y][z];
	}
	int tmp = dfs(turn^1,w,x,y,z);
	dp[turn][w][x][y][z] = tmp;
	/*
	cout<<turn<<' '<<w<<' '<<x<<' '<<y<<' '<<z<<":";
	cout<<tmp<<endl;

   */
	return tmp;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(dp,-1,sizeof(dp));
	for(char c = '6';c<='9';c++)mp[c] = c-'6';
	mp['T'] = 4,mp['J'] = 5,mp['Q'] = 6,mp['K'] = 7;mp['A'] = 8;
	mp['C'] = 0,mp['S'] = 1,mp['D'] = 2,mp['H'] = 3;
	for(auto &i:player)for(auto &j:i)j = 1;
	for(int i = 0;i<18;i++){
		string s;
		cin>>s;
		int x = mp[s[0]],y = mp[s[1]];
		player[y][x] = 0;
	}
	for(int i = 0;i<18;i++){
		string s;
		cin>>s;
		int x = mp[s[0]],y = mp[s[1]];
		player[y][x] = 1;
	}
	/*
	for(int i = 0;i<4;i++){
		for(int j = 0;j<mxn;j++)cout<<player[i][j]<<' ';cout<<endl;
	}

   */
	int tmp = dfs(0,40,40,40,40);
	if(tmp == 0)cout<<"Alice";
	else cout<<"Bob";
	return 0;
}
