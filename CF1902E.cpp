#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll



const int mxn = 1e6+10;
ll ans = 0;
int childs[mxn][26];
ll dp[mxn];
int ppp;
int n;
string arr[mxn];
string tmp;

int newnode(){
	ppp++;
	memset(childs[ppp],0,sizeof(childs[ppp]));
	dp[ppp] = 0;
	return ppp;
}

inline void add(int rt,string &s){
	int now = rt;
	for(auto &i:s){
		if(!childs[now][i-'a']){
			childs[now][i-'a'] = newnode();
		}
		now = childs[now][i-'a'];
		dp[now] ++;
	}
	return;
}

inline ll match(int rt,string &s){
	ll re = 0;
	int now = rt;
	for(auto &i:s){
		if(!childs[now][i-'a'])return re;
		now = childs[now][i-'a'];
		re += dp[now];
	}
	return re;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i],ans += arr[i].size();
	ans = ans*n*2;
	int rt = newnode();
	for(int i = 1;i<=n;i++){
		tmp = arr[i];
		reverse(tmp.begin(),tmp.end());
		add(rt,tmp);
		ans -= match(rt,arr[i])*2;
	}
	ppp = 0;
	rt = newnode();
	for(int i = n;i>=1;i--){
		ans -= match(rt,arr[i])*2;
		tmp = arr[i];
		reverse(tmp.begin(),tmp.end());
		add(rt,tmp);
	}
	cout<<ans;
}
