#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2020;
string arr[mxn];
vector<int> row[mxn],col[mxn];
vector<pii> br[mxn],bc[mxn];
pii dir[] = {{-1,0},{1,0},{0,1},{0,-1}};
int dist[mxn][mxn];
queue<pii> q;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	pii s,e;
	arr[0] = arr[n+1] = string(m+2,'#');
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		arr[i] = "#"+arr[i]+"#";
		for(int j = 1;j<=m;j++){
			if(arr[i][j] == 'S')s = {i,j},arr[i][j] = '.';
			else if(arr[i][j] == 'G')e = {i,j},arr[i][j] = '.';
		}
	}
	for(int i = 0;i<=n+1;i++){
		for(int j = 0;j<=m+1;j++){
			if(arr[i][j] != 'S'&&arr[i][j] != 'G'&&arr[i][j] != '.'){
				row[i].push_back(j);
				col[j].push_back(i);
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(arr[i][j] == '>'){
				auto it = upper_bound(row[i].begin(),row[i].end(),j);
				br[i].push_back({j,*it});
			}
			else if(arr[i][j] == '<'){
				auto it = --lower_bound(row[i].begin(),row[i].end(),j);
					br[i].push_back({*it,j});
			}
			else if(arr[i][j] == '^'){
				auto it = --lower_bound(col[j].begin(),col[j].end(),i);
				bc[j].push_back({*it,i});
			}
			else if(arr[i][j] == 'v'){
				auto it = upper_bound(col[j].begin(),col[j].end(),i);
				bc[j].push_back({i,*it});
			}
		}
	}
	/*
	for(int i = 1;i<=n;i++)assert(row[i][0] == 0&&row[i].back() == m+1);
	for(int i = 1;i<=m;i++)assert(col[i][0] == 0&&col[i].back() == n+1);

   */
	for(int i = 1;i<=n;i++){
		sort(br[i].begin(),br[i].end());
		int pt = 0;
		for(auto &j:br[i]){
			while(j.sc>m+1);
			pt = max(pt,j.fs);
			while(pt<=j.sc){
				arr[i][pt] = 'x';
				pt++;
			}
		}
	}
	for(int i = 1;i<=m;i++){
		sort(bc[i].begin(),bc[i].end());
		int pt = 0;
		for(auto &j:bc[i]){
			pt = max(pt,j.fs);
			while(j.sc>n+1);
			while(pt<=j.sc){
				arr[pt][i] = 'x';
				pt++;
			}
		}
	}
	//for(int i = 0;i<=n+1;i++)cout<<arr[i]<<endl;
	memset(dist,-1,sizeof(dist));
	arr[s.fs][s.sc] = 'g';
	dist[s.fs][s.sc] = 0;
	q.push(s);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto &i:dir){
			pii nxt = {now.fs+i.fs,now.sc+i.sc};
			if(arr[nxt.fs][nxt.sc] == '.'){
				dist[nxt.fs][nxt.sc] = dist[now.fs][now.sc]+1;
				arr[nxt.fs][nxt.sc] = 'g';
				q.push(nxt);
			}
		}
	}
	cout<<dist[e.fs][e.sc];
}
