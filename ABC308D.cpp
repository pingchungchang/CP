#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 505;
bool vis[mxn][mxn][5];
string arr[mxn];
string tar = "snuke";
pii dir[] = {{0,1},{0,-1},{-1,0},{1,0}};

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		arr[i] = "#"+arr[i]+"#";
	}
	arr[0] = arr[n+1] = string(m+2,'#');
	queue<pair<pii,int>> q;
	if(arr[1][1] != 's'){
		cout<<"No";
		return 0;
	}
	vis[1][1][0] = true;
	q.push(make_pair(make_pair(1,1),0));
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		now.sc = (now.sc == 4?0:now.sc+1);
		for(auto &i:dir){
			pii nxt = {now.fs.fs+i.fs,now.fs.sc+i.sc};
			if(vis[nxt.fs][nxt.sc][now.sc]||arr[nxt.fs][nxt.sc] != tar[now.sc])continue;
			vis[nxt.fs][nxt.sc][now.sc] = true;
			q.push({nxt,now.sc});
		}
	}
	bool ans = false;
	for(auto &i:vis[n][m])ans = ans|i;
	if(ans)cout<<"Yes";
	else cout<<"No";
	return 0;
}
