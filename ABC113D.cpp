#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

ll h,w,k;
const ll mod = 1e9+7;
vector<ll> valid;
ll dp[2][10];
void dfs(int a,int b){
//	cout<<a<<' '<<b<<endl;
	if(b == w){
		for(int i = 1;i<10;i++){
			if(((1<<i)&a)&&((1<<(i-1))&a))return;
		}
		valid.push_back(a);
		return;
	}
	if(b == 0 || !(a&(1<<(b-1)))){
		dfs(a^(1<<b),b+1);
	}
	for(int j = b+1;j<w;j++){
		dfs(a^(1<<j),j+1);
	}
	dfs(a,b+1);
	return;
}
string to2(int k){
	string re;
	for(int i = 0;i<31;i++){
		if(k&(1<<i))re += '1';
		else re += '0';
	}
	reverse(_all(re));
	return re;
}
int main(){
	io
	short now = 1;
	cin>>h>>w>>k;
	w--;
	dfs(0,0);
	dfs(1,0);
	w++;
	sort(_all(valid));
	valid.erase(unique(_all(valid)),valid.end());
//	for(auto &i:valid)cout<<to2(i)<<'\n';
	if(w == 1){
		cout<<1;
		return 0;
	}
	dp[now][0] = 1;
	for(int i = 0;i<h;i++){
		now ^= 1;
		for(auto &j:dp[now])j = 0;
		for(auto &j:valid){
			for(int kk = 0;kk<w-1;kk++){
				if(j&(1<<kk)){
					dp[now][kk] += dp[now^1][kk+1];
					dp[now][kk+1] += dp[now^1][kk];
				}
				else if(kk == w-2){
					dp[now][w-1] += dp[now^1][w-1];
					if(!((1<<(kk-1))&j))dp[now][kk] += dp[now^1][kk];
				}
				else if(kk == 0|| !((1<<(kk-1))&j)){
					dp[now][kk] += dp[now^1][kk];
				}
			}
		}
		for(auto &j:dp[now]){
			j %= mod;
//			cout<<j<<' ';
		}
//		cout<<endl;
	}
	cout<<dp[now][k-1];
}

