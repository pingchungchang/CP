#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
int col[mxn];
vector<int> paths[mxn];

pii arr[mxn];

bool dfs(int now,int c){
	if(col[now]&&c != col[now])return false;
	col[now] = c;
	bool re = true;
	for(auto nxt:paths[now]){
		if(col[nxt] == c)return false;
		if(!col[nxt])re = re&&dfs(nxt,-c);
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i  =0;i<m;i++)cin>>arr[i].fs;
	for(int i = 0;i<m;i++)cin>>arr[i].sc;
	for(int i = 0;i<m;i++){
		paths[arr[i].fs].push_back(arr[i].sc);
		paths[arr[i].sc].push_back(arr[i].fs);
	}
	bool flag = true;
	for(int i = 1;i<=n;i++){
		if(!col[i]){
			flag = flag&&dfs(i,1);
		}
	}
	cout<<(flag?"Yes":"No");
}
