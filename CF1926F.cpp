#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,sse4")
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

string arr[7];
vector<pii> v;
vector<pii> tar;
vector<int> now;
pii dir[] = {{1,1},{1,-1},{-1,1},{-1,-1},{0,0}};
int ans;
map<string,int> mp;

inline bool check(){
	for(auto &i:tar){
		int s = 0;
		for(auto &d:dir){
			s += (arr[i.fs+d.fs][i.sc+d.sc]=='B');
		}
		if(s == 5)return false;
	}
	return true;
}

void dfs(){
	if(check()){
		ans = min(ans,(int)now.size());
		return;
	}
	if(now.size()>=ans)return;
	for(int j = (now.empty()?0:now.back()+1);j<v.size();j++){
		now.push_back(j);
		pii pos = v[j];
		arr[pos.fs][pos.sc] = 'W';
		dfs();
		arr[pos.fs][pos.sc] = 'B';
		now.pop_back();
	}
	return;
}

void solve(){
	v.clear();
	tar.clear();
	assert(now.empty());
	ans = 8;
	string s;
	for(int i = 0;i<7;i++){
		cin>>arr[i];
		s += arr[i];
	}
	if(mp.find(s) != mp.end()){
		cout<<mp[s]<<'\n';
		return;
	}
	for(int i = 1;i+1<7;i++){
		for(int j = 1;j+1<7;j++){
			int c = 0;
			for(auto &d:dir){
				int nr = d.fs+i,nc = d.sc+j;
				c += (arr[nr][nc] == 'B');
			}
			if(c == 5)tar.push_back({i,j});
			if(arr[i][j] != 'B')continue;
			if(i==j&&(i==1||i==5))continue;
			if((i==1&&j==5)||(i==5&&j==1))continue;
			v.push_back({i,j});
		}
	}
	dfs();
	cout<<(mp[s] = ans)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
