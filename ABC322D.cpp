#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

vector<string> rotate(vector<string> v){
	vector<string> tmp(4,string(4,'.'));
	for(int i = 0;i<4;i++){
		for(int j = 0;j<4;j++){
			tmp[j][3-i] = v[i][j];
		}
	}
	return tmp;
}

vector<string> board;

void dfs(int now,vector<string> piece[]){
	if(now == 3){
		for(auto &i:board){
			for(auto &j:i){
				if(j == '.')return;
			}
		}
		cout<<"Yes";
		exit(0);
	}
	for(int x = -4;x<=4;x++){
		for(int y = -4;y<=4;y++){
			bool flag = true;
			for(int i = 0;i<4;i++){
				for(int j = 0;j<4;j++){
					if(piece[now][i][j] == '.')continue;
					int px = x+i,py = y+j;
					if(px<0||px>=4||py<0||py>=4)flag = false;
					else if(board[px][py] == '#')flag = false;
				}
			}
			if(!flag)continue;
			for(int i = 0;i<4;i++){
				for(int j = 0;j<4;j++){
					if(piece[now][i][j] == '.')continue;
					board[x+i][y+j] = '#';
				}
			}
			dfs(now+1,piece);
			for(int i = 0;i<4;i++){
				for(int j = 0;j<4;j++){
					if(piece[now][i][j] == '.')continue;
					board[x+i][y+j] = '.';
				}
			}
		}
	}
	return;
}

void check(vector<string> piece[]){
	board = vector<string>(4,string(4,'.'));
	dfs(0,piece);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	vector<string> piece[3];
	for(int i = 0;i<3;i++){
		for(int j = 0;j<4;j++){
			string in;
			cin>>in;
			piece[i].push_back(in);
		}
	}
	for(int i = 0;i<64;i++){
		int tmp = i;
		vector<string> now[3];
		for(int j = 0;j<3;j++){
			now[j] = piece[j];
			for(int k = 0;k<tmp%4;k++){
				now[j] = rotate(now[j]);
			}
			tmp/=4;
		}
		check(now);
	}
	cout<<"No";
	return 0;
}
