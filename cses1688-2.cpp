#include <bits/stdc++.h>
using namespace std;

struct node{
	int par;
	vector<int> childs;
	int val;
	node(){
		val = 1e6;
		par = -1;
	}
};
vector<node> v;
vector<int> appear;
map<int,int> mp;
vector<int> segtree;
void dfs(int now){
	v[now].val = min(v[now].val,(int)appear.size());
	appear.push_back(v[now].val);
	mp[v[now].val] = now;
	for(auto nxt:v[now].childs){
		dfs(nxt);
		appear.push_back(v[now].val);
	}
	return;
}
void maketree(int pos,int val,int now,int l,int r){
	if(l == r){
		segtree[now] = val;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=pos)maketree(pos,val,now*2+1,l,mid);
	else maketree(pos,val,now*2+2,mid+1,r);
	segtree[now] = min(segtree[now*2+1],segtree[now*2+2]);
	return;
}
int getval(int s,int e,int now,int l,int r){
	if(l == s&&e == r)return segtree[now];
	int mid = (l+r)/2;
	if(mid>=e)return getval(s,e,now*2+1,l,mid);
	else if(mid+1<=s)return getval(s,e,now*2+2,mid+1,r);
	else return min(getval(s,mid,now*2+1,l,mid),getval(mid+1,e,now*2+2,mid+1,r));
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	v = vector<node>(n,node());
	for(int i = 1;i<=n-1;i++){
		int k;cin>>k;
		k--;
		v[i].par = k;
		v[k].childs.push_back(i);
	}
	dfs(0);
	int x= appear.size();
	segtree = vector<int>(4*appear.size(),0);
	for(int i = 0;i<appear.size();i++)maketree(i,appear[i],0,0,x-1);
	for(int i = 0;i<q;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		int vv = getval(min(v[a].val,v[b].val),max(v[a].val,v[b].val),0,0,x-1);;
		cout<<mp[vv]+1<<'\n';
	}
	return 0;
}
