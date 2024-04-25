#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e6+10;
const int mod = 1e9+7;
int ans = mod/2+1;
vector<pii> edges;
int dsu[mxn];
short col[mxn];
int paths[mxn*2];
int head[mxn],pre[mxn*2];
int ptr;

int root(int k){
	return k==dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	//if(sz[a]<sz[b])swap(a,b);
	dsu[b] = a;
	//sz[a] += sz[b];
	return;
}
void add_edge(int a,int b){
	ptr++;
	pre[ptr] = head[a];
	head[a] = ptr;
	paths[ptr] = b;
	ptr++;
	pre[ptr] = head[b];
	head[b] = ptr;
	paths[ptr] = a;
	return;
}

void dfs(int now,int C){
	if(col[now]&&col[now] != C){
		cout<<"0";
		exit(0);
	}
	if(col[now])return;
	col[now] = C;
	for(int i = head[now];i>0;i = pre[i]){
		dfs(paths[i],-C);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 0;i<mxn;i++)dsu[i] = i;//sz[i] = 1;
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(c)onion(a,b);
		else edges.push_back({a,b});
	}
	for(auto &i:edges){
		i.fs = root(i.fs),i.sc = root(i.sc);
		if(i.fs == i.sc){
			cout<<0;
			return 0;
		}
		add_edge(i.fs,i.sc);
	}
	for(int i = 0;i<n;i++){
		if(!col[root(i)]){
			dfs(root(i),1);
			ans <<=1;
			if(ans>=mod)ans -= mod;
		}
	}
	cout<<ans;
}
