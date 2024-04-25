#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2010;
vector<int> paths[mxn];
vector<int> v,rest;
int deg[mxn];
int ppp = 0;
queue<int> q;
int dp[mxn];


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	ppp = n;
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		v = vector<int>(k);
		rest.clear();
		for(auto &j:v)cin>>j;
		int rb = 0;
		int ptr = 0;
		for(int j = v[0];j<v.back();j++){
			if(ptr <v.size()&&v[ptr] == j){
				ptr++;
				continue;
			}
			rest.push_back(j);
		}
		ppp++;
		for(auto &j:v)deg[ppp]++,paths[j].push_back(ppp);
		for(auto &j:rest)deg[j]++,paths[ppp].push_back(j);
	}
	for(int i = 1;i<=ppp;i++){
		if(!deg[i])q.push(i);
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		dp[now] ++;
		for(auto nxt:paths[now]){
			dp[nxt] = max(dp[nxt],dp[now]);
			deg[nxt]--;
			if(!deg[nxt])q.push(nxt);
		}
	}
	cout<<(*max_element(dp+1,dp+ppp+1)+1)/2;
}
