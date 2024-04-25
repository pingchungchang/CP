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

void pv(vector<vector<int>> v){
	for(int i = 0;i<v.size();i++){
		for(int j = 0;j<v[0].size();j++){
			cout<<v[i][j]<<' ';
		}
		cout<<' ';
	}	
	cout<<'\n';
	return;
}
struct node{
	int r;
	int c;
	vector<vector<int>> board;
	int t;
	node(int a,int b,int x,vector<vector<int>> vv){
		r = a;
		c = b;
		t = x;
		board = vv;
	}
};
int main(){
	cin>>n;
	sort(dir,dir+8);
	queue<node> q;
	for(int i = 0;i<3;i++){
		for(int j= 0;j<n;j++){
			vector<vector<int>> v(3,vector<int>(n,-1));
			v[i][j] = 1;
			q.push(node(i,j,1,v));
		}
	}
	while(!q.empty()){
		node now = q.front();
		q.pop();
		for(auto i:dir){
			if(now.t == n*3){
				pv(now.board);
				return 0;
			}
			if(now.r+i.fs>=0&&now.c+i.sc>=0&&now.r+i.fs<3&&now.c+i.sc<n&&now.board[now.r+i.fs][now.c+i.sc]== -1){
				now.board[now.r+i.fs][now.c+i.sc] = now.t+1;
				node nxt = node(now.r+i.fs,now.c+i.sc,now.t+1,now.board);
				q.push(nxt);
				now.board[now.r+i.fs][now.c+i.sc] = -1;
			}
		}
	}
	cout<<0;
}

