#include <bits/stdc++.h>
using namespace std;

struct node{
	vector<string> childs;
	int depth;
	string parent;
	node(){
		parent = "-1";
		depth = -1;
	}
};
map<string,node> tree;
void dfs(string pos,int val){
	tree[pos].depth = val;
	for(int i = 0;i<tree[pos].childs.size();i++){
		string nxt = tree[pos].childs[i];
		dfs(nxt,val+1);
	}
	return;
}
int main(){
	int n;
	string buf;
	stringstream ss;
	getline(cin,buf);
	n = stoi(buf);
	for(int i = 0;i<n;i++){
		getline(cin,buf);
		ss.clear();
		ss.str(buf);
		string p;
		ss>>p;
		string c;
		while(ss>>c){
			tree[c].parent = p;
			tree[p].childs.push_back(c);
		}
	}
	for(auto it = tree.begin();it != tree.end();it++){
		if(it->second.parent == "-1"){
			dfs(it->first,0);
			break;
		}
	}
	getline(cin,buf);
	ss.clear();
	ss.str(buf);
	string s,e;
	ss>>s>>e;
	int ans = 0;
	while(s != e){
		ans++;
		if(tree[s].depth>tree[e].depth){
			s = tree[s].parent;
		}
		else e = tree[e].parent;
	}
	cout<<ans;
}
