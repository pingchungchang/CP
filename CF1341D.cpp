#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2022;
int dp[mxn][mxn];
int arr[10];
int n,k;

inline int check(int from,int to){
	if((from|to) != to)return -1;
	else return __builtin_popcount(from^to);
}

int main(){

	arr[0] = (1<<7)-1-(1<<3);
	arr[1] = (1<<2)|(1<<5);
	arr[2] = (1<<7)-1-(1<<1)-(1<<5);
	arr[3] = (1<<7)-1-(1<<1)-(1<<4);
	arr[4] = (1<<7)-1-(1<<0)-(1<<4)-(1<<6);
	arr[5] = (1<<7)-1-(1<<2)-(1<<4);
	arr[6] = (1<<7)-1-(1<<2);
	arr[7] = (1<<0)|(1<<2)|(1<<5);
	arr[8] = (1<<7)-1;
	arr[9] = (1<<7)-1-(1<<4);

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(dp,-1,sizeof(dp));
	cin>>n>>k;
	vector<int> v(n,0);
	for(auto &i:v){
		string s;
		cin>>s;
		for(int j = 0;j<s.size();j++){
			if(s[j] == '1')i^= 1<<j;
		}
	}
	for(int i = 0;i<10;i++){
		int re = check(v.back(),arr[i]);
		if(re == -1||re>k)continue;
		dp[n-1][k-re] = max(dp[n-1][k-re],i);
	}
	for(int i = n-2;i>=0;i--){
		for(int j = 0;j<=k;j++){
			for(int l = 0;l<10;l++){
				int re = check(v[i],arr[l]);
				if(re == -1||re>j||dp[i+1][j] == -1)continue;
				dp[i][j-re] = max(dp[i][j-re],l);
			}
		}
	}
	/*
	for(int i = 0;i<n;i++){
		for(int j = 0;j<=k;j++)cout<<dp[i][j]<<' ';cout<<'\n';
	}
   */
	pii now = {-1,-1};
	for(int i = 0;i<n;i++){
		if(dp[i][0] != -1){
			now = {i,0};
			break;
		}
	}
	for(int i = 0;i<n;i++){
		if(v[i]&&now.fs>i){
			cout<<-1;
			return 0;
		}
	}
	if(now.fs == -1){
		cout<<-1;
		return 0;
	}
	string ans;
	for(;now.fs<n;now.fs++){
		ans += '0'+dp[now.fs][now.sc];
		now.sc += check(v[now.fs],arr[dp[now.fs][now.sc]]);
	}
	assert(now.sc == k);
	cout<<ans;
}
