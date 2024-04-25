#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1010;
pii arr[mxn][mxn];
pii dir[mxn][mxn];
pii dx[] = {{0,1},{0,-1},{1,0},{-1,0}};

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cin>>arr[i][j].fs>>arr[i][j].sc;
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(arr[i][j].fs == -1){
				bool flag = false;
				for(auto &d:dx){
					pii nxt = {i+d.fs,j+d.sc};
					if(arr[nxt.fs][nxt.sc].fs == -1){
						dir[i][j] = d;
						flag = true;
						break;
					}
				}
				if(!flag){
					cout<<"INVALID";
					return 0;
				}
			}
		}
	}
	queue<pii> q;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(arr[i][j].fs == i&&arr[i][j].sc == j)q.push({i,j}),dir[i][j] = {2,2};
		}
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto &i:dx){
			pii nxt = {-i.fs+now.fs,-i.sc+now.sc};
			if(dir[nxt.fs][nxt.sc].fs+dir[nxt.fs][nxt.sc].sc != 0)continue;
			if(arr[nxt.fs][nxt.sc].fs == arr[now.fs][now.sc].fs&&arr[nxt.fs][nxt.sc].sc == arr[now.fs][now.sc].sc){
				//cout<<now.fs<<' '<<now.sc<<' '<<nxt.fs<<' '<<nxt.sc<<' '<<i.fs<<' '<<i.sc<<'\n';
				dir[nxt.fs][nxt.sc] = i;
				q.push(nxt);
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(dir[i][j].fs+dir[i][j].sc == 0){
				cout<<"INVALID";
				return 0;
			}
		}
	}
	cout<<"VALID\n";
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(dir[i][j].fs == 2)cout<<'X';
			else if(dir[i][j].fs == 1)cout<<"D";
			else if(dir[i][j].fs == -1)cout<<"U";
			else if(dir[i][j].sc == 1)cout<<"R";
			else cout<<"L";
		}
		cout<<'\n';
	}
	return 0;
}
