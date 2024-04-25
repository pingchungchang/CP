#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
int n;
vector<int> tree[mxn];
pll dp[mxn];
ll arr[mxn];
vector<pll> tmp;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 2;i<=n;i++){
		int p;
		cin>>p;
		tree[p].push_back(i);
	}
	for(int  i = 1;i<=n;i++)cin>>arr[i];
	for(int i = n;i>=1;i--){
		dp[i].sc = arr[i];
		tmp.clear();
		for(auto nxt:tree[i]){
			dp[i].sc += arr[nxt];
			tmp.push_back(make_pair(dp[nxt].fs,arr[nxt]));
		}
		sort(tmp.begin(),tmp.end(),[](pll &a,pll &b){return a.fs+b.sc>a.sc+b.fs;});
		ll p = 0;
		for(auto &j:tmp){
			dp[i].fs = max(dp[i].fs,j.fs+p);
			p += j.sc;
		}
		dp[i].fs = max(dp[i].fs,dp[i].sc);
	}
	for(int i = 1;i<=n;i++)cout<<dp[i].fs<<' ';
}
