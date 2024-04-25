#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 110;
string arr[mxn];
pii dir[] = {{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
char tar;
queue<pii> q;
bitset<mxn> vis[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>tar;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(arr[i][j] == tar)vis[i][j] = true,q.push({i,j});
		}
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto &d:dir){
			pii nxt = {now.fs+d.fs,now.sc+d.sc};
			if(nxt.fs>=n||nxt.sc>=m||nxt.fs<0||nxt.sc<0||vis[nxt.fs][nxt.sc]||arr[nxt.fs][nxt.sc] == '.')continue;
			vis[nxt.fs][nxt.sc] = true;
		}
	}
	set<char> st;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++)if(vis[i][j])st.insert(arr[i][j]);
	}
	cout<<st.size()-1;
}
