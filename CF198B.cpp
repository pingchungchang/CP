#include <bits/stdc++.h>
using namespace std;

struct node{
	int side;
	int pos;
	int time;
	node(){
		side = -1;
		pos = -1;
		time = -1;
	}
	node(int a,int b,int c){
		side = a;
		pos = b;
		time = c;
	}
};
vector<string> v;
queue<node> q;
bool done = false;
vector<vector<bool>> goneto;
int n,m;
void bfs(){
	while(!q.empty()&&!done){
		node now = q.front();
		q.pop();
		if(now.pos+m>=n){
			done = true;
			break;
		}
		if(now.time+1<=now.pos-1&&v[now.side][now.pos-1] != 'X'&&goneto[now.side][now.pos-1] != true){
			goneto[now.side][now.pos-1] = true;
			q.push(node(now.side,now.pos-1,now.time+1));
		}
		if(v[now.side][now.pos+1] != 'X'&&goneto[now.side][now.pos+1] == false){
			goneto[now.side][now.pos+1] = true;
			q.push(node(now.side,now.pos+1,now.time+1));
		}
		if(v[now.side^1][now.pos+m] != 'X'&&goneto[now.side^1][now.pos+m] == false){
			goneto[now.side^1][now.pos+m] = true;
			q.push(node(now.side^1,now.pos+m,now.time+1));
		}
	}	
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	v = vector<string>(2);
	goneto = vector<vector<bool>>(2,vector<bool>(n+1,false));
	cin>>v[0]>>v[1];
	v[0]+= 'E';
	v[1]+= 'E';
	q.push(node(0,0,0));
	bfs();
	if(done)cout<<"YES";
	else cout<<"NO";
}
