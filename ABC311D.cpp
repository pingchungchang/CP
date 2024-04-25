#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 202;
string arr[mxn];
bool vis[mxn][mxn],done[mxn][mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	queue<pii> q;
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>arr[i];
	pii d[] = {{0,1},{0,-1},{1,0},{-1,0}};
	q.push({1,1});
	done[1][1] = vis[1][1] = 1;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto &i:d){
			pii tmp = now;
			do{
				vis[tmp.fs][tmp.sc] = true;
				tmp.fs += i.fs;
				tmp.sc += i.sc;
			}while(arr[tmp.fs][tmp.sc] != '#');
			tmp.fs -= i.fs;
			tmp.sc -= i.sc;
			if(!done[tmp.fs][tmp.sc]){
				done[tmp.fs][tmp.sc] = true;
				q.push(tmp);
			}
		}
	}
	int ans = 0;
	for(int i = 0;i<n;i++)for(int j =0;j<m;j++)if(vis[i][j])ans++;
	cout<<ans;
}
