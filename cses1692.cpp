#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 16;
int n;
int ptr[1<<mxn];
vector<pii> paths[1<<mxn];
vector<int> eul;
string ans;

void dfs(int now){
	//cout<<now<<":";for(auto &i:paths[now])cout<<i.fs<<' ';cout<<endl;
	for(int &i = ptr[now];i<paths[now].size();){
		i++;
		dfs(paths[now][i-1].fs);
	}
	eul.push_back(now);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	if(n == 1){
		cout<<10;
		return 0;
	}
	for(int i = 1;i<(1<<n);i++){
		int s = 0;
		int e = i>>1;
		for(int j = 0;j<n-1;j++)s |= ((1<<j)&i);
		paths[e].push_back({s,i});
	}
	dfs(0);
	eul.pop_back();
	reverse(eul.begin(),eul.end());
	//for(auto &i:eul)cout<<i<<' ';cout<<endl;
	ans = string(n,'0');
	for(int i = 0;i<eul.size();i++)ans += '0'+(eul[i]&1);
	cout<<ans;
	assert(ans.size() == (1<<n)+n-1);
}
