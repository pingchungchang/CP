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
#define int ll
int ccc = 0;
struct node{
	char c;
	int idx;
	node* paths[26];
	node* fail;
	int id;
	int dp;
	node* par;
	node(){
		idx = ccc++;
		par = this;
		id = 0;
		c = '#';
		fill(paths,paths+26,nullptr);
		dp = INT_MAX;
		fail = 0;
	}
	node(char cc,node* fa){
		par = fa;
		idx = ccc++;
		c = cc;
		id = 0;
		fill(paths,paths+26,nullptr);
		dp = INT_MAX;
		fail = 0;
	}	
};
node* trie = new node();
node* rtrie = new node();
void build(string &t,int p,node* now,int id){
	if(p == t.size()){
		now->id = id;
		return;
	}
	if(!now->paths[t[p]-'A'])now->paths[t[p]-'A'] = new node(t[p],now);
	build(t,p+1,now->paths[t[p]-'A'],id);
}
vector<node*> make_fail(node* root){
	queue<node*> q;
	for(auto &i:root->paths){
		if(i){
			i->fail = root;
			q.push(i);
		}
	}
	root->fail = root;
	vector<node*> re;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		re.push_back(now);
		while(now->fail->c != '#'&&!now->fail->paths[now->c-'A'])now->fail = now->fail->fail;
		if(!now->fail->paths[now->c-'A']||now->fail->paths[now->c-'A'] == now)now->fail = root;
		else now->fail = now->fail->paths[now->c-'A'];
		for(auto &i:now->paths){
			if(i){
				i->fail = now->fail;
				q.push(i);
			}
		}
//		cout<<now->idx<<' '<<now->fail->idx<<endl;
	}
	return re;
}
void dfs(node* now,string ss){
	cout<<now->idx<<' '<<ss<<' '<<now->fail->idx<<endl;
	for(auto &i:now->paths){
		if(i){
			dfs(i,ss+i->c);
		}
	}
	return;
}
main(){
	io
	string s;
	cin>>s;
	int m;
	cin>>m;
	string v[m],rv[m];
	for(int i = 0;i<m;i++){
		cin>>v[i];
		rv[i] = v[i];
		build(v[i],0,trie,i+1);
		reverse(_all(rv[i]));
		build(rv[i],0,rtrie,i+1);
	}
//	dfs(trie,"");
	auto stamp = make_fail(trie);
	auto rstamp = make_fail(rtrie);
	auto now = trie;
	for(int j = 0;j<s.size();j++){
		auto i = s[j];
		while(now->c != '#'&&!now->paths[i-'A'])now = now->fail;
		if(now->paths[i-'A'])now = now->paths[i-'A'];
		now->dp = min(now->dp,j+1);
	}
	reverse(_all(s));
	now = rtrie;
//	dfs(rtrie,"");
	for(int i = 0;i<s.size();i++){
		auto c = s[i];
		while(now->c != '#'&&!now->paths[c-'A'])now = now->fail;
		if(now->paths[c-'A'])now = now->paths[c-'A'];
		now->dp = min(now->dp,i+1);
	}
//	return 0;
	for(int i = stamp.size()-1;i>=0;i--){
		auto tmp  =stamp[i];
		tmp->fail->dp = min(tmp->fail->dp,tmp->dp);
	}
	for(int i =rstamp.size()-1;i>=0;i--){
		auto tmp = rstamp[i];
		tmp->fail->dp = min(tmp->fail->dp,tmp->dp);
	}
	int ans = 0;
	trie->dp = rtrie->dp = 0;
	for(int asd = 0;asd<m;asd++){
		auto &t = v[asd];
		auto &rt = rv[asd];
		auto p1 = trie;
		auto p2 = rtrie;
		for(auto &i:t){
			p1 = p1->paths[i-'A'];
		}
		p1 = p1->par;
		p2 = p2->paths[rt[0]-'A'];
		bool flag = false;
		for(int j = 1;j<rt.size();j++){
			auto i = rt[j];
			if(p1->dp+p2->dp<=s.size())flag = true;
			p1 = p1->par;
			p2 = p2->paths[i-'A'];
		}
//		if(p1->dp+p2->dp<=s.size())flag = true;
		if(flag)ans++;
	}
	cout<<ans;
}

