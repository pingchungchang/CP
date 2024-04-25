#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
int par[mxn];
pii eul[mxn];
int cnt = 0;
int n;
vector<int> tree[mxn];
int vpar[mxn];
int dp[mxn];

void dfs(int now){
	eul[now].fs = ++cnt;
	for(auto nxt:tree[now])dfs(nxt);
	eul[now].sc = ++cnt;
}

void solve(){
	int m;
	cin>>m;
	vector<pii> v;
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		dp[k] = vpar[k] = 0;
		v.push_back({eul[k].fs,k});
		v.push_back({eul[k].sc,-k});
	}
	sort(v.begin(),v.end());
	vector<int> st;
	st.push_back(0);
	for(auto &i:v){
		if(i.sc>0){
			vpar[i.sc] = st.back();
			st.push_back(i.sc);
		}
		else st.pop_back();
	}
	reverse(v.begin(),v.end());
	int ans = 0;
	for(auto &i:v){
		if(i.sc<0)continue;
		ans += dp[i.sc]+tree[i.sc].size();
		if(!vpar[i.sc])ans++;
		else{
			if(vpar[i.sc] != par[i.sc]){
				dp[vpar[i.sc]]++;
			}
			else dp[vpar[i.sc]]--;
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	int q;
	cin>>q;
	for(int i = 2;i<=n;i++)cin>>par[i],tree[par[i]].push_back(i);
	dfs(1);
	while(q--)solve();
}
