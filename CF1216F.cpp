#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 2e5+10;
ll dp[mxn];
int n,k;
string s;
vector<pll> pre[mxn];
ll bit[mxn];
const ll inf = 1e18;
void modify(int p,ll v){
	for(;p<mxn;p+=p&-p)bit[p] = min(bit[p],v);
	return;
}
ll getval(int p){
	ll re = 1e18;
	for(;p>0;p-= p&-p)re = min(re,bit[p]);
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fill(bit,bit+mxn,inf);
	cin>>n>>k;
	cin>>s;
	s = "#"+s;
	for(int i = 1;i<=n;i++){
		if(s[i] == '0')pre[i].push_back({i,i+1});
		else{
			int l = max(1,i-k),r = min(n,i+k);
			pre[l].push_back({i,r+1});
		}
	}
	modify(n+1,0);
	for(int i = n;i>=1;i--){
		dp[i] = inf;
		for(auto &j:pre[i]){
			dp[i] = min(dp[i],j.fs+getval(j.sc));
		}
		modify(i,dp[i]);
	}
	cout<<dp[1];
}
