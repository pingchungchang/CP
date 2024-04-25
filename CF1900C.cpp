#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 3e5+100;
pii tree[mxn];
int n;
string s;

int dfs(int now){
	if(!tree[now].fs&&!tree[now].sc)return 0;
	int sh = 0;
	int re = 1e9;
	if(tree[now].fs&&s[now] == 'L')re = min(re,dfs(tree[now].fs));
	else if(tree[now].fs)re = min(re,dfs(tree[now].fs)+1);
	if(s[now] == 'R'&&tree[now].sc)re = min(re,dfs(tree[now].sc));
	else if(tree[now].sc)re = min(re,dfs(tree[now].sc)+1);
	return re;
}

void solve(){
	cin>>n>>s;
	s = "#"+s;
	for(int i = 1;i<=n;i++){
		cin>>tree[i].fs>>tree[i].sc;
	}
	cout<<dfs(1)<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
