#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;
vector<int> tree[mxn];
int n;

void solve(){
	for(int i = 0;i<=n;i++)tree[i].clear();
	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		ans += (tree[i].size() == 1);
	}
	cout<<(ans+1)/2<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
