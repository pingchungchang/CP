#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 3e5+10;
bitset<mxn> dp,change;
vector<int> ans;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		int k;
		cin>>k;
		change[k] = (change[k]?0:1);
	}
	for(int i = 1;i<=n;i++){
		if(!change[i])continue;
		for(int j = i;j<=n;j+=i){
			dp[j] = dp[j]^1;
		}
	}
	for(int i = 1;i<=n;i++){
		if(dp[i])ans.push_back(i);
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<'\n';
}
