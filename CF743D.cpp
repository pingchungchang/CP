#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node{
	vector<int> p;
	vector<ll> vals;
	ll val;
	ll biggest;
	ll sum;
	bool goneto;
	node(){
		goneto = false;
		val = -1;
		biggest = -1;
		sum = -1;
	}
};
vector<node> v;
ll ans = LONG_LONG_MIN;
bool error = true;
void dfs(int now){
	v[now].goneto = true;
	v[now].sum = v[now].val;
	v[now].biggest = LONG_LONG_MIN;
	for(int nxt:v[now].p){
		if(v[nxt].goneto == true)continue;
		dfs(nxt);
		v[now].sum += v[nxt].sum;
		v[now].biggest = max(v[now].biggest,v[nxt].biggest);
		v[now].vals.push_back(v[nxt].biggest);
	}
	v[now].biggest = max(v[now].biggest,v[now].sum);
	if(v[now].vals.size()<2)return;
	error = false;
	sort(v[now].vals.rbegin(),v[now].vals.rend());
	ans = max(ans,v[now].vals[0]+v[now].vals[1]);
	return;
}
int main(){
	int n;
	cin>>n;
	v = vector<node>(n,node());
	for(int i = 0;i<n;i++)cin>>v[i].val;
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		v[a-1].p.push_back(b-1);
		v[b-1].p.push_back(a-1);
	}
	dfs(0);
	if(error)cout<<"Impossible";
	else cout<<ans<<'\n';
//	for(int i = 0;i<n;i++)cout<<v[i].biggest<<' ';
}
