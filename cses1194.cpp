#include <bits/stdc++.h>
using namespace std;

typedef struct node{
	int x;
	int y;
	int t;
	node(int a,int b,int c){
		x = a;
		y = b;
		t = c;
	}
}node;
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<char>> goneto(n,vector<char>(m,'o'));
	vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
	pair<int,int> start;
	vector<vector<char>> v(n,vector<char>(m));
	queue<node> mons;
	for(int i =0;i<n;i++)for(int j =0;j<m;j++){
		cin>>v[i][j];
		if(v[i][j] == 'A'){
			start = make_pair(i,j);
			v[i][j] = '.';
			goneto[i][j] = 's';
		}
		if(v[i][j] == 'M'){
			mons.push(node(i,j,0));
		}
	}
//	for(int i =0;i<n;i++){
//		for(int j =0;j<m;j++)cout<<v[i][j];
//		cout<<endl;
//	}
	queue<node> q;
	q.push(node(start.first,start.second,0));
	pair<int,int> finish = make_pair(-1,-1);
	int time = 0;
	while(!q.empty()){
		while(!mons.empty()&&mons.front().t == time){
			node now= mons.front();
			mons.pop();
			for(int i =0;i<4;i++){
				pair<int,int> nxt = make_pair(now.x+dir[i].first,now.y+dir[i].second);
				if(nxt.first>=0&&nxt.second>=0&&nxt.second<m&&nxt.first<n&&v[nxt.first][nxt.second] == '.'){
					v[nxt.first][nxt.second] = 'M';
					mons.push(node(nxt.first,nxt.second,now.t+1));
				}
			}
		}
//		for(int i =0;i<n;i++){
//			for(int j  =0;j<m;j++)cout<<v[i][j];
//			cout<<endl;
//		}
		while(!q.empty()&&q.front().t == time){
			node now = q.front();
//			cout<<now.x<<' '<<now.y<<' '<<now.t<<endl;
			if(now.x == 0||now.x == n-1||now.y == 0||now.y == m-1){
				finish.first = now.x;
				finish.second = now.y;
				break;
			}
			q.pop();
			for(int i =0;i<4;i++){
				pair<int,int> nxt = make_pair(now.x+dir[i].first,now.y+dir[i].second);
				if(nxt.first>=0&&nxt.second>=0&&nxt.first<n&&nxt.second<m&&v[nxt.first][nxt.second] == '.'&&goneto[nxt.first][nxt.second] == 'o'){
					q.push(node(nxt.first,nxt.second,time+1));
					if(dir[i].first == 0&&dir[i].second == 1)goneto[nxt.first][nxt.second] = 'R';
					else if(dir[i].first ==0&&dir[i].second == -1)goneto[nxt.first][nxt.second] = 'L';
					else if(dir[i].first == 1)goneto[nxt.first][nxt.second] = 'D';
					else goneto[nxt.first][nxt.second] = 'U';	
				}
			}
		}

		if(finish.first != -1){
			break;
		}
		time++;
	}
	if(finish.first != -1){
		pair<int,int> now = finish;
		string pos;
		while(now.first != start.first||now.second != start.second){
//			cout<<now.first<<' '<<now.second<<' '<<pos<<endl;
			pos += goneto[now.first][now.second];
			if(goneto[now.first][now.second] == 'U'){
				now.first++;
			}
			else if(goneto[now.first][now.second] == 'D')now.first--;
			else if(goneto[now.first][now.second] == 'R')now.second--;
			else now.second++;
		}
		cout<<"YES\n";
		cout<<pos.size()<<'\n';
		reverse(pos.begin(),pos.end());
		cout<<pos;
	}
	else cout<<"NO";
}
