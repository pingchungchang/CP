#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


const int mxn = 1e4+10;
const int inf = 1e9;
int dp[2][26];
int dist[26][26];
string tmp[3] = {"qwertyuiop","asdfghjkl","zxcvbnm"};
string s;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(auto &i:dist)for(auto &j:i)j = 100;
	for(int i = 0;i<26;i++){
		dist[i][i] = 0;
	}
	for(int i = 0;i<tmp[1].size();i++){
		int ta = tmp[1][i]-'a',tb = tmp[0][i]-'a',tc = tmp[0][i+1]-'a';
		dist[ta][tb] = dist[tb][ta] = 1;
		dist[ta][tc] = dist[tc][ta] = 1;
	}
	for(int i = 0;i<tmp[2].size();i++){
		int ta = tmp[2][i]-'a',tb = tmp[1][i]-'a',tc = tmp[1][i+1]-'a';
		dist[ta][tb] = dist[tb][ta] = 1;
		dist[tc][ta] = dist[ta][tc] = 1;
	}
	for(int i = 0;i<3;i++){
		for(int j = 1;j<tmp[i].size();j++){
			int ta = tmp[i][j-1]-'a',tb = tmp[i][j]-'a';
			dist[ta][tb] = dist[tb][ta] = 1;
		}
	}
	for(int i = 0;i<26;i++){
		for(int j = 0;j<26;j++){
			for(int k = 0;k<26;k++){
				dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
			}
		}
	}
	bool roll = 0;
	int n;
	/*
	for(char i = 'A';i<='Z';i++){
		for(char j = 'A';j<='Z';j++){
			cout<<i<<j<<":"<<dist[i-'A'][j-'A']<<endl;
		}
	}
	return 0;
   */
	cin>>n>>s;
	s = "F"+s;
	fill(dp[roll],dp[roll]+26,inf);
	dp[roll]['j'-'a'] = 0;
	for(int i = 1;i<=n;i++){
		roll ^= 1;
		fill(dp[roll],dp[roll]+26,inf);
		for(int j = 0;j<26;j++){
			for(int k = 0;k<26;k++){
				pii pre = {s[i-1]-'A',j};
				pii now = {s[i]-'A',k};
				dp[roll][k] = min(dp[roll][k],dp[roll^1][j]+
					min({dist[pre.fs][now.fs]+dist[pre.sc][now.sc],dist[pre.fs][now.sc]+dist[pre.sc][now.fs]}));
			}
		}
	}
	cout<<*min_element(dp[roll],dp[roll]+26);
}
