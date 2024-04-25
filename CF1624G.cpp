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
int dsu[mxn];
struct edge{
	int a,b,val;
	edge(){}
};
int root(int now){
	while(now != dsu[now]){
		dsu[now] = dsu[dsu[now]];
		now = dsu[now];
	}
	return now;
}
void solve(){
	int n,m;
	cin>>n>>m;
	set<int> st;
	for(int i = 0;i<m;i++)st.insert(i);
	edge paths[m];
	for(int i= 0;i<m;i++){
		cin>>paths[i].a>>paths[i].b>>paths[i].val;
	}
	int ans = 0;
	for(int bit = 30;bit>=0;bit--){
		for(int i = 1;i<=n;i++)dsu[i] = i;
		set<int> del;
		for(auto i:st){
			auto tmp = paths[i];
			if((tmp.val&(1<<bit)) != 0)del.insert(i);
		}
		for(auto i:st){
			if(del.find(i) != del.end())continue;
			auto tmp = paths[i];
			dsu[root(tmp.a)] = root(tmp.b);
		}
		bool flag = true;
		for(int i = 1;i<=n;i++){
			if(root(i) != root(1)){
				ans = ans|(1<<bit);
				flag = false;
			}
		}
		if(flag){
			for(auto i:del)st.erase(i);
		}
	}
//	for(auto i:st)cout<<i<<',';
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

