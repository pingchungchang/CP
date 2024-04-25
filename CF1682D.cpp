#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

struct node{
	char val;
	int nxt;
	int id;
	int pre;
	node(){}
};

const int mxn = 2e5+10;
node cycle[mxn];
int ppp = 0;
int newnode(char c,int ii){
	ppp++; 
	id = ii;
	cycle[ppp].val = c;
	cycle[ppp].nxt = 0;
	return ppp;
}
int del(int k){
	int p = cycle[k].pre;
	int s = cycle[k].nxt;
	cycle[p].nxt = s;
	cycle[s].pre = p;
	return s;
	return;
}

void solve(){
	int n;
	ppp = 0;
	cin>>n;
	string s;
	cin>>s;
	bool one = false;
	int z = 0;
	for(auto &i:s){
		if(i == '1')one = true;
		else z++;
	}
	if((z&1)||z == 0){
		cout<<"NO\n";
		return;
	}
	if(!one){
		cout<<"YES\n";
		for(int i = 2;i<=n;i++){
			cout<<1<<' '<<i<<'\n';
		}
		return;
	}
	vector<pii> ans;
	int root = newnode(s[0],1);
	int ttt = root;
	for(int i = 1;i<n;i++){
		int k = newnode(s[i],i+1);
		cycle[ttt].nxt = k;
		cycle[k].pre = ttt;
		ttt = k;
	}
	cycle[ttt].nxt = root;
	cycle[root].pre = ttt;
	while(cycle[root].val != '1'||cycle[cycle[root].nxt].val != '0')root = cycle[root].nxt;
	bool done[n+1] = {};
	while(!done[root]){
		done[root] = true;
		if(cycle[root].val == '0'){
			if(cycle[cycle[root].pre].val == '1')ans.push_back({cycle[root].pre,root});
		}
		else{
			int p = cycle[root].pre;
			ans.push_back({p,root});
		}
		root = cycle[root].nxt;
	}
	memset(done,false,sizeof(done));
	while(!done[root]){
		if(cycle[root].val == '0'){
			if(cycle[cycle[root].nxt].val == '1')del(root);
		}
		else{
			if(cycle[cycle[root].pre].val == '1')del(root);
		}
		root = cycle[root].nxt;
	}
	memset(done,false,sizeof(done));
	while(cycle[root].val != '0')root = cycle[root].nxt;
	while(cycle[root].val != '1')root = cycle[root].nxt;
	int p = root;
	done[p] = true;
	int pc = 0;
	root = cycle[root].nxt;
	ans.push_back({p,root});
	root = cycle[root].nxt;
	while(!done[root]){
		done[root] = true;
		if(cycle[root].val == '1'){
			p = root;
		}
		else{
			if(pc){
				ans.push_back({p,pc});
				ans.push_back({p,root});
				pc = 0;
			}
			else pc = root;
		}
		root = cycle[root].nxt;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
