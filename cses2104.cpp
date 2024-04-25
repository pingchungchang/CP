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

const int mxn = 5e5+10;
struct node{
	vector<int> id;
	node* paths[26];
	node* fail;
	ll idx;
	ll dp;
	char c;
	node(){
		c = '#';
		dp = idx = INT_MAX;
		fill(paths,paths+26,nullptr);
		fail = 0;
	}
	node(char cc){
		c = cc;
		dp = idx = INT_MAX;
		fill(paths,paths+26,nullptr);
		fail = 0;
	}
};
node* trie = new node();
vector<node*> stamp;
ll ans[mxn];
void build(int id,string &ss,node* now,int p){
	if(p == ss.size()){
		now->id.push_back(id);
		return;
	}
	if(!now->paths[ss[p]-'a'])now->paths[ss[p]-'a'] = new node(ss[p]);
	build(id,ss,now->paths[ss[p]-'a'],p+1);
}
void make_fail(){
	queue<node*> q;
	for(auto &i:trie->paths){
		if(i){
			q.push(i);
			i->fail = trie;
		}
	}
	while(!q.empty()){
		auto now = q.front();
		stamp.push_back(now);
		q.pop();
		while(now->fail->c != '#'&&!now->fail->paths[now->c-'a'])now->fail = now->fail->fail;
		if(!now->fail->paths[now->c-'a']||now->fail->paths[now->c-'a'] == now)now->fail = trie;
		else{
			now->fail = now->fail->paths[now->c-'a'];
		}
		for(auto &i:now->paths){
			if(i){
				i->fail = now->fail;
				q.push(i);
			}
		}
	}
	return;
}
int main(){
	io
	string s;
	cin>>s;
	int n;
	cin>>n;
	string t[n+1];
	for(int i = 1;i<=n;++i){
		cin>>t[i];
		build(i,t[i],trie,0);
	}
	for(int i = 0;i<=n;i++)ans[i] = INT_MAX;
	trie->fail = trie;
	make_fail();
	auto now = trie;
	for(int i = 0;i<s.size();i++){
		while(now->c != '#'&&!now->paths[s[i]-'a'])now = now->fail;
		if(now->paths[s[i]-'a'])now = now->paths[s[i]-'a'];
		now->dp = min(now->dp,(ll)i+1);
	}
	for(int i = stamp.size()-1;i>=0;i--){
		auto tmp = stamp[i];
		for(auto &j:tmp->id){
			ans[j] = min(ans[j],tmp->dp);
		}
		tmp->fail->dp = min(tmp->dp,tmp->fail->dp);
	}
	for(int i = 1;i<=n;i++){
		if(ans[i] >= INT_MAX)cout<<-1<<'\n';
		else cout<<ans[i]-t[i].size()+1<<'\n';
	}
	return 0;
}

