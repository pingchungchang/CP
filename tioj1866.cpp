#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
pii trie[mxn*100];
int ans[mxn];
int ptr = 0;
vector<int> tree[mxn];
int arr[mxn];
int start[mxn];
vector<vector<pair<int,pii>>> rev;
int n;

int newnode(){
	rev.back().push_back({ptr,trie[ptr]});
	ptr++;
	trie[ptr].fs = trie[ptr].sc = 0;
	return ptr;
}

void add(int k){
	int now = 0;
	for(int i = 30;i>=0;i--){
		if(k&(1<<i)){
			if(!trie[now].sc){
				rev.back().push_back(make_pair(now,trie[now]));
				trie[now].sc = newnode();
			}
			now = trie[now].sc;
		}
		else{
			if(!trie[now].fs){
				rev.back().push_back(make_pair(now,trie[now]));
				trie[now].fs = newnode();
			}
			now = trie[now].fs;
		}
	}
	return;
}

int get(int k){
	int re = 0;
	int now = 0;
	for(int i = 30;i>=0;i--){
		if(k&(1<<i)){
			if(trie[now].fs)re^=1<<i,now = trie[now].fs;
			else now = trie[now].sc;
		}
		else{
			if(trie[now].sc)re^=1<<i,now = trie[now].sc;
			else now = trie[now].fs;
		}
	}
	return re;
}

void dfs(int now,int par){
	rev.push_back({});
	add(arr[now]);
	start[now] = ptr;
	ans[now] = get(arr[now]);
	ans[now] = max(ans[now],ans[par]);
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		arr[nxt]^=arr[now];
		dfs(nxt,now);
	}
	ptr = start[now];
	while(!rev.back().empty()){
		trie[rev.back().back().fs] = rev.back().back().sc;
		rev.back().pop_back();
	}
	rev.pop_back();
	return;
}

void init(){
	for(int i = 0;i<=n;i++){
		tree[i].clear();
		arr[i] = 0;
		ans[i] = 0;
		start[i] = 0;
	}
	while(!rev.empty()){
		while(!rev.back().empty()){
			trie[rev.back().back().fs] = rev.back().back().sc;
			rev.back().pop_back();
		}
		rev.pop_back();
	}
	return;
}

void solve(){
	init();
	ptr = 0;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	rev.push_back({});
	add(0);
	start[1] = ptr;
	dfs(1,1);
	for(int i = 1;i<=n;i++)cout<<ans[i]<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
