#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 3e5+10;
vector<int> segtree[mxn*4];
int ans[mxn];
map<int,vector<int>> mp;
pii trie[mxn*32*4];
int ppp = 1;
vector<vector<pair<pii*,pii>>> dtrie;
vector<int> dans;
int newnode(){
	ppp++;
	trie[ppp].fs = trie[ppp].sc = 0;
	return ppp;
}

void modify(int now,int l,int r,int s,int e,int k){
	if(l>=s&&e>=r){
		segtree[now].push_back(k);
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=s)modify(now*2+1,l,mid,s,e,k);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,k);
	return;
}

void add(int val){
	int now = 1;
	int tans = 0;
	for(int i = 30;i>=0;i--){
		if(val&(1<<i)){
			if(trie[now].sc)now = trie[now].sc;
			else now = trie[now].fs,tans ^= 1<<i;
		}
		else{
			if(trie[now].fs)now = trie[now].fs;
			else now = trie[now].sc,tans ^= 1<<i;
		}
	}
	dans.push_back(min(dans.back(),tans));

	dtrie.push_back({});
	now = 1;
	for(int i = 30;i>=0;i--){
		if((1<<i)&val){
			if(trie[now].sc)now = trie[now].sc;
			else{
				dtrie.back().push_back({&trie[now],trie[now]});
				trie[now].sc = newnode();
				now = trie[now].sc;
			}
		}
		else{
			if(trie[now].fs)now = trie[now].fs;
			else{
				dtrie.back().push_back({&trie[now],trie[now]});
				trie[now].fs = newnode();
				now = trie[now].fs;
			}
		}
	}
}
void undo(){
	while(!dtrie.back().empty()){
		*dtrie.back().back().fs = dtrie.back().back().sc;
		dtrie.back().pop_back();
	}
	dtrie.pop_back();
	dans.pop_back();
	return;
}

void dfs(int now,int l,int r){
	//cout<<l<<' '<<r<<":";
	for(auto &i:segtree[now]){
		add(i);
		//cout<<i<<' ';
	}
	//cout<<'\n';
	if(l == r){
		ans[l] = dans.back();
	}
	else{
		int mid = (l+r)>>1;
		dfs(now*2+1,l,mid);
		dfs(now*2+2,mid+1,r);
	}
	for(auto &i:segtree[now])undo();
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;
	dans.push_back(1<<30);
	cin>>q;
	vector<int> ask;
	for(int i = 0;i<q;i++){
		int t;
		cin>>t;
		if(t == 3){
			ask.push_back(i);
		}
		else if(t == 1){
			int k;
			cin>>k;
			mp[k].push_back(i);
		}
		else{
			int k;
			cin>>k;
			modify(0,0,q,mp[k].back(),i-1,k);
			mp[k].pop_back();
		}
	}
	for(auto &i:mp){
		for(auto &j:i.sc){
			modify(0,0,q,j,q,i.fs);
		}
	}
	dfs(0,0,q);
	for(auto &i:ask)cout<<ans[i]<<'\n';
}
