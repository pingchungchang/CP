#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e6+10;
vector<int> op[mxn];
pii range[mxn];
int n,m;
multiset<int> st;
int dp[mxn];

void solve(){
	st.clear();
	for(int i = 0;i<=n+1;i++){
		op[i].clear();
	}
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		op[a].push_back(a);
		op[b+1].push_back(-a);
	}
	for(int i = 1;i<=n+1;i++){
		dp[i] = dp[i-1];
		for(auto &j:op[i]){
			if(j>0){
				st.insert(j);
			}
			else{
				st.erase(st.find(-j));
			}
		}
		if(!st.empty()){
			dp[i] = max(dp[i],dp[*st.begin()-1]+(int)st.size());
		}
	}
	cout<<dp[n+1]<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
