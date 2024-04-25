#include <bits/stdc++.h>
using namespace std;

struct node{
	int x;
	int y;
	int time;
	node(int a,int b,int c){
		x = a;
		y=b;
		time = c;
	}
};
int main(){
	int t;
	cin>>t;
	for(int asd=0;asd<t;asd++){
		int n,m;
		cin>>n>>m;
		vector<vector<int>> v(n,vector<int>(m,0));
		vector<vector<int>> dist(n,vector<int>(m,-1));
		for(int i =0;i<n;i++){
			for(int j =0;j<m;j++){
				int k;
				cin>>k;
				v[i][j] = k;
//				cout<<v[i][j]<<' ';
			}
//			cout<<endl;
		}
		queue<node> q;
		dist[0][0] = 0;
		q.push(node(0,0,0));
		while(!q.empty()&&dist[n-1][m-1] == -1){
			node now = q.front();
//			cout<<now.x<<' '<<now.y<<' '<<v[now.x][now.y]<<'\n';
			q.pop();
			if(now.x>0&&dist[now.x-1][now.y] == -1&&abs(v[now.x-1][now.y]-v[now.x][now.y])<=5){
				dist[now.x-1][now.y] = now.time+1;
				q.push(node(now.x-1,now.y,now.time+1));
			}
			if(now.x<n-1&&dist[now.x+1][now.y] == -1&&abs(v[now.x+1][now.y]-v[now.x][now.y])<=5){
				dist[now.x+1][now.y] = now.time+1;
				q.push(node(now.x+1,now.y,now.time+1));
			}
			if(now.y>0&&dist[now.x][now.y-1] == -1&&abs(v[now.x][now.y-1]-v[now.x][now.y])<=5){
				dist[now.x][now.y-1] = now.time+1;
				q.push(node(now.x,now.y-1,now.time+1));
			}
			if(now.y<m-1&&dist[now.x][now.y+1] == -1&&abs(v[now.x][now.y+1]-v[now.x][now.y])<=5){
				dist[now.x][now.y+1] = now.time+1;
				q.push(node(now.x,now.y+1,now.time+1));
			}
		}
		cout<<dist[n-1][m-1]<<'\n';	
	}
}
