#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
int pi[mxn];
pii nxt[mxn][26];
int dp[2][mxn];
int n,m;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s,t;
	cin>>s>>t;
	if(s.size()<t.size()){
		cout<<0;
		return 0;
	}
	n = s.size(),m = t.size();
	pi[0] = 0;
	if(t.size()>1&&t[0] == t[1])pi[1] = 1;
	for(int i = 2;i<t.size();i++){
		int p = i-1;
		while(p>0&&t[pi[p]] != t[i]){
			p = pi[p]-1;
		}
		if(p<=0&&t[0] == t[i])pi[i] = 1;
		else if(p>0)pi[i] = pi[p]+1;
	}

	for(int i = 1;i<t.size();i++){
		for(char c = 'a';c<='z';c++){
			int p = i-1;
			while(p>0&&t[pi[p]] != c)p = pi[p]-1;
			if(p<=0&&t[0] == c)nxt[i][c-'a'] = {1,0};
			else if(p>0)nxt[i][c-'a'] = {pi[p]+1,0};
		}
	}
	for(int i = 0;i+1<t.size();i++)nxt[i][t[i]-'a'] = {i+1,0};
	nxt[t.size()-1][t.back()-'a'].sc = 1;

	/*
	for(int i = 0;i<t.size();i++){
		for(int j = 0;j<26;j++)cout<<nxt[i][j].fs<<' ';cout<<endl;
	}cout<<endl;
   */

	memset(dp,-1,sizeof(dp));
	bool roll = 0;
	dp[roll][0] = 0;
	for(int i = 0;i<s.size();i++){
		roll ^= 1;
		fill(dp[roll],dp[roll]+t.size(),-1);
		if(s[i] != '?'){
			for(int j = 0;j<t.size();j++){
				if(dp[roll^1][j] == -1)continue;
				auto tmp = nxt[j][s[i]-'a'];
				dp[roll][tmp.fs] = max(dp[roll^1][j]+tmp.sc,dp[roll][tmp.fs]);
			}
		}
		else{
			for(int j = 0;j<t.size();j++){
				if(dp[roll^1][j] == -1)continue;
				for(char c = 'a';c<='z';c++){
					auto tmp = nxt[j][c-'a'];
					dp[roll][tmp.fs] = max(dp[roll^1][j]+tmp.sc,dp[roll][tmp.fs]);
				}
			}
		}
		//for(int j = 0;j<t.size();j++)cout<<dp[roll][j]<<' ';cout<<endl;
	}
	cout<<*max_element(dp[roll],dp[roll]+t.size());
}
