#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;
vector<pair<int,int>> segtree;

void maketree(int pos,int val,int now,int l,int r){
	if(l == r){
		segtree[now] = make_pair(val,pos);
		return;
	}
	int mid = (l+r)/2;
	if(mid>=pos)maketree(pos,val,now*2+1,l,mid);
	else maketree(pos,val,now*2+2,mid+1,r);
	segtree[now] = min(segtree[now*2+1],segtree[now*2+2]);
	return;
}

pair<int,int> getval(int s,int e,int ran,int now,int l,int r){
	if(l == r){
		return segtree[now];
	}
	int mid = (l+r)/2;
	if(mid>=e)return getval(s,e,ran,now*2+1,l,mid);
	else if(mid+1<=s)return getval(s,e,ran,now*2+2,mid+1,r);
	else{
		if(segtree[now*2+1].first<ran)return getval(s,mid,ran,now*2+1,l,mid);
		else return getval(mid+1,e,ran,now*2+2,mid+1,r);
	}
}
void solve(){
	int n;
	cin>>n;
	v = vector<pair<int,int>>(n);
	segtree = vector<pair<int,int>>(n*4,make_pair(INT_MAX,INT_MAX));
	for(int i = 0;i<n;i++){
		cin>>v[i].first>>v[i].second;
		v[i].second+=v[i].first;
		maketree(i,v[i].first,0,0,n-1);
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	for(int i = 0;i<n;i++){
		pq.push(make_pair(v[i].second,i));
	}
	vector<int> ans(n);
	set<int> used;
	
	for(int i = 0;i<n;i++){
		while(!pq.empty()&&used.find(pq.top().second) != used.end())pq.pop();
		int lim = INT_MAX;
		if(!pq.empty())lim = pq.top().first;
		int range = n-1;
		if(!pq.empty())range = pq.top().second;
		pair<int,int> tmp = getval(0,range,lim,0,0,n-1);
		used.insert(tmp.second);
		maketree(tmp.second,INT_MAX,0,0,n-1);
		ans[i] = tmp.second;
	}
	for(int i:ans)cout<<i+1<<' ';
	cout<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i =0;i<t;i++)solve();
}
