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

const int mxn = 2e5+10;
set<int> st;
vector<int> tree[mxn];
int dep[mxn];
int par[mxn];
int cnt = 0;
void dfs(int now,int h){
	dep[now] = 1;
	for(auto nxt:tree[now]){
		dfs(nxt,h);
		dep[now] = max(dep[now],dep[nxt]+1);
	}
	if(dep[now] >= h){
		if(st.find(now) == st.end())cnt++;
		dep[now] = 0;
	}
//	cout<<now<<' '<<dep[now]<<endl;
	return;
}
void solve(){
	int n,k;
	cin>>n>>k;
	st.clear();
	for(int i = 1;i<=n;i++){
		dep[i] = 0;
		tree[i].clear();
	}
	st.insert(1);
	for(int i = 2;i<=n;i++){
		int tmp;
		cin>>tmp;
		if(tmp == 1)st.insert(i);
		tree[tmp].push_back(i);
	}
	int l = 0,r = n;
	while(l != r){
		int mid = (l+r)>>1;
		cnt = 0;
		dfs(1,mid);
		if(cnt <=k)r = mid;
		else l = mid+1;
//		cout<<mid<<','<<cnt<<endl;
		
	}
	if(l != 0)cout<<l<<'\n';
	else cout<<"1\n";
//	cout<<(l>0?l-1:0)<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

