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

int ccc = 0;
struct node{
	ll dp;
	int idx;
	vector<int> id;
	char c;
	node* paths[26];
	node* fail;
	node(){
		idx = ccc++;
		c = '#';
		dp = 0;
		fill(paths,paths+26,nullptr);
		fail = 0;
	}
	node(char cc){
		idx = ccc++;
		c = cc;
		dp = 0;
		fill(paths,paths+26,nullptr);
		fail = 0;
	}
};
node* trie = new node();
vector<node*> stamp;
void build(int id,string & ss,node* now,int p){
	if(p == ss.size()){
		now->id.push_back(id);
		return;
	}
	if(!now->paths[ss[p]-'a']){
		now->paths[ss[p]-'a'] = new node(ss[p]);
		build(id,ss,now->paths[ss[p]-'a'],p+1);
	}
	else{
		build(id,ss,now->paths[ss[p]-'a'],p+1);
	}
	return;
}
void make_fail(){
	queue<node*> q;
	for(auto &i:trie->paths){
		if(!i)continue;
		i->fail = trie;
		q.push(i);
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		stamp.push_back(now);
		while(now->fail->c != '#'&&!now->fail->paths[now->c-'a'])now->fail = now->fail->fail;
		if(now->fail->paths[now->c-'a']&&now->fail->paths[now->c-'a'] != now){
			now->fail = now->fail->paths[now->c-'a'];
		}
		else{
			now->fail = trie;
		}
//		cout<<now->idx<<' '<<now->fail->idx<<',';
		for(auto &i:now->paths){
			if(!i)continue;
			i->fail = now->fail;
			q.push(i);
		}
	}
	return;
}
const int mxn = 5e5+10;
bitset<mxn> vis;
int ans[mxn];
void dfs(node* now){
	for(int i = stamp.size()-1;i>=0;i--){
		auto now =stamp[i];
		for(auto &j:now->id){
			ans[j] += now->dp;
		}
		now->fail->dp+= now->dp;
	}
	return;
}
void pv(node* now,string& ss){
	cout<<now->dp<<' '<<ss<<' '<<now->idx<<' '<<now->fail->idx<<':';for(auto i:now->id)cout<<i<<' ';cout<<endl;
	for(auto nxt:now->paths){
		if(nxt){
			ss += nxt->c;
			pv(nxt,ss);
			ss.pop_back();
		}
	}
	return;
}
int main(){
	string s;
	cin>>s;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		string t;
		cin>>t;
		build(i+1,t,trie,0);
	}
	trie->fail = trie;
	make_fail();
	node* now = trie;
	for(int i = 0;i<s.size();i++){
		while(now->c != '#'&&!now->paths[s[i]-'a']){
			now = now->fail;
		}
		if(now->paths[s[i]-'a'])now = now->paths[s[i]-'a'];
		now->dp++;
//		cout<<s[i]<<' '<<now->idx<<',';
	}
	dfs(trie);
	string ss = "";
//	pv(trie,ss);
	for(int i= 1;i<=n;i++)cout<<(ans[i] != 0?"YES":"NO")<<'\n';
	return 0;
}

