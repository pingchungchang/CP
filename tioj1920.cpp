#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


struct node{
	int childs[2];
	int dp;
	node(){
		childs[0] = childs[1] = dp = 0;
	}
};

const int mxn = 1e4+10;
node trie[mxn*60];
int head[mxn];
int ppp = 0;

int newnode(){
	ppp++;
	assert(ppp<mxn*60);
	trie[ppp].dp = trie[ppp].childs[0] = trie[ppp].childs[1] = 0;
	return ppp;
}
int newnode(int pre){
	ppp++;
	assert(ppp<mxn*60);
	trie[ppp] = trie[pre];
	return ppp;
}

const int S = 30;
inline void add(int now,int val){
	for(int i = S;i>=0;i--){
		//assert(now);
		trie[now].dp++;
		int d = 0;
		if(val&(1<<i))d = 1;
		else d = 0;
		trie[now].childs[d] = newnode(trie[now].childs[d]);
		now = trie[now].childs[d];
	}
	trie[now].dp++;
	return;
}

inline int getans(int l,int r,int tar){
	int tl = head[l],tr = head[r];
	int ans = 0;
	for(int i = S;i>=0;i--){
		//assert(trie[tr].dp-trie[tl].dp);
		int d = 0;
		if(tar&(1<<i))d = 0;
		else d = 1;
		//cout<<tar<<' '<<i<<":"<<tl<<' '<<tr<<' '<<trie[trie[tr].childs[d]].dp-trie[trie[tl].childs[d]].dp<<' '<<endl;
		if(trie[trie[tr].childs[d]].dp-trie[trie[tl].childs[d]].dp){
			if(d)ans |= 1<<i;
			tl = trie[tl].childs[d];
			tr = trie[tr].childs[d];
		}
		else{
			if(d^1)ans |= 1<<i;
			tl = trie[tl].childs[d^1];
			tr = trie[tr].childs[d^1];
		}
	}
	return ans;
}

void dfs(int now,int v=0,int dep = S){
	if(!now)return;
	cout<<now<<":"<<trie[now].dp<<' '<<trie[now].childs[0]<<' '<<trie[now].childs[1]<<' '<<v<<endl;
	dfs(trie[now].childs[0],v,dep-1);
	dfs(trie[now].childs[1],v^(1<<dep),dep-1);
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	head[0] = newnode();
	int n,q;
	cin>>n>>q;
	int arr[n+1] = {};
	arr[1] = 0;
	head[1] = newnode(head[0]);
	add(head[1],arr[1]);
	for(int i = 2;i<=n+1;i++){
		cin>>arr[i];
		arr[i] ^= arr[i-1];
		head[i] = newnode(head[i-1]);
		//assert(head[i]);
		add(head[i],arr[i]);
	}
	/*
	for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';cout<<endl;
	for(int i = 1;i<=n;i++){
		cout<<i<<":"<<endl;
		dfs(head[i]);cout<<endl;
	}

   */
	while(q--){
		int l,r,v;
		cin>>l>>r>>v;
		l+=2;
		r++;
		int k = getans(l-2,r-1,arr[r]^v);
		//cout<<k<<":";
		cout<<(k^arr[r]^v)<<'\n';
	}
}
