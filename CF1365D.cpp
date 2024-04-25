#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 55;
string arr[mxn];
pii dx[] = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
int total;
bool flag = true;

void dfs(int r,int c){
	if(arr[r][c] == '#')return;
	if(arr[r][c] == 'G')total--;
	if(arr[r][c] == 'B')flag = false;
	arr[r][c] = '#';
	for(auto &i:dx){
		pii nxt = {i.fs+r,i.sc+c};
		if(nxt.fs<0||nxt.fs>=n||nxt.sc<0||nxt.sc>=m)continue;
		dfs(nxt.fs,nxt.sc);
	}
	return;
}

void solve(){
	flag = true;
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i =0;i<n;i++){
		for(int j= 0;j<m;j++){
			if(arr[i][j] == 'B'){
				for(auto &k:dx){
					if(i+k.fs<0||i+k.fs>=n||j+k.sc<0||j+k.sc>=m)continue;
					else if(arr[i+k.fs][j+k.sc] == 'B')continue;
					else if(arr[i+k.fs][j+k.sc] == 'G')flag = false;
					else arr[i+k.fs][j+k.sc] = '#';
				}
			}
		}
	}
	total = 0;
	for(int i = 0;i<n;i++)for(int j = 0;j<m;j++)if(arr[i][j] == 'G')total++;
	dfs(n-1,m-1);
	if(total != 0)flag = false;
	cout<<(flag?"YES\n":"NO\n");
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
