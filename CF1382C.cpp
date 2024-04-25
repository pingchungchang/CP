#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


struct node{
	int pl,pr;
	bool rev;
	int tag,val;
	int pri;
	int sz;
	node(){
		sz = 1;
		pri = rand();
		pl = pr = 0;
		rev = tag = val = 0;
	}
};

const int mxn = 1e5+10;
node treap[mxn];
int ppp;
int newnode(int v){
	ppp++;
	treap[ppp].sz = 1;
	treap[ppp].pri = rand();
	treap[ppp].rev = treap[ppp].tag = 0;
	treap[ppp].val = v;
	return ppp;
}

void push(int now){
	if(!now)return;
	int ls = treap[now].pl,rs = treap[now].pr;
	treap[ls].tag ^= treap[now].tag;
	treap[rs].tag ^= treap[now].tag;
	treap[now].val ^= treap[now].tag;
	treap[now].tag = 0;
	if(treap[now].rev){
		treap[ls].rev ^= 1;
		treap[rs].rev ^= 1;
		treap[now].rev = 0;
		swap(treap[now].pl,treap[now].pr);
	}
	return;
}
void pull(int now){
	if(!now)return;
	int ls = treap[now].pl,rs = treap[now].pr;
	treap[now].sz = 1;
	if(ls)treap[now].sz += treap[ls].sz;
	if(rs)treap[now].sz += treap[rs].sz;
	return;
}

int merge(int a,int b){
	if(!a)return b;
	if(!b)return a;
	if(treap[a].pri>treap[b].pri){
		push(a);
		treap[a].pr = merge(treap[a].pr,b);
		pull(a);
		return a;
	}
	else{
		push(b);
		treap[b].pl = merge(a,treap[b].pl);
		pull(b);
		return b;
	}
}

void split(int now,int &a,int &b,int tar){
	//cout<<now<<':'<<treap[now].pl<<' '<<treap[now].pr<<endl;
	if(!now){
		a = 0;
		b = 0;
		return;
	}
	push(now);
	if(treap[now].sz-treap[treap[now].pr].sz == tar){
		a = now;
		b = treap[now].pr;
		treap[a].pr = 0;
	}
	else if(treap[now].sz-treap[treap[now].pr].sz<tar){
		a = now;
		split(treap[now].pr,treap[a].pr,b,tar-(treap[treap[now].pl].sz+1));
	}
	else{
		b = now;
		split(treap[now].pl,a,treap[b].pl,tar);
	}
	pull(a);
	pull(b);
	return;
}


int getright(int now){
	push(now);
	while(treap[now].pr){
		now = treap[now].pr;
		push(now);
	}
	return treap[now].val;
}

int getleft(int now){
	push(now);
	while(treap[now].pl){
		now = treap[now].pl;
		push(now);
	}
	return treap[now].val;
}

void dfs(int now){
	if(!now)return;
	push(now);
	dfs(treap[now].pl);
	cout<<now<<' '<<treap[now].val<<',';
	dfs(treap[now].pr);
}

void solve(){
	ppp = 0;
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	a = "#"+a;
	b = "#"+b;
	if(n == 1){
		if(a[1] == b[1])cout<<0<<'\n';
		else cout<<"1 1\n";
		return;
	}
	int total = 0;
	vector<int> ans;
	int root = newnode(a[1]-'0');
	for(int i = 2;i<=n;i++){
		root = merge(root,newnode(a[i]-'0'));
	}
	assert(treap[root].sz == n);
	for(int i = n;i>=1;i--){
		int ta,tb;
		if(treap[root].sz != i){
			split(root,ta,tb,i);
			root = ta;
		}
		assert(treap[root].sz == i);
		/*
		if(i == n-1){
			cout<<root<<endl;dfs(root);return;
		}

	   */
		//assert(treap[ta].sz != i);
		//dfs(root);cout<<endl;
		if(getright(root) == b[i]-'0')continue;
		if(getleft(root) == b[i]-'0'){
			ans.push_back(1);
			split(root,ta,tb,1);
			treap[ta].tag ^= 1;
			root = merge(ta,tb);
		}
		ans.push_back(i);
		split(root,ta,tb,i);
		//dfs(ta);cout<<endl<<endl;
		root = ta;
		treap[ta].rev ^= 1;
		treap[ta].tag ^= 1;
	}
	//cout<<endl;
	cout<<ans.size()<<' ';for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
/*

*/

int main(){
	treap[0].sz = 0;
	srand(time(NULL));
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
