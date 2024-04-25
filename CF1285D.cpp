#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

struct node{
	node* pl,*pr;
	node(){
		pl = pr = 0;
	}
};

node* trie = new node();

void add(int k){
	auto now = trie;
	for(int i = 29;i>=0;i--){
		if((1<<i)&k){
			if(!now->pr)now->pr = new node();
			now = now->pr;
		}
		else{
			if(!now->pl)now->pl = new node();
			now = now->pl;
		}
	}
	return;
}

int getval(int k){
	auto now = trie;
	int re = 0;
	for(int i = 29;i>=0;i--){
		if((1<<i)&k){
			if(now->pl)now = now->pl,re ^= 1<<i;
			else now = now->pr;
		}
		else{
			if(now->pr)now = now->pr,re ^= 1<<i;
			else now = now->pl;
		}
	}
	return re;
}

int dfs(node* now,int dep,int re){
	if(!now)return INT_MAX;
	if(now->pl&&now->pr)re ^= 1<<dep;
	//cout<<dep<<' '<<re<<endl;
	if(dep == 0)return re;
	return min(dfs(now->pl,dep-1,re),dfs(now->pr,dep-1,re));
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr){
		cin>>i;
		add(i);
	}
	cout<<dfs(trie,29,0);
}
