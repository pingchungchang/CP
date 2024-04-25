#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1010;
string arr[mxn];
pii pre[mxn][mxn];
int dist[mxn][mxn];
pii dir[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)};

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	arr[0] = string(m+2,'#');
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		arr[i] = "#"+arr[i]+"#";
	}
	arr[n+1] = arr[0];
	pii s,e;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(arr[i][j] == 'A')s = {i,j};
			else if(arr[i][j] == 'B')e = {i,j};
		}
	}
	//for(int i = 0;i<=n+1;i++)cout<<arr[i]<<'\n';
	memset(dist,-1,sizeof(dist));
	queue<pii> lolli;
	lolli.push(s);
	dist[s.fs][s.sc] = 0;
	pre[s.fs][s.sc] = {0,0};
	while(!lolli.empty()){
		auto now = lolli.front();
		//cout<<now.fs<<' '<<now.sc<<endl;
		lolli.pop();
		for(auto dd:dir){
			pii nxt = {now.fs+dd.fs,now.sc+dd.sc};
			if(dist[nxt.fs][nxt.sc] == -1&&arr[nxt.fs][nxt.sc] != '#'){
				pre[nxt.fs][nxt.sc] = now;
				dist[nxt.fs][nxt.sc] = dist[now.fs][now.sc]+1;
				lolli.push(nxt);
			}
		}
	}
	if(dist[e.fs][e.sc] == -1){
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	cout<<dist[e.fs][e.sc]<<'\n';
	string ss;
	auto now = e;
	while(pre[now.fs][now.sc].fs != 0){
		auto p = pre[now.fs][now.sc];
		if(p.fs+1 == now.fs)ss += 'D';
		else if(p.fs-1 == now.fs)ss += 'U';
		else if(p.sc+1 == now.sc)ss += 'R';
		else ss += 'L';
		now = pre[now.fs][now.sc];
	}
	reverse(ss.begin(),ss.end());
	cout<<ss;
	return 0;
}
