#include <bits/stdc++.h>
using namespace std;

struct player{
	vector<vector<int>> b;
	int win;
	string id;
	player(){
		b = vector<vector<int>>(4,vector<int>(4,0));
		win = -1;
	}
};
void add(vector<vector<int>> &v,int now){
	for(int i = 0;i<4;i++)for(int j = 0;j<4;j++)if(v[i][j] == now)v[i][j] = -1;
}
void check(player &p){
	bool returns = false;
	for(int i = 0;i<4;i++){
		
		for(int j = 1;j<4;j++){
			if(p.b[i][j] == p.b[i][j-1]&&j == 3)returns = true;
			else if(p.b[i][j] != p.b[i][j-1])break;
		}
		for(int j = 1;j<4;j++){
			if(p.b[j][i] == p.b[j-1][i] &&j == 3)returns = true;
			else if(p.b[j][i] != p.b[j-1][i])break;
		}
	}
	
	for(int i = 1;i<4;i++){
		if(p.b[i][i] == p.b[i-1][i-1]&&i == 3)returns = true;
		else if(p.b[i][i] != p.b[i-1][i-1])break;
	}
	
	for(int i = 1;i<4;i++){
		if(p.b[i-1][4-i] == p.b[i][3-i]&&i == 3)returns = true;
		else if(p.b[i-1][4-i] != p.b[i][3-i])break;
	}
	if(returns)p.win = 1;
	return;
}
int main(){
	string c;
	int n;
	cin>>c>>n;
	vector<player> p(n);
	for(int i = 0;i<n;i++){
		cin>>p[i].id;
		for(int j = 0;j<4;j++)for(int k = 0;k<4;k++)cin>>p[i].b[j][k];
	}
	cin>>c;
	bool wins = false;
	for(int asd = 0;asd<16;asd++){
		int now;
		cin>>now;
		cout<<now<<' ';
		for(int i = 0;i<n;i++){
			add(p[i].b,now);
		}
		for(int i = 0;i<n;i++){
			check(p[i]);
			if(p[i].win != -1){
				wins = true;
				cout<<p[i].id<<' ';
			}
		}
		if(wins)return 0;
	}
}
