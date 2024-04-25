#include <bits/stdc++.h>
using namespace std;

#define printv; for(int asd=0;asd<v.size();asd++){for(int sd=0;sd<v[0].size();sd++){cout<<v[asd][sd];}cout<<endl;}
struct node{
	int x;
	int y;
	int time;
	node(int a,int b,int c){
		x = a;
		y = b;
		time = c;
	}
};
int main(){
	vector<string> v = {"*****************","*...*.......**..*","**..*....*.*.*..*","*......*.**.**.**","*..**...**..**.**","**.....**..*.*..*","*....*..........*","*.....****.*...**","****.*.*........*","*****************"};
	int fx,fy,sx,sy,t,ex,ey;
	cin>>fx>>fy>>t>>sx>>sy>>ex>>ey;
	queue<node> q;
	int ts = t;
	q.push(node(fx,fy,1));
	v[fx][fy] = 'X';
	v[ex][ey] = 'S';
	while(!q.empty()&&q.front().time != t){
		node now = q.front();
		q.pop();
		if(now.x>0&&v[now.x-1][now.y] == '.'){
			v[now.x-1][now.y] = 'X';
			q.push(node(now.x-1,now.y,now.time+1));
		}
		if(now.x<v.size()-1&&v[now.x+1][now.y] == '.'){
			v[now.x+1][now.y] = 'X';
			q.push(node(now.x+1,now.y,now.time+1));
		}
		if(now.y>0&&v[now.x][now.y-1]=='.'){
			v[now.x][now.y-1] = 'X';
			q.push(node(now.x,now.y-1,now.time+1));
		}
		if(now.y<v[0].size()-1&&v[now.x][now.y+1] == '.'){
			v[now.x][now.y+1] = 'X';
			q.push(node(now.x,now.y+1,now.time+1));
		}
	}
//	printv;
	queue<node> q2;
	q2.push(node(sx,sy,t));
	if(v[sx][sy] != '.'){
		cout<<"Help!";
		return 0;
	}
	while(!q2.empty()){
		t++;
		while(!q.empty()&&q.front().time!= t){
			node now = q.front();
			q.pop();
			if(now.x>0&&v[now.x-1][now.y] == '.'){
				v[now.x-1][now.y] = 'X';
				q.push(node(now.x-1,now.y,now.time+1));
			}
			if(now.x<v.size()-1&&v[now.x+1][now.y] == '.'){
				v[now.x+1][now.y] = 'X';
				q.push(node(now.x+1,now.y,now.time+1));
			}
			if(now.y>0&&v[now.x][now.y-1]=='.'){
				v[now.x][now.y-1] = 'X';
				q.push(node(now.x,now.y-1,now.time+1));
			}
			if(now.y<v[0].size()-1&&v[now.x][now.y+1] == '.'){
				v[now.x][now.y+1] = 'X';
				q.push(node(now.x,now.y+1,now.time+1));
			}			
		}
//		printv;
//		cout<<endl<<t<<endl;
		while(!q2.empty()&&q2.front().time != t){
			node now = q2.front();
			if(v[now.x][now.y] == 'S'){
				cout<<now.time-ts;
				return 0;
			}
			q2.pop();
			if(now.x>0&&(v[now.x-1][now.y] == '.'||v[now.x-1][now.y] == 'S')){
				q2.push(node(now.x-1,now.y,now.time+1));
			}
			if(now.x<v.size()-1&&(v[now.x+1][now.y] == '.'||v[now.x+1][now.y] == 'S')){
				q2.push(node(now.x+1,now.y,now.time+1));
			}
			if(now.y>0&&(v[now.x][now.y-1] == '.'||v[now.x][now.y-1] == 'S')){
				q2.push(node(now.x,now.y-1,now.time+1));
			}
			if(now.y<v[0].size()-1&&(v[now.x][now.y+1]=='.'||v[now.x][now.y+1] == 'S')){
				q2.push(node(now.x,now.y+1,now.time+1));
			}
		}
	}
	cout<<"Help!";
	return 0;
}
//1 1
//3
//4 1 3 3


