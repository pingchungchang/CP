#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1010;
int arr[mxn][mxn];
pii dir[] = {{0,1},{0,-1},{1,0},{-1,0}};
queue<pii> q;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(arr,-1,sizeof(arr));
	int m,n;
	cin>>m>>n;
	for(int i = 0;i<n;i++){
		int a,b;
		cin>>a>>b;
		arr[a][b] = -2;
	}
	pii s,e;
	cin>>s.fs>>s.sc>>e.fs>>e.sc;
	if(arr[s.fs][s.sc] == -2){
		cout<<"-1\n";
		return 0;
	}
	arr[s.fs][s.sc] = 0;
	q.push(s);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto d:dir){
			pii nxt = {now.fs+d.fs,now.sc+d.sc};
			if(nxt.fs<=0||nxt.fs>m||nxt.sc<0||nxt.sc>m)continue;
			if(arr[nxt.fs][nxt.sc] == -1){
				arr[nxt.fs][nxt.sc] = arr[now.fs][now.sc]+1;
				q.push(nxt);
			}
		}
	}
	cout<<(arr[e.fs][e.sc]<0?-1:arr[e.fs][e.sc]);
}
