#include <bits/stdc++.h>
using namespace std;

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
	int t;
	cin>>t;
	for(int asd=0;asd<t;asd++){
		int n,m;
		cin>>n>>m;
		int dp[n][m];
		for(int i =0;i<n;i++){
			for(int j =0;j<m;j++){
				cin>>dp[i][j];
			}
		}
		int v[n][m] = {{0}};
//		for(int i =0;i<n;i++)cout<<v[i][0];
		queue<node> q;
		q.push(node(0,0,0));
		v[0][0]= -1;
		while(!q.empty()&&v[n-1][m-1] == 0){
			node now = q.front();
			cout<<now.x<<' '<<now.y<<' '<<now.time<<'\n';
			q.pop();
			if(now.x>0&&v[now.x-1][now.y] == 0&&abs(dp[now.x][now.y]-dp[now.x-1][now.y])<=5){
				v[now.x-1][now.y] = now.time+1;
				q.push(node(now.x-1,now.y,now.time+1));
			}
			if(now.x<n-1&&v[now.x+1][now.y] == 0&&abs(dp[now.x][now.y]-dp[now.x+1][now.y])<=5){
				v[now.x+1][now.y] = now.time+1;
				q.push(node(now.x+1,now.y,now.time+1));
			}
			if(now.y>0&&v[now.x][now.y-1] == 0&&abs(dp[now.x][now.y]-dp[now.x][now.y-1])<=5){
				v[now.x][now.y-1] = now.time+1;
				q.push(node(now.x,now.y-1,now.time+1));
			}
			if(now.y<m-1&&v[now.x][now.y+1] == 0&&abs(dp[now.x][now.y]-dp[now.x][now.y+1])<=5){
				v[now.x][1+now.y] = now.time+1;
				q.push(node(now.x,1+now.y,now.time+1));
			}
		}
		cout<<v[n-1][m-1]<<'\n';
	}
}
