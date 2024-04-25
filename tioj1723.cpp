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

struct node{
	node* paths[26];
	node* fail;
	vector<int> id;
	pll dp;
	int c;
	node(){
		fill(paths,paths+26,nullptr);
		dp = {0,0};
		fail = 0;
		c = -1;
	}
	node(int k){
		fill(paths,paths+26,nullptr);
		dp = {0,0};
		fail = 0;
		c = k;
	}
};
node* trie = new node();

void build(int p,node* now,string &t,int id){
	if(p == t.size()){
		now->id.push_back(id);
		return;
	}
	if(!now->paths[t[p]-'a'])now->paths[t[p]-'a'] = new node(t[p]-'a');
	build(p+1,now->paths[t[p]-'a'],t,id);
}
vector<node*> stamp;
void make_fail(){
	queue<node*> q;
	trie->fail = trie;
	for(auto &i:trie->paths){
		if(i){
			i->fail = trie;
			q.push(i);
		}
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		stamp.push_back(now);
		while(now->fail != trie&&!now->fail->paths[now->c])now->fail = now->fail->fail;
		if(!now->fail->paths[now->c]||now->fail->paths[now->c] == now)now->fail = trie;
		else now->fail = now->fail->paths[now->c];
		for(auto &i:now->paths){
			if(i){
				i->fail = now->fail;
				q.push(i);
			}
		}
	}
	return;
}
void solve(int idx){
	string s;
	int p;
	cin>>s>>p;
	node* now = trie;
	for(auto &i:s){
//		cout<<i;
		while(now != trie&&!now->paths[i-'a'])now = now->fail;
		if(now->paths[i-'a'])now = now->paths[i-'a'];
		now->dp = max(now->dp,{1LL*p,1LL*idx});
	}
	return;
}
int main(){
	io
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		string t;
		cin>>t;
		build(0,trie,t,i);
	}
	make_fail();
	for(int i = 1;i<=n;i++){
		solve(i);
	}
	vector<pll> ans(m+1,{0,0});
	for(int i = stamp.size()-1;i>=0;i--){
		auto now = stamp[i];
		for(auto &j:now->id){
			ans[j] = max(ans[j],now->dp);
		}
		now->fail->dp = max(now->fail->dp,now->dp);
	}
	for(int i = 1;i<=m;i++){
		if(ans[i].fs == 0)cout<<"0";
		else cout<<ans[i].sc;
		cout<<'\n';
	}
	return 0;
}

