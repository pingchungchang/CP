#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct node{
	int par;
	ll val;
	vector<int> childs;
	node(){
		val = 0;
		par = -1;
	}
};
vector<node> v;
void dfs(int now){
	for(auto i:v[now].childs){
		dfs(i);
		v[now].val = max(v[now].val,v[i].val+1);
	}
	return;
}
int main(){
	int n;
	cin>>n;
	v = vector<node>(n,node());
	ll sum = 1LL*n*(n-1)/2;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		for(int j = 0;j<k;j++){
			int x;
			cin>>x;
			x--;
			sum -= x;
			v[i].childs.push_back(x);
			v[x].par = i;
		}
	}
	int root = (int)sum;
	cout<<root+1<<'\n';
	dfs(root);
	ll ans = 0;
	for(auto i:v){
		ans += i.val;
	}
	cout<<ans;
	return 0;
}

