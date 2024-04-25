#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

map<int,int> dp[4];

int calc(int n,int t){
	if(dp[t].find(n) != dp[t].end())return dp[t][n];
	set<int> st;
	for(int i = 1;i<=n;i++){
		if(t == 0){
			if(i != 1&&i != n)st.insert(calc(i-1,0)^calc(n-i,0));
			st.insert(calc(i-1,1)^calc(n-i,1));
		}
		else if(t == 1){
			if(i != 1)st.insert(calc(i-1,0)^calc(n-i,1));
			if(i != n)st.insert(calc(i-1,1)^calc(n-i,0));
		}
		else if(t == 2){
			st.insert(calc(i-1,2)^calc(n-i,1));
			if(i != n)st.insert(calc(i-1,2)^calc(n-i,0));
		}
		else if(t == 3){
			st.insert(calc(i-1,2)^calc(n-i,2));
		}
	}
	for(int i = 0;i<=1000;i++){
		if(st.find(i) == st.end()){
			return dp[t][n] = i;
		}
	}
}

int f(ll n,int t){
	if(t == 0)return (!n?0:1);
	else if(t == 1)return 0;
	else if(t == 2)return n;
	else if(t == 3)return (n&1);
}

void solve(){
	/*
	dp[0][0] = dp[1][0] = dp[1][1] = 0;
	dp[0][1] = 1;
	dp[2][0] = 0;dp[2][1] = 1;
	dp[3][0] = 0;dp[3][1] = 1;
	for(int i = 0;i<=30;i++)cout<<calc(i,0)<<' ';cout<<endl;
	for(int i = 0;i<=30;i++)cout<<calc(i,1)<<' ';cout<<endl;
	for(int i = 0;i<=30;i++)cout<<calc(i,2)<<' ';cout<<endl;
	for(int i = 0;i<=30;i++)cout<<calc(i,3)<<' ';cout<<endl;
	return;

   */
	ll n,m;
	cin>>n>>m;
	pll arr[m];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	ll re = 0;
	if(!m)re = f(n,3);
	else re = re^f(arr[0].fs-1,2)^f(n-arr[m-1].fs,2);
	for(int i = 1;i<m;i++){
		re = re^f(arr[i].fs-arr[i-1].fs-1,arr[i].sc^arr[i-1].sc);
	}
	cout<<(re?"Takahashi":"Aoki");
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
