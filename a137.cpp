#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

pii dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};
int main(){
	io
	int r,c;
	cin>>r>>c;
	int sr,sc,er,ec;
	cin>>sr>>sc>>er>>ec;
	vector<vector<int>> v(r+2,vector<int>(c+2,INT_MAX));
	sr++,sc++,er++,ec++;
	v[sr][sc] = 0;
	v[er][ec] = 0;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v[a+1][b+1] = c;
	}
	vector<vector<int>> goneto(r+2,vector<int>(c+2,INT_MAX));
	goneto[sr][sc] = 0;
	priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pq;
	pq.push(make_pair(0,make_pair(sr,sc)));
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
//		cout<<now.sc.fs<<' '<<now.sc.sc<<' '<<now.fs<<'\n';
		for(auto i:dir){
			if(v[now.sc.fs+i.fs][now.sc.sc+i.sc] == INT_MAX||goneto[now.sc.fs+i.fs][now.sc.sc+i.sc] != INT_MAX)continue;
			goneto[now.sc.fs+i.fs][now.sc.sc+i.sc] = max(now.fs,v[now.sc.fs+i.fs][now.sc.sc+i.sc]);
			pq.push(make_pair(max(now.fs,v[now.sc.fs+i.fs][now.sc.sc+i.sc]),make_pair(now.sc.fs+i.fs,now.sc.sc+i.sc))); 
		}
	} 
//	for(int i = 1;i<=r;i++){
//		for(int j = 1;j<=c;j++){
//			if(v[i][j] == INT_MAX)cout<<-1<<' ';
//			else cout<<v[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	for(int i = 1;i<=r;i++){
//		for(int j = 1;j<=c;j++){
//			if(goneto[i][j] == INT_MAX)cout<<setw(5)<<"-1 ";
//			else cout<<setw(5)<<goneto[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	cout<<goneto[er][ec];
}

